/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 23:27:06 by ariard            #+#    #+#             */
/*   Updated: 2016/12/20 20:03:52 by ariard           ###   ########.fr       */
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

static void			ft_print_lines(t_dlist **list_files, int column)
{
	t_dlist			*tmp;
	t_info			*info;
	int				block;
	int				max;
	int				nb;
	char			buf[624];

	tmp = *list_files;
	if ((max = ft_get_max(list_files) + 1) == 1)
		return ;
	block = ft_get_block(list_files, column, max);
	while (tmp && block)
	{
		nb = block;
		while (nb-- && tmp)
		{
			ft_bzero(buf, 614);
			info = tmp->data;
			ft_strcpy(buf, info->name);
			ft_space(buf, max, info->name);
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
	t_info			*info;
	int				block;
	int				lines;
	int				cp;
	int				max;
	int				nb;
	int				size;
	char			buf[624];

	tmp = *list_files;
	if ((max = ft_get_max(list_files) + 1) == 1)
		return ;
	lines = ft_get_lines(list_files, column, max);
	block = ft_get_block(list_files, column, max);
	size = ft_list_size(list_files);
	cp = lines;
	while (tmp && block && lines)
	{
		nb = block;
		while (nb-- && tmp)
		{
			ft_bzero(buf, 614);
			if (size == block * cp)
				info = ft_get_special(tmp, nb, block, size);
			else
				info = ft_get_next(tmp, nb, block, size);
			if (info)
			{
				ft_strcpy(buf, info->name);
				ft_space(buf, max, info->name);
				if (nb == 0 || !(tmp->next))
					ft_strcat(buf, "\n");
				write(1, &buf, ft_strlen(buf));
			}
			else if (size != 1)
			{
				nb = 0;
				ft_putchar(10);
			}
		}
		lines--;
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
