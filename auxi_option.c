/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_option.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:36:08 by ariard            #+#    #+#             */
/*   Updated: 2016/12/22 20:48:54 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_generate_option2(t_option *option, char *value)
{
	if (*value == 'e')
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

void		ft_generate_option1(t_option *option, char *value)
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
	else if (*value == 'u' && !option->t)
		option->sort = 'u';
	else if (*value == 'U' && !option->t)
		option->sort = 'U';
	ft_generate_option2(option, value);
}
