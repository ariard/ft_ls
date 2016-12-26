/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 18:27:21 by ariard            #+#    #+#             */
/*   Updated: 2016/12/26 17:40:59 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_error						*ft_set_error(char *name, char *message)
{
	t_error			*one_error;

	one_error = ft_memalloc(sizeof(t_error));
	if (name)
		one_error->name = name;
	else
		one_error->name = 0;
	if (message)
		one_error->message = message;
	else
		one_error->message = 0;
	return (one_error);
}

int							ft_check_dir(char *argv, t_dlist **list_error,
		t_option *option, t_dlist **list_files)
{
	DIR				*ds;
	char			*s;

	ds = opendir(argv);
	s = strerror(errno);
	if (ds == NULL && ft_strcmp(s, "Permission denied") != 0)
	{
		if (ft_strcmp(s, "Not a directory") == 0)
		{
			option->file = 1;
			ft_list_push_back_special(list_files,
					ft_get_info(argv, option), &ft_create_info);
			return (1);
		}
		ft_list_push_back_special(list_error,
				ft_set_error(ft_strrchr(argv, '/'), s), &ft_create_error);
		return (1);
	}
	else if (ds)
		closedir(ds);
	return (0);
}

void						ft_print_error(t_dlist **list_error)
{
	t_dlist			*tmp;
	t_error			*error;
	char			*buf;

	if (*list_error)
		ft_insert_sort_3(list_error, &ft_stralphcmp);
	tmp = *list_error;
	while (tmp)
	{
		error = tmp->data;
		buf = ft_strnew(614);
		ft_strcpy(buf, "ls: ");
		ft_strcat(buf, error->name);
		ft_strcat(buf, ": ");
		ft_strcat(buf, error->message);
		ft_strcat(buf, "\n");
		ft_putstr_fd(buf, 0);
		tmp = tmp->next;
	}
	ft_list_clear(list_error);
}

void						ft_check_dir_2(t_info *info, int alone)
{
	DIR				*ds;
	char			*error;
	char			*buf;

	ds = opendir(info->path);
	if (ds == NULL)
	{
		buf = ft_strnew(614);
		error = strerror(errno);
		if (alone != 0)
		{
			ft_strcat(buf, info->path);
			ft_strcat(buf, ":\n");
		}
		ft_strcat(buf, "ls: ");
		ft_strcat(buf, info->name);
		ft_strcat(buf, ": ");
		ft_strcat(buf, error);
		ft_strcat(buf, "\n");
		info->error = buf;
	}
}
