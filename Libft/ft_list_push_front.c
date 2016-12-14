/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 01:45:52 by ariard            #+#    #+#             */
/*   Updated: 2016/12/01 15:52:42 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_list_push_front(t_dlist **begin_list, void *data)
{
	t_dlist	*node;

	node = ft_create_elem(data);
	if (node != 0)
	{
		node->next = *begin_list;
		*begin_list = node;
		node->previous = NULL;
	}
}
