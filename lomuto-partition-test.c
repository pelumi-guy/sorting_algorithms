#include "sort.h"
#include <stdio.h>

/**
 * main - main block
 * Description:
 * Return: 0
 */

int partition(int *arr, int start, int end)
{
	int pivot, pIndex, i;

	pivot = arr[end];
	pIndex = start;

	for(i = start; i < end - 1; i++)
	{
		if(arr[i] <= pivot)
		{
			if (i != pIndex)
				SWAP(arr[i], arr[pIndex]);
			pIndex++;
		}	
	}
	SWAP(arr[pIndex], arr[end]);
	return pIndex;
}

int main(void)
{
	int arr[] = {3, 1, 2, 6, 5, 8, 7, 4};
	int i, res;

	res = partition(arr, 0, 7);
	printf("Partitioned array: [");
	for (i = 0; i < 8; i++)
	{
		printf("%i", arr[i]);
		if (i < 7)
			printf(", ");
	}
	printf("]\n");
	printf("Partition Index: %i\n", res);

	return(0);
}
