/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 13:39:51 by ariard            #+#    #+#             */
/*   Updated: 2016/12/23 14:29:16 by ariard           ###   ########.fr       */
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
# include <sys/ioctl.h>
# include <sys/time.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <time.h>
# include <errno.h>
# include <unistd.h>

# define RED "\e[31m"
# define BLUE "\e[34m"
# define MAG "\e[35m"
# define CYAN "\e[36m"
# define GREEN "\e[32m"
# define BLACK "\e[30m"
# define YELLOW "\e[33m"
# define DEF "\e[39m"
# define B_DEF "\e[49m"
# define B_RED "\e[41m"
# define B_BLACK "\e[40m"
# define B_BLUE "\e[44m"
# define B_MAGENTA "\e[45m"
# define B_CYAN "\e[46m"
# define B_GREEN "\e[42m"
# define B_YELLOW "\e[43m"

typedef struct		s_option
{
	char	mode;
	char	rr;
	char	a;
	char	r;
	char	t;
	char	sort;
	char	ss;
	char	gg;
	char	g;
	char	e;
	char	aro;
	char	p;
	char	d;
	char	o;
	char	f;
	char	x;
	int		isindev;
	int		nb;
	char	*exe;
}					t_option;

typedef struct		s_info
{
	char			*perm;
	unsigned int	link;
	char			*owner;
	char			*team;
	long long int	size;
	dev_t			dev;
	char			*time;
	long int		pure_time;
	char			*path;
	char			*name;
	char			*att;
	char			*acl;
	long long int	blocks;
	long long int	sort;
	char			*error;
}					t_info;

typedef struct		s_error
{
	char			*name;
	char			*message;
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

typedef struct		s_col
{
	int				block;
	int				lines;
	int				cp;
	int				max;
	int				nb;
	int				size;
}					t_col;

int					ft_parse_option(char **argv, t_option *option);

void				ft_command(int argc, char **argv, t_option *option);

void				ft_scroll_dir(t_option *option, t_stack **head);

void				ft_scroll_dir_a(t_option *option, t_stack **head);

void				ft_scroll_dir_d(t_option *option, t_stack **head);

void				ft_insert_sort(t_dlist **begin_list,
		int (*cmp)(const void *key1, const void *key2));

void				ft_insert_sort_2(t_dlist **begin_list);

void				ft_insert_sort_3(t_dlist **begin_list,
		int (*cmp)(const void *key1, const void *key2));

t_info				*ft_get_info(char *s, t_option *option);

t_error				*ft_set_error(char *name, char *message);

int					ft_check_dir(char *argv, t_dlist **list_error,
		t_option *option, t_dlist **list_files);

void				ft_print_error(t_dlist **list_error);

void				ft_print_one_error(t_dlist **list_error);

t_dlist				*ft_create_info(void *data);

t_dlist				*ft_create_error(void *data);

int					ft_stralphcmp(const void *s1, const void *s2);

int					main(int argc, char **argv);

long long int		ft_gen_time(long int *time);

void				ft_print_dir(t_option *option, t_dlist **list_files);

char				*ft_strsub_lim(char *s);

char				*ft_setacl(char *s, t_option *option);

void				ft_space(char *buf, size_t len_max, char *s);

void				ft_join_owner(char *buf, t_info *info,
		t_sizeprint *sizeprint, t_option *option);

void				ft_join_team(char *buf, t_info *info,
		t_sizeprint *sizeprint, t_option *option);

void				ft_join_name(char *buf, t_info *info, t_option *option);

void				ft_print_path(char *s);

void				ft_sort(t_option *option, t_dlist **list_files);

void				ft_print_files(t_dlist **list_files, t_option *option);

int					ft_get_column(void);

int					ft_get_max(t_dlist **list_files);

int					ft_get_less(int col, int lines, int size);

int					ft_get_block(t_dlist **list_files, int col, int max);

int					ft_get_lines(t_dlist **list_files, int col, int max);

void				*ft_get_next(t_dlist *node, int nb, int block, int size);

void				*ft_get_special(t_dlist *node, int nb, int block, int size);

char				*ft_set_date(long int time);

void				ft_put_color(t_info *info);

void				ft_set_sort(t_info *info, t_option *option);

void				ft_set_time(struct stat *buf, t_info *info,
		t_option *option);

void				ft_check_dir_2(t_info *info, int alone);

char				*ft_setatt(char *s, t_option *option);

void				ft_join_size(char *buf, t_info *info,
		t_sizeprint *sizeprint, t_option *option);

char				*ft_set_perm(struct stat *buf);

void				ft_generate_option1(t_option *option, char *value);

void				ft_solve_conflict(t_option *option);

void				ft_print_column2(t_col *col, t_dlist *tmp,
		t_option *option);

void				ft_get_size2(t_sizeprint *sizeprint, t_info *info);

void				ft_set_others(t_info *info, t_option *option, char *buf);

void				ft_just_print_color(t_info *info, t_sizeprint *sizeprint,
		t_option *option);

void				ft_print_dir_error(t_info *info);

#endif
