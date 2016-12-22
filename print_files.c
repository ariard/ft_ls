/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 23:27:06 by ariard            #+#    #+#             */
/*   Updated: 2016/12/22 17:49:34 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			ft_print_uno(t_dlist **list_files)
{
	t_dlist		*tmp;
	t_info		*info;
	char		buf[1028];

	tmp = *list_files;
	while (tmp)
	{
		ft_bzero(buf, 1028);
		info = tmp->data;
		ft_strcpy(buf, info->name);
		ft_strcat(buf, "\n");
		write(1, &buf, ft_strlen(buf));
		tmp = tmp->next;
	}
}

static void			ft_print_comma(t_dlist **list_files)
{
	t_dlist		*tmp;
	t_info		*info;
	char		buf[1028];

	tmp = *list_files;
	while (tmp)
	{
		ft_bzero(buf, 1028);
		info = tmp->data;
		ft_strcpy(buf, info->name);
		if (tmp->next)
			ft_strcat(buf, ", ");
		else
			ft_strcat(buf, "\n");
		write(1, &buf, ft_strlen(buf));
		tmp = tmp->next;
	}
}

static void			ft_print_lines(t_dlist **list_files, int column)
{
	t_dlist			*tmp;
	t_info			*info;
	int				block;
	int				nb;
	char			buf[624];

	tmp = *list_files;
	if (ft_get_max(list_files) + 1 == 1)
		return ;
	block = ft_get_block(list_files, column, ft_get_max(list_files) + 1);
	while (tmp && block)
	{
		nb = block;
		while (nb-- && tmp)
		{
			ft_bzero(buf, 614);
			info = tmp->data;
			ft_strcpy(buf, info->name);
			ft_space(buf, ft_get_max(list_files) + 1, info->name);
			if (nb == 0 || !(tmp->next))
				ft_strcat(buf, "\n");
			write(1, &buf, ft_strlen(buf));
			tmp = tmp->next;
		}
	}
}

static void			ft_print_column(t_dlist **list_files, int column)
{
	t_dlist			*tmp;
	t_col			*col;

	tmp = *list_files;
	col = ft_memalloc(sizeof(t_col));
	if ((col->max = ft_get_max(list_files) + 1) == 1)
		return ;
	col->lines = ft_get_lines(list_files, column, col->max);
	col->block = ft_get_block(list_files, column, col->max);
	col->size = ft_list_size(list_files);
	col->cp = col->lines;
	while (tmp && col->block && col->lines)
	{
		col->nb = col->block;
		while (col->nb-- && tmp)
			ft_print_column2(col, tmp);
		col->lines--;
		tmp = tmp->next;
	}
}

void				ft_print_files(t_dlist **list_files, t_option *option)
{
	static	int		column;

	if (!column)
		column = ft_get_column();
	if (option->mode == '1')
		ft_print_uno(list_files);
	else if (option->mode == 'm')
		ft_print_comma(list_files);
	else if (option->x == 'x')
		ft_print_lines(list_files, column);
	else
		ft_print_column(list_files, column);
}
