/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   column.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 00:18:44 by ariard            #+#    #+#             */
/*   Updated: 2016/12/20 01:21:35 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				ft_get_column(void)
{
	struct winsize w;

	ioctl(0, TIOCGWINSZ, &w);
	return (w.ws_col);
}

int				ft_get_lines(void)
{
	struct winsize w;

	ioctl(0, TIOCGWINSZ, &w);
	return (w.ws_row);
}

int				ft_get_less(int col, int lines, int size)
{
	return (size - (col*lines));
}

int				ft_get_max(t_dlist **list_files)
{
	t_dlist		*tmp;
	t_info		*info;
	int			max;

	tmp = *list_files;
	max = 0;
	while (tmp)
	{
		info = tmp->data;
		if ((int)ft_strlen(info->name) > max)
			max = ft_strlen(info->name);
		tmp = tmp->next;
	}
	return (max);
}
