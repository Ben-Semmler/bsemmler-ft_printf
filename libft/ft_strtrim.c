/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:41:03 by bsemmler          #+#    #+#             */
/*   Updated: 2021/10/09 18:14:55 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

static int	find_trimmed_length(const char *s1, const char *set);
static int	find_trim_start(const char *s1, const char *set);
static int	find_trim_end(const char *s1, const char *set);

char	*ft_strtrim(const char *s1, const char *set)
{
	int		pos;
	int		pos2;
	int		len;
	char	*str;

	len = find_trimmed_length(s1, set);
	str = malloc(len + 1);
	pos = find_trim_start(s1, set);
	pos2 = 0;
	while (pos2 <= len)
	{
		str[pos2] = s1[pos];
		pos++;
		pos2++;
	}
	str[pos2] = 0;
	return (str);
}

static int	find_trimmed_length(const char *s1, const char *set)
{
	int	len;

	len = ft_strlen(s1) - find_trim_start(s1, set) - find_trim_end(s1, set) - 1;
	if (len >= 0)
		return (len);
	else
		return (0);
}

static int	find_trim_start(const char *s1, const char *set)
{
	int	pos;
	int	pos2;
	int	rm;

	pos = 0;
	rm = 0;
	while (pos == rm && s1[pos])
	{
		pos2 = 0;
		while (set[pos2])
		{
			if (s1[pos] == set[pos2])
				rm++;
			pos2++;
		}
		pos++;
	}
	return (rm);
}

static int	find_trim_end(const char *s1, const char *set)
{
	int	pos;
	int	pos2;
	int	rm;

	pos = ft_strlen(s1) - 1;
	rm = 0;
	while ((int)ft_strlen(s1) == rm + pos + 1 && pos >= 0)
	{
		pos2 = 0;
		while (set[pos2])
		{
			if (s1[pos] == set[pos2])
				rm++;
			pos2++;
		}
		pos--;
	}
	return (rm);
}
