/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxi_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 19:20:55 by ariard            #+#    #+#             */
/*   Updated: 2016/12/18 19:17:25 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char					*ft_strsub_lim(char *s)
{
	char		*tmp;
	char		*tmp2;

	if (!s)
		return (0);
	tmp = ft_strchr(s, ' ');
	tmp++;
	tmp2 = tmp;
	while (*(tmp2 + 1))
		tmp2++;
	while (*tmp2 != ' ')
	{
		*tmp2 = 0;
		tmp2--;
	}
	*tmp2 = 0;
	return (tmp);
}

long long int			ft_gen_time(long int *time)
{
	return (*time);
}
