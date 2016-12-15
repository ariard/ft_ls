/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 19:52:29 by ariard            #+#    #+#             */
/*   Updated: 2016/12/16 00:17:14 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_dlist
{
	struct s_dlist	*next;
	struct s_dlist	*previous;
	void			*data;
	int				key;
}					t_dlist;

typedef t_dlist		t_stack;

void				*ft_memset(void *b, int c, size_t len);

void				ft_bzero(void *s, size_t n);

void				*ft_memcpy(void	*dst, const void *src, size_t n);

void				*ft_memccpy(void *dst, const void *src, int c, size_t n);

void				*ft_memmove(void *dest, const void *src, size_t size);

void				*ft_memchr(const void *s, int c, size_t n);

int					ft_memcmp(const void *s1, const void *s2, size_t n);

size_t				ft_intlen(long long int d);

size_t				ft_unsintlen(unsigned long long int d);

size_t				ft_strlen(const char *s);

size_t				ft_strlenchr(const char *s, char c);

char				*ft_strdup(const char *s1);

char				*ft_strcpy(char *dst, const char *src);

char				*ft_strncpy(char *dst, const char *src, size_t len);

char				*ft_strchrcpy(char *dst, const char *src, char c);

char				*ft_strcat(char *s1, const char *s2);

char				*ft_strncat(char *s1, const char *s2, size_t n);

size_t				ft_strlcat(char *dst, const char *src, size_t size);

char				*ft_strchr(const char *s, int c);

char				*ft_strrchr(const char *s, int c);

void				ft_strrev(char *s);

char				*ft_strstr(const char *big, const char *little);

char				*ft_strnstr(const char *big, const char *little,
	size_t len);

int					ft_strcmp(const char *s1, const char *s2);

int					ft_strncmp(const char *s1, const char *s2, size_t n);

int					ft_atoi(const char *str);

int					ft_atoi_base(char *s, size_t size_base);

int					ft_isalpha(int c);

int					ft_isdigit(int c);

int					ft_isalnum(int c);

int					ft_isascii(int c);

int					ft_isprint(int c);

int					ft_toupper(int c);

int					ft_tolower(int c);

void				*ft_memalloc(size_t size);

void				ft_memdel(void	**ap);

char				*ft_strnew(size_t size);

void				ft_strdel(char **as);

void				ft_strclr(char *as);

void				ft_striter(char *s, void (*f)(char *));

void				ft_striteri(char *s, void (*f)(unsigned int, char *));

char				*ft_strmap(char const *s, char (*f)(char));

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

int					ft_strequ(char const *s1, char const *s2);

int					ft_strnequ(char const *s1, char const *s2, size_t n);

char				*ft_strsub(char const *s, unsigned int start, size_t len);

char				*ft_strjoin(char const *s1, char const *s2);

char				*ft_strtrim(char const *s);

char				*ft_strsub(char const *s, unsigned int start, size_t len);

char				**ft_strsplit(char const *s, char c);

char				*ft_itoa(int n);

char				*ft_itoa_base(unsigned long long int nb,
		size_t size_base, char new[]);

int					ft_putchar(char c);

int					ft_putstr(char const *s);

int					ft_putstrn(char const *s, int n);

void				ft_putendl(char const *s);

void				ft_putnbr(long long int n);

void				ft_putunsnbr(unsigned long long n);

void				ft_putchar_fd(char c, int fd);

void				ft_putstr_fd(char const *s, int fd);

void				ft_putendl_fd(char const *s, int fd);

void				ft_putnbr_fd(int n, int fd);

t_list				*ft_lstnew(void const *content, size_t content_size);

void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));

void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));

void				ft_lstadd(t_list **alst, t_list *new);

void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

t_dlist				*ft_create_elem(void *data);

void				ft_list_push_back(t_dlist **begin_list, void *data);

void				ft_list_push_front(t_dlist **begin_list, void *data);

int					ft_list_size(t_dlist **begin_list);

t_dlist				*ft_list_last(t_dlist **begin_list);

t_dlist				*ft_list_push_params(int argc, char **argv);

void				ft_list_clear(t_dlist **begin_list);

void				ft_list_reverse(t_dlist **begin_list);

void				ft_list_foreach(t_dlist **begin_list, void (*f)(void *));

t_dlist				*ft_list_find(t_dlist **begin_list, void *data_ref,
	int (*cmp)());

void				ft_list_cycle(t_dlist **begin_list);

void				ft_list_rem_front(t_dlist **begin_list);

void				ft_list_swap(t_dlist **begin_list, t_dlist *node1, t_dlist *node2);

t_dlist				*ft_list_rem(t_dlist **begin_list, t_dlist *node);

void				ft_list_ins(t_dlist **begin_list, 
		t_dlist *node1, t_dlist *node2);

void				ft_stack_pop(t_stack **stack);

void				ft_stack_push(t_stack **stack, void *data);

int					ft_recursive_power(int nb, int power);

int					ft_putwchar(wchar_t w);

int					ft_putwstr(wchar_t *w);

size_t				ft_sizewchar(wchar_t w);

size_t				ft_strwlen(wchar_t *w);

void				ft_list_push_back_special(t_dlist **begin_list, void *data,
		t_dlist *(*create)(void *));

#endif
