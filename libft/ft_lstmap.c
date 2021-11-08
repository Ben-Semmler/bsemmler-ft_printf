/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 19:00:06 by bsemmler          #+#    #+#             */
/*   Updated: 2021/09/28 15:31:42 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*pos;
	t_list	*tempelement;
	void	*what;

	what = NULL;
	(*del)(what);
	pos = lst;
	newlst = NULL;
	tempelement = NULL;
	while (pos != NULL)
	{
		if (tempelement == NULL)
		{
			tempelement = ft_lstnew((f)(pos->content));
			newlst = tempelement;
		}
		else
		{
			tempelement->next = ft_lstnew((f)(pos->content));
			tempelement = tempelement->next;
		}
		pos = pos->next;
	}
	return (newlst);
}
