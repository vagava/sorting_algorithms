#include "sort.h"
/**
 * selection_sort -  function that sorts an array of integers in
 * ascending order usingthe Selection sort algorithm
 * @array: array of integers to sort
 * @size: length of array
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i = 0, j = 0, pos_lower = 0;
	int lower = 0;

	if (!array)
		return;
	for (; i < size - 1; i++)
	{
		pos_lower = i;
		for (j = i + 1; j < size; j++) /*compare the rest of elements*/
		{
			if (array[pos_lower] > array[j])
				pos_lower = j; /*save the position of minior elemnt*/
		}
		if (array[i] > array[pos_lower])
		{
			/*compare the menor and do swap*/
			lower = array[pos_lower];
			array[pos_lower] = array[i];
			array[i] = lower;
			print_array(array, size);
		}
	}
}
