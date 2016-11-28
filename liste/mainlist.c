#include <stdio.h>
#include "ft_list.h"

t_dlist			*ft_create_elem(void *data)
{
	t_dlist		*node;

	node = (t_dlist *)malloc(sizeof(t_dlist));
   	if(!node)
		return (NULL);	
	if (node)
	{
		node->data = data;
		node->next = NULL;
		node->previous = NULL;
	}
	return (node);
}

void			ft_list_push_back(t_dlist **begin_list, void *data)
{
	t_dlist		*node;
	t_dlist		*tmp;
	t_dlist		*tmp2;

	node = ft_create_elem(data);
	if (node)
	{
		if (*begin_list)
		{
			tmp = *begin_list;	
			while (tmp->next)
				tmp = tmp->next;
			tmp2 = tmp;
			tmp->next = node;
			node->previous = tmp2;
		}
		else
			*begin_list = node;
	}
}

t_dlist		*ft_list_last(t_dlist *begin_list)
{
	if (begin_list)
	{
		while (begin_list->next)
			begin_list = begin_list->next;
	}
	return (begin_list);
}

/*void			ft_list_reverse(t_dlist **begin_list)
{
	t_dlist		*current;
	t_dlist		*tmp1;
	t_dlist		*tmp2;

	current = *begin_list;
	while (current)
	{
		tmp1 = current->next;
		current->next = current->previous;
		current->previous = current;
		tmp2 = current;
		current = tmp1;
	}
	*begin_list = tmp2;
}*/

void		ft_make_cycle(t_dlist **begin_list)
{
	t_dlist *tmp;

	tmp = ft_list_last(*begin_list);
	tmp->next = *begin_list;
	(*begin_list)->previous = tmp;
}

int			main(void)
{
	char	*a;
	char	*b;
	char	*c;
	char	*d;
	char	*e;
	char	*f;
	int		i;
	t_dlist	*list;
	t_dlist	*tmp;

	a = "La rue assourdissante autour de moi hurlait";
	b = "Longue, mince, en grand deuil, douleur majestueuse";
	c = "Une femme passa, d'une main fastueuse";
	d = "Soulevant, balançant le feston et l'ourlet";
	e = "Agile et noble, avec sa jambe de statue";
	f = "Moi, je buvais, crispé comme un extravagant";
	i = 6;

	list = NULL;
	ft_list_push_back(&list, a);
	ft_list_push_back(&list, b);
	ft_list_push_back(&list, c);
	ft_list_push_back(&list, d);
	ft_list_push_back(&list, e);
	ft_list_push_back(&list, f);

	tmp = list;
	ft_make_cycle(&list);
	while (tmp)
	{
		printf("%s\n", tmp->data);
		tmp = tmp->next;
	}
/*	printf("\n\n");
	ft_list_reverse(&list);
	tmp = list;
	while (tmp)
	{
		printf("%s\n", tmp->data);
		tmp = tmp->next;
	}	*/
	return (0);
}
