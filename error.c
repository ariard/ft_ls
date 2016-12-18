/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 18:27:21 by ariard            #+#    #+#             */
/*   Updated: 2016/12/18 15:18:28 by ariard           ###   ########.fr       */
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
	one_error->sort = ft_strlen(one_error->name);
	return (one_error);
}

int					ft_check_dir(char *argv, t_dlist **list_error, t_option *option)
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
		ft_insert_sort_2(list_error);
	tmp = *list_error;
	while (tmp)
	{
		error = tmp->data;
		printf("ls: %s: %s\n", error->name, error->message);
		tmp = tmp->next;
	}
	ft_list_clear(list_error);
}

void			ft_print_one_error(t_dlist **list_error)
{
	t_error		*error;

	if (*list_error)
	{
		error = (*list_error)->data;
		printf("ls: %s: %s\n", error->name, error->message);
		free(*list_error);
		*list_error = NULL;
	}
}