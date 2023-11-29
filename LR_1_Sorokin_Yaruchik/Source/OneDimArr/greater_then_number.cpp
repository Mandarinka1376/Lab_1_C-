#include "Libraries.h"

int* greater_then_number(int* array, int array_size, int number_c)
{
    int* result_array = nullptr;

    int value_counter = 0;
    int result_value_coordinate = 1;

    for (int i = 0; i < array_size; i++)
    {
        if (array[i] > number_c)
        {
            value_counter++;
        }
    }

    result_array = new int[value_counter + 1];
    result_array[0] = value_counter;

    for (int i = 0; i < array_size; i++)
    {
        if (array[i] > number_c)
        {
            result_array[result_value_coordinate] = i;
            result_value_coordinate++;
        }
    }

    return result_array;
}
