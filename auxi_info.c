/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxi_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 14:33:22 by ariard            #+#    #+#             */
/*   Updated: 2016/12/22 15:31:22 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_fill2(char *dst, char *src)
{
	while (*src != ':')
	{
		ft_strncat(dst, src, 1);
		src++;
	}
	ft_strcat(dst, " ");
	src++;
	while (*src != 10)
	{
		ft_strncat(dst, src, 1);
		src++;
	}
	ft_strncat(dst, "\n", 1);
}

void		ft_fill(char *dst, char *src)
{
	while (*(src - 1) != ':')
	{
		ft_strncat(dst, src, 1);
		src++;
	}
	src++;
	while (*src != ':')
		src++;
	src++;
	while (*src != ':')
	{
		ft_strncat(dst, src, 1);
		src++;
	}
	src++;
	while (*src != ':')
		src++;
	src++;
	ft_strcat(dst, " ");
	ft_fill2(dst, src);
}

void		ft_fillacl(char *ret, char *str)
{
	int		d;

	d = 0;
	ft_strcat(ret, "\n");
	while (*str)
	{
		ft_strcat(ret, " ");
		ft_strcat(ret, ft_itoa(d));
		ft_strcat(ret, ": ");
		ft_fill(ret, str);
		while (*str != 10)
			str++;
		str++;
		d++;
	}
}

char		*ft_setacl(char *s, t_option *option)
{
	char	*str;
	char	*ret;
	acl_t	acl;
	ssize_t	len;
	char	*tmp;

	acl = acl_get_link_np(s, ACL_TYPE_EXTENDED);
	if (!acl)
		return (NULL);
	if (!option->e)
		return ("");
	str = ft_strnew(1028);
	tmp = str;
	ret = ft_strnew(1028);
	ft_strcpy(str, acl_to_text(acl, &len));
	while (*str != 10)
		str++;
	str++;
	ft_fillacl(ret, str);
	acl_free(acl);
	acl = NULL;
	ft_strdel(&tmp);
	return (ret);
}
