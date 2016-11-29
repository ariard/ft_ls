#include <stdio.h>
#include <dirent.h>

int		main(void)
{
	DIR	*ds;
	struct dirent *lu;

	ds = opendir("hello");
	while ((lu = readdir(ds)))
		printf("%s\n", lu->d_name);
	printf("%d", closedir(ds));
	return (0);
}
