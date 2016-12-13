/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizewchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 17:56:09 by ariard            #+#    #+#             */
/*   Updated: 2016/12/11 18:05:13 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_sizewchar(wchar_t w)
{
	if (w < 128)
		return (1);
	else if (w < 2048)
		return (2);
	else if (w < 65536)
		return (3);
	else
		return (4);
}
