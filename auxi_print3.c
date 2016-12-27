/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxi_print3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 17:55:13 by ariard            #+#    #+#             */
/*   Updated: 2016/12/26 19:14:03 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_space(char *buf, size_t len_max, char *s)
{
	size_t		to_space;

	to_space = len_max - ft_strlen(s);
	while (to_space--)
		ft_strcat(buf, " ");
}

void			ft_get_size2(t_sizeprint *sizeprint, t_info *info)
{
	if (ft_strlen(info->perm) > sizeprint->perm)
		sizeprint->perm = ft_strlen(info->perm);
	if (ft_strlen(ft_itoa(info->link)) > sizeprint->link)
		sizeprint->link = ft_strlen(ft_itoa(info->link));
	if (ft_strlen(info->owner) > sizeprint->owner)
		sizeprint->owner = ft_strlen(info->owner);
	if (ft_strlen(info->team) > sizeprint->team)
		sizeprint->team = ft_strlen(info->team);
	if (ft_strlen(ft_itoa(info->size)) > sizeprint->size)
		sizeprint->size = ft_strlen(ft_itoa(info->size));
	if (ft_strlen(info->time) > sizeprint->time)
		sizeprint->time = ft_strlen(info->time);
}

void			ft_set_others(t_info *info, t_option *option, char *buf)
{
	char		*link;

	if (info->perm[0] == 'l')
	{
		link = ft_strnew(256);
		readlink(info->path, link, 256);
		ft_strcat(buf, " -> ");
		ft_strcat(buf, link);
	}
	if (option->e && info->acl)
		ft_strcat(buf, info->acl);
	if (option->aro && info->att)
		ft_strcat(buf, info->att);
	ft_strcat(buf, "\n");
}

void			ft_just_print_color(t_info *info, t_sizeprint *sizeprint,
	t_option *option)
{
	char		buf[1028];

	ft_bzero(buf, 1028);
	ft_space(buf, sizeprint->perm, info->perm);
	ft_strcpy(buf, info->perm);
	if ((info->acl || info->att) && info->perm[0] != 'l'
			&& info->perm[0] != 'c' && info->perm[0] != 'b')
		ft_strcat(buf, " ");
	else
		ft_strcat(buf, "  ");
	ft_space(buf, sizeprint->link, ft_itoa(info->link));
	ft_strcat(buf, " ");
	ft_join_owner(buf, info, sizeprint, option);
	ft_join_team(buf, info, sizeprint, option);
	ft_join_size(buf, info, sizeprint, option);
	ft_space(buf, sizeprint->time, info->time);
	ft_strcat(buf, info->time);
	ft_strcat(buf, " ");
	write(1, &buf, ft_strlen(buf));
	ft_put_color(info);
	ft_bzero(buf, 1024);
	ft_set_others(info, option, buf);
	write(1, &buf, ft_strlen(buf));
}

void			ft_print_dir_error(t_info *info, t_option *option)
{
	if (option->nb > 1)
	{
		ft_putstr(info->path);
		ft_putchar(10);
	}
	ft_putchar(*info->error++);
	ft_putchar(*info->error++);
	while (*(info->error - 1) != '\n')
		ft_putchar(*info->error++);
	ft_putstr_fd(info->error, 0);
}
