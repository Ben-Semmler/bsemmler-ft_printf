/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 15:30:37 by bsemmler          #+#    #+#             */
/*   Updated: 2021/09/27 16:35:38 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>

static int	abslut(int i);

void	ft_putnbr_fd(int n, int fd)
{
	int	i;
	int	ntemp;

	if (n == 0)
		ft_putchar_fd('0', fd);
	if (n < 0)
		ft_putchar_fd('-', fd);
	while (n != 0)
	{
		i = 1;
		ntemp = n;
		while (ntemp >= 10 || ntemp <= -10)
		{
			i = i * 10;
			ntemp = ntemp / 10;
		}
		n = n - (ntemp * i);
		ft_putchar_fd((char)(abslut(ntemp)) + '0', fd);
		while ((n >= 0 && i / 10 > n) || (n < 0 && - i / 10 < n))
		{
			i = i / 10;
			ft_putchar_fd('0', fd);
		}
	}
}

static int	abslut(int i)
{
	if (i < 0)
		return (-i);
	return (i);
}
