#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <term.h>
#include <curses.h>


int     voir_touche(void)
{
	char     buffer[3];

	while (1)
	{
		read(0, buffer, 3);
		printf(">> %d.%d.%d <<\n", buffer[0], buffer[1], buffer[2]);
		if (buffer[0] == 27)
			printf("C'est une fleche !\n");
		else if (buffer[0] == 4)
		{
			printf("Ctlr+d, on quitte !\n");
			return (0);
		}
	}
	return (0);
}

int              main(int ac, char **av, char **envp)
{
	char           *name_term;
	struct termios term;
	struct termios term2;

	if ((name_term = getenv("TERM")) == NULL)
	{
		printf("erreur getenv\n");
		return (-1);
	}
	if (tgetent(NULL, name_term) == ERR)
	{
		printf("erreur tgetent\n");
		return (-1);
	}
	// remplis la structure termios des possibilités du terminal.
	if (tcgetattr(0, &term) == -1)
		return (-1);
	term.c_lflag &= ~(ICANON); // Met le terminal en mode canonique.
	term.c_lflag &= ~(ECHO); // les touches tapées ne s'inscriront plus dans le terminal
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (-1);
	voir_touche();
	if (tcgetattr(0, &term2) == -1)
		   return (-1);
	term2.c_lflag = (ICANON | ECHO);
	if (tcsetattr(0, 0, &term2) == -1)
		   return (-1);
	return (0);
}
