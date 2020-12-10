#include <stdlib.h>

struct item //! Linked List
{
	int data;
	struct item *next;
};

struct item *
int_array_to_list(int *arr, int len) //! функция заносит елементы в конец списка
{
	struct item *first = NULL, *last = NULL, *tmp;
	int i;
	for (i = 0; i < len; i++)
	{
		tmp = malloc(sizeof(struct item));
		tmp->data = arr[i];
		tmp->next = NULL;
		if (last)
		{
			last->next = tmp;
			last = last->next;
		}
		else
		{
			first = last = tmp;
		}
	}
	return first;
}

struct item *int_array_to_list_begin(int *arr, int len) //! функция добавляет елементы в начало списка
{
	struct item *first = NULL, *tmp;
	int i;
	for (i = len - 1; i >= 0; i--)
	{
		tmp = malloc(sizeof(struct item));
		tmp->data = arr[i];
		tmp->next = first;
		first = tmp;
	}
	return first;
}

struct item *int_array_to_list_second(int *arr, int len)
{
	struct item *tmp;
	if (!len)
	{
		return NULL;
	}
	tmp = malloc(sizeof(struct item));
	tmp->data = *arr;
	tmp->next = int_array_to_list_second(arr + 1, len - 1);
	return tmp;
}
//! Функция, вычисляет сумму всех елементов списка
int int_list_sum(const struct item *lst)
{
	int sum = 0;
	const struct item *tmp;
	for (tmp = lst; tmp; tmp = tmp->next)
	{
		sum += tmp->data;
	}
	return sum;
}
//! Тоже самое но короче
int int_list_sum(const struct item *lst)
{
	int sum = 0;
	for (; lst; lst = lst->next)
	{
		sum += lst->data;
	}
	return sum;
}
//! Тоже самое но с рекурсией и ещё короче
int int_list_sum(const struct item *lst)
{
	if (lst)
	{
		return lst->data + int_list_sum(lst->next);
	}
	else
	{
		return 0;
	}
}
//! one-liner function
int int_list_sum(const struct item *lst)
{
	return lst ? lst->data + int_list_sum(lst->next) : 0;
}

//! Два решения удаления списка
void delete_int_list(struct item *lst)
{
	while (lst)
	{
		struct item *temp = lst;
		lst = lst->next;
		free(temp);
	}
}

void delete_int_list(struct item *list)
{
	while (list)
	{
		struct item *temp = list->next;
		free(list);
		list = temp;
	}
}
//! Тоже самое через рекурсию
void delete_int_list(struct item *lst)
{
	if (lst)
	{
		delete_int_list(lst->next);
		free(lst);
	}
}
//! Удаление из заданного списка всех элементов удовлетворяющих определённому условию
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
//! Вызываем функцию выше
//!      delete delete_negatives_from_int_list(&first);
//! Тот же вариант только через рекурсию
void delete_negatives_from_int_list(struct item **pcur)
{
	if (!*pcur)
	{
		return;
	}
	delete_negatives_from_int_list(&(*pcur)->next);
	if ((*pcur)->data < 0)
	{
		struct item *tmp = *pcur;
		*pcur = (*pcur)->next;
		free(tmp);
	}
}