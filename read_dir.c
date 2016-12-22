/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 19:13:31 by ariard            #+#    #+#             */
/*   Updated: 2016/12/22 02:14:54 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_ls.h"

void				ft_print_path(char *s)
{
	char		buf[1028];

	ft_bzero(buf, 1028);
	ft_strncat(buf, s, (ft_strlen(s) - 1));
	ft_strcat(buf, ":\n");
	write(1, &buf, ft_strlen(buf));
}

void				ft_sort(t_option *option, t_dlist **list_files)
{
	if (*list_files && (option->sort || option->S || option->t))
	{
		ft_insert_sort(list_files, &ft_stralphcmp);
		ft_insert_sort_2(list_files);
	}
	if (option->r)
		if (*list_files)
			ft_list_reverse(list_files);
}

void				ft_push_dir(t_option *option, t_stack **head, 
		t_dlist **list_files)
{	
	t_dlist			*tmp;
	t_info			*info;

	if (*list_files)
		ft_print_dir(option, list_files);
	tmp = *list_files;
	while (tmp)
	{
		info = tmp->data;
		if (info->perm[0] == 'd' && option->R) 
		{	
			ft_check_dir_2(info);
			ft_stack_push(head, info);
		}
		tmp = tmp->next;
	}
}

void				ft_read_dir(t_option *option, t_stack **head, DIR *ds,
		char *path)
{
	char			*path2;
	struct dirent	*lu;
	t_dlist			**list_files;
	static int		i;

	if (!i)
		i = 0;
	list_files = ft_memalloc(sizeof(t_list));
	if (i != 0 || option->nb > 1)
		ft_print_path(path);
	i++;
	while ((lu = readdir(ds)))
	{
		if (lu->d_name[0] != '.')
		{	
			path2 = ft_strjoin(path, lu->d_name);
			ft_list_push_back_special(list_files, 
				ft_get_info(path2, option), &ft_create_info);
		}
	}
	if (*list_files && !option->f)
		ft_insert_sort(list_files, &ft_stralphcmp);
	if (option->sort || option->S || option->r || option->t)
		ft_sort(option, list_files);
	ft_push_dir(option, head, list_files);
}

void				ft_scroll_dir(t_option *option, t_stack **head)
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
			ft_read_dir(option, head, ds, path);
			closedir(ds);
		}
		else if (ds == NULL && info->error)
		{
			ft_putchar(*info->error++);
			ft_putchar(*info->error++);
			while (*(info->error - 1) != '\n')
				ft_putchar(*info->error++);
			ft_putstr_fd(info->error, 0);
		}
		if (*head)
			ft_putchar(10);
		ft_strdel(&path);
	}
}
