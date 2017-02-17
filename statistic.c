#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

string get_input_text();
string to_upper_case(string str);
string sort_letters(string str);
void show_amount_of_each_letter(string str);

int main(void)
{
    show_amount_of_each_letter(sort_letters(to_upper_case(get_input_text())));
}

// Пользовательский ввод
string get_input_text()
{
    printf("Enter a string: ");
    return get_string(); 
}

// Перевод всех букв в верхний регистр
string to_upper_case(string str)
{
    for(int i = 0, n = strlen(str); i < n; i++)
        str[i] = toupper(str[i]);
        
    return str;
}

// Сортировка букв
string sort_letters(string str)
{
    for (int i = 0, temp = 0, n = strlen(str); i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (str[j] < str[j - 1])
            {
                temp = str[j];
                str[j] = str[j - 1];
                str[j - 1] = temp;
            }
        }
    }
    
    return str;
}

// Подсчёт и вывод количества каждой буквы в строке
void show_amount_of_each_letter(string str)
{
    for (int i = 0, same_letters = 1, n = strlen(str); i < n; i++)
    {
        if(isalpha(str[i]))
        {
            if(str[i] == str[i + 1])
                same_letters++;
            else
            {
                printf("%c - %i\n", str[i], same_letters);
                same_letters = 1;
            }
        }
    }
}