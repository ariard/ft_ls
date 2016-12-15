/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 19:13:31 by ariard            #+#    #+#             */
/*   Updated: 2016/12/16 00:46:34 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_ls.h"
#include	<stdio.h>

void				ft_read_files(t_option *option, t_stack **head, DIR *ds,
		char *path)
{
	char			*path2;
	struct dirent	*lu;
	t_dlist			**list_files;
	t_dlist			*tmp;
	t_info			*info;

	list_files = ft_memalloc(sizeof(t_list));
	printf("\n%s:\n", path);
	while ((lu = readdir(ds)))
		ft_list_push_back_special(list_files, ft_get_info(lu->d_name), &ft_create_info);
	if (*list_files)
		ft_insert_sort_2(list_files);
	tmp = *list_files;
	while (tmp)
	{
		info = tmp->data;
		printf("%s\n", info->name);
		tmp = tmp->next;
		if (info->type == 'd' && info->name[0] != '.' && option->R)
		{
			path2 = ft_strjoin(path, info->name);
			ft_stack_push(head, path2);
		}
	}
}

void				ft_read_dir(t_option *option, t_stack **head)
{
	DIR				*ds;
	char			*path;

	while (*head)
	{
		ds = opendir((*head)->data);
		path = ft_strjoin((*head)->data, "/");
		ft_stack_pop(head);
		if (ds)
		{
			ft_read_files(option, head, ds, path);
			closedir(ds);
		}
		ft_strdel(&path);
	}
}
