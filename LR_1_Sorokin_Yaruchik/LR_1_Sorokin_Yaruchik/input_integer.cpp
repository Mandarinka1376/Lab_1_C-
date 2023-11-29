#include "Libraries.h"

int input_integer(bool negative_condition)
{
    char input_string[100]{}, symbol = ' ';

    int size = 0, integer_value = 0;

    bool condition_control = true, input_end = false, negative_value = false;

    while (!input_end)
    {
        size = 0;
        integer_value = 0;
        cin.getline(input_string, 100);

        if (negative_condition && input_string[0] == '-')
        {
            negative_value = true;
            for (int i = 0; i < 99; i++)
            {
                input_string[i] = input_string[i + 1];
            }
            input_string[99] = '\0';
        }

        symbol = input_string[size];
        size++;
        condition_control = true;

        while (symbol != '\0')
        {
            if (!isdigit(symbol))
            {
                condition_control = false;
                break;
            }
            symbol = input_string[size];
            size++;
        }
        size--;

        if (size == 0 && symbol == '\0')
        {
            condition_control = false;
        }

        if (!condition_control)
        {
            cout << "Введенное значение не является" << ((negative_condition) ? "" : " положительным") << " числом." << endl;
        }
        else
        {
            input_end = true;
        }
    }

    for (int i = 0; i < size; i++)
    {
        integer_value += static_cast<int>((static_cast<__int64_t>(input_string[i]) - 48) * (pow(10, size - 1 - i)));
    }

    return (negative_value) ? (-1 * integer_value) : integer_value;
}
