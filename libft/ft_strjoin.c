/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:33:13 by bsemmler          #+#    #+#             */
/*   Updated: 2021/09/20 16:36:05 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	pos;
	size_t	pos2;
	char	*str;

	pos = 0;
	pos2 = 0;
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	while (s1[pos2])
	{
		str[pos] = s1[pos2];
		pos++;
		pos2++;
	}
	pos2 = 0;
	while (s2[pos2])
	{
		str[pos] = s2[pos2];
		pos++;
		pos2++;
	}
	str[pos] = 0;
	return (str);
}
