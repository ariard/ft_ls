/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 15:49:33 by ariard            #+#    #+#             */
/*   Updated: 2016/12/26 17:07:37 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char				*ft_set_type(struct stat *buf)
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

static char				*ft_set_end_perm(struct stat *buf, char *perm)
{
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

static char				*ft_set_mid_perm(struct stat *buf, char *perm)
{
	if (((buf->st_mode & S_IRGRP) ? 'r' : '-') == 'r')
		ft_strcat(perm, "r");
	else
		ft_strcat(perm, "-");
	if (((buf->st_mode & S_IWGRP) ? 'w' : '-') == 'w')
		ft_strcat(perm, "w");
	else
		ft_strcat(perm, "-");
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
	return (ft_set_end_perm(buf, perm));
}

char					*ft_set_perm(struct stat *buf)
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
	return (ft_set_mid_perm(buf, perm));
}
