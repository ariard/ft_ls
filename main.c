#include "ft_ls.h"
#include <stdio.h>

int				main(int argc, char **argv)
{
	t_option	*option;
	int			i;

	i = 0;
	option = ft_memalloc(sizeof(option));
	if (argc > 1)
	{
		if (argv[1][0] == '-')
			option = ft_parse_option(argv);
		if (option == NULL)
			return (0);
		if (option)
		{
			argv++;
			while (*argv && **argv == '-')
				argv++;
		}
	} 
	ft_command(argc, argv, option);
	return (0);
}


/*	test parsing option
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
	*/
