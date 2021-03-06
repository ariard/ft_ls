/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_rem_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 20:27:09 by ariard            #+#    #+#             */
/*   Updated: 2016/12/15 17:02:28 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		ft_list_rem_front(t_dlist **begin_list)
{
	t_dlist		*tmp;

	if (*begin_list)
	{
		tmp = (*begin_list)->next;
		free(*begin_list);
		*begin_list = NULL;
		*begin_list = tmp;
	}
}
