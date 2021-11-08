/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 13:46:37 by bsemmler          #+#    #+#             */
/*   Updated: 2021/10/09 18:25:51 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		pos;

	pos = 0;
	while (pos < n)
	{
		if (((unsigned char *)s1)[pos] != ((unsigned char *)s2)[pos])
			return (((unsigned char *)s1)[pos] - ((unsigned char *)s2)[pos]);
		pos++;
	}
	return (0);
}
