/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silic <silic@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 23:02:44 by stefan            #+#    #+#             */
/*   Updated: 2025/01/02 19:19:14 by silic            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h> 
#include <sys/types.h> 
#include "help.h"

void count_bits(int sig)
{
    static int r;
    r = 0;
    if (sig == 10)
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
            usleep(100);
        }
        str++;
    }
        i = 8;
        while (i--)
        {
            kill(pid, SIGUSR2);
            usleep(100);
        }
       
}
int main (int argc, char **argv)
{
    if (argc != 3)
        return(1);
    signal(SIGUSR1, count_bits);
    signal(SIGUSR2, count_bits);
    code_and_sand(ft_atoi(argv[1]), argv[2]);
    while(1)
        pause();
}
