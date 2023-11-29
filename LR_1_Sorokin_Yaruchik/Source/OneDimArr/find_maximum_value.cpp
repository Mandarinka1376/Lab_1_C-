#include "Libraries.h"

int* find_maximum_values(int* array, int array_size)
{
    int* maximum_array = nullptr;

    int maximum = -2147483647;
    int maximum_counter = 0;
    int maximum_array_index = 2;

    for (int i = 0; i < array_size; i++)
    {
        if (array[i] > maximum)
        {
            maximum = array[i];
            maximum_array = 0;
            maximum_counter = 1;
        }
        else if (array[i] == maximum)
        {
            maximum_counter++;
        }
    }

    maximum_array = new int[maximum_counter + 2];

    maximum_array[0] = maximum;
    maximum_array[1] = maximum_counter;

    for (int i = 0; i < array_size; i++)
    {
        if (array[i] == maximum)
        {
            maximum_array[maximum_array_index] = i;
            maximum_array_index++;
        }
    }

    return maximum_array;
}
