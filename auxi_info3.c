/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxi_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 19:20:55 by ariard            #+#    #+#             */
/*   Updated: 2016/12/22 18:33:25 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char			*ft_strsub_lim(char *s)
{
	char		*tmp;
	char		*tmp2;

	if (!s)
		return (0);
	tmp = ft_strchr(s, ' ');
	tmp++;
	tmp2 = tmp;
	while (*(tmp2 + 1))
		tmp2++;
	while (*tmp2 != ':')
	{
		*tmp2 = 0;
		tmp2--;
	}
	*tmp2 = 0;
	return (tmp);
}

char			*ft_set_date(long int time)
{
	char				*new;
	char				*buf;
	struct timeval		*current;

	new = ctime(&time);
	current = ft_memalloc(sizeof(struct timeval));
	gettimeofday(current, NULL);
	if (time < (current->tv_sec - 15552000))
	{
		buf = ft_strnew(128);
		while (*(new - 1) != ' ')
			new++;
		ft_strncat(buf, new, 6);
		ft_strcat(buf, "  ");
		while (*(new + 1))
			new++;
		new -= 4;
		ft_strncat(buf, new, 4);
		return (buf);
	}
	else
		return ((ft_strsub_lim(new)));
}

void			ft_set_sort(t_info *info, t_option *option)
{
	if (option->t == 't')
		info->sort = info->pure_time;
	else if (option->sort == 'u')
		info->sort = info->pure_time;
	else if (option->sort == 'U')
		info->sort = info->pure_time;
	else if (option->ss == 'S')
		info->sort = info->size;
}

void			ft_set_time(struct stat *buf, t_info *info, t_option *option)
{
	if (option->sort == 'u')
	{
		info->pure_time = buf->st_atimespec.tv_sec;
		info->time = ft_strdup(ft_set_date(info->pure_time));
	}
	else if (option->sort == 'U')
	{
		info->pure_time = buf->st_birthtimespec.tv_sec;
		info->time = ft_strdup(ft_set_date(info->pure_time));
	}
	else
	{
		info->pure_time = buf->st_mtimespec.tv_sec;
		info->time = ft_strdup(ft_set_date(info->pure_time));
	}
}
