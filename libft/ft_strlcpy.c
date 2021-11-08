/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 13:42:24 by bsemmler          #+#    #+#             */
/*   Updated: 2021/09/27 16:37:48 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	pos;
	size_t	length;

	pos = 0;
	length = ft_strlen(src);
	while (pos + 1 < dstsize && src[pos])
	{
		dst[pos] = src[pos];
		pos++;
	}
	if (pos < dstsize && dstsize > 0)
		dst[pos] = 0;
	return (length);
}
