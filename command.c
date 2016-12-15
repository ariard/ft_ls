/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 18:27:21 by ariard            #+#    #+#             */
/*   Updated: 2016/12/16 00:18:06 by ariard           ###   ########.fr       */
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
	one_error->sort = one_error->name;
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

	if (*list_error)
		ft_insert_sort(list_error, &ft_stralphcmp);
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
	t_stack			**head;
	t_dlist			**list_error;
	t_dlist			**list_arg;
	t_dlist			*tmp;

	head = ft_memalloc(sizeof(t_stack));
	list_error = ft_memalloc(sizeof(t_list));
	list_arg = ft_memalloc(sizeof(t_list));
	if (argc == 1 || !*argv)
		ft_stack_push(head, ".");
	while (*argv)
	{
		if (!ft_check_dir(*argv, list_error))
			ft_list_push_back(list_arg, *argv);
		argv++;
	}
	ft_print_error(list_error);
	if (*list_arg)
		ft_insert_sort_arg(list_arg, &ft_stralphcmp);
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
