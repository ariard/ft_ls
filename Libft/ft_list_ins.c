/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_ins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 17:50:04 by ariard            #+#    #+#             */
/*   Updated: 2016/12/14 23:48:47 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		ft_list_ins(t_dlist **begin_list, t_dlist *node1, t_dlist *node2)
{
	if (!node2 || !node1)
		return ;
	else
	{
		if (!node1->previous)
			*begin_list = node2;
		else
			(node1->previous)->next = node2;
		node2->next = node1;
		node2->previous = node1->previous;
		node1->previous = node2;
	}
}
