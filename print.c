/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 16:40:19 by ariard            #+#    #+#             */
/*   Updated: 2016/12/26 16:34:32 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					ft_get_size(t_dlist **list_files, t_sizeprint *sizeprint,
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
		ft_get_size2(sizeprint, info);
		blocks += info->blocks;
		if (info->perm[0] == 'c' || info->perm[0] == 'b')
			option->isindev--;
		tmp = tmp->next;
	}
	return (blocks);
}

static void			ft_just_print(t_info *info, t_sizeprint *sizeprint,
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
	ft_strcat(buf, ft_itoa(info->link));
	ft_strcat(buf, " ");
	ft_join_owner(buf, info, sizeprint, option);
	ft_join_team(buf, info, sizeprint, option);
	ft_join_size(buf, info, sizeprint, option);
	ft_space(buf, sizeprint->time, info->time);
	ft_strcat(buf, info->time);
	ft_strcat(buf, " ");
	ft_join_name(buf, info, option);
	ft_set_others(info, option, buf);
	write(1, &buf, ft_strlen(buf));
}

static void			ft_print_total(t_dlist **list_files, char buf[],
		t_sizeprint *sizeprint, t_option *option)
{
	ft_bzero(buf, 1028);
	ft_strcpy(buf, "total ");
	ft_strcat(buf, ft_itoa(ft_get_size(list_files, sizeprint, option)));
	ft_strcat(buf, "\n");
}

static void			ft_print_all(t_dlist **list_files, t_option *option)
{
	t_dlist		*tmp;
	t_info		*info;
	t_sizeprint	*sizeprint;
	char		buf[1028];

	tmp = *list_files;
	sizeprint = ft_memalloc(sizeof(t_sizeprint));
	ft_print_total(list_files, buf, sizeprint, option);
	if (tmp)
		if (tmp->next)
			write(1, &buf, ft_strlen(buf));
	while (tmp)
	{
		info = tmp->data;
		if (option->gg)
			ft_just_print_color(info, sizeprint, option);
		else
			ft_just_print(info, sizeprint, option);
		tmp = tmp->next;
	}
	free(sizeprint);
	sizeprint = NULL;
}

void				ft_print_dir(t_option *option, t_dlist **list_files)
{
	ft_list_reverse(list_files);
	if (option->mode == 'l')
		ft_print_all(list_files, option);
	else
		ft_print_files(list_files, option);
	ft_list_reverse(list_files);
}
