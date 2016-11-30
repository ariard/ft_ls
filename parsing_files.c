/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 21:46:24 by ariard            #+#    #+#             */
/*   Updated: 2016/11/30 01:11:52 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>

int				ft_error_files(DIR *ds)
{


t_dlist			**ft_parse_files(int argc, char **argv, t_option *option)
{
	DIR *ds;
	t_dlist		**dir_list;


	if (argc == 1)
		printf("phase appel");
	while (*argv)
	{
		ds = opendir(*argv);
		if (!(ft_error_files(ds)))
//			ft_generate_dlist(dir_list, *argv, option);
		argv++;
	}
	return (0);
}
