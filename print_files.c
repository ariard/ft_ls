/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 23:27:06 by ariard            #+#    #+#             */
/*   Updated: 2016/12/19 23:46:43 by ariard           ###   ########.fr       */
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
		
void				ft_print_files(t_dlist **list_files, t_option *option)
{
	if (option->mode == '1')
		ft_print_uno(list_files);
	else if (option->mode == 'm')
		ft_print_comma(list_files);
}
