/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_option.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:36:08 by ariard            #+#    #+#             */
/*   Updated: 2016/12/22 15:40:10 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>

static void		ft_generate_option1(t_option *option, char *value)
{
	if (*value == 'l')
		option->mode = 'l';
	else if (*value == 'a')
		option->a = 'a';
	else if (*value == 'R')
		option->rr = 'R';
	else if (*value == 't')
		option->t = 't';
	else if (*value == 'r')
		option->r = 'r';
	else if (*value == 'S')
		option->ss = 'S';
	else if (*value == '@')
		option->aro = '@';
	else if (*value == '1')
		option->mode = '1';
	else if (*value == 'u')
		option->sort = 'u';
	else if (*value == 'U')
		option->sort = 'U';
	else if (*value == 'e')
		option->e = 'e';
	else if (*value == 'g')
		option->g = 'g';
	else if (*value == 'o')
		option->o = 'o';
	else if (*value == 'p')
		option->p = 'p';
	else if (*value == 'd')
		option->d = 'd';
	else if (*value == 'm')
		option->mode = 'm';
	else if (*value == 'x')
		option->x = 'x';
	else if (*value == 'G')
		option->gg = 'G';
	else if (*value == 'f')
		option->f = 'f';
}

static int		ft_error_option(char *string)
{
	ft_putstr("illegal option :");
	ft_putchar(*string);
	ft_putchar(10);
	ft_putstr("usage: ls [-laRtr@1uUegopdmxGf][file ...]\n");
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
		if ((*string == '-' && *(string - 1) == '-' && *(string + 1)) || check == 0)
			return (ft_error_option(string));
		string++;
	}
	return (0);
}

static void		ft_solve_conflict(t_option *option)
{
	static int	i;
	static int 	j;
	static int 	k;

	if (!i)
		i = 0;
	if (!j)
		j = 0;
	if (!k)
		k = 0;
	if (option->aro)
		i++;
	if (option->g)
		j++;
	if (option->o)
		k++;
	if (option->ss && option->sort)
		option->sort = 0;
	if (option->g || option->o)
		option->mode = 'l';
	if ((option->aro == '@' || option->g == 'g' || option->o == 'o') 
			&& option->mode != 'l' )
	{
		option->aro = 0;
		option->g = 0;
		option->o = 0;
		i++;
		j++;
	}
	if (option->mode == 'l' && i)
		option->aro = '@';
	if (option->mode == 'l' && j)
		option->aro = 'g';
	if (option->o == 'l' && k)
		option->o = 'o';
	if ((option->sort == 'u' || option->sort == 'U') && !option->t)
		option->sort = 0;
	if (option->f)
	{
		option->sort = 0;
		option->ss = 0;
		option->r = 0;
		option->a = 'a';
	}
}

t_option		*ft_parse_option(char **argv, t_option *option)
{
	int			i;
	int			j;

	i = 1;
	while (argv[i] && argv[i][0] == '-')
	{
		if (ft_check_option(&argv[i][1]))
			return (NULL);
		j = 1;
		while (argv[i][j])
		{
			ft_generate_option1(option, &argv[i][j++]);
			ft_solve_conflict(option);
		}
		i++;
	}
	return (option);
}
