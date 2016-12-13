/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 17:10:53 by ariard            #+#    #+#             */
/*   Updated: 2016/12/11 17:26:44 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		ft_strrev(char *s)
{
	char	*tmp;
	char	c;

	tmp = s;
	while (*tmp + 1)
		tmp++;
	while (s < tmp)
	{
		c = *s;
		*s = *tmp;
		*tmp = c;
		s++;
		tmp--;
	}
}
