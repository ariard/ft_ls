/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 16:04:40 by ariard            #+#    #+#             */
/*   Updated: 2016/12/16 21:48:37 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_sort_ascii(t_dlist **begin_list)
{
	t_dlist	*tmp;
	t_dlist	*first;
	t_dlist	*second;

	tmp = *begin_list;
	while (tmp->next)
	{
		first = tmp;
		second = tmp->next;
		while (*(first->name) || *(second->name))
		{
			if (*(first->name) < *(second->name) && first->key == second->key)
			{
				ft_list_swap(begin_list, first, second);
				tmp = *begin_list;
				break;
			}




			}

			{
				tmp = tmp->next;
				break;
			}
			if (*(first->name) == *(second->name))
			{
				(first->name)++;
				(second->name)++;
			}
		}
		tmp = tmp->next;
	}
}

void		ft_insert_sort_2(t_dlist **begin_list)
{
	t_dlist		*tmp;
	t_dlist		*tmp2;
	t_dlist		*to_sort;

	tmp = *begin_list;
	while (tmp->next)
	{
		if (tmp->key > (tmp->next)->key)
		{
			to_sort = ft_list_rem(begin_list, tmp->next);
			tmp2 = *begin_list;
			while (tmp2)
			{	
				if (tmp2->key > to_sort->key)
				{
					ft_list_ins(begin_list, tmp2, to_sort);
					break;
				}
				tmp2 = tmp2->next;	
			}	
		}
		else
			tmp = tmp->next;
	}
}
