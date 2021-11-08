/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:38:07 by bsemmler          #+#    #+#             */
/*   Updated: 2021/09/21 16:40:58 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	pos;
	char	*dst;

	pos = 0;
	if (len + start < ft_strlen(s))
		dst = malloc(sizeof(char) * len + 1);
	else if (start <= ft_strlen(s))
		dst = malloc(sizeof(char) * ft_strlen(s) - start);
	else
		dst = malloc(sizeof(char) * 1);
	while (s[start + pos] && pos < len && start < ft_strlen(s))
	{
		dst[pos] = s[start + pos];
		pos++;
	}
	dst[pos] = 0;
	return (dst);
}
