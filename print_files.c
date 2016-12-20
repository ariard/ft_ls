/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 23:27:06 by ariard            #+#    #+#             */
/*   Updated: 2016/12/20 01:32:37 by ariard           ###   ########.fr       */
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

static void 		ft_print_comma(t_dlist **list_files)
{
	t_dlist 	*tmp;
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

static void			ft_print_normal(t_dlist **list_files, t_option *option, 
		int column)
{
	t_dlist			*tmp;
	t_info			*info;
	int				nb;
	int				col;
	int				lines;
	int				max;
	int				size;
	int				less;
	char			buf[624];
	char			c;

	(void)option;
	max = ft_get_max(list_files) + 1;
	nb = column/max;
	tmp = *list_files;
	size = ft_list_size(list_files);
	lines = size/nb;
	less = ft_get_less(nb, lines, size) + 1;
	while (tmp)
	{
		col = nb;
		while (col-- && tmp)
		{
			if (col == 0 && (lines - less) <= 0)
			{
				c = 10;
				write(1, &c, 1);
			}
			else
			{
				ft_bzero(buf, 614);
				info = tmp->data;
				ft_strcpy(buf, info->name);
				ft_space(buf, max, info->name);
				if (col == 0 || !(tmp->next))
					ft_strcat(buf, "\n");
				write(1, &buf, ft_strlen(buf));
				tmp = tmp->next;	
			}	
		}
		lines--;
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
	else
		ft_print_normal(list_files, option, column);
}
