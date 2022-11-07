#include "sort.h"

/**
 * lomuto_partition - a function that partions an array
 * using the Lomuto partition scheme
 * @arr: array to be partiotioned
 * @start: start index of partition
 * @end: end index of partition
 * @size: size of input array
 * Return: partition index
 **/

int lomuto_partition(int *arr, int start, int end, size_t size)
{
	int pivot, pIndex, i;

	pivot = arr[end];
	pIndex = start;

	for (i = start; i < end; i++)
	{
		if (arr[i] <= pivot)
		{
			if (pIndex < i)
			{
				if (arr[pIndex] != arr[i])
					SWAP(arr[pIndex], arr[i]);
				print_array(arr, size);
			}
			pIndex++;
		}
	}

	if (arr[pIndex] > pivot)
	{
		SWAP(arr[pIndex], arr[end]);
		print_array(arr, size);
	}
	return (pIndex);
}

/**
 * lomuto_sorter - function that implements quick sort algorithm
 * recursively
 * @array: array to be sorted
 * @start: start index
 * @size: size of input array
 * @end: end index
 **/
void lomuto_sorter(int *array, int start, int end, size_t size)
{
	int pIndex;

	if (start >= end || start < 0)
		return;

	pIndex = lomuto_partition(array, start, end, size);
	lomuto_sorter(array, start, pIndex - 1, size);
	lomuto_sorter(array, pIndex + 1, end, size);
}

/**
 * quick_sort - a function that sorts an array of integers
 * in ascending order using the Quick sort algorithm
 * Description:
 * @array: array to be sorted
 * @size: size of input array
 * Return:
 */

void quick_sort(int *array, size_t size)
{
	int start = 0, end = size - 1;

	if (array == NULL || size < 2)
		return;

	lomuto_sorter(array, start, end, size);
}
