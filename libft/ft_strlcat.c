/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 13:42:57 by bsemmler          #+#    #+#             */
/*   Updated: 2021/09/27 16:38:05 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	pos;
	size_t	length;

	pos = 0;
	length = ft_strlen(dst);
	while (length + pos + 1 < dstsize && src[pos])
	{
		dst[length + pos] = src[pos];
		pos++;
	}
	if (length + pos < dstsize)
		dst[length + pos] = 0;
	if (length < dstsize)
		return (length + ft_strlen(src));
	return (ft_strlen(src) + dstsize);
}
