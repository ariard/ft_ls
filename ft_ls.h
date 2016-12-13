/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 13:39:51 by ariard            #+#    #+#             */
/*   Updated: 2016/12/11 20:04:57 by ariard           ###   ########.fr       */
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

t_option			*ft_parse_option(char **argv);

t_dlist				**ft_parse_files(int argc, char **argv, t_option *option);

int					main(int argc, char **argv);

#endif
