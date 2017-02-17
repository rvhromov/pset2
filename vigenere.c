#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

string get_plaintext();
bool check_amount_of_arguments(int argc);
bool check_is_not_alpha_string(string key);
void vigenere_ciphering(string plaintext, string key);

int main(int argc, string argv[])
{
    // Проверяем количество аргументов, если не 2 - ошибка
    if(check_amount_of_arguments(argc))
        return 1;
    // Проверяем строку на присутствие только букв, иначе - ошибка
    if(check_is_not_alpha_string(argv[1]))
        return 1;
    // Шифрование
    vigenere_ciphering(get_plaintext(), argv[1]);
}

bool check_amount_of_arguments(int argc)
{
    if(argc != 2)
    {
        printf("Usage: ./vigenere k\n");
        return true;
    }
    
    return false;
}

bool check_is_not_alpha_string(string argv)
{
    for (int i = 0, n = strlen(argv); i < n; i++)
    {
        if (!isalpha(argv[i]))
        {
            printf("Keyword must only contain letters A-Z and a-z\n");
            return true;
        }
    }
    
    return false;
}
// Пользовательский ввод
string get_plaintext()
{
    printf("plaintext: ");
    return get_string();
}
// Шифрование
void vigenere_ciphering(string plaintext, string key)
{
    for (int i = 0, j = 0, key_length = strlen(key), n = strlen(plaintext); i < n; i++)
    {
        if(isalpha(plaintext[i]))
        {
            if(isupper(plaintext[i]))
            {
                if(isupper(key[j % key_length]))
                    // Если буква и ключ в верхнем регистре
                    plaintext[i] = ((plaintext[i] - 'A' + (key[j % key_length] - 'A')) % 26) + 'A';
                else
                    // Если буква в верхнем, а ключ в нижнем регистре
                    plaintext[i] = ((plaintext[i] - 'A' + (key[j % key_length] - 'a')) % 26) + 'A';
            }
            else
            {
                if(isupper(key[j % key_length]))
                    // Если буква в нижнем регистре, а ключ в верхнем
                    plaintext[i] = ((plaintext[i] - 'a' + (key[j % key_length] - 'A')) % 26) + 'a';
                else
                    // Если буква и ключ в нижнем регистре
                    plaintext[i] = ((plaintext[i] - 'a' + (key[j % key_length] - 'a')) % 26) + 'a';
            }
            
            j++;
        }
    }
    
    printf("ciphertext: %s\n", plaintext);
}

