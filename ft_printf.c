/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 16:09:41 by bsemmler          #+#    #+#             */
/*   Updated: 2021/10/19 17:25:18 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "functions/ft_printf_functs.h"

static char	*specifiers(const char *s, int pos, va_list args);
static int	count_flags(const char *s);

int	ft_printf(const char *s, ...)
{
	va_list	args;
	size_t	total;
	int		pos;
	int		n_p;

	va_start(args, s);
	pos = 0;
	total = 0;
	while (s[pos])
	{
		if (s[pos] == '%')
		{
			n_p = pos + 1 + count_flags(&s[pos + 1]);
			total += apply_flags(&s[pos + 1], specifiers(s, n_p, args), s[n_p]);
			pos = n_p;
		}
		else
		{
			ft_putchar_fd(s[pos], 1);
			total++;
		}
		pos++;
	}
	va_end(args);
	return (total);
}

static char	*specifiers(const char *s, int pos, va_list args)
{
	char	*str;

	str = NULL;
	if (s[pos] == 'c' || s[pos] == '%')
	{
		str = malloc(2);
		if (s[pos] == 'c')
			str[0] = va_arg(args, int);
		else
			str[0] = '%';
		str[1] = 0;
	}
	else if (s[pos] == 's')
		str = ft_strdup(va_arg(args, char *));
	else if (s[pos] == 'p')
		str = write_base(va_arg(args, uintptr_t), "0123456789abcdef");
	else if (s[pos] == 'd' || s[pos] == 'i')
		str = ft_itoa(va_arg(args, int));
	else if (s[pos] == 'u')
		str = write_base(va_arg(args, unsigned int), "0123456789");
	else if (s[pos] == 'x')
		str = write_base(va_arg(args, unsigned int), "0123456789abcdef");
	else if (s[pos] == 'X')
		str = write_base(va_arg(args, unsigned int), "0123456789ABCDEF");
	return (str);
}	

static int	count_flags(const char *s)
{
	int	pos;

	pos = 0;
	if (s[pos] == '-')
		pos++;
	if (s[pos] == '+')
		pos++;
	if (s[pos] == ' ')
		pos++;
	if (s[pos] == '#')
		pos++;
	if (s[pos] == '0')
		pos++;
	while (s[pos] >= '0' && s[pos] <= '9')
		pos++;
	if (s[pos] == '.')
	{
		pos++;
		while (s[pos] >= '0' && s[pos] <= '9')
			pos++;
	}
	return (pos);
}
