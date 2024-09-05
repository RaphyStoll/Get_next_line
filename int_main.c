#include "get_next_line.h"

int main()
{
	int fd = open("text.txt", O_RDONLY);
	if(fd == -1)
	{
		printf("Erreur lors de l'ouverture du fichier\n");
		return 1;
	}
	printf("fd = %d\n",fd);
	while(1)
	{
		char *line = get_next_line(fd);
		printf("Données lues : %s\n", line);
		if(line == NULL)
			{
				break;
			}
		//! si pas free = leaks car pointeur ecraser chaque boucle et plu possible de le free apres
		free(line);
	}
	return 0;
}