#include <stdio.h>
#include <stdlib.h>

//! Бинарное дерево и работа с тамим деревом через рекурсию

struct node
{
	int val;
	struct node *left, *right;
};

void int_bin_tree_print_rec(struct node *r)
{
	if (!r)
	{
		return;
	}
	int_bin_tree_print_rec(r->left);
	printf("%d ", r->val);
	int_bin_tree_print_rec(r->right);
}

void int_bit_tree_add(struct node **root, int n) // Передаем адрес указателя, **root
{
	if (!*root) // Если нулевой
	{
		*root = malloc(sizeof(**root)); // Выделяем динамически память
		(*root)->val = n;				// заполняем поле val данными
		(*root)->left = NULL;			// левый указатель нуль
		(*root)->right = NULL;			// правый нуль
		return;							// возвращаем управление
	}
	if ((*root)->val == n) // Проверка, не равно ли новое число(которое добавляем(n)) текущему(val), если равно то
	{
		return; // Возвращаем управление, так как такое число в дереве уже есть
	}
	if (n < (*root)->val) // Соответственно проверка на то в какую ветку добавляем новое число, если оно меньше чем то которое есть сейчас в *root
	{
		int_bit_tree_add(&(*root)->left, n); // То добавляем его в левую ветку
	}
	else // если не меньше
	{
		int_bit_tree_add(&(*root)->right, n); // то в правую
	}
}