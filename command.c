/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 18:27:21 by ariard            #+#    #+#             */
/*   Updated: 2016/12/14 00:01:55 by ariard           ###   ########.fr       */
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

int					ft_check_dir(char *argv, t_dlist **list_error)
{
	DIR				*ds;
	char			*s;

	ds = opendir(argv);
	if (ds == NULL)
	{
		s = strerror(errno);
		if (ft_strcmp(s, "Not a directory") == 0)
			return (0);
		ft_list_push_back(list_error, ft_set_error(argv, s));
		return (1);
	}
	return (0);
}

void				ft_print_error(t_dlist **list_error)
{
	t_dlist			*tmp;
	t_error			*one_error;

	tmp = *list_error;
	while (tmp)
	{
		one_error = tmp->data;
		printf("ls: %s: %s\n", one_error->name, one_error->message);
		tmp = tmp->next;
	}
	ft_list_clear(list_error);
}

void				ft_command(int argc, char **argv, t_option *option)
{
	DIR				*ds;
	struct dirent	*lu;
	char			*path;
	char			*path2;
	t_stack			**head;
	t_dlist			**list_error;

	head = ft_memalloc(sizeof(t_stack));
	list_error = ft_memalloc(sizeof(t_list));
	if (argc == 1 || !*argv)
		ft_stack_push(head, ".");
	while (*argv)
	{
		if (!ft_check_dir(*argv, list_error))
			ft_stack_push(head, *argv);
		argv++;
	}
	ft_print_error(list_error);
	free(list_error);
	list_error = NULL;
	while (*head)
	{
		ds = opendir((*head)->data);
		path = ft_strnew(1024);
		path = ft_strjoin((*head)->data, "/");
		ft_stack_pop(head);
		if (ds)
		{
			while ((lu = readdir(ds)))
			{
				printf("%s\n", lu->d_name);
				if (lu->d_type == DT_DIR && lu->d_name[0] != '.' && option->R) 
				{
					path2 = ft_strnew(1024);
					path2 = ft_strjoin(path, lu->d_name);
					ft_stack_push(head, path2);
				}
			}
			closedir(ds);
		}
		ft_strdel(&path);
	}
/*	tmp = *head;
	while (tmp)
	{
		printf("%s\n", tmp->data);
		tmp = tmp->next;
	}*/
}
