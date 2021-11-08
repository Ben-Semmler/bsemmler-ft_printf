/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 13:49:06 by bsemmler          #+#    #+#             */
/*   Updated: 2021/09/27 16:32:06 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	pos;
	size_t	length;

	if (s1 == NULL)
		return (ft_strdup("(null)"));
	length = ft_strlen(s1);
	dst = malloc(length);
	pos = 0;
	while (pos < length)
	{
		dst[pos] = s1[pos];
		pos++;
	}
	dst[pos] = 0;
	return (dst);
}
