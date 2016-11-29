#include "ft_ls.h"
#include <stdio.h>

int				main(int argc, char **argv)
{
	t_option	*option;

	(void)argc;

	option = ft_memalloc(sizeof(option));
	if (argv[1][0] == '-')
		option = ft_parse_option(argv);
	if (option == NULL)
	{
		printf("usage: ls [-laRtr][file ...]\n");
		return (0);
	}
	if (option->l)
		printf("%d-", (int)option->l);
	if (option->a)
		printf("%d-", (int)option->a);
	if (option->R)
		printf("%d-", (int)option->R);
	if (option->t)
		printf("%d-", (int)option->t);
	if (option->r)
		printf("%d-", (int)option->r);
	printf("\n");
	return (0);
}
