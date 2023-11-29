#include "Libraries.h"

void interfaceOne()
{
    int* array = nullptr;

    int* first_item_result = nullptr;
    int* second_item_maximum_array = nullptr;
    int second_item_result = 0;
    int* third_item_result = nullptr;

    int task_item = 0;

    int array_size = 0;
    int number_c = 0;
    int maximum_element_index = 0;

    cout << "\nВ одномерном массиве, состоящем из n целых элементов, вам необходимо:\n1)Найти значения и координаты элементов, которые больше \"C\";\n2)Найти умножение элементов, расположенных после максимального по модулю элемента. Определите значение и координаты этого элемента. Если массив содержит несколько максимальных элементов, пользователь должен выбрать один из них;\n3)Сжать массив таким образом, чтобы первыми были расположены отрицательные элементы, а вторыми - положительные элементы.\n\n";
    
    cout << "Введите размер массива:\n";
    array_size = input_integer();
    while (array_size == 0)
    {
        cout << "Размер не может быть равен 0" << endl;
        array_size = input_integer();
    }

    cout << "Введите элементы массива:" << endl;
    array = input_array(array_size);

    cout << "Массив представляет собой\n";
    display_array(array, array_size);

    cout << "\nВыберите пункт задачи (1, 2 или 3) или введите 0 для выхода:" << endl;
    task_item = input_integer();
    while (task_item != 1 && task_item != 2 && task_item != 3 && task_item != 0)
    {
        cout << "Это значение не является номером элемента задачи. Введите 1, 2, 3 или 0:" << endl;
        task_item = input_integer();
    }

    switch (task_item)
    {
    case 1:
        cout << "Введите значение C" << endl;
        number_c = input_integer(true);

        first_item_result = greater_then_number(array, array_size, number_c);
        
        cout << "Количество элементов, которые больше, чем C, равно " << first_item_result[0] << endl;

        if (first_item_result[0] != 0)
        {
            cout << "Это элементы под номерами: ";
            display_array(first_item_result, first_item_result[0] + 1, 1);
        }

        break;

    case 2:
        second_item_maximum_array = find_maximum_values(array, array_size);
        
        cout << "Массив содержит " << second_item_maximum_array[1] << " максимальное количество элементов, равное " << second_item_maximum_array[0] << endl;
        
        if (array_size == 1 || (array_size == 2 && second_item_maximum_array[3] == 1))
        {
            cout << "Нет возможности найти умножение на нулевое число элементов" << endl;
        }
        else
        {
            if (second_item_maximum_array[1] > 1)
            {
                cout << "Выберите максимальное количество элементов, после которого вы хотите найти несколько: ";
                for (int i = 1; i <= second_item_maximum_array[1]; i++)
                {
                    cout << i;
                }
                cout << endl;

                while (true)
                {
                    maximum_element_index = input_integer();
                    if (maximum_element_index == 0 || maximum_element_index > second_item_maximum_array[1])
                    {
                        cout << "Введенное значение не является номером максимального элемента" << endl;
                    }
                    else
                    {
                        break;
                    }
                }

                maximum_element_index = second_item_maximum_array[maximum_element_index + 1];
            }
            else
            {
                maximum_element_index = second_item_maximum_array[2];
            }

            if (array_size == maximum_element_index + 1)
            {
                cout << "Нет возможности найти умножение на нулевое число элементов" << endl;
            }
            else if (array_size == maximum_element_index + 2)
            {
                cout << "Нет возможности найти умножение одного элемента" << endl;
            }
            else
            {
                second_item_result = array_multiplication(array, array_size, maximum_element_index);

                cout << "Умножение элементов, расположенных после " << maximum_element_index << " элемент - это " << second_item_result << endl;
            }
        }

        break;

    case 3:
        third_item_result = array_sort(array, array_size);
        
        cout << "Отсортированный массив представляет собой" << endl;
        display_array(third_item_result, array_size);

        break;

    default:
        break;
    }

    delete[] array;

    delete[] first_item_result;
    delete[] second_item_maximum_array;
    delete[] third_item_result;
}
