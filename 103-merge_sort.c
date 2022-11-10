#include "sort.h"

/**
 * print_merging - handles printing during merging
 * @arr: pointer to first element of array
 * @start: pointer to first element of right array
 * @mid: middle of merge
 * @end: end of array
 * Return
 **/
void print_merging(int *arr, int start, int mid, int end)
{
	int i;

	printf("Merging...\n");
	printf("[Left]: ");
	for (i = start; i <= mid; i++)
	{
		printf("%d", arr[i]);
		if (i != mid)
			printf(", ");
	}
	printf("\n[Right]: ");
	for (i = mid + 1; i <= end; i++)
	{
		printf("%d", arr[i]);
		if (i != end)
			printf(", ");
	}
}


/**
 * merge_in_place - merge function to merge two sorted halves of array
 * @arr: pointer to first element of array
 * @start: pointer to first element of right array
 * @mid: middle of merge
 * @end: end of array
 * Return
 **/

void merge_in_place(int *arr, int start, int mid, int end)
{
	int i, value, index, start2 = mid + 1;
	int p1 = start;
	/*
	* if (arr[mid] <= arr[start2])
	*	return;
	*/
	print_merging(arr, start, mid, end);
	while (start <= mid && start2 <= end)
	{
		if (arr[start] <= arr[start2])
			start++;
		else
		{
			value = arr[start2];
			index = start2;
			while (index != start)
			{
				arr[index] = arr[index - 1];
				index--;
			}
			arr[start] = value;

			/* update all pointers */
			start++;
			mid++;
			start2++;
		}

	}
	printf("\n[Done]: ");
	for (i = p1; i <= end; i++)
	{
		printf("%d", arr[i]);
		if (i != end)
			printf(", ");
	}
	printf("\n");
}

/**
 * rec_merge_sort - implementation of merge sort
 * function recursively
 * @arr: array to be sorted
 * @left: beginning index of left array
 * @right: beginning index of right array
 * Return:
 **/
void rec_merge_sort(int *arr, int left, int right)
{
	int mid;

	if (left < right)
	{
		/*printf("Left: %d || Right: %d\n", left, right); */

		mid = (left + right - 1) / 2;

		rec_merge_sort(arr, left, mid);
		rec_merge_sort(arr, mid + 1, right);

		merge_in_place(arr, left, mid, right);
	}
}


/**
 * merge_sort - a function that sorts an array of integers
 * in ascending order using the Merge sort algorithm
 * Description:
 * @array: array to sort
 * @size: size of array
 * Return:
 */

void merge_sort(int *array, size_t size)
{

	if (size < 2)
		return;

	rec_merge_sort(array, 0, size - 1);
}

