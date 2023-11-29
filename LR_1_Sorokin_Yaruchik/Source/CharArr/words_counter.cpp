#include "Libraries.h"

int words_counter(char* word, int word_size)
{
    char symbol;

    bool word_match = false;

    int index = 0;
    int counter = 0;;

    ifstream file("/Users/nikitasorokin/Desktop/лабы/Новая папка/LR_1_Sorokin_Yaruchik/Source/CharArr/Text.txt");

    while (file.get(symbol))
    {
        if (symbol == word[index])
        {
            if (index == word_size - 1)
            {
                word_match = true;
            }
            else
            {
                index++;
            }
        }
        else
        {
            index = 0;
        }

        if (word_match)
        {
            counter++;
            word_match = false;
        }
    }

    return counter;
}
