/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 18:38:31 by bsemmler          #+#    #+#             */
/*   Updated: 2021/09/23 19:48:19 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*pos;

	pos = lst;
	if (pos == NULL)
		return (pos);
	while (pos->next != NULL)
	{
		pos = pos->next;
	}
	return (pos);
}
