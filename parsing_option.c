/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_option.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:36:08 by ariard            #+#    #+#             */
/*   Updated: 2016/12/22 20:31:38 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		ft_error_option(char *string)
{
	ft_putstr("ls: illegal option -- ");
	ft_putchar(*string);
	ft_putchar(10);
	ft_putstr("usage: ls [-laRtr@1uUegopdmxGf] [file ...]\n");
	return (1);
}

static int		ft_check_option(char *string)
{
	char		*legal_opt;
	int			check;
	int			index;

	legal_opt = "laRtrS@1uUegopdmxGf";
	while (*string)
	{
		check = 0;
		index = 0;
		while (legal_opt[index])
		{
			if (*string == legal_opt[index])
				check++;
			index++;
		}
		if (*string == '-' && *(string - 1) == '-')
			check++;
		if ((*string == '-' && *(string - 1) == '-' && *(string + 1))
				|| check == 0)
			return (ft_error_option(string));
		string++;
	}
	return (0);
}

int				ft_parse_option(char **argv, t_option *option)
{
	int			i;
	int			j;

	i = 1;
	while (argv[i] && argv[i][0] == '-')
	{
		if (ft_check_option(&argv[i][1]))
			return (0);
		j = 1;
		while (argv[i][j])
		{
			ft_generate_option1(option, &argv[i][j++]);
			ft_solve_conflict(option);
		}
		i++;
	}
	return (1);
}
