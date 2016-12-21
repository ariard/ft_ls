/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 18:27:21 by ariard            #+#    #+#             */
/*   Updated: 2016/12/21 20:40:46 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_error				*ft_set_error(char *name, char *message)
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

int					ft_check_dir(char *argv, t_dlist **list_error, 
		t_option *option)
{
	DIR				*ds;
	char			*s;

	ds = opendir(argv);
	if (ds == NULL)
	{
		s = strerror(errno);
		if (ft_strcmp(s, "Not a directory") == 0 && !option->R)
			return (0);
		ft_list_push_back_special(list_error,
				ft_set_error(argv, s), &ft_create_error);
		return (1);
	}
	else
		closedir(ds);
	return (0);
}

void				ft_print_error(t_dlist **list_error) 
{
	t_dlist			*tmp;
	t_error			*error;

	if (*list_error)
		ft_insert_sort_3(list_error, &ft_stralphcmp);
	tmp = *list_error;
	while (tmp)
	{
		error = tmp->data;
		printf("ls: %s: %s\n", error->name, error->message);
		tmp = tmp->next;
	}
	ft_list_clear(list_error);
}

void				ft_check_dir_2(t_info *info)
{
	DIR				*ds;
	char			*error;
	char			*buf;

	ds = opendir(info->path);
	if (ds == NULL)
	{
		buf = ft_strnew(128);
		error = strerror(errno);
		ft_strcpy(buf, "\n");
		ft_strcat(buf, info->path);
		ft_strcat(buf, ":\n");
		ft_strcat(buf, "ls: ");
		ft_strcat(buf, info->name);
		ft_strcat(buf, ": ");
		ft_strcat(buf, error);
		ft_strcat(buf, "\n");
		info->error = buf;
	}
}
