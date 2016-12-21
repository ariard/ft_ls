/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   column.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 00:18:44 by ariard            #+#    #+#             */
/*   Updated: 2016/12/21 00:30:37 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				ft_get_column(void)
{
	struct winsize w;

	ioctl(0, TIOCGWINSZ, &w);
	return (w.ws_col);
}

int				ft_get_block(t_dlist **list_files, int col, int max)
{
	int			lines;
	int			size;
	int			block;

	size = ft_list_size(list_files);
	if (size == 0)
		return (0);
	block = col/max;
	if (block == 0)
		return (0);
	lines = 0;
	while (block * lines < size)
		lines++;
	if ((lines - ((block * lines) - size)) == 0)
		block--;
	return (block);
}

int				ft_get_lines(t_dlist **list_files, int col, int max)
{
	int			lines;
	int			size;
	int			block;

	size = ft_list_size(list_files);
	if (size == 0)
		return (0);
	block = col / max;
	if (block == 0)
		return (0);
	lines = 0;
	while (block * lines < size)
		lines++;
	return (lines);
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

void			*ft_get_next(t_dlist *node, int nb, int block, int size)
{
	int			jump;
	int			nb2;
	int			lencol;
	
	lencol = size/block;
	nb2 = block - (nb + 1);
	jump = nb2 * (lencol + 1);
	while (node->next && jump)
	{
		node = node->next;
		jump--;
	}
	if (jump == 0)
		return (node->data);
	return (NULL);
}

void			*ft_get_special(t_dlist *node, int nb, int block, int size)
{
	int			jump;
	int			nb2;
	int			lencol;
	
	lencol = size/block;
	nb2 = block - (nb + 1);
	jump = nb2 * (lencol);
	while (node->next && jump)
	{
		node = node->next;
		jump--;
	}
	if (jump == 0)
		return (node->data);
	return (NULL);
}
