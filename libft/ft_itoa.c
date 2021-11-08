/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:13:19 by bsemmler          #+#    #+#             */
/*   Updated: 2021/10/14 15:43:01 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_abs(int n);
static int	get_length(int n);

char	*ft_itoa(int n)
{
	char	*str;
	int		pos;
	int		len;

	len = get_length(n);
	str = malloc(len + 1);
	str[0] = '+';
	if (n < 0)
		str[0] = '-';
	str[len] = 0;
	pos = len - 1;
	while ((str[0] != '-' && pos >= 0) || (str[0] == '-' && pos > 0))
	{
		str[pos] = (char)(ft_abs(n - (int)(10 * (n / 10))) + '0');
		n = n / 10;
		pos--;
	}
	return (str);
}

static int	get_length(int n)
{
	size_t	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
