/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 16:13:50 by ariard            #+#    #+#             */
/*   Updated: 2016/12/17 18:22:02 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_list_reverse(t_dlist **begin_list)
{
	t_dlist		*tmp1;
	t_dlist		*tmp2;

	tmp1 = *begin_list;
	while (tmp1->next)
		tmp1 = tmp1->next;
	*begin_list = tmp1;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		tmp1->next = tmp1->previous;
		tmp1->previous = tmp2;
		tmp1 = tmp1->next;
	}
}
