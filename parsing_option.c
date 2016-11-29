/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_option.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:36:08 by ariard            #+#    #+#             */
/*   Updated: 2016/11/29 17:27:11 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>

static void		ft_generate_option1(t_option *option, char *value)
{
	if (*value == 'l')
		option->mode = 1;
	else if (*value == 'a')
		option->a = 1;
	else if (*value == 'R')
		option->R = 1;
	else if (*value == 't')
		option->sort = 1;
	else if (*value == 'r')
		option->r = 1;
}

static int		ft_check_option(char *string)
{
	char		*legal_opt;
	int			check;
	int			index;

	legal_opt = "laRtr";
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
		if (*string == '-' && *(string - 1) == '-' && *(string + 1))
			return (1);
		if (check == 0)
			return (1);
		string++;
	}
	return (0);
}

static void		ft_solve_conflict(t_option *option)
{
	if
}


t_option		*ft_parse_option(char **argv)
{
	t_option	*option;
	int			i;
	int			j;

	i = 1;
	option = ft_memalloc(sizeof(option));
	while (argv[i] && argv[i][0] == '-')
	{
		if (ft_check_option(&argv[i][1]))
			return (NULL);
		j = 1;
		while (argv[i][j])
			ft_generate_option1(option, &argv[i][j++]);
		i++;
	}
	ft_solve_conflict(option);
	return (option);
}
