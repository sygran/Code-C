
// ! - Цикл переворачивает массив arr длины arr_len, состоящий из целочисленных элементов.
int main()
{
	for (i = 0, j = arr_len - 1; i < j; i++, j++)
	{
		int t;
		t = arr[i];
		arr[i] = arr[j];
		arr[j] = t;
	}
}