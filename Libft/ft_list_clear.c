/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 15:43:15 by ariard            #+#    #+#             */
/*   Updated: 2016/12/13 23:38:22 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_list_clear(t_dlist **begin_list)
{
	t_dlist	*tmp;
	t_dlist *tmp2;

	tmp = *begin_list;
	while (tmp)
	{
		tmp2 = tmp->next;
		free(tmp);
		tmp = NULL;
		tmp = tmp2;
	}
}
