#include "Libraries.h"

int* zero_column(int** matrix, int row_size, int col_size)
{
    int* zero_row = new int[row_size + 1];

    int zero_row_number = -1;

    for (int i = 0; i < row_size; i++)
    {
        for (int j = 0; j < row_size; j++)
        {
            if (matrix[i][j] == 0)
            {
                zero_row_number = j;
                break;
            }
            if (zero_row_number != -1)
            {
                break;
            }
        }
    }

    zero_row[0] = zero_row_number;

    for (int i = 0; i < row_size; i++)
    {
        zero_row[i+1] = matrix[i][zero_row_number];
    }

    return zero_row;
}
