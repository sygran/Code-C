#include <stdlib.h>
#include <stdio.h>

//! Описание структуры с полем объединения (union)
struct expression_item
{
	char c;
	union un_data
	{
		int i;
		double d;
		char var[sizeof(double)];
	} data;
	struct expression_item *next;
};

// Описание значений С
enum expr_item_types
{
	eit_int = 0,
	eit_dbl = 1,
	eit_var = 2,
	eit_min_op = ' '
};
//! Если поле 'char c' равно значению eit_int, то это целочисленная константа и используется data.i, если eit_dbl - дробная и data.d, если eit_var то используется data.var; если больше либо равное eit_min_op то data не используется воо бще а елемент списка представляет собой символ операции или скобку