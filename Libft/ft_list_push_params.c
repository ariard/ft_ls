/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 15:32:59 by ariard            #+#    #+#             */
/*   Updated: 2016/12/01 15:55:53 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_dlist	*ft_list_push_params(int argc, char **argv)
{
	t_dlist		**begin_list;

	begin_list = NULL;
	while (argc--)
	{
		ft_list_push_front(begin_list, argv);
		argv++;
	}
	return (*begin_list);
}
