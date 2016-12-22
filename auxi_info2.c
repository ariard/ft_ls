/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxi_info2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 19:38:51 by ariard            #+#    #+#             */
/*   Updated: 2016/12/22 15:31:39 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*ft_setatt(char *s, t_option *option)
{
	int		buflen;
	char	buf[614];
	char	list[614];
	int		vallen;
	int		len;

	buflen = listxattr(s, list, 614, 0);
	if (buflen == 0)
		return (NULL);
	else if (!option->aro)
		return ("");
	vallen = 0;
	len = 0;
	ft_bzero(buf, 614);
	while (len < buflen)
	{
		ft_strcpy(buf, "\n  	 ");
		ft_strcat(buf, &list[len]);
		vallen = getxattr(s, &list[len], NULL, 614, 0, 0);
		ft_strcat(buf, "		");
		ft_strcat(buf, ft_itoa(vallen));
		ft_strcat(buf, "\n");
		len += ft_strlen(&list[len]) + 1;
	}
	return (ft_strdup(buf));
}
