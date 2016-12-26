/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 18:27:21 by ariard            #+#    #+#             */
/*   Updated: 2016/12/26 18:01:42 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void				ft_sort_arg(t_dlist **list_arg)
{
	ft_insert_sort_3(list_arg, &ft_stralphcmp);
	ft_insert_sort_2(list_arg);
}

static void				ft_read_all(t_dlist **list_files, t_dlist **list_arg,
		t_option *option, t_stack **head)
{
	t_dlist			*tmp;
	t_info			*info;
	int				alone;

	alone = 0;
	if (*list_files)
	{
		ft_print_dir(option, list_files);
		if (*list_arg)
			ft_putchar(10);
	}
	tmp = *list_arg;
	if (tmp)
		if (tmp->next)
			alone++;
	if (tmp)
		while (tmp->next)
			tmp = tmp->next;
	while (tmp)
	{
		info = tmp->data;
		ft_check_dir_2(info, alone);
		ft_stack_push(head, info);
		tmp = tmp->previous;
	}
}

static void				ft_read_argv(char **argv, t_option *option,
		t_stack **head)
{
	t_dlist			**list_error;
	t_dlist			**list_arg;
	t_dlist			**list_files;
	int				nb;

	list_error = ft_memalloc(sizeof(t_list));
	list_arg = ft_memalloc(sizeof(t_list));
	list_files = ft_memalloc(sizeof(t_list));
	nb = 0;
	while (*argv)
	{
		if (ft_strcmp(option->exe, *argv))
			if (!ft_check_dir(*argv, list_error, option, list_files))
				ft_list_push_back_special(list_arg,
					ft_get_info(*argv, option), &ft_create_info2);
		argv++;
		nb++;
	}
	option->nb = nb;
	if (*list_error)
		ft_print_error(list_error);
	if (*list_arg)
		ft_sort_arg(list_arg);
	ft_read_all(list_files, list_arg, option, head);
}

void					ft_command(int argc, char **argv, t_option *option)
{
	t_stack			**head;

	head = ft_memalloc(sizeof(t_stack));
	option->file = 0;
	if (argc == 1 || !*argv)
		ft_list_push_back_special(head, ft_get_info(".", option),
				&ft_create_info);
	if (*argv)
		ft_read_argv(argv, option, head);
	if (option->d)
		ft_scroll_dir_d(option, head);
	else if (option->a)
		ft_scroll_dir_a(option, head);
	else
		ft_scroll_dir(option, head);
}
