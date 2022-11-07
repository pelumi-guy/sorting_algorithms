#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using the
 * 				Shell sort algorithm, using the Knuth sequence
 * @size: size of the array
 * @array: list with numbers
 */
void shell_sort(int *array, size_t size)
{
	size_t interval = 1, i, j;

	if (array == NULL || size < 2)
		return;

	while (interval < size / 3)
	{
		interval = 3 * interval + 1; /*the n+1 = n * 3 + 1 (Knuth sequence)*/
	}
	while (interval >= 1)
	{
		for (i = interval; i < size; i++)
		{
			for (j = i; j >= interval && (array[j] < array[j - interval]);
			     j -= interval)
			{
				SWAP(array[j], array[j - interval]);
			}
		}
		print_array(array, size);
		interval = interval / 3;
	}
}
