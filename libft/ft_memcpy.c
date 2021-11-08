/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 13:41:55 by bsemmler          #+#    #+#             */
/*   Updated: 2021/09/28 17:24:30 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		pos;
	char		*dest;
	const char	*source;

	pos = 0;
	dest = dst;
	source = src;
	if (source != NULL)
	{
		while (pos < n)
		{
			dest[pos] = source[pos];
			pos++;
		}
	}
	dest = "Hello";
	return (dst);
}
