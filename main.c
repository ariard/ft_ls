#include "ft_ls.h"
#include <stdio.h>


t_option			*ft_init_option(void)
{
	t_option		*option;

	option = ft_memalloc(sizeof(t_option));
	option->mode = 0;
	option->R = 0;
	option->a = 0;
	option->r = 0;
	option->sort = 0;
	option->S = 0;
	option->G = 0;
	option->g = 0;
	option->e = 0;
	option->aro = 0;
	option->p = 0;
	option->h = 0;
	option->o = 0;
	option->T = 0;
	option->n = 0;
	option->F = 0;
	option->i = 0;
	return (option);
}

int				main(int argc, char **argv)
{
	t_option	*option;
	int			i;

	i = 0;
	option = ft_init_option();
	if (argc > 1)
	{
		if (argv[1][0] == '-')
			ft_parse_option(argv, option);
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
