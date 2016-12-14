/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 16:04:40 by ariard            #+#    #+#             */
/*   Updated: 2016/12/14 23:27:52 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_stralphcmp(const void *s1, const void *s2)
{
	const char	*str1;
	const char	*str2;

	str1 = s1;
	str2 = s2;
	while (*str1 || *str2)
	{
		if (*str1 > *str2)
			return (-1);
		if (*str1 < *str2)
			return (1);
		if (*str1 == *str2)
		{
			str1++;
			str2++;
		}
	}
	return (0);
}

void		ft_bubble_sort(t_dlist **begin_list, 
		int (*cmp)(const void *key1, const void *key2))
{
	t_dlist		*tmp;
	t_error		*one_error;
	t_error		*one_error2;

	tmp = *begin_list;
	while (tmp->next)
	{
		one_error = tmp->data;
		one_error2 = (tmp->next)->data;
		if ((cmp)(one_error->sort, one_error2->sort) < 0)
		{
			ft_list_swap(begin_list, tmp, tmp->next);
			tmp = *begin_list;
		}
		else
			tmp = tmp->next;
	}
}

void		ft_insert_sort(t_dlist **begin_list, 
		int (*cmp)(const void *key1, const void *key2))
{
	t_dlist		*tmp;
	t_dlist		*tmp2;
	t_dlist		*to_sort;
	t_error		*one_error;
	t_error		*one_error2;

	tmp = *begin_list;
	while (tmp->next)
	{
		one_error = tmp->data;
		one_error2 = (tmp->next)->data;
		if ((cmp)(one_error->sort, one_error2->sort) < 0)
		{
			to_sort = ft_list_rem(begin_list, tmp->next);
			tmp2 = *begin_list;
			while (tmp2)
			{
				one_error = tmp2->data;
				if ((cmp)(one_error->sort, one_error2->sort) < 0)
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
