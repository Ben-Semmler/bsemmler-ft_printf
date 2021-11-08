/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:14:23 by bsemmler          #+#    #+#             */
/*   Updated: 2021/10/19 16:57:49 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_functs.h"
#include "../libft.h"

static int	find_arg_len(char *arg, int *flags, char spec);
static int	*check_flags(const char *s);
static void	get_bool_flags(const char *s, int *applied_flags, int pos[2]);
static int	get_int_flag(const char *s);

int	apply_flags(const char *s, char *arg, char spec)
{
	size_t	total;
	int		*flags;
	int		arg_len;

	flags = check_flags(s);
	arg_len = find_arg_len(arg, flags, spec);
	total = arg_len;
	if ((flags[3] != -1 && arg[0] != '0') || spec == 'p')
	{
		if (spec == 'x' || spec == 'p')
			ft_putstr_fd("0x", 1);
		else if (spec == 'X')
			ft_putstr_fd("0X", 1);
	}
	total += write_arg(arg_len, arg, flags, spec);
	free(arg);
	free(flags);
	return (total);
}

static int	find_arg_len(char *arg, int *flags, char spec)
{
	int		arg_len;
	char	*pspecs;
	int		pos;

	arg_len = 1;
	if (spec != 'c')
		arg_len = ft_strlen(arg);
	pspecs = ft_strdup("diuxX");
	pos = -1;
	while (pspecs[++pos])
		if (pspecs[pos] == spec && arg_len < flags[6])
			arg_len = flags[6];
	if (spec == 'd' || spec == 'i')
		if ((flags[1] != -1 || flags[2] != -1) && arg[0] != '-')
			arg_len++;
	free(pspecs);
	if ((flags[3] != -1 && arg[0] != '0' && (spec == 'x' || spec == 'X'))
		|| spec == 'p')
		arg_len += 2;
	if (flags[6] != -1 && spec == 's' && arg_len > flags[6])
		arg_len = flags[6];
	if (spec == 'd' || spec == 'i')
		if (arg && arg[0] == '-' && flags[6] > (int)ft_strlen(arg) - 1)
			arg_len++;
	return (arg_len);
}

static int	*check_flags(const char *s)
{
	int		*applied_flags;
	int		pos[2];

	pos[0] = 0;
	pos[1] = 0;
	applied_flags = malloc(sizeof(int) * 7);
	get_bool_flags(s, applied_flags, pos);
	applied_flags[5] = get_int_flag(&s[pos[1]]);
	while (s[pos[1]] >= '0' && s[pos[1]] <= '9')
		pos[1]++;
	if (s[pos[1]] == '.')
	{
		applied_flags[6] = get_int_flag(&s[pos[1] + 1]);
		if (applied_flags[6] == -1)
			applied_flags[6] = 0;
	}
	else
		applied_flags[6] = -1;
	return (applied_flags);
}

static void	get_bool_flags(const char *s, int *applied_flags, int pos[2])
{
	char	*flags;

	flags = ft_strdup("-+ #0");
	while (pos[0] < 5)
	{
		if (flags[pos[0]] == s[pos[1]])
		{
			applied_flags[pos[0]] = 1;
			pos[1]++;
		}
		else
			applied_flags[pos[0]] = -1;
		pos[0]++;
	}
	free(flags);
}

static int	get_int_flag(const char *s)
{
	int		pos;
	int		result;
	char	*flag;

	pos = 0;
	while (s[pos] >= '0' && s[pos] <= '9')
		pos++;
	if (pos == 0)
		return (-1);
	flag = malloc(pos + 1);
	pos = 0;
	while (s[pos] >= '0' && s[pos] <= '9')
	{
		flag[pos] = s[pos];
		pos++;
	}
	flag[pos] = 0;
	result = atoi(flag);
	free(flag);
	return (result);
}
