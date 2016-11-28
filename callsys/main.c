#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include <stdlib.h>
#include <grp.h>
#include <uuid/uuid.h>
#include <time.h>
#include <string.h>

int		main(int argc, char **argv)
{
	struct stat 	*buf;
	struct passwd	*uid;
	struct group	*gid;
	char			*ti;
	char			*s;
	char			*perm;

	(void)argc;
	if (argc != 2)
		return (1);
	buf = (struct stat *)malloc(sizeof(struct stat));
	stat(argv[1], buf);
	uid = getpwuid(buf->st_uid);
	gid = getgrgid(buf->st_gid);
	ti = ctime(&buf->st_mtimespec.tv_sec);
	perm = (char *)malloc(sizeof(char) * 11);

	if ((S_ISDIR(buf->st_mode) ? 'd' : '-') == '-')
	{
		s = "Fichier";
		strcpy(perm, "-");
	}
	else 
	{
		s = "Dossier";
		strcpy(perm, "d");
	}
	if (((buf->st_mode & S_IRUSR) ? 'r' : '-') == 'r')
		strcat(perm, "r");
	else
		strcat(perm, "-");
	if (((buf->st_mode & S_IWUSR) ? 'w' : '-') == 'w')
		strcat(perm, "w");
	else
		strcat(perm, "-");
	if (((buf->st_mode & S_IXUSR) ? 'x' : '-') == 'x')
		strcat(perm, "x");
	else
		strcat(perm, "-");
	if (((buf->st_mode & S_IRGRP) ? 'r' : '-') == 'r')
		strcat(perm, "r");
	else
		strcat(perm, "-");
	if (((buf->st_mode & S_IWGRP) ? 'w' : '-') == 'w')
		strcat(perm, "w");
	else
		strcat(perm, "-");
	if (((buf->st_mode & S_IXGRP) ? 'x' : '-') == 'x')
		strcat(perm, "x");
	else
		strcat(perm, "-");
	if (((buf->st_mode & S_IROTH) ? 'r' : '-') == 'r')
		strcat(perm, "r");
	else
		strcat(perm, "-");
	if (((buf->st_mode & S_IWOTH) ? 'w' : '-') == 'w')
		strcat(perm, "w");
	else
		strcat(perm, "-");
	if (((buf->st_mode & S_IXOTH) ? 'x' : '-') == 'x')
		strcat(perm, "x");
	else
		strcat(perm, "-"); 

	
/*	printf("Nom : %s\n", argv[1]);
	printf("Type : %s\n", s); 
	printf("Modes : %s\n", perm);
	printf("Nombre de liens : %u\n", buf->st_nlink);
	printf("Proprietaire : %s\n", uid->pw_name);
	printf("Groupe : %s\n", gid->gr_name);
	printf("Taille : %lld\n", buf->st_size); 
	printf("Date de derniere modification : %s\n", ti);
*/
	printf("%s  %u %s  %s  %lld %s %s", perm, buf->st_nlink, uid->pw_name, gid->gr_name, buf->st_size, ti, argv[1]);

	return (0);
}
