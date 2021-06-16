#include "sort.h"
/**
 * len_arr - function that return the lenght of the array
 * @array: subarray of integer to sort
 * Return: Nothing
 */
size_t len_arr(int *array)
{
	size_t count = 0;

	while (array[count])
		count++;
	return (count);

}
/**
 * swap_arr - function that swaps two elements of a array
 * @sub_array: subarray of integer to sort
 * @index_i: index to swap i
 * @index_j: index to swap j
 * Return: Nothing
 */
void swap_arr(int *sub_array, int index_i, int index_j)
{
	int aux = 0;

	aux = sub_array[index_i];
	sub_array[index_i] = sub_array[index_j];
	sub_array[index_j] = aux;
}
/**
 * position - function that find the right position of a element in the array
 * @sub_array: subarray of integers to sort
 * @low: lowest position
 * @high: highest position
 * Return: Nothing
 */
int position(int *sub_array, int low, int high)
{
	int pivot = 0, i = 0, j = 0;

	pivot = sub_array[high];
	i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (sub_array[j] <= pivot)
		{
			i++;
			swap_arr(sub_array, i, j);

		}
	}
	swap_arr(sub_array, i + 1, high);
	print_array(sub_array, len_arr(sub_array));
	return (i + 1);
}
/**
 * quicksort - function that sorts an array of integers in ascending
 * order using the Quick sort algorithm
 * @sub_array: subarray of integer to sort
 * @low: lowest position
 * @high: highest position
 * Return: Nothing
 */
void quicksort(int *sub_array, int low, int high)
{
	int right_position = 0;

	if (low < high)
	{
		right_position = position(sub_array, low, high);
		quicksort(sub_array, low, right_position - 1);
		quicksort(sub_array, right_position + 1, high);
	}

}

/**
 * quick_sort - function that sorts an array of integers in ascending
 * order using the Quick sort algorithm
 * @array: array of integer to sort
 * @size: length of array
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	quicksort(array, 0, size - 1);
}
