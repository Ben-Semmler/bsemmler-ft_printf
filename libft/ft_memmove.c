/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 13:42:10 by bsemmler          #+#    #+#             */
/*   Updated: 2021/09/19 17:25:22 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		pos;
	char		*d;
	const char	*s;

	pos = 0;
	d = dst;
	s = src;
	if (src < dst)
	{
		while (pos < len)
		{
			d[len - pos - 1] = s[len - pos - 1];
			pos++;
		}
	}
	else
	{
		while (pos < len)
		{
			d[pos] = s[pos];
			pos++;
		}
	}
	return (dst);
}
