/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 23:07:18 by stefan            #+#    #+#             */
/*   Updated: 2025/01/04 18:29:00 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include "help.h"
#include <string.h>

void	decode_and_print(int sig);

void	signal_handler(int sig, siginfo_t *info, void *context)
{
	static int c = 0;
    static int i = 0;

    (void)context;
    if (sig == SIGUSR1)
        c |= 1;
    c <<= 1;
    i++;
    if (i == 8)
    {
        c >>= 1;
        ft_putchar_fd(c, 1);
        if (c == '\0')
        {
            kill(info->si_pid, SIGUSR2);
            ft_putstr_fd("\nend of reciving", 1);
            ft_putnbr_fd(i, 1);
        }
        c = 0;
        i = 0;
    }
    kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;
	
	sa.sa_sigaction = signal_handler;
	
    sa.sa_sigaction = signal_handler;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);
    
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    ft_putnbr_fd(getpid(), 1);
	while (1)
	{
		pause();
	}
	return (0);
}
