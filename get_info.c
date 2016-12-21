/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 19:13:31 by ariard            #+#    #+#             */
/*   Updated: 2016/12/21 18:20:29 by ariard           ###   ########.fr       */
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
			node->name = info->name;
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
	else if (((S_ISCHR(buf->st_mode)) ? 'c' : '-') == 'c')
		c = "c";
	else if (((S_ISBLK(buf->st_mode)) ? 'b' : '-') == 'b')
		c = "b";
	else if (((S_ISFIFO(buf->st_mode)) ? 'p' : '-') == 'p')
		c = "p";
	else if (((S_ISSOCK(buf->st_mode)) ? 's' : '-') == 's')
		c = "s";
	else if (((S_ISLNK(buf->st_mode)) ? 'l' : '-') == 'l')
		c = "l";
	return (c);
}

char				*ft_set_end_perm(struct stat *buf, char *perm)
{
	if ((((buf->st_mode & S_ISGID) ? 's' : '-') == 's')
		&& (((buf->st_mode & S_IXGRP) ? 'x' : '-') == 'x'))
		ft_strcat(perm, "s");
	else if ((((buf->st_mode & S_ISGID) ? 's' : '-') == 's')
		&& (((buf->st_mode & S_IXGRP) ? 'x' : '-') != 'x'))
		ft_strcat(perm, "S");
	else if (((buf->st_mode & S_IXGRP) ? 'x' : '-') == 'x')
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
	if ((((buf->st_mode & S_ISVTX) ? 's' : '-') == 's')
		&& (((buf->st_mode & S_IXOTH) ? 'x' : '-') == 'x'))
		ft_strcat(perm, "t");
	else if ((((buf->st_mode & S_ISVTX) ? 's' : '-') == 's')
		&& (((buf->st_mode & S_IXOTH) ? 'x' : '-') != 'x'))
		ft_strcat(perm, "T");
	else if (((buf->st_mode & S_IXOTH) ? 'x' : '-') == 'x')
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
	if ((((buf->st_mode & S_ISUID) ? 's' : '-') == 's')
		&& (((buf->st_mode & S_IXUSR) ? 'x' : '-') == 'x'))
		ft_strcat(perm, "s");
	else if ((((buf->st_mode & S_ISUID) ? 's' : '-') == 's')
		&& (((buf->st_mode & S_IXUSR) ? 'x' : '-') != 'x'))
		ft_strcat(perm, "S");
	else if (((buf->st_mode & S_IXUSR) ? 'x' : '-') == 'x')
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

t_info				*ft_get_info(char *s, t_option *option)
{
	struct stat		*buf;
	struct passwd	*uid;
	struct group	*gid;
	t_info			*info;

	buf = ft_memalloc(sizeof(struct stat));
	lstat(s, buf);
	uid = getpwuid(buf->st_uid);
	gid = getgrgid(buf->st_gid);
	info = ft_memalloc(sizeof(t_info));
	info->perm = ft_set_perm(buf);
	info->link = buf->st_nlink;
	info->owner = uid->pw_name;
	info->team = gid->gr_name;
	info->size = buf->st_size;
	info->blocks = buf->st_blocks;
	ft_set_time(buf, info, option);
	info->path = s;
	info->name = ft_strrchr(s, '/'); 
	info->ACL = ft_setACL(s, option);
	if (ft_strcmp(&info->perm[1], "---------"))
		info->att = listxattr(s, NULL, 1, 0); 
	if (info->att && info->perm[0] != 'l')
		ft_strcat(info->perm, "@");
	if (info->ACL && !info->att)
		ft_strcat(info->perm, "+");
	ft_set_sort(info, option);
	return (info);
}
