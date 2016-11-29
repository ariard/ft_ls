#include "ft_ls.h"
#include <stdio.h>

int				main(int argc, char **argv)
{
	t_option	*option;

	(void)argc;

	option = ft_memalloc(sizeof(option));
	if (argv[1][0] == '-')
		option = ft_parse_option(argv);

	printf("%d\n", (int)option->l);
	printf("%d\n", (int)option->a);
	printf("%d\n", (int)option->R);
	printf("%d\n", (int)option->t);
	printf("%d\n", (int)option->r);
	printf("%d\n", (int)option->U);

	return (0);
}
