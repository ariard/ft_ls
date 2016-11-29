/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 16:27:08 by ariard            #+#    #+#             */
/*   Updated: 2016/11/28 14:21:33 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_list_foreach(t_dlist **begin_list, void (*f)(void *))
{
	while (*begin_list)
	{
		f((*begin_list)->data);
		*begin_list = (*begin_list)->next;
	}
}
