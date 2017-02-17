#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

string get_plaintext();
int get_key(string argv);
bool check_amount_of_arguments(int argc);
bool is_negative(int key);
void caesar_ciphering(string plaintext, int key);

int main(int argc, string argv[])
{
    // Проверяем количество аргументов
    if(check_amount_of_arguments(argc))
        return 1;
    // Если число негативное - ошибка
    if(is_negative(get_key(argv[1])))
        return 1;
    // Шифрование
    caesar_ciphering(get_plaintext(), get_key(argv[1]));
}

// Получить сдвиг (на сколько сдвигать текст)
int get_key(string argv)
{
    return atoi(argv);
}

// Пользовательский ввод
string get_plaintext()
{
    printf("plaintext: ");
    return get_string();
}

bool check_amount_of_arguments(int argc)
{
    if(argc != 2)
    {
        printf("Usage: ./caeser k\n");
        return true;
    }
    
    return false;
}

bool is_negative(int key)
{
    if(key < 0)
    {
        printf("Usage: ./caeser k\n");
        return true;
    }
    
    return false;
}

// Шифрование
void caesar_ciphering(string plaintext, int key)
{
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if(isalpha(plaintext[i]))
        {
            if(isupper(plaintext[i]))
                plaintext[i] = ((plaintext[i] + key - 'A') % 26) + 'A';
            else
                plaintext[i] = ((plaintext[i] + key - 'a') % 26) + 'a';
        }
    }
    
    printf("ciphertext: %s\n", plaintext);
}