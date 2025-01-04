/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 23:02:44 by stefan            #+#    #+#             */
/*   Updated: 2025/01/04 18:35:06 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h> 
#include <sys/types.h> 
#include "help.h"

void count_bits(int sig, siginfo_t *info, void *context)
{
    (void)context;
    static int r;
    int i ;
    static int a ;
    r = 0;
    if  (a ==0)
        a = info->si_pid;
    if(sig == 2)
    {
        ft_putstr_fd("\nclient interupted ", 1);
        i = 0;
        while (i < 16)
        {
            // ft_putstr_fd("sending end of transmision\n", 1);
            kill(a, SIGUSR2);
            usleep(100000);
            i++;
        }
        _exit(0); 
    }
    else if (sig == 10)
    {
        ft_putstr_fd("recived\n", 1);
        r++;
    }
    else if (sig == 12)
    {
        ft_putstr_fd("end of transmision", 1);
        exit(0);
    }
  
}
void code_and_sand(pid_t pid, char *str)
{
    int i;
    int c;
    while (*str)
    {
        i = 8;
        while(i--)
        {
            c = *str;
            if (c >> i & 1)
                kill(pid, SIGUSR1);
            else
                kill(pid, SIGUSR2);
            usleep(100000);
        }
        str++;
    }
        i = 8;
        while (i--)
        {
            kill(pid, SIGUSR2);
            usleep(100000);
        }
       
}
int main (int argc, char **argv)
{
    if (argc != 3)
        return(1);
    if (ft_atoi(argv[1]) < 0)
    {
        return(1);
        ft_putstr_fd("invalid pid\n", 1);
    }
    struct sigaction	sa;
	
	sa.sa_sigaction = count_bits;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);
    
    sigaction(SIGINT, &sa, NULL);
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    code_and_sand(ft_atoi(argv[1]), argv[2]);
    while(1)
        pause();
}
