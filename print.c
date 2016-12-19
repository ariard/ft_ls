/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 16:40:19 by ariard            #+#    #+#             */
/*   Updated: 2016/12/19 17:07:21 by ariard           ###   ########.fr       */
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

int				ft_get_size(t_dlist **list_files, t_sizeprint *sizeprint)
{
	t_dlist			*tmp;
	t_info			*info;
	long long int	blocks;

	blocks = 0;
	tmp = *list_files;
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
		tmp = tmp->next;
	}
	return (blocks);
}

void			ft_just_print(t_info *info, t_sizeprint *sizeprint)
{
	char		buf[1028];

	(void)sizeprint;
	ft_bzero(buf, 1028);
	ft_space(buf, sizeprint->perm, info->perm);
	ft_strcpy(buf, info->perm);
	if (info->ACL)
		ft_strcat(buf, " ");
	else
		ft_strcat(buf, "  ");
	ft_space(buf, sizeprint->link, ft_itoa(info->link));
	ft_strcat(buf, ft_itoa(info->link));
	ft_strcat(buf, " ");
	ft_space(buf, sizeprint->owner, info->owner);
	ft_strcat(buf, info->owner);
	ft_strcat(buf, "  ");
	ft_space(buf, sizeprint->team, info->team);
	ft_strcat(buf, info->team);
	ft_strcat(buf, "  ");
	ft_space(buf, sizeprint->size, ft_itoa(info->size));
	ft_strcat(buf, ft_itoa(info->size));
	ft_strcat(buf, " ");
	ft_space(buf, sizeprint->time, info->time);
	ft_strcat(buf, info->time);
	ft_strcat(buf, " ");
	ft_strcat(buf, info->name);
	if (info->ACL)
		ft_strcat(buf, info->ACL);
	else
		ft_strcat(buf, "\n");
	write(1, &buf, ft_strlen(buf));
}

void			ft_print_all(t_dlist **list_files)
{
	t_dlist		*tmp;
	t_info		*info;
	t_sizeprint	*sizeprint;
	char		buf[1028];

	tmp = *list_files;
	sizeprint = ft_memalloc(sizeof(t_sizeprint));
	ft_bzero(buf, 1028);
	ft_strcpy(buf, "total ");
	ft_strcat(buf, ft_itoa(ft_get_size(list_files, sizeprint)));
	ft_strcat(buf, "\n");
	write(1, buf, ft_strlen(buf));
	while (tmp)
	{
		info = tmp->data;
		ft_just_print(info, sizeprint);					
		tmp = tmp->next;
	}
	free(sizeprint);
	sizeprint = NULL;
}

void			ft_print_dir(t_option *option, t_dlist **list_files)
{
	t_dlist		*tmp;
	t_info		*info;

	ft_insert_sort_3(list_files, &ft_stralphcmp);
	if (option->mode == 'l')
		ft_print_all(list_files);
	else
	{
		tmp = *list_files;
		while (tmp)
		{
			info = tmp->data;
			printf("%s\n", info->name);
			tmp = tmp->next;
		}
	}
	ft_insert_sort(list_files, &ft_stralphcmp);
}
