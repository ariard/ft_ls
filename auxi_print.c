/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxi_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 21:24:03 by ariard            #+#    #+#             */
/*   Updated: 2016/12/22 18:33:39 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_join_owner(char *buf, t_info *info, t_sizeprint *sizeprint,
		t_option *option)
{
	if (!option->g && option->isindev > 0)
	{
		ft_space(buf, sizeprint->owner, info->owner);
		ft_strcat(buf, info->owner);
		ft_strcat(buf, "  ");
	}
	else if (!option->g)
	{
		ft_strcat(buf, info->owner);
		ft_space(buf, sizeprint->owner, info->owner);
		ft_strcat(buf, "  ");
	}
}

void		ft_join_team(char *buf, t_info *info, t_sizeprint *sizeprint,
		t_option *option)
{
	if (!option->o && option->isindev > 0)
	{
		ft_space(buf, sizeprint->team, info->team);
		ft_strcat(buf, info->team);
		ft_strcat(buf, "  ");
	}
	else if (!option->o)
	{
		ft_strcat(buf, info->team);
		ft_space(buf, sizeprint->team, info->team);
		ft_strcat(buf, "   ");
	}
}

void		ft_join_name(char *buf, t_info *info, t_option *option)
{
	if (!option->p)
		ft_strcat(buf, info->name);
	else if (option->p && info->perm[0] == 'd')
	{
		ft_strcat(buf, info->name);
		ft_strcat(buf, "/");
	}
	else if (option->p)
		ft_strcat(buf, info->name);
}

void		ft_join_size(char *buf, t_info *info, t_sizeprint *sizeprint,
		t_option *option)
{
	if (info->perm[0] == 'b' || info->perm[0] == 'c')
	{
		ft_space(buf, 2, ft_itoa(major(info->dev)));
		ft_strcat(buf, ft_itoa(major(info->dev)));
		ft_strcat(buf, ", ");
		ft_space(buf, 3, ft_itoa(minor(info->dev)));
		ft_strcat(buf, ft_itoa(minor(info->dev)));
		ft_strcat(buf, " ");
	}
	else if (option->isindev < 1)
	{
		ft_strcat(buf, "      ");
		ft_strcat(buf, ft_itoa(info->size));
		ft_strcat(buf, " ");
	}
	else
	{
		ft_space(buf, sizeprint->size, ft_itoa(info->size));
		ft_strcat(buf, ft_itoa(info->size));
		ft_strcat(buf, " ");
	}
}

void		ft_print_column2(t_col *col, t_dlist *tmp)
{
	char	buf[614];
	t_info	*info;

	ft_bzero(buf, 614);
	if (col->size == col->block * col->cp)
		info = ft_get_special(tmp, col->nb, col->block, col->size);
	else
		info = ft_get_next(tmp, col->nb, col->block, col->size);
	if (info)
	{
		ft_strcpy(buf, info->name);
		ft_space(buf, col->max, info->name);
		if (col->nb == 0 || !(tmp->next))
			ft_strcat(buf, "\n");
		write(1, &buf, ft_strlen(buf));
	}
	else if (col->size != 1)
	{
		col->nb = 0;
		ft_putchar(10);
	}
}
