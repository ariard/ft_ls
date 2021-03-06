/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 01:42:02 by ariard            #+#    #+#             */
/*   Updated: 2016/12/22 20:06:20 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_list_push_back_special(t_dlist **begin_list, void *data,
		t_dlist *(*create)(void *))
{
	t_dlist	*node;
	t_dlist	*tmp;
	t_dlist	*tmp2;

	node = (create)(data);
	if (node)
	{
		if (*begin_list)
		{
			tmp = *begin_list;
			while (tmp->next)
				tmp = tmp->next;
			tmp2 = tmp;
			tmp->next = node;
			node->previous = tmp2;
		}
		else
			*begin_list = node;
	}
}
