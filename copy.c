int lomuto_partition(int *arr, int start, int end, size_t size)
{
int pivot, pIndex, i;

pivot = arr[end];
pIndex = start;
/* printf("start index: %d, end index: %d\n", start, end);
* printf("pivot: %d\n", pivot); */

for(i = start; i < end; i++)
{
if(arr[i] <= pivot)
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
return pIndex;
}

