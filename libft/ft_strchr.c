/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 13:43:43 by bsemmler          #+#    #+#             */
/*   Updated: 2021/09/19 18:00:07 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	size_t	pos;

	pos = 0;
	while (s[pos] != 0 && s[pos] != (char)c)
		pos++;
	if (s[pos] == 0 && c != 0)
		return (NULL);
	else
		return ((char *)&s[pos]);
}
