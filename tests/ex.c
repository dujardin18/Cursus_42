#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv, char **envp)
{
	pid_t	father;
	int		tmp;

	father = fork();
	if (father == 0)
	{
		tmp = execve("/bin/ls", argv, envp);
		printf("%d\n", tmp);
	}
	if (father > 0)
	{
		wait(&father);
		printf("Here is the father !\n");
	}
}
