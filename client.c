/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silic <silic@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 23:02:44 by stefan            #+#    #+#             */
/*   Updated: 2025/01/08 18:12:00 by silic            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "help.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void	count_bits(int sig, siginfo_t *info, void *context)
{
	int			i;
	static int	a;

	(void)context;
	if (a == 0)
		a = info->si_pid;
	if (sig == 2)
	{
		ft_putstr_fd("\nclient interupted ", 1);
		i = 0;
		while (i < 16)
		{
			kill(a, SIGUSR2);
			usleep(100000);
			i++;
		}
		exit(0);
	}
	else if (sig == 10)
		ft_putstr_fd("recived\n", 1);
	else if (sig == 12)
	{
		ft_putstr_fd("end of transmision", 1);
		exit(0);
	}
}

void	code_and_sand(pid_t pid, char *str)
{
	int	i;
	int	c;

	while (*str)
	{
		i = 8;
		while (i--)
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

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	if (argc != 3)
		return (1);
	if (ft_atoi(argv[1]) < 0)
	{
		ft_putstr_fd("invalid pid\n", 1);
		return (1);
	}
	sa.sa_sigaction = count_bits;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	code_and_sand(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
}
