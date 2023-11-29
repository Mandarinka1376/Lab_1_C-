#include "Libraries.h"

int** find_matrix_characteristic(int** matrix, int row_size, int col_size)
{
    int** characteristic = new int*[row_size];
    for (int i = 0; i < row_size; i++)
        characteristic[i] = new int[2];
    
    int row_characterisitic = 0;
    
    for (int i = 0; i < row_size; i++)
    {
        for (int j = 0; j < col_size; j++)
        {
            if (matrix[i][j] < 0 && matrix[i][j] % 2 == 0)
            {
                row_characterisitic += matrix[i][j];
            }
        }

        characteristic[i][0] = i;
        characteristic[i][1] = row_characterisitic;

        row_characterisitic = 0;
    }

    return characteristic;
}
