/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 13:39:51 by ariard            #+#    #+#             */
/*   Updated: 2016/12/15 00:13:55 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "./Libft/includes/libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <time.h>
# include <errno.h>
# include <stdio.h>

typedef struct		s_option
{
	char	mode;
	char	R;
	char	a;
	char	r;
	char	sort;
	char	S;
	char 	G;
	char	g;
	char	e;
	char	aro;
	char	p;
	char	h;
	char	o;
	char	T;
	char	n;
	char	F;
	char	i;
}					t_option;	

typedef struct		s_dir_id
{
	char			*name;
	char			type;
	char			*modes;
	char			*time;
}					t_dir_id;

typedef struct		s_error
{
	char			*name;
	char			*message;
	void			*sort;
}					t_error;

t_option			*ft_parse_option(char **argv);

void				ft_command(int argc, char **argv, t_option *option);

void				ft_bubble_sort(t_dlist **begin_list,
		int (*cmp)(const void *key1, const void *key2));

void				ft_insert_sort(t_dlist **begin_list,
		int (*cmp)(const void *key1, const void *key2));

void				ft_insert_sort_arg(t_dlist **begin_list,
		int (*cmp)(const void *key1, const void *key2));

int					ft_stralphcmp(const void *s1, const void *s2);

int					main(int argc, char **argv);

#endif
