/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create-elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 01:25:53 by ariard            #+#    #+#             */
/*   Updated: 2016/11/29 13:45:31 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_dlist		*ft_create_elem(void *data)
{
	t_dlist	*node;

	node = 0;
	node = (t_dlist *)malloc(sizeof(t_dlist));
	if (node != 0)
	{
		node->data = data;
		node->next = NULL;
		node->previous = NULL;
	}
	return (node);
}
