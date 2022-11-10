void merge(int arr[], int start, int mid, int end)
{
	int value, index, start2 = mid + 1;

	/* if (arr[mid] <= arr[start2])
		return; */

	while (start <= mid && start2 <= end)
	{
		if (arr[start] <= arr[start2])
			start++;

		else
		{
			value = arr[start2];
			index = start2;

			/* Shift all the elements between element 1 element 2, right by 1. */
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
}
