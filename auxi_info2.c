/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxi_info2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 19:38:51 by ariard            #+#    #+#             */
/*   Updated: 2016/12/20 22:58:52 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*ft_setatt(char *s)
{
	size_t	buflen;
	char	buf[614];
	char	*str;
	int		vallen;

	ft_bzero(buf, 614);
	buflen = listxattr(s, buf, 1, 0);
	if (buflen == 0)
		return (NULL);
	else
		return ("");
}
