/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_functs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:37:46 by bsemmler          #+#    #+#             */
/*   Updated: 2021/10/19 16:58:07 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_FUNCTS_H
# define FT_PRINTF_FUNCTS_H

unsigned long long	ft_pow(int base, int exp);
double				ft_abs(double n);

char				*write_base(unsigned long i, char *set);

int					write_arg(int arg_len, char *arg, int *flags, char spec);

int					apply_flags(const char *s, char *arg, char spec);
#endif
