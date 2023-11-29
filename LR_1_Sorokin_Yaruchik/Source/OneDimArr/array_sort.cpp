#include "Libraries.h"

int* array_sort(int* array, int array_size)
{
    int* sorted_array = new int[array_size];
    int end_index = array_size - 1, start_index = 0;

    for (int i = 0; i < array_size; i++)
    {
        if (array[i] < 0)
        {
            sorted_array[start_index] = array[i];
            start_index++;
        }
        else
        {
            sorted_array[end_index] = array[i];
            end_index--;
        }
    }

    return sorted_array;
}
