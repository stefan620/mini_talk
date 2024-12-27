/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:54:00 by stefan            #+#    #+#             */
/*   Updated: 2024/12/25 16:54:46 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	crate_str(int nb, int fd);
static int	count_nb(int nb);

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
		write(fd, "0", 1);
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
	}
	if (n > 0)
		crate_str(n, fd);
	if (n < 0 && n != -2147483648)
	{
		write(fd, "-", 1);
		crate_str(n, fd);
	}
}
/*
int	main(void)
{
	ft_putnbr_fd(-2147483648, 1);
}
*/

static int	count_nb(int nb)
{
	int	j;

	j = 0;
	while (nb != 0)
	{
		nb = nb / 10;
		j++;
	}
	return (j);
}

static void	crate_str(int nb, int fd)
{
	int		j;
	int		i;
	char	str[11];

	i = count_nb(nb);
	j = count_nb(nb);
	if (nb < 0)
		nb = nb * -1;
	while (j > 0)
	{
		str[j - 1] = nb % 10 + '0';
		nb = nb / 10;
		j--;
	}
	str[i] = '\0';
	j = 0;
	while (str[j])
	{
		write(fd, &str[j], 1);
		j++;
	}
}