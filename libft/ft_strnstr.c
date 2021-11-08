/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 13:47:00 by bsemmler          #+#    #+#             */
/*   Updated: 2021/09/20 16:37:08 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	h_pos;
	size_t	n_pos;

	h_pos = 0;
	if (ft_strlen(haystack) == 0 && ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (haystack[h_pos] != 0 && h_pos < len)
	{
		n_pos = 0;
		while (haystack[h_pos + n_pos] == needle[n_pos] && needle[n_pos] != 0)
			n_pos++;
		if (needle[n_pos] == 0 && h_pos + n_pos <= len)
			return ((char *)&haystack[h_pos]);
		h_pos++;
	}
	return (NULL);
}
