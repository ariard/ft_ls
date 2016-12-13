/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 15:43:59 by ariard            #+#    #+#             */
/*   Updated: 2016/12/01 16:50:13 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strchrcpy(char *dst, const char *src, char c)
{
	while (*src && *src != c)
		*dst++ = *src++;
	*dst = '\0';
	return (dst);
}
