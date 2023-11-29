#include "Libraries.h"

int* input_array(int size)
{
    int* array = nullptr;
    array = new int[size];

    for (int i = 0; i < size; i++)
    {
        array[i] = input_integer(true);
    }

    return array;
}
