/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 02:03:15 by ariard            #+#    #+#             */
/*   Updated: 2016/11/29 13:46:23 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_dlist	*ft_list_last(t_dlist **begin_list)
{
	if (*begin_list)
	{
		while ((*begin_list)->next)
			*begin_list = (*begin_list)->next;
	}
	return (*begin_list);
}
