#include <stdio.h>
#include <dirent.h>
#include <inttypes.h>
#include <sys/types.h>
#include <sys/dir.h>
#include <sys/stat.h>
#include <time.h>
#include <stdlib.h>

#include <string.h>
#include <strings.h>

void	*ft_memalloc(size_t size)
{
	void *s;

	if ((s = (malloc(size))) == NULL)
		return (NULL);
	bzero(s, size);
	return (s);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	char	*joined;
	size_t	i;
	size_t	i2;

	i = 0;
	i2 = 0;
	if (!(s1) || !(s2))
		return (NULL);
	if (!(joined = (char *)ft_memalloc(sizeof(char) * (strlen(s1) + \
						strlen(s2) + 2))))
		return (NULL);
	while (s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	while (i2 < strlen(s2))
	{
		joined[i] = s2[i2];
		i++;
		i2++;
	}
	joined[i] = '\0';
	return (joined);
}

int main(int argc, char **argv)
{
	DIR *rep = NULL;
	long long tt = 0, tt2 = 0;
	struct dirent *new;
	struct stat buf;
	struct stat buf2;
	char *path;

	rep = opendir(argv[1]);
	if (rep)
	{
		printf("ouverture du directory : |%s|\n", argv[1]);
		new = readdir(rep);
		while (new)
		{
			printf("Name : |%s|, type : |%jd|\n", new->d_name, (intmax_t)new->d_type);
			path = ft_strjoin(argv[1], new->d_name);
			lstat(path, &buf2);
			tt2 += (long long)(buf2.st_blocks);
			printf("total here: %lld |%s|\n", tt2, path);
			new = readdir(rep);
			free(path);
		}
		printf("\ntotal = %d, %lld", tt, tt2);
		closedir(rep);
	}
	else
		printf("Echec de l'ouverture du fichier /!\\\n");
	return (0);
}
