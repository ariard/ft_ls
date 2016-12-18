/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 16:40:19 by ariard            #+#    #+#             */
/*   Updated: 2016/12/18 17:09:46 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_print_all(t_dlist **list_files)
{
	t_dlist		*tmp;
	t_info		*info;
	char		buf[1028];

	tmp = *list_files;
	while (tmp)
	{
		info = tmp->data;
		ft_bzero(buf, 1028);
		ft_strcpy(buf, info->perm);
		ft_strcat(buf, " ");
		ft_strcat(buf, ft_itoa(info->link));
		ft_strcat(buf, " ");
		ft_strcat(buf, info->owner);
		ft_strcat(buf, " ");
		ft_strcat(buf, info->team);
		ft_strcat(buf, " ");
		ft_strcat(buf, ft_itoa(info->size));
		ft_strcat(buf, " ");
		ft_strcat(buf, info->time);
		ft_strcat(buf, " ");
		ft_strcat(buf, info->name);
		ft_strcat(buf, "\n");
		write(1, &buf, ft_strlen(buf));
		tmp = tmp->next;
	}
}

void			ft_print_dir(t_option *option, t_dlist **list_files)
{
	t_dlist		*tmp;
	t_info		*info;

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
}
