/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxi_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 21:24:03 by ariard            #+#    #+#             */
/*   Updated: 2016/12/21 17:02:16 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_join_owner(char *buf, t_info *info, t_sizeprint *sizeprint, 
		t_option *option)
{
	if (!option->g && !option->n)
	{
		ft_space(buf, sizeprint->owner, info->owner);
		ft_strcat(buf, info->owner);
		ft_strcat(buf, "  ");
	}
}

void		ft_join_team(char *buf, t_info *info, t_sizeprint *sizeprint,
		t_option *option)
{
	if (!option->o)
	{
		ft_space(buf, sizeprint->team, info->team);
		ft_strcat(buf, info->team);
		ft_strcat(buf, "  ");
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
