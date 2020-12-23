#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int pid;
	pid = fork();
	if (pid == -1) // Ошибка порождения процесса
	{
		perror("fork");
		exit(1);
	}
	if (pid == 0) // Порожденный процесс
	{
		execlp("ls", "ls", "-l", "-a", "/var", NULL);
		perror("ls"); //exec вернул управление -> ошибка
		exit(1);	  // завершаем процесс с кодом неуспеха
	}
	// родительский процесс
	wait(NULL); // дожидаемся завершения порожденного процесса, заодно убираем зомби

	printf("Ok\n");
	return 0;
}