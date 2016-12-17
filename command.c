/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 18:27:21 by ariard            #+#    #+#             */
/*   Updated: 2016/12/17 17:48:16 by ariard           ###   ########.fr       */
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

void				ft_command(int argc, char **argv, t_option *option)
{
	t_stack			**head;
	t_dlist			**list_error;
	t_dlist			**list_arg;
	t_dlist			*tmp;
	char			**tmp2;

	head = ft_memalloc(sizeof(t_stack));
	list_error = ft_memalloc(sizeof(t_list));
	list_arg = ft_memalloc(sizeof(t_list));
	if (argc == 1 || !*argv)
		ft_list_push_back_special(head, ft_get_info(".", option), &ft_create_info);
	while (*argv)
	{
		if (!ft_check_dir(*argv, list_error, option))
			ft_list_push_back_special(list_arg, 
				ft_get_info(*argv, option), &ft_create_info);
		argv++;
	}
	if (*list_error)
		ft_print_error(list_error);
	if (*list_arg)
		ft_insert_sort_2(list_arg);
	tmp = *list_arg;
	if (tmp)
		while (tmp->next)
			tmp = tmp->next;
	while (tmp)
	{
		ft_stack_push(head, tmp->data);
		tmp = tmp->previous;
	}
	ft_read_dir(option, head);
}
