#include "sort.h"

/**
 * bubble_sort - sort array of integers using the bubble
 * 				method
 * @array:	the array to sort
 * @size:	the size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i;
	int current, changed;

	if (size < 2)
		return;
	for (;;)
	{
		changed = 0;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1] && array[i + 1])
			{
				current = array[i];
				/* hold the current item*/
				array[i] = array[i + 1];
				array[i + 1] = current;
				/* move the lower int forward*/

				changed = 1;
				print_array(array, size);
			}
		}
		if (changed == 0)
		{
			return;
		}
	}
}
