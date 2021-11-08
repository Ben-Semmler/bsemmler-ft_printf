/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared_write_functs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:36:34 by bsemmler          #+#    #+#             */
/*   Updated: 2021/10/19 16:39:03 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long long	ft_pow(int base, int exp)
{
	unsigned long long	result;

	result = 1;
	while (exp > 0)
	{
		result = result * base;
		exp--;
	}
	return (result);
}

double	ft_abs(double n)
{
	if (n < 0)
		return (-n);
	return (n);
}
