/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silic <silic@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 23:07:18 by stefan            #+#    #+#             */
/*   Updated: 2025/01/02 17:58:38 by silic            ###   ########.fr       */
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
    kill(info->si_pid, SIGUSR1);
    if (sig == SIGUSR1)
    {
        c |= 1;
    }
    c <<= 1;
    i++;
    if (i == 8)
    {
        c >>= 1;
        ft_putchar_fd(c, 1);
        if (c == '\0')
            kill(info->si_pid, SIGUSR2);
        c = 0;
        i = 0;
    }
}

int	main(void)
{
	struct sigaction	sa;
	
	sa.sa_sigaction = signal_handler;
	
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	printf("PID: %d\n", getpid());
	printf("Waiting for signals...\n");
	while (1)
	{
		pause();
	}
	return (0);
}
