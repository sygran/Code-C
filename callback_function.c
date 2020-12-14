#include <stdio.h>
#include <stdlib.h>
struct node
{
	int val;
	struct node *left, *right;
};
void callback_function(int num, void *userdata);
void int_bin_tree_traverse(struct node *r, void (*callback)(int, void *), void *userdata) //Tree traverse
{
	if (!r)
	{
		return;
	}
	int_bin_tree_traverse(r->left);
	(*callback)(r->val, userdata);
	int_bin_tree_traverse(r->right);
}

void int_callback_print(int data, void *userdata)
{
	printf("%d ", data);
}