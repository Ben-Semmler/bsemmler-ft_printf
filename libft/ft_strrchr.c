/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 13:43:52 by bsemmler          #+#    #+#             */
/*   Updated: 2021/09/27 16:30:18 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	pos;

	pos = ft_strlen(s);
	while (pos >= 0 && s[pos] != (char)c)
		pos--;
	if (s[pos] == (char)c)
		return ((char *)&s[pos]);
	else
		return (NULL);
}
