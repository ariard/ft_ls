/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxi_info2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 19:38:51 by ariard            #+#    #+#             */
/*   Updated: 2016/12/19 22:08:50 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*ft_setatt(char *s)
{
	size_t	buflen;
	char	*buf;
	char	*str;
	char	*val;
	int		vallen;

	buflen = listxattr(s, NULL, 1028, 0);
	if (buflen < 0)
		return (NULL);
	buf = ft_strnew(buflen);
	str = ft_strnew(1024);
	val = ft_strnew(1024);
	listxattr(s, buf, buflen, 0);
	while (buflen > 0)
	{		
		ft_strcat(str, "        ");
		ft_strcat(str, buf);
		vallen = getxattr(s, buf, NULL, 0, 0, 0); 
		ft_strcat(str, ft_itoa(vallen));
		ft_strcat(str, "\n");
		ft_strdel(&val);
		val = ft_strnew(1028);
	}
}		
