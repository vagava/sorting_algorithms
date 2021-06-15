#include "sort.h"
/**
 * bubble_sort - function that sorts an array of integers in ascending
 * order using the Bubble sort algorithm
 * @array: array of integers
 * @size: length of array
 * Retrun: nothing
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int i = 0, j = 0;
	int swap = 0;

	for (i = 0; i < size; i++) /*loop principal*/
	{
		for (j = 0; j < size - 1; j++)  /* iner loop*/
		{
			if (array[j] > array[j + 1])
			{
				swap = array[j]; /*swap integers*/
				array[j] = array[j + 1];
				array[j + 1] = swap;
				print_array(array, size);
			}
		}
	}
}
