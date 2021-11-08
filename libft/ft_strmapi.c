/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 17:17:32 by bsemmler          #+#    #+#             */
/*   Updated: 2021/09/19 17:17:33 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	pos;
	size_t	len;

	len = ft_strlen(s);
	str = NULL;
	str = malloc(len + 1);
	pos = 0;
	while (pos < len)
	{
		str[pos] = (*f)(pos, s[pos]);
		pos++;
	}
	str[pos] = 0;
	return (str);
}
