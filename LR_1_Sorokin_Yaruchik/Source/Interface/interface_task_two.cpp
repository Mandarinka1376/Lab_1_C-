#include "Libraries.h"

void interfaceTwo()
{
    int** matrix = nullptr;

    int* first_item_result = nullptr;
    int** second_item_result = nullptr;

    int** matrix_characteristic = nullptr;
    int** sorted_matrix_characteristic = nullptr;

    int row_size = 0, col_size = 0;
    int task_item = -1;

    cout << "\nВ целочисленной прямоугольной матрице размером NxM вам необходимо:\n1)Определить номер первой строки, состоящей из одного или нескольких элементов, равных нулю;\n2)отсортировать строки матрицы, расположив их в соответствии с убывающими характеристиками.\n Характеристикой строки в матрице является сумма ее отрицательных элементов.\n\n";

    cout << "Введите количество строк:\n";
    row_size = input_integer();
    while (row_size == 0)
    {
        cout << "Размер не может быть равен 0" << endl;
        row_size = input_integer();
    }

    cout << "Введите количество столбцов:\n";
    col_size = input_integer();
    while (col_size == 0)
    {
        cout << "Размер не может быть равен 0" << endl;
        col_size = input_integer();
    }

    cout << "Введите элементы массива" << endl;
    matrix = input_matrix(row_size, col_size);

    cout << "Матрица по умолчанию равна" << endl;
    display_matrix(matrix, row_size, col_size);

    cout << "\nВыберите элемент задачи (1 или 2) или введите 0 для выхода:" << endl;
    task_item = input_integer();
    while (task_item != 1 && task_item != 2 && task_item != 0)
    {
        cout << "Это значение не является номером элемента задачи. Введите 1, 3 или 0:" << endl;
        task_item = input_integer();
    }
    
    switch (task_item)
    {
    case 1:
        first_item_result = zero_column(matrix, row_size, col_size);

        if (first_item_result[0] == -1)
        {
            cout << "Эта матрица не содержит элементов, равных нулю" << endl;
        }
        else
        {
            cout << "Первый столбец, содержащий ноль, равна " << first_item_result[0] <<" колонне" << endl;

            cout << "Эта строка является: ";

            for (int i = 0; i < row_size; i++)
            {
                cout << matrix[i][first_item_result[0]] << " " << endl;
            }
        }

        break;

    case 2:
        matrix_characteristic = find_matrix_characteristic(matrix, row_size, col_size);

        cout << "Матрица по умолчанию равна:" << endl;
        display_matrix(matrix, row_size, col_size);

        cout << "\nМатричная характеристика по умолчанию равна:" << endl;
        for (int i = 0; i < row_size; i++)
        {
            cout << matrix_characteristic[i][1] << " ";
        }
        cout << endl;

        second_item_result = sort_matrix(matrix, row_size, col_size, matrix_characteristic);
        sorted_matrix_characteristic = find_matrix_characteristic(second_item_result, row_size, col_size);

        cout << "\nОтсортированная матрица представляет собой:" << endl;
        display_matrix(second_item_result, row_size, col_size);

        cout << "\nОтсортированная матричная характеристика равна:" << endl;
        for (int i = 0; i < row_size; i++)
        {
            cout << matrix_characteristic[i][1] << " ";
        }
        cout << endl;

        break;

    default:
        break;
    }

    delete[] first_item_result;

    for (int i = 0; i < row_size; ++i)
        delete matrix[i];
    delete[] matrix;
    
    if (second_item_result != nullptr)
    {
        for (int i = 0; i < row_size; ++i)
        {
            delete second_item_result[i];
        }
    }
    delete[] second_item_result;
    
    if (matrix_characteristic != nullptr)
    {
        for (int i = 0; i < row_size; ++i)
        {
            delete matrix_characteristic[i];
        }
    }
    delete[] matrix_characteristic;

    if (sorted_matrix_characteristic != nullptr)
    {
        for (int i = 0; i < row_size; ++i)
        {
            delete sorted_matrix_characteristic[i];
        }
    }
    delete[] sorted_matrix_characteristic;
   
    
}
