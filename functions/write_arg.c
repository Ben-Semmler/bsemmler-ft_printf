/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:59:17 by bsemmler          #+#    #+#             */
/*   Updated: 2021/10/18 18:23:54 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_printf_functs.h"

static void	write_sign(char spec, char *arg, int *flags);
static void	write_dot(char spec, int *flags, char *arg);
static void	write_spec(char spec, char *arg, int arg_len, int *flags);
static int	apply_field(int size, int arg_len, int zeroes);

int	write_arg(int arg_len, char *arg, int *flags, char spec)
{
	int		total;

	total = 0;
	if (flags[4] != -1)
		write_sign(spec, arg, flags);
	if (flags[0] == -1)
		total += apply_field(flags[5], arg_len, flags[4]);
	if (flags[4] == -1)
		write_sign(spec, arg, flags);
	write_dot(spec, flags, arg);
	write_spec(spec, arg, arg_len, flags);
	if (flags[0] != -1)
		total += apply_field(flags[5], arg_len, -1);
	return (total);
}

static void	write_sign(char spec, char *arg, int *flags)
{
	if (spec == 'd' || spec == 'i')
	{
		if (arg[0] == '-')
			ft_putchar_fd('-', 1);
		else
		{
			if (flags[1] != -1)
				ft_putchar_fd('+', 1);
			else if (flags[2] != -1)
				ft_putchar_fd(' ', 1);
		}
	}
}

static void	write_dot(char spec, int *flags, char *arg)
{
	char	*pspecs;
	int		pos;

	pspecs = ft_strdup("diuxX");
	pos = 0;
	while (pspecs[pos])
	{
		while (pspecs[pos] == spec && flags[6] > (int)ft_strlen(arg))
		{
			ft_putchar_fd('0', 1);
			flags[6]--;
		}
		if (pspecs[pos] == spec && flags[6] == (int)ft_strlen(arg)
			&& arg[0] == '-')
			ft_putchar_fd('0', 1);
		pos++;
	}
	free(pspecs);
}

static void	write_spec(char spec, char *arg, int arg_len, int *flags)
{
	int	pos;

	if ((spec == 'd' || spec == 'i') && arg[0] == '-')
		ft_putstr_fd(&arg[1], 1);
	else if (spec == 'c')
		ft_putchar_fd(arg[0], 1);
	else if (spec == 's' && flags[6] != -1 && (int)ft_strlen(arg) > flags[6])
	{
		pos = -1;
		while (pos++ < arg_len - 1)
			ft_putchar_fd(arg[pos], 1);
	}
	else
		ft_putstr_fd(arg, 1);
}

static int	apply_field(int size, int arg_len, int zeroes)
{
	size_t	total;

	total = 0;
	while (size > arg_len)
	{
		size--;
		total++;
		if (zeroes == -1)
			ft_putchar_fd(' ', 1);
		else
			ft_putchar_fd('0', 1);
	}
	return (total);
}
