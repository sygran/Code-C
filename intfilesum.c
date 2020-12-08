#include <stdio.h>

void intfilesum(FILE *f, int *sum, int *count)
{
	int n;
	*count = 0;
	*sum = 0;
	while (fscanf(f, "%d", &n) == 1)
	{
		*sum += n;
		*count++;
	}
}

//! Читает строку из f1 после заиисывает в поток f2 эти же строки обрамленные в квадратные скобки. Строкам позволяется иметь длину не более 50 символов.
void string50(FILE *f1, FILE *f2)
{
	char buf[51];
	while (fgets(buf, sizeof(buf), f1))
	{
		int i;
		int nlpos = -1;
		for (i = 0; i < sizeof(buf) && buf[i]; i++)
		{
			if (buf[i] == '\n')
			{
				nlpos = i;
				break;
			}
		}
		if (nlpos == -1)
		{
			int c;
			fputc('\n', f2);
			while ((c = fgetc(f1)) != EOF && c != '\n')
			{
			}
		}
		else
		{
			buf[nlpos] = '\n';
			fprintf(f2, "[%s]\n", buf);
		}
	}
}

int main()
{
}