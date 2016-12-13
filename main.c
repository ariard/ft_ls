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
