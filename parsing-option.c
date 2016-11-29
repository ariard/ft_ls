/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing-option.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 13:55:58 by ariard            #+#    #+#             */
/*   Updated: 2016/11/29 15:20:39 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>

static void			ft_generate_option(t_option *option, char *value)
{
	if (*value == 'l')
		option->l = 1;
	else if (*value == 'a')
		option->a = 1;
	else if (*value == 'R')
		option->R = 1;
	else if (*value == 't')
		option->t = 1;
	else if (*value == 'r')
		option->r = 1;
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
		j = 0;	
		while (argv[i][j])
			ft_generate_option(option, &argv[i][j++]);	
		i++;
	}
	return (option);
}
