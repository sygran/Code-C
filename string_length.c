#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>

/* int string_length(const char *str)  //! Первый вариант функции возвращающую конец строки.
{
	int i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return i;
} */

/* int string_length(const char *str) //! Second 
{
	int i;
	for (i = 0; str[i]; i++)
	{
	}
	return i;
} */

/* //! копирует строку в отведённую область памяти  Первый вариант
void string_copy(char *dest, const char *src) //! 1) куда 2) откуда. Ничего не возвращает
{
	int i;
	for (i = 0; src[i]; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = 0;
} */

/* //! Второй вариант копирования
void string_copy(char *dest, const char *src)
{
	for (; *src; dest++, src++)
		*dest = *src;
	*dest = 0;
}*/

int string_length(const char *str)
{
	const char *p;
	for (p = str; *p; p++)
	{
	}
	return p - str;
}

int main()
{

	return 0;
}