#include <stdio.h>

int main()
{
	int pid, status;
	pid = fork();
	if (pid == 0) // Порожденный процесс
	{
		int fd = open("flist", O_GREAT | O_WRONLY | O_TRUNC, 0666);
		if (pid = -1)
		{
			perror("flist");
			exti(1);
		}
		dup2(fd, 1);
		close(fd);
		execlp("ls", "ls", "-l", "-a", "-R", "/", NULL);
		perror("ls");
		exit(1);
	}

	wait(&status);
	if (!WIFEXITED(status) || WEXITSTATUS(status) != 0)
	{
		// Обработка ошибки
	}
}