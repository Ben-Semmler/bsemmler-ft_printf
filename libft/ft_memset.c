/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 13:41:20 by bsemmler          #+#    #+#             */
/*   Updated: 2021/09/15 13:41:22 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	pos;
	char	*str;

	pos = 0;
	str = b;
	while (pos < len)
	{
		str[pos] = c;
		pos++;
	}
	return (b);
}
