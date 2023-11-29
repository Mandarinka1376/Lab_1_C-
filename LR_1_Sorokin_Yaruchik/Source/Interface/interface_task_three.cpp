#include "Libraries.h"

void interfaceThree()
{
    int* largest_word_props = nullptr;
    char* largest_word = nullptr;

    int largest_words_counter;

    char symbol;

    int index = 0, i = 0;

    ifstream file("/Users/nikitasorokin/Desktop/лабы/Новая папка/LR_1_Sorokin_Yaruchik/Source/CharArr/Text.txt");

    if (!file.is_open())
    {
        cout << "Ошибка. Файл не может быть открыт\n";
        file.close();
        return;
    }
    else
    {
        cout << "Текс:" << endl;
        while (file.get(symbol))
        {
            cout << symbol;
        }
        cout << endl;

        file.clear();
        file.seekg(0, ios::beg);


        largest_word_props = find_largest_word();

        largest_word = new char[largest_word_props[1]];

        cout << "Самое длинное слово - это ";

        while (file.get(symbol))
        {
            if (index >= largest_word_props[1] && ((static_cast<int>(symbol) >= 65 && static_cast<int>(symbol) <= 90) || (static_cast<int>(symbol) >= 97 && static_cast<int>(symbol) <= 122)))
            {
                cout << symbol;
                largest_word[i] = symbol;
                i++;
            }
            else if (index >= largest_word_props[1] && !((static_cast<int>(symbol) >= 65 && static_cast<int>(symbol) <= 90) || (static_cast<int>(symbol) >= 97 && static_cast<int>(symbol) <= 122)))
            {
                break;
            }

            index++;
        }

        largest_words_counter = words_counter(largest_word, largest_word_props[0]);

        cout << ". Этот текст включает " << largest_words_counter << " таких слова" << endl;

        file.close();
    }

    delete[] largest_word;
    delete[] largest_word_props;
}
