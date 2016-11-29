/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 12:55:27 by ariard            #+#    #+#             */
/*   Updated: 2016/11/23 16:33:39 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list	*new_elem;
	t_list	*prev_elem;
	t_list	*new_list;

	if (!lst || !f)
		return (NULL);
	new_list = (*f)(lst);
	prev_elem = new_list;
	lst = lst->next;
	while (lst)
	{
		new_elem = (*f)(lst);
		prev_elem->next = new_elem;
		prev_elem = new_elem;
		lst = lst->next;
	}
	prev_elem->next = NULL;
	return (new_list);
}
