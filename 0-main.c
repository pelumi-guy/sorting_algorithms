#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	/*
	 * int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
	 */
	int array[] = {38, 66, 30, 168, 85, 198, 60, 107, 139, 133, 180, 2, 126, 24,
	               100, 25, 102, 182, 194, 37, 26, 61, 3, 120, 155, 176, 136,
	               144, 43, 74, 68, 8, 12, 138, 188, 35, 163, 143, 148, 154, 81,
	               184, 175, 105, 83, 110, 129, 153, 101, 150};
	size_t n = sizeof(array) / sizeof(array[0]);

	print_array(array, n);
	printf("\n");
	bubble_sort(array, n);
	printf("\n");
	print_array(array, n);
	return (0);
}
