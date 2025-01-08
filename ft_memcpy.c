/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silic <silic@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 17:17:03 by silic             #+#    #+#             */
/*   Updated: 2025/01/08 17:12:24 by silic            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dptr;
	const unsigned char	*sptr;

	sptr = src;
	dptr = dest;
	if (!dest && !src)
		return (0);
	while (n-- > 0)
	{
		*dptr++ = *sptr++;
	}
	return (dest);
}

size_t	ft_strlen(const char *str)
{
	size_t	n;

	n = 0;
	while (str[n])
	{
		n++;
	}
	return (n);
}
