#include <stdio.h>
//! Получив через аргументы командной строки имена двух файлов, откроет первый на чтение, второй на запись и запишет во второй первые десять строк из первого, если строк окажется меньше, файл окажется просто скопирован
//! fgetc  ввод символов для типа FILE* как getchar
//! fputc  вывод символов для типа FILE* как putchar

int main(int argc, char **argv)
{
	FILE *from, *to;
	int c, lnum;
	lnum = 1;
	if (argc < 3)
	{
		fprintf(stderr, "Too few arguments\n");
		return 1;
	}
	from = fopen(argv[1], "r");
	if (!from)
	{
		perror(argv[1]);
		return 2;
	}
	to = fopen(argv[2], "w");
	if (!to)
	{
		perror(argv[2]);
		return 3;
	}
	while (lnum <= 10 && (c = fgetc(from)) != EOF)
	{
		fputc(c, to);
		if (c == '\n')
		{
			lnum++;
		}
	}
	return 0;
}