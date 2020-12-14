#if 0 //! this implementattion was too slow
void sort (int *a, int n)
{
	/* ..... */
}
#endif

#define USE_INDEX_IN_STRING_COPY 1
#if USE_INDEX_IN_STRING_COPY
void string_copy(char *dest, const char *src)
{
	int i;
	for (i = 0; src[i]; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = 0;
}
#else
void string_copy(char *dest, const char *src)
{
	for (; *src; dest++, src++)
	{
		*dest = *src;
	}
	*dest = 0;
}
#endif

#if defined(FOR_PETROV)
/* Код для Петрова */
#elif defined(FOR_SIDOROV) //! Можно использовать #elifdef and elifndef
/* Код для Сидорова */
#else
/* Код для остальных */
#endif