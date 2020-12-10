#include <stdlib.h>

struct dbl_item
{
	double data;
	struct dbl_item *prev, *next;
};

int main()
{
	struct dbl_item *first = NULL, *last = NULL;
	struct dbl_item *current = NULL, *tmp;
	int x;
	//!Внесение в начало списка
	tmp = malloc(sizeof(struct dbl_item));
	tmp->data = x;
	tmp->prev = NULL;
	tmp->next = first;
	if (first)
	{
		first->prev = tmp;
	}
	else
	{
		last = tmp;
	}
	first = tmp;

	//! Внесение в конец списка
	tmp = malloc(sizeof(struct dbl_item));
	tmp->data = x;
	tmp->prev = last;
	tmp->next = NULL;
	if (last)
	{
		last->next = tmp;
	}
	else
	{
		first = tmp;
	}
	last = tmp;

	//! Изъятие первого элемента двусвязного списка
	if (first) // Проверка обязательна
	{
		tmp = first;
		first = first->next;
		if (first)
		{
			first->prev = NULL;
		}
		else // Список опустел
		{
			last = NULL;
		}
		free(tmp);
	}

	//! Изъятие последнего элемента
	if (last)
	{
		tmp = last;
		last = first->prev;
		if (last)
		{
			last->next = NULL;
		}
		else
		{
			first = NULL;
		}
		free(tmp);
	}

	//! Вставка перед текущим элементом
	tmp = malloc(sizeof(struct dbl_item));
	tmp->data = x;
	tmp->next = current;
	tmp->prev = current->prev;
	current->prev = tmp;
	if (tmp->prev)
	{
		tmp->prev->next = tmp;
	}
	else
	{
		first = tmp;
	}

	//! Удаление текущего элемента
	if (current->prev) //если есть предудущий
	{
		current->prev->next = current->next; // то в поле next предыдущего присваиваем поле next текущего,
	}
	else
	{
		first = current->next; // либо в указатель first присваиваем поле next текущего
	}
	if (current->next) // если есть следующий
	{
		current->next->prev = current->prev; // в поле prev следующего присваиваем поле prev текущего
	}
	else
	{
		last = current->prev; // либо в указатель Last присваиваем поле prev текущего
	}
}