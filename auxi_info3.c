/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxi_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 19:20:55 by ariard            #+#    #+#             */
/*   Updated: 2016/12/21 01:29:02 by ariard           ###   ########.fr       */
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
	while (*tmp2 != ':')
	{
		*tmp2 = 0;
		tmp2--;
	}
	*tmp2 = 0;
	return (tmp);
}

char		*ft_set_date(long int time)
{
	char 			*new;
	char 			*buf;
	struct timeval	*current;

	new = ctime(&time);
	current = ft_memalloc(sizeof(struct timeval));
	gettimeofday(current, NULL);
	if (time < (current->tv_sec - 15552000))
	{
		buf = ft_strnew(128);	
		while (*(new - 1) != ' ')
			new++;
		ft_strncat(buf, new, 6);
		ft_strcat(buf, "  ");
		while (*(new + 1))
			new++;
		new -= 4;
		ft_strncat(buf, new, 4);
		return (buf);
	}
	else
		return((ft_strsub_lim(new)));	
}

void		ft_put_color(t_info *info)
{
	if (info->perm[0] == 'd')
		ft_putstr(BLUE);
	if (info->perm[0] == 'l')
		ft_putstr(MAG);
	if (info->perm[0] == 's')
		ft_putstr(CYAN);
	if (info->perm[0] == 'p')
		ft_putstr(BROWN);
	if (info->perm[0] == '-' && info->perm[3] == 'x')
		ft_putstr(RED);
	if (info->perm[0] == 'b')
	{
		ft_putstr(BLUE);
		ft_putstr(CYAN);
	}
	if (info->perm[0] == 'c')
		ft_putstr(BLUE);
	ft_putstr(info->name);
	ft_putchar(10);
	ft_putstr(DEF);
	ft_putstr(B_DEF);
}
