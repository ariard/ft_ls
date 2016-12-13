/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 20:36:31 by ariard            #+#    #+#             */
/*   Updated: 2016/12/03 21:15:40 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_putstrn(char const *s, int len)
{
	if (!s)
		return (0);
	write(1, s, len);
	return (len);
}
