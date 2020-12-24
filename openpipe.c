#include <signal.h>
#include <errno.h>

int main()
{
	int fd[2];
	pipe(fd);		 // создаем канал для связи
	if (fork() == 0) // процесс для выполнения ls -lR
	{
		close(fd[0]);					  // читать из канала не нужно
		dup2(fd[1], 1);					  // станд. вывод - в канал
		close(fd[1]);					  // fd[1] больше не нужен
		execlp("ls", "ls", "-lR", NUILL); // запускаем ls -lR
		perror("ls");					  // не получилось, сообщаем об ошибке
		exit(1);
	}
	if (fork() == 0) // процесс для выполнения grep
	{
		close(fd[1]);						// писать в канал не нужно
		dup2(fd[0], 0);						// станд. ввод - из канала
		close(fd[0]);						// fd[0] больше не нужен
		execlp("grep", "grep", "^d", NULL); // запускаем grep
		perror("grep");						// не получилось, сообщаем об ошибке
		exit(1);
	}
	// в родительском процессе закрываем оба конца канала
	close(fd[0]);
	close(fd[1]);
	wait(NULL); // дожидаемся завершения потомков
	wait(NULL);
	return 0;
}