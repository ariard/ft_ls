/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 13:39:51 by ariard            #+#    #+#             */
/*   Updated: 2016/12/19 16:49:33 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "./Libft/includes/libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <time.h>
# include <errno.h>
# include <stdio.h>
#

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

typedef struct		s_info
{
	char			*perm;
	unsigned int	link;
	char			*owner;
	char			*team;
	long long int	size;
	char			*time;
	long int 		*pure_time;
	char			*path;
	char			*name;
	char			*att;
	char			*ACL;
	long long int	blocks;
	long long int 	sort;
}					t_info;	

typedef struct		s_error
{
	char			*name;
	char			*message;
	long long int	sort;
}					t_error;

typedef struct		s_sizeprint
{
	size_t			perm;
	size_t			link;
	size_t			owner;
	size_t			team;
	size_t			size;
	size_t			time;
}					t_sizeprint;

t_option			*ft_parse_option(char **argv, t_option *option);

void				ft_command(int argc, char **argv, t_option *option);

void				ft_scroll_dir(t_option *option, t_stack **head);

void				ft_scroll_dir_a(t_option *option, t_stack **head);

void				ft_insert_sort(t_dlist **begin_list,
		int (*cmp)(const void *key1, const void *key2));

void				ft_insert_sort_2(t_dlist **begin_list);

void				ft_insert_sort_3(t_dlist **begin_list, 
		int (*cmp)(const void *key1, const void *key2));

t_info				*ft_get_info(char *s, t_option *option);

t_error				*ft_set_error(char *name, char *message);

int					ft_check_dir(char *argv, t_dlist **list_error, t_option *option);

void				ft_print_error(t_dlist **list_error);

void				ft_print_one_error(t_dlist **list_error);

t_dlist				*ft_create_info(void *data);

t_dlist				*ft_create_error(void *data);

int					ft_stralphcmp(const void *s1, const void *s2);

int					main(int argc, char **argv);

long long int		ft_gen_time(long int *time);

void				ft_print_dir(t_option *option, t_dlist **list_files);

char				*ft_strsub_lim(char *s);

char				*ft_setACL(char *s);

#endif
