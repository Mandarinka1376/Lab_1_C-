#include "Libraries.h"

void interfaceMenu()
{
    int exit_value = 1;
    int task_number = 0;

    while (exit_value == 1)
    {
        cout << "Введите номер задачи, которую вы хотите открыть (задача 1, задача 2 или задача 3):" << endl;
        task_number = input_integer();

        while (task_number != 1 && task_number != 2 && task_number != 3)
        {
            cout << "Это значение не является номером задачи. Введите 1, 2 или 3" << endl;
            task_number = input_integer();
        }

        switch (task_number)
        {
        case 1:
            interfaceOne();
            cout << endl << endl;

            break;

        case 2:
            interfaceTwo();
            cout << endl << endl;

            break;
        case 3:
            interfaceThree();
            cout << endl << endl;
            break;
        }


        cout << "Введите 0 для выхода или 1 для перезапуска:" << endl;
        exit_value = input_integer();

        while (exit_value != 1 && exit_value != 0)
        {
            cout << "Это значение неверно. Введите 0 или 1:" << endl;
            exit_value = input_integer();
        }
    }

}
