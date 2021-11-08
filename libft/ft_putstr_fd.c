/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 14:57:44 by bsemmler          #+#    #+#             */
/*   Updated: 2021/09/15 15:00:30 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	int	pos;

	pos = 0;
	if (s == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return ;
	}
	while (s[pos])
	{
		write(fd, &s[pos], 1);
		pos++;
	}
}
