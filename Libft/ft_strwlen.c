/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 17:57:28 by ariard            #+#    #+#             */
/*   Updated: 2016/12/11 17:58:17 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t		ft_strwlen(wchar_t *w)
{
	int		len;

	len = 0;
	while (*w)
		len += ft_sizewchar(*w++);
	return (len);
}