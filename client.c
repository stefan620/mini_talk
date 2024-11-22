/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 23:02:44 by stefan            #+#    #+#             */
/*   Updated: 2024/11/23 00:29:22 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h> 

char *code_the_message(char *str);
void reverse_bin(char **str, int j);
int main(int argc, char **argv)
{
    char *pr;
    pr = code_the_message(argv[1]);
    printf("%s", pr);
    free(pr);
}
char *code_the_message(char *str)
{
    int i;
    int j;
    int c;
    char *ret;
    ret = malloc(7* sizeof(char));
    i =0;
    j =0;
    c = 0;
    
    while (str[i])
    {
        c = str[i];
        while (c != 0)
        {
            if (c % 2 == 0)
                ret[j] = '0';
            else 
                ret[j] = '1';
            j++;
            c = c/2;
        }
        reverse_bin(&ret, j);
        i++;
    }
    return(ret);
}
void reverse_bin(char **str, int j)
{
    int i;
    int k;
    char *temp; 
    temp = (char *)malloc(7*sizeof(char));
    i = 0;
    j--;
    k = j -6;
    while (j >= k)
    {
        temp[i] =(*str)[j];
        i++;
        j--;
    }
    j++;
    i = 0;
    k = j + 7;
    while (j != k)
    {
        (*str)[j] = temp[i];
        j++;
        i++;
    }
    free(temp);
}
