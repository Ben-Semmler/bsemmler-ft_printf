/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 13:46:22 by bsemmler          #+#    #+#             */
/*   Updated: 2021/10/09 19:00:50 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				pos;
	const unsigned char	*str;

	str = s;
	pos = 0;
	while (str[pos] != (unsigned char)c && pos < n)
		pos++;
	if (pos == n || (str[pos] == 0 && (unsigned char)c != 0))
		return (NULL);
	return ((void *)&str[pos]);
}
