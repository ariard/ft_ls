/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 01:56:59 by ariard            #+#    #+#             */
/*   Updated: 2016/11/29 13:47:45 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_list_size(t_dlist **begin_list)
{
	t_dlist		*tmp;
	int			count;

	tmp = *begin_list;
	count = 0;
	while (tmp != 0)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}
