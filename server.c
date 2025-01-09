/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silic <silic@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 23:07:18 by stefan            #+#    #+#             */
/*   Updated: 2025/01/09 15:48:04 by silic            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "help.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

static void	extender(char **str, int *j, pid_t pid);

void	signal_handler(int sig, siginfo_t *info, void *context)
{
	static int	c = 0;
	static int	i = 0;
	static int	j = 0;
	static char	*str = NULL;

	(void)context;
	if (sig == SIGUSR1)
		c |= 1;
	c <<= 1;
	i++;
	if (i == 8)
	{
		c >>= 1;
		str = realocation(str);
		if (!str)
			return ;
		str[j] = c;
		j++;
		str[j] = 0;
		if (c == '\0')
			extender(&str, &j, info->si_pid);
		c = 0;
		i = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

static void	extender(char **str, int *j, pid_t pid)
{
	ft_putstr_fd(*str, 1);
	kill(pid, SIGUSR2);
	(*j) = 0;
	free(*str);
	(*str) = NULL;
}

char	*realocation(char *str)
{
	char	*new_str;
	int		i;

	i = 0;
	if (!str)
		return (new_str = (char *)malloc(2));
	new_str = (char *)malloc(ft_strlen(str) + 2);
	if (!new_str)
		return (NULL);
	ft_memcpy(new_str, str, ft_strlen(str));
	free(str);
	return (new_str);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putstr_fd("server pid: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	while (1)
		pause();
	return (0);
}
