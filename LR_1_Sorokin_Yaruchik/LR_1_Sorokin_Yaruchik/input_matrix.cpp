#include "Libraries.h"

int** input_matrix(int row_size, int col_size)
{
    int** matrix = nullptr;

    matrix = new int* [row_size];
    for (int i = 0; i < row_size; i++) {
        matrix[i] = new int[col_size];
    }

    for (int i = 0; i < row_size; i++)
    {
        for (int j = 0; j < col_size; j++) {
            matrix[i][j] = input_integer(true);
        }
    }

    return matrix;
}

