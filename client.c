/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 23:02:44 by stefan            #+#    #+#             */
/*   Updated: 2024/12/04 20:26:47 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h> 
#include <sys/types.h> 

int *code_the_message(int c, int i);
void reverse_bin(char **str, int j);
void ft_send_signal(int *arr, pid_t pid, int i);
int ft_pid(char *str);
int ft_validation(char *str);
int main(int argc, char **argv)
{
    int *pr;
    int pid;
    int i;
    int c;
    
    i = 0;
    pid = ft_pid(argv[1]);
    if (!ft_validation(argv[2]))
        return(printf("mistake\n"), 0);
    while (argv[2][i])
    {
        c = argv[2][i];
        pr = code_the_message(c, i);
        ft_send_signal(pr, pid, i);
        free(pr);
        i++;
    }
    printf("%d", pid);
}
int *code_the_message(int c, int i)
{
    int k;
    int j;
   
    int *ret;
    ret = malloc(7 * sizeof(int));
    k =0;
    j = 6;
    // printf("passed int %c\n",c);
    while (c != 0)
    {
        if (c % 2 == 0)
            ret[j] = 0;
        else 
            ret[j] = 1;
        // printf("asdsad %d \n", ret[j]);
        j--;
        c = c/2;
    }
    return(ret);
}
void ft_send_signal(int *arr, pid_t pid, int i)
{
    int j;
    
    j = 0;
    
    while (j != 8)
    {   
        if (arr[j] == 1)
            kill(pid, SIGUSR1);
        else if(arr[j] == 0)
            kill(pid, SIGUSR2);
        j++;
        sleep(0.5);
    }
}
int ft_pid(char *str)
{
    int i;
    int pid;

    i = 0;
    while (str[i])
    {
        pid = pid * 10 + str[i] - '0';
        i++;
    }
    return(pid);
}
int ft_validation(char *str)
{
    int i;
    
    i = 0;
    while (str[i])
    {
        if (str[i] < 0 || str[i] > 155)
            return(0);
        i++;
    }
    return(1);
}