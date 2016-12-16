/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 19:13:31 by ariard            #+#    #+#             */
/*   Updated: 2016/12/16 16:39:09 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>

t_dlist				*ft_create_info(void *data)
{
	t_dlist			*node;
	t_info			*info;

	node = ft_memalloc(sizeof(t_dlist));
	if (node)
	{
		node->data = data;
		node->next = NULL;
		node->previous = NULL;
		if (data)
		{
			info = data;
			node->key = info->sort;
		}
	}
	return (node);
}

char				*ft_set_type(struct stat *buf)
{
	char			*c;

	c = "0";
	if (((S_ISDIR(buf->st_mode)) ? 'd' : '-') == 'd')
		c = "d";
	else if (((S_ISREG(buf->st_mode)) ? '-' : 'd') == '-')
		c = "-";
	return (c);
}

char				*ft_set_end_perm(struct stat *buf, char *perm)
{
	if (((buf->st_mode & S_IXGRP) ? 'x' : '-') == 'x')
		ft_strcat(perm, "x");
	else
		ft_strcat(perm, "-");
	if (((buf->st_mode & S_IROTH) ? 'r' : '-') == 'r')
		ft_strcat(perm, "r");
	else
		ft_strcat(perm, "-");
	if (((buf->st_mode & S_IWOTH) ? 'w' : '-') == 'w')
		ft_strcat(perm, "w");
	else
		ft_strcat(perm, "-");
	if (((buf->st_mode & S_IXOTH) ? 'x' : '-') == 'x')
		ft_strcat(perm, "x");
	else
		ft_strcat(perm, "-");
	return (perm);
}

char				*ft_set_perm(struct stat *buf)
{
	char			*perm;

	perm = ft_memalloc(sizeof(11));
	ft_strcat(perm, ft_set_type(buf));
	if (((buf->st_mode & S_IRUSR) ? 'r' : '-') == 'r')
		ft_strcat(perm, "r");
	else
		ft_strcat(perm, "-");
	if (((buf->st_mode & S_IWUSR) ? 'w' : '-') == 'w')
		ft_strcat(perm, "w");
	else
		ft_strcat(perm, "-");
	if (((buf->st_mode & S_IXUSR) ? 'x' : '-') == 'x')
		ft_strcat(perm, "x");
	else
		ft_strcat(perm, "-");
	if (((buf->st_mode & S_IRGRP) ? 'r' : '-') == 'r')
		ft_strcat(perm, "r");
	else
		ft_strcat(perm, "-");
	if (((buf->st_mode & S_IWGRP) ? 'w' : '-') == 'w')
		ft_strcat(perm, "w");
	else
		ft_strcat(perm, "-");
	return (ft_set_end_perm(buf, perm));
}

t_info				*ft_get_info(char *s)
{
	struct stat		*buf;
	struct passwd	*uid;
	struct group	*gid;
	t_info			*info;
	
	buf = ft_memalloc(sizeof(struct stat));
	stat(s, buf);
	uid = getpwuid(buf->st_uid);
	gid = getgrgid(buf->st_gid);
	info = ft_memalloc(sizeof(t_info));
	info->perm = ft_set_perm(buf);
	info->type = info->perm[0];
	info->link = buf->st_nlink;
	info->owner = uid->pw_name;
	info->team = gid->gr_name;
	info->size = buf->st_size;
	info->time = ctime(&buf->st_mtimespec.tv_sec);
	info->pure_time = &buf->st_mtimespec.tv_sec;
	info->name = s;
	info->sort = ft_strlen(info->name);;
	return (info);
}
