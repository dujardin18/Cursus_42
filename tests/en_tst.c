#include <stdio.h>

int main(int argc, char **argv, char **envp)
{
	int i = 0;
	char buf[1024];

	while (envp[i])
	{
		printf("|%s| <-- %d\n", envp[i], i);
		i++;
	}
	getcwd(buf, 1024);
	printf(" >>>>>>>>>>> %s", buf);
	return (0);
}
