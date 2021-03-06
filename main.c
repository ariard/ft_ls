/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 16:05:36 by ariard            #+#    #+#             */
/*   Updated: 2016/12/26 18:22:07 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_option			*ft_init_option(void)
{
	t_option		*option;

	option = ft_memalloc(sizeof(t_option));
	option->mode = 0;
	option->rr = 0;
	option->a = 0;
	option->r = 0;
	option->sort = 0;
	option->ss = 0;
	option->gg = 0;
	option->g = 0;
	option->e = 0;
	option->aro = 0;
	option->p = 0;
	option->o = 0;
	option->x = 0;
	option->t = 0;
	option->d = 0;
	option->f = 0;
	option->nb = 0;
	option->exe = 0;
	return (option);
}

int						main(int argc, char **argv)
{
	t_option	*option;
	int			check;

	option = ft_init_option();
	option->exe = ft_strdup(argv[0]);
	if (argc > 1 && ft_strcmp(argv[1], "-") != 0)
	{
		if (argv[1][0] == '-')
			if ((check = ft_parse_option(argv, option)) == 0)
				return (1);
		if (option)
			argv++;
		while (*argv && **argv == '-' && check != 3)
		{
			argv++;
			check++;
		}
	}
	if (*argv)
		if (ft_strcmp("--", *argv) == 0)
			argv++;
	ft_command(argc, argv, option);
	return (0);
}
