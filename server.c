/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 23:07:18 by stefan            #+#    #+#             */
/*   Updated: 2024/12/04 20:10:10 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>

void just_a_print(int signum);
void ft_decode_signal(int *dec);
void ft_collect_signl(int sig);
int ft_power(int power);
int main(void)
{
    int i;

    i = getpid();
    printf("%d\n", i);
    while (1)
    {
        signal(SIGUSR2, just_a_print);
        signal(SIGUSR1, just_a_print);
    }
}
void just_a_print(int signum)
{
    if (signum == 10)
        ft_collect_signl(1);
    else if (signum == 12)
        ft_collect_signl(0);
}
void ft_collect_signl(int sig)
{
    static int i;
    static int arr[6];
    
    // printf("sig: %d\n", sig);
    if (i > 6)
    {
        ft_decode_signal(arr);
        i = 0;
        return;
    }
    if (sig == 1)
    {
        arr[i] = 1;
    }
    if (sig == 0)
    {
        arr[i] = 0;
    }
    // printf("dec1 %d\n", arr[i]);
    // printf("i: %d \n", i);
    i++; 
}
void ft_decode_signal(int *dec)
{
    int i;
    int j;
    int ch;

    ch = 0;
    i = 0;
    j = 6;
    while (i != 7)
    {
        // printf("dec %d\n", dec[i]);
        if (dec[i] == 1)
        {
            ch = ch + ft_power(j);
            // printf("power: %d\n", ft_power(j));
        }
        j--;
        i++;
    }
    printf("%c\n", ch);
}
int ft_power(int power)
{
    int con;
    int ret;

    con = 2;
    ret = 2;
    if (power == 0)
        return (1);
    while (power > 1)
    {
        // printf("sa ovim: %d\n", power);
        ret = ret * con;
        power--;
    }
    // printf("con: %d\n", ret);
    return (ret);
}