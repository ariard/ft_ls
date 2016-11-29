/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 01:42:02 by ariard            #+#    #+#             */
/*   Updated: 2016/11/28 13:38:20 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_list_push_back(t_dlist **begin_list, void *data)
{
	t_dlist	*node;
	t_dlist	*tmp;
	t_dlist	*tmp2;

	node = ft_create_elem(data);
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
