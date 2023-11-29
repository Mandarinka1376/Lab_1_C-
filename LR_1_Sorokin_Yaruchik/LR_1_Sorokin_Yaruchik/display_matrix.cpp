#include "Libraries.h"

void display_matrix(int** matrix, int row_size, int col_size)
{
    for (int i = 0; i < row_size; i++)
    {
        for (int j = 0; j < col_size; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
