/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dir_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 16:38:00 by ariard            #+#    #+#             */
/*   Updated: 2016/12/26 19:12:12 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void				ft_push_dir_d(t_option *option, t_dlist **list_files)
{
	t_dlist			*tmp;
	t_dlist			**list_error;

	list_error = ft_memalloc(sizeof(t_error));
	if (*list_files)
		ft_print_dir(option, list_files);
	tmp = *list_files;
}

static void				ft_read_dir_d(t_option *option, DIR *ds, char *path)
{
	char			*path2;
	struct dirent	*lu;
	t_dlist			**list_files;

	list_files = ft_memalloc(sizeof(t_list));
	while ((lu = readdir(ds)))
	{
		if (ft_strcmp(lu->d_name, ".") == 0)
		{
			path2 = ft_strjoin(path, lu->d_name);
			ft_list_push_back_special(list_files,
				ft_get_info(path2, option), &ft_create_info);
		}
	}
	ft_push_dir_d(option, list_files);
}

void					ft_scroll_dir_d(t_option *option, t_stack **head)
{
	DIR				*ds;
	char			*path;
	t_info			*info;

	while (*head)
	{
		info = (*head)->data;
		ds = opendir(info->path);
		path = ft_strjoin(info->path, "/");
		ft_stack_pop(head);
		if (ds)
		{
			ft_read_dir_d(option, ds, path);
			closedir(ds);
		}
		else if (ds == NULL && info->error)
			ft_print_dir_error(info, option);
		if (*head)
			ft_putchar(10);
		ft_strdel(&path);
	}
}
