#ifndef	FT_LIST_H
# define FT_LIST_H
# include <stdlib.h>

typedef struct		s_dlist
{
	struct s_dlist	*next;
	struct s_dlist	*previous;
	void			*data;
}					t_dlist;

#endif
