#include "sort.h"

/**
 * selection_sort - function that sorts an array of integers in
 * ascending order using the Selection sort algorithm
 * Description:
 * @array: input array to sort
 * @size: size of input array
 * Return:
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int *min;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		min = &(array[i]);
		for (j = i + 1; j < size; j++)
			min = (array[j] < *min) ? &(array[j]) : min;

		if (min != &(array[i]))
		{
			SWAP(array[i], *min);
			print_array(array, size);
		}
	}
}
