/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_new_recur.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 18:19:07 by ariard            #+#    #+#             */
/*   Updated: 2016/12/13 19:16:26 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include "Libft/includes/libft.h"

int				ft_parsing_dir(char *s)
{
	DIR					*ds;
	struct dirent		*lu;
	char				*path;
	char				*path2;
	t_stack				**front_stack;

	front_stack = ft_memalloc(sizeof(t_stack));
	ft_stack_push(front_stack, s);
	while (*front_stack)
	{
		ds = opendir((*front_stack)->data);
		path = ft_strnew(1024);
		path = ft_strjoin((*front_stack)->data, "/");
		ft_stack_pop(front_stack);
		if (ds)
		{
			while ((lu = readdir(ds)))
			{
				printf("%s\n", lu->d_name);
				if (lu->d_type == DT_DIR && lu->d_name[0] != '.')
				{
					path2 = ft_strnew(1024);
					path2 = ft_strjoin(path, lu->d_name);			
					ft_stack_push(front_stack, path2);
				}
			}
			closedir(ds);
		}
	}
	return (0);
}

int		main(void)
{
	ft_parsing_dir(".");
	return(0);
}
