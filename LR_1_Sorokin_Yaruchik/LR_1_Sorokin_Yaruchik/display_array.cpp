#include "Libraries.h"

void display_array(int* array, int array_size, int start_index)
{
    for (int i = start_index; i < array_size; i++)
    {
        cout << array[i] << ' ';
    }
    cout << endl;
}
