/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 15:43:15 by ariard            #+#    #+#             */
/*   Updated: 2016/11/29 13:50:16 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_list_clear(t_dlist **begin_list)
{
	t_dlist	*tmp;

	while (*begin_list)
	{
		tmp = (*begin_list)->next;
		free(*begin_list);
		*begin_list = NULL;
		*begin_list = tmp;
	}
	begin_list = NULL;
}
