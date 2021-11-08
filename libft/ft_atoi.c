/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 13:47:12 by bsemmler          #+#    #+#             */
/*   Updated: 2021/09/28 15:51:05 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t	pos;
	int		result;
	int		sign;

	pos = 0;
	result = 0;
	sign = 1;
	while ((str[pos] >= 9 && str[pos] <= 13) || str[pos] == ' ')
		pos++;
	if (str[pos] == '-')
		sign = -1;
	if (str[pos] == '+' || str[pos] == '-')
		pos++;
	while (ft_isdigit(str[pos]) != 0)
	{
		result = result * 10 + sign * (str[pos] - '0');
		pos++;
	}
	return (result);
}
