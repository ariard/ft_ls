#include <stdio.h>
#include "../../ft_ls.h"

int		main(int argc, char **argv)
{
	DIR *ds;
	char *s;

	(void)argc;
	ds = opendir(argv[1]);
	if (ds == NULL)
	{
		s = strerror(errno);
		printf("%s", s);
	{
	return (0);
}
