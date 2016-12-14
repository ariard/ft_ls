/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 17:52:20 by ariard            #+#    #+#             */
/*   Updated: 2016/12/11 18:05:29 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int			ft_putwstr(wchar_t *w)
{
	int		n;

	n = 0;
	while (*w)
	{
		if (*w < 128)
			n += ft_putchar(*w++);
		else
			n += ft_putwchar(*w++);
	}
	return (n);
}