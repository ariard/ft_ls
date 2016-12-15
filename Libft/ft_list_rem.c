/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_rem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 17:47:07 by ariard            #+#    #+#             */
/*   Updated: 2016/12/15 00:35:07 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_dlist			*ft_list_rem(t_dlist **begin_list, t_dlist *node)
{
	if (!node || !*begin_list)
		return (0);
	if (node->next)
		(node->next)->previous = node->previous;
	if (node->previous)
		(node->previous)->next = node->next;
	else if (node->next)
		*begin_list = node->next;
	else
		*begin_list = NULL;
	node->previous = NULL;
	node->next = NULL;
	return (node);
}
