/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_hex_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:08:02 by bsemmler          #+#    #+#             */
/*   Updated: 2021/10/17 18:32:15 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_functs.h"
#include "../libft.h"

static void		find_str(char *str, char *set, unsigned long i, int set_len);
unsigned int	find_base_next_num(unsigned long i, int set_len);
static int		find_base_length(unsigned long i, int set_len);

char	*write_base(unsigned long i, char *set)
{
	char	*str;
	int		set_len;

	str = NULL;
	set_len = ft_strlen(set);
	if (set_len == 0)
		str = ft_strdup("ERROR: INVALID BASE SET");
	if (i == 0)
	{
		str = malloc(2);
		str[0] = set[0];
		str[1] = 0;
	}
	else
	{
		str = malloc(find_base_length(i, set_len) + 1);
		find_str(str, set, i, set_len);
	}
	return (str);
}

static void	find_str(char *str, char *set, unsigned long i, int set_len)
{
	int	num;
	int	len;
	int	nextlen;
	int	pos;

	pos = 0;
	nextlen = -1;
	while (i > 0)
	{
		num = find_base_next_num(i, set_len);
		if (nextlen == -1)
			len = find_base_length(i, set_len);
		else
			len = nextlen;
		i -= num * ft_pow(set_len, len - 1);
		str[pos++] = set[num];
		len--;
		nextlen = find_base_length(i, set_len);
		while (len > nextlen || (i == 0 && len == nextlen))
		{
			str[pos++] = set[0];
			len--;
		}
	}
	str[pos] = 0;
}

static int	find_base_length(unsigned long i, int set_len)
{
	unsigned long	base;

	base = 1;
	while (ft_pow(set_len, base) <= i && ft_pow(set_len, base) != 0)
		base++;
	return (base);
}

unsigned int	find_base_next_num(unsigned long i, int set_len)
{
	int	base;
	int	multi;

	if (i == 0)
		return (0);
	base = find_base_length(i, set_len) - 1;
	multi = 1;
	while (ft_pow(set_len, base) * multi <= i && multi < set_len)
	{
		multi++;
	}
	multi--;
	return (multi);
}
