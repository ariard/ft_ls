/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 16:05:36 by ariard            #+#    #+#             */
/*   Updated: 2016/12/22 20:31:55 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_option			*ft_init_option(void)
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

int					main(int argc, char **argv)
{
	t_option	*option;
	int			i;

	i = 0;
	option = ft_init_option();
	option->exe = ft_strdup(argv[0]);
	if (argc > 1)
	{
		if (argv[1][0] == '-')
			if (ft_parse_option(argv, option) == 0)
				return (0);
		if (option)
		{
			argv++;
			while (*argv && **argv == '-')
				argv++;
		}
	}
	ft_command(argc, argv, option);
	return (0);
}
