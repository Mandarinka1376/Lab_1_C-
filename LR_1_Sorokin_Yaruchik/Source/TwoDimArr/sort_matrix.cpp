#include "Libraries.h"

int** sort_matrix(int** matrix, int row_size, int col_size, int** matrix_characteristic)
{
    int** sorted_matrix = new int*[row_size];
    for (int i = 0; i < row_size; i++)
        sorted_matrix[i] = new int[col_size];
        
    int index = 0, value = 0;

    for (int i = 0; i < row_size - 1; i++)
    {
        for (int j = i + 1; j < row_size; j++)
        {
            if (matrix_characteristic[i][1] < matrix_characteristic[j][1])
            {
                index = matrix_characteristic[i][0];
                value = matrix_characteristic[i][1];

                matrix_characteristic[i][0] = matrix_characteristic[j][0];
                matrix_characteristic[i][1] = matrix_characteristic[j][1];

                matrix_characteristic[j][0] = index;
                matrix_characteristic[j][1] = value;
            }
        }
    }

    for (int i = 0; i < row_size; i++)
    {
        for (int j = 0; j < col_size; j++)
        {
            sorted_matrix[i][j] = matrix[matrix_characteristic[i][0]][j];
        }
    }
    
    return sorted_matrix;
}
