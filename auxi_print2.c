/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxi_print2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 17:06:50 by ariard            #+#    #+#             */
/*   Updated: 2016/12/22 18:35:04 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_put_color2(t_info *info)
{
	if (info->perm[0] == 'l')
		ft_putstr(MAG);
	if (info->perm[0] == '-' && info->perm[6] == 's')
	{
		ft_putstr(BLACK);
		ft_putstr(B_CYAN);
	}
	if (info->perm[0] == 'd' && info->perm[8] == 'w'
			&& (info->perm[9] == 't' || info->perm[9] == 'T'))
	{
		ft_putstr(BLACK);
		ft_putstr(B_GREEN);
	}
	if (info->perm[0] == 'd' && info->perm[8] == 'w'
			&& info->perm[9] != 't' && info->perm[9] != 'T')
	{
		ft_putstr(BLACK);
		ft_putstr(B_YELLOW);
	}
	ft_putstr(info->name);
	ft_putstr(DEF);
	ft_putstr(B_DEF);
}

void			ft_put_color(t_info *info)
{
	if (info->perm[0] == 'd')
		ft_putstr(BLUE);
	if (info->perm[0] == 's')
		ft_putstr(CYAN);
	if (info->perm[0] == 'p')
		ft_putstr(YELLOW);
	if (info->perm[0] == 'b')
	{
		ft_putstr(BLUE);
		ft_putstr(B_CYAN);
	}
	if (info->perm[0] == 'c')
	{
		ft_putstr(BLUE);
		ft_putstr(B_YELLOW);
	}
	if (info->perm[0] == '-' && info->perm[3] == 's')
	{
		ft_putstr(BLACK);
		ft_putstr(B_RED);
	}
	ft_put_color2(info);
}

int				ft_get_column(void)
{
	struct winsize w;

	ioctl(0, TIOCGWINSZ, &w);
	return (w.ws_col);
}
