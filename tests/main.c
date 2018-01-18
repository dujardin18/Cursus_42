#include <stdio.h>
#include <dirent.h>
#include <inttypes.h>
#include <sys/types.h>
#include <sys/dir.h>

int main(int argc, char **argv)
{
	DIR *rep = NULL;
	struct dirent *new;
	
	rep = opendir(argv[1]);
	if (rep)
	{
		printf("ouverture du directory : |%s|\n", argv[1]);
		new = readdir(rep);
		while (new)
		{
			printf("Name : |%s|, type : |%jd|\n", new->d_name, (intmax_t)new->d_type);
			new = readdir(rep);
		}
		closedir(rep);
	}
	else
		printf("Echec de l'ouverture du fichier /!\\\n");
	return (0);
}
