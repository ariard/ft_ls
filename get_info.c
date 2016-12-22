/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 15:49:33 by ariard            #+#    #+#             */
/*   Updated: 2016/12/22 21:34:30 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void				ft_set_info(struct stat *buf, t_info *info,
		t_option *option)
{
	struct passwd	*uid;
	struct group	*gid;

	uid = getpwuid(buf->st_uid);
	gid = getgrgid(buf->st_gid);
	info->perm = ft_set_perm(buf);
	info->link = buf->st_nlink;
	info->owner = uid->pw_name;
	info->team = gid->gr_name;
	info->size = buf->st_size;
	info->dev = buf->st_rdev;
	info->blocks = buf->st_blocks;
	ft_set_time(buf, info, option);
}

t_info					*ft_get_info(char *s, t_option *option)
{
	struct stat		*buf;
	t_info			*info;

	buf = ft_memalloc(sizeof(struct stat));
	lstat(s, buf);
	info = ft_memalloc(sizeof(t_info));
	ft_set_info(buf, info, option);
	info->path = s;
	info->name = ft_strrchr(s, '/');
	info->acl = ft_setacl(s, option);
	if (ft_strcmp(&info->perm[1], "---------"))
		info->att = ft_setatt(s, option);
	if (info->att && info->perm[0] != 'l' && info->perm[0] != 'c'
			&& info->perm[0] != 'b')
		ft_strcat(info->perm, "@");
	if (info->acl && !info->att)
		ft_strcat(info->perm, "+");
	ft_set_sort(info, option);
	info->error = 0;
	return (info);
}
