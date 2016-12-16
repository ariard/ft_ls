/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 19:13:31 by ariard            #+#    #+#             */
/*   Updated: 2016/12/16 15:30:55 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_ls.h"
#include	<stdio.h>
	
int					ft_no_parent(char *s)
{
	int				i;

	i = 0;
	while (*s)
	{
		if (*s != '/' && *s != '.')
			i++;
		s++;
	}
	return (i);
}

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
	{
		if (lu->d_name[0] != '.')
		{
			printf("%s\n", lu->d_name);
			path2 = ft_strjoin(path, lu->d_name);
			ft_list_push_back_special(list_files, 
				ft_get_info(path2), &ft_create_info);
		}
	}
	if (*list_files)
		ft_insert_sort_2(list_files);
	tmp = *list_files;
	while (tmp)
	{
		info = tmp->data;
		if (info->type == 'd' && option->R) 
			ft_stack_push(head, info);
		tmp = tmp->next;
	}
}

void				ft_read_dir(t_option *option, t_stack **head)
{
	DIR				*ds;
	char			*path;
	t_info			*info;

	while (*head)
	{
		info = (*head)->data;
		ds = opendir(info->name);
		path = ft_strjoin(info->name, "/");
		ft_stack_pop(head);
		if (ds) 
		{
			ft_read_files(option, head, ds, path);
			closedir(ds);
		}
		ft_strdel(&path);
	}
}
