/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 13:39:24 by bsemmler          #+#    #+#             */
/*   Updated: 2021/09/15 13:39:34 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int value)
{
	if (value >= 0 && value <= 127)
		return (1);
	return (0);
}
