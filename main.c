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
		return (0);
	if (option->sort)
		printf("%c-", option->sort);
	if (option->mode)
		printf("%c-", option->mode);
	if (option->a)
		printf("%c-", option->a);
	if (option->R)
		printf("%c-", option->R);
	if (option->r)
		printf("%c-", option->r);
	if (option->aro)
		printf("%c-", option->aro);
	if (option->n)
		printf("%c-", option->n);
	if (option->S)
		printf("%c-", option->S);
	printf("\n");
	return (0);
}
