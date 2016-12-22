/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_option.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:36:08 by ariard            #+#    #+#             */
/*   Updated: 2016/12/22 16:29:04 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			ft_solve_conflict3(t_option *option)
{
	static int	k;

	if (!k)
		k = 0;
	if (option->o)
		k++;
	if (option->o == 'o' && option->mode != 'l')
		option->o = 0;
	if (option->o == 'l' && k)
		option->o = 'o';
}

static void			ft_solve_conflict2(t_option *option)
{
	if (option->ss && option->sort)
		option->sort = 0;
	if (option->g || option->o)
		option->mode = 'l';
	if ((option->sort == 'u' || option->sort == 'U') && !option->t)
		option->sort = 0;
	if (option->f)
	{
		option->sort = 0;
		option->ss = 0;
		option->r = 0;
		option->a = 'a';
	}
	ft_solve_conflict3(option);
}

void				ft_solve_conflict(t_option *option)
{
	static int	i;
	static int	j;

	if (!i)
		i = 0;
	if (!j)
		j = 0;
	if (option->aro)
		i++;
	if (option->g)
		j++;
	if ((option->aro == '@' || option->g == 'g') && option->mode != 'l')
	{
		option->aro = 0;
		option->g = 0;
	}
	if (option->mode == 'l' && i)
		option->aro = '@';
	if (option->mode == 'l' && j)
		option->g = 'g';
	ft_solve_conflict2(option);
}
