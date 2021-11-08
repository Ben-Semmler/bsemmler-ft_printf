/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 13:56:58 by bsemmler          #+#    #+#             */
/*   Updated: 2021/09/27 16:33:55 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>

static void		store_split(int *pos, const char *s, char c, char **splits);
static size_t	get_split_length(const char *s, char c);
static size_t	count_strings(const char *s, char c);

char	**ft_split(const char *s, char c)
{
	int		pos[2];
	char	**splits;

	pos[0] = 0;
	pos[1] = 0;
	splits = malloc(sizeof(char *) * (count_strings(s, c) + 1));
	while (s[pos[0]])
	{
		if (get_split_length(&s[pos[0]], c) > 0)
		{
			store_split(&pos[0], s, c, splits);
		}
		if (s[pos[0]])
			pos[0]++;
	}
	splits[pos[1]] = NULL;
	return (splits);
}

static void	store_split(int *pos, const char *s, char c, char **splits)
{
	int	pos3;

	pos3 = 0;
	splits[pos[1]] = malloc(get_split_length(&s[pos[0]], c) + 1);
	while (s[pos[0] + pos3] != c && s[pos[0] + pos3] != 0)
	{
		splits[pos[1]][pos3] = s[pos[0] + pos3];
		pos3++;
	}
	splits[pos[1]][pos3] = 0;
	pos[1]++;
	pos[0] += pos3;
}

static size_t	get_split_length(const char *s, char c)
{
	size_t	pos;

	pos = 0;
	while (s[pos] && s[pos] != c)
		pos++;
	return (pos);
}

static size_t	count_strings(const char *s, char c)
{
	int	pos;
	int	len;

	pos = 0;
	len = 0;
	while (s[pos])
	{
		if (get_split_length(&s[pos], c) > 0)
			len++;
		pos += get_split_length(&s[pos], c);
		if (s[pos])
			pos++;
	}
	return (len);
}
