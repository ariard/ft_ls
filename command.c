/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 18:27:21 by ariard            #+#    #+#             */
/*   Updated: 2016/12/13 19:14:01 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				ft_command(int argc, char **argv, t_option *option)
{
	DIR				*ds;
	struct dirent	*lu;
	char			*path;
	char			*path2;
	t_stack			**head;
//	t_stack			*tmp;

	(void)option;
	head = ft_memalloc(sizeof(t_stack));
	if (argc == 1 || option->R)
		ft_stack_push(head, ".");
	while (*argv)  
		ft_stack_push(head, *argv++);
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
