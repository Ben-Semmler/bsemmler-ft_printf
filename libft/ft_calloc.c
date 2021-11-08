/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 13:48:51 by bsemmler          #+#    #+#             */
/*   Updated: 2021/09/15 13:48:54 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*mem;
	size_t	pos;

	mem = malloc(count * size);
	pos = 0;
	while (pos < count * size)
	{
		mem[pos] = 0;
		pos++;
	}
	return ((void *)mem);
}
