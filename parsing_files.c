/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 21:46:24 by ariard            #+#    #+#             */
/*   Updated: 2016/12/13 18:39:56 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>

int				ft_error_files(DIR *ds)
{
	char		*s;

	if (ds == NULL)
	{
		s = strerror(errno);
		if (ft_strcmp(s, "Not a directory") == 0)
			return (0);
		ft_putstr(s);
		ft_putchar(10);
		return (1);
	}
	return (0);
}

t_dlist				**ft_parse_files(int argc, char **argv, t_option *option)
{
	DIR 			*ds;
	DIR				*ds2;
	char			**new;
	struct dirent	*lu;
	char			*s;
//	t_dlist		**dir_list;

	(void)option;
	if (argc == 1)
		printf("phase appel");
	argv++;
	new = argv;
	while (*argv)
	{
		ft_putstr(*argv);
		argv++;
	}
	while (*new)
	{
		ds = opendir(*new);
		while ((lu = readdir(ds)))	
		{
			ds2 = opendir(lu->d_name);
				if (!(ft_error_files(ds2)))
				{
					s = lu->d_name;
					main(2, &s);
				}
		}
//			ft_generate_dlist(dir_list, *argv, option);
		new++;
	}
	return (0);
}
