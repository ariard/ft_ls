/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 16:40:19 by ariard            #+#    #+#             */
/*   Updated: 2016/12/22 01:19:12 by ariard           ###   ########.fr       */
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

int				ft_get_size(t_dlist **list_files, t_sizeprint *sizeprint,
		t_option *option)
{
	t_dlist			*tmp;
	t_info			*info;
	long long int	blocks;

	blocks = 0;
	tmp = *list_files;
	option->isindev = 1;
	while (tmp)
	{
		info = tmp->data;
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
		blocks += info->blocks;
		if (info->perm[0] == 'c' || info->perm[0] == 'b')
			option->isindev--;
		tmp = tmp->next;
	}
	return (blocks);
}

void			ft_just_print(t_info *info, t_sizeprint *sizeprint, 
		t_option *option)
{
	char		buf[614];
	char		link[256];

	ft_bzero(buf, 614);
	ft_space(buf, sizeprint->perm, info->perm);
	ft_strcpy(buf, info->perm);
	if ((info->ACL || info->att) && info->perm[0] != 'l' && info->perm[0] != 'c' 
			&& info->perm[0] != 'b')
		ft_strcat(buf, " ");
	else
		ft_strcat(buf, "  ");
	ft_space(buf, sizeprint->link, ft_itoa(info->link));
	ft_strcat(buf, ft_itoa(info->link));
	ft_strcat(buf, " ");
	ft_join_owner(buf, info, sizeprint, option);
	ft_join_team(buf, info, sizeprint, option);
	ft_join_size(buf, info, sizeprint, option);
	ft_space(buf, sizeprint->time, info->time);
	ft_strcat(buf, info->time);
	ft_strcat(buf, " ");
	if (!option->G)
		ft_join_name(buf, info, option);
	else
	{
		write(1, &buf, ft_strlen(buf));
		ft_put_color(info);
	}
	if (info->perm[0] == 'l' || info->perm[0] == '0')
	{
		ft_bzero(link, 256);
		readlink(info->path, link, 256);
		ft_strcat(buf," -> ");
		ft_strcat(buf, link);
	}
	if (option->e)
		ft_strcat(buf, info->ACL);
	else
		ft_strcat(buf, "\n");
	if (!option->G)
		write(1, &buf, ft_strlen(buf));
}

void			ft_print_all(t_dlist **list_files, t_option *option)
{
	t_dlist		*tmp;
	t_info		*info;
	t_sizeprint	*sizeprint;
	char		buf[1028];

	tmp = *list_files;
	sizeprint = ft_memalloc(sizeof(t_sizeprint));
	ft_bzero(buf, 1028);
	ft_strcpy(buf, "total ");
	ft_strcat(buf, ft_itoa(ft_get_size(list_files, sizeprint, option)));
	ft_strcat(buf, "\n");
	write(1, buf, ft_strlen(buf));
	while (tmp)
	{
		info = tmp->data;
		ft_just_print(info, sizeprint, option);
		tmp = tmp->next;
	}
	free(sizeprint);
	sizeprint = NULL;
}

void			ft_print_dir(t_option *option, t_dlist **list_files)
{
	ft_list_reverse(list_files);
	if (option->mode == 'l')
		ft_print_all(list_files, option);
	else
		ft_print_files(list_files, option);
	ft_list_reverse(list_files);
}
