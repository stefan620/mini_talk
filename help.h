/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silic <silic@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:19:45 by silic             #+#    #+#             */
/*   Updated: 2025/01/08 17:53:19 by silic            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELP_H
# define HELP_H

# include <stdlib.h>

int		ft_atoi(const char *str);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
char	*realocation(char *str);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *str);

#endif /* FILENAME_H */