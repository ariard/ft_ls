/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 21:46:24 by ariard            #+#    #+#             */
/*   Updated: 2016/12/04 00:40:42 by ariard           ###   ########.fr       */
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

t_dlist			**ft_parse_files(int argc, char **argv, t_option *option)
{
	DIR *ds;
//	t_dlist		**dir_list;

	(void)option;
	if (argc == 1)
		printf("phase appel");
	argv++;
	while (*argv)
	{
		ds = opendir(*argv);
		if (!(ft_error_files(ds)))
			ft_putstr(*argv);
//			ft_generate_dlist(dir_list, *argv, option);
		argv++;
	}
	return (0);
}
