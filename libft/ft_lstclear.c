/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 18:46:08 by bsemmler          #+#    #+#             */
/*   Updated: 2021/09/23 18:54:10 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*pos;

	pos = lst[0];
	while (pos != NULL)
	{
		ft_lstdelone(pos, (*del));
		pos = pos->next;
	}
	lst[0] = NULL;
}
