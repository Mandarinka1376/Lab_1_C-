#include "Libraries.h"

int* find_largest_word()
{
    int* largest_word = new int[2];
    char symbol;

    int letter_counter_first = 0, letter_counter_second = 0;
    int word_start_index_first = -1, word_start_index_second = -1;
    int index = 0;


    ifstream file("/Users/nikitasorokin/Desktop/лабы/Новая папка/LR_1_Sorokin_Yaruchik/Source/CharArr/Text.txt");

    while (file.get(symbol))
    {
        if ((static_cast<int>(symbol) >= 65 && static_cast<int>(symbol) <= 90) || (static_cast<int>(symbol) >= 97 && static_cast<int>(symbol) <= 122))
        {
            letter_counter_first++;
            if (word_start_index_first == -1)
            {
                word_start_index_first = index;
            }
        }
        else
        {
            if (letter_counter_second < letter_counter_first)
            {
                letter_counter_second = letter_counter_first;

                word_start_index_second = word_start_index_first;
            }

            letter_counter_first = 0;
            word_start_index_first = -1;
        }

        index++;
    }

    largest_word[0] = letter_counter_second;
    largest_word[1] = word_start_index_second;

    file.close();

    return largest_word;
}
