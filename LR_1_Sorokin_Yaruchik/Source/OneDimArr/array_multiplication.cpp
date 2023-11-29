#include "Libraries.h"

int array_multiplication(int* array, int array_size, int maximum_element_index)
{
    int multiplication_result = 1;

    for (int i = maximum_element_index + 1; i < array_size; i++)
    {
        multiplication_result *= array[i];
    }

    return multiplication_result;
}
