/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxi_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 15:49:10 by ariard            #+#    #+#             */
/*   Updated: 2016/12/22 21:33:52 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dlist				*ft_create_error(void *data)
{
	t_dlist			*node;
	t_error			*error;

	node = ft_memalloc(sizeof(t_dlist));
	if (node)
	{
		node->data = data;
		node->next = NULL;
		node->previous = NULL;
		if (data)
		{
			error = data;
			node->name = error->name;
		}
	}
	return (node);
}

t_dlist				*ft_create_info(void *data)
{
	t_dlist		*node;
	t_info		*info;

	node = ft_memalloc(sizeof(t_dlist));
	if (node)
	{
		node->data = data;
		node->next = NULL;
		node->previous = NULL;
		if (data)
		{
			info = data;
			node->key = info->sort;
			node->name = info->name;
		}
	}
	return (node);
}
