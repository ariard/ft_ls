/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dir_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 15:47:50 by ariard            #+#    #+#             */
/*   Updated: 2016/12/18 17:11:40 by ariard           ###   ########.fr       */
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

void				ft_sort_a(t_option *option, t_dlist **list_files)
{	
	if (*list_files && (option->sort || option->S))
		ft_insert_sort_2(list_files);
	if (option->r || option->S)
		if (*list_files)
			ft_list_reverse(list_files);
}

void				ft_push_dir_a(t_option *option, t_stack **head, 
		t_dlist **list_files)
{	
	t_dlist			*tmp;
	t_dlist			**list_error;	
	t_info			*info;

	list_error = ft_memalloc(sizeof(t_error));
	tmp = *list_files;
	ft_print_dir(option, list_files);
	while (tmp)
	{
		info = tmp->data;
		if ((info->name[0] != '.' || info->name[1] != '.') &&
			(info->name[0] != '.' || info->name[1] != 0))
			if (info->perm[0] == 'd' && option->R) 
			{	
				if (ft_check_dir(info->path, list_error, option))
				{
					printf("\n");
					ft_print_one_error(list_error);
				}
				else
					ft_stack_push(head, info);
				}
		tmp = tmp->next;
	}
}

void				ft_read_dir_a(t_option *option, t_stack **head, DIR *ds,
		char *path)
{
	char			*path2;
	struct dirent	*lu;
	t_dlist			**list_files;

	list_files = ft_memalloc(sizeof(t_list));
	printf("\n%s:\n", path);
	while ((lu = readdir(ds)))
	{
		path2 = ft_strjoin(path, lu->d_name);
		ft_list_push_back_special(list_files, 
			ft_get_info(path2, option), &ft_create_info);
	}
	if (*list_files)
		ft_insert_sort(list_files, &ft_stralphcmp);
	if (option->sort || option->S || option->r)
		ft_sort_a(option, list_files);
	ft_push_dir_a(option, head, list_files);
}

void				ft_scroll_dir_a(t_option *option, t_stack **head)
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
			ft_read_dir_a(option, head, ds, path);
			closedir(ds);
		}
		ft_strdel(&path);
	}
}
