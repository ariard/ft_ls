#include "ft_ls.h"

int		main(int argc, char **argv)
{
	int		listlen;
	int		valuelen;
	char 	list[10000];
	char	value[10000];
	int		ns;

	(void)argc;
	listlen = listxattr(argv[1], list, 10000, 0);
	ns = 0;
	valuelen = 0;
	while (ns < listlen)
	{
		printf("	name = %s", &list[ns]);
		valuelen = getxattr(argv[1], &list[ns], value, 10000, 0, 0);
		printf("{%s}	value = %d\n", value, valuelen);
		ns += strlen(&list[ns] ) + 1;
	}
}
