#include <stdio.h>
struct item //! Linked List
{
	int data;
	struct item *next;
};

int is_negative(int x)
{
	return x < 0;
}
int is_even(int x)
{
	return x % 2 == 0;
}
int is_div7(int x)
{
	return x % 7 == 0;
}

//! Удаление из заданного списка всех элементов удовлетворяющих определённому условию
//! Версия из файла LinkedList.c
struct item **pcur;
void delete_negatives_from_int_list(struct item **pcur)
{
	while (*pcur)
	{
		if ((*pcur)->data < 0)
		{
			struct item *tmp = *pcur; //закидываем в tmp адрес *pcur
			*pcur = (*pcur)->next;	  //в *pcur присваиваем следующий адрес, тоесть как бы делаем второй елемент первым
			free(tmp);				  // очищаем темп, тем самым удаляя первый елемент
		}
		else
		{
			pcur = &(*pcur)->next;
		}
	}
}
//! Переписываем функцию, добавив в её заголовок параметр, указатель на функцию, задающий критейрий
//! Вместо сравнения с нулём в операторе If подставили вызов этой функции от числа из текущего элемента списка
//! Удаление из заданного списка всех элементов удовлетворяющих определённому условию

void delete_negatives_from_int_list(struct item **pcur, int (*crit)(int))
{
	while (*pcur)
	{
		if ((*crit)((*pcur)->data))
		{
			struct item *tmp = *pcur; //закидываем в tmp адрес *pcur
			*pcur = (*pcur)->next;	  //в *pcur присваиваем следующий адрес, тоесть как бы делаем второй елемент первым
			free(tmp);				  // очищаем темп, тем самым удаляя первый елемент
		}
		else
		{
			pcur = &(*pcur)->next;
		}
	}
}

int main()
{
	struct item *first = NULL, *last = NULL, *tmp;
	delete_negatives_from_int_list(&first, &is_negative); //! Теперь можно удалить из этого списка все отрицательные числа вызовом
	delete_negatives_from_int_list(&first, &is_div7);	  //! Удалить все числа делящиеся без остатка на семь
}