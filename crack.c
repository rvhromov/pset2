#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <crypt.h>

#define _XOPEN_SOURCE 
#define ALPHABET_LENGHT 52
#define ALPHAS "ABCDEFGHIGKLMNOPQRSTUVWXYZabcdefghigklmnopqrstuvwxyz"

string get_hash(string argv);
bool check_amount_of_arguments(int argc);
int crack_one_character_password(string hash, char salt []);
int crack_two_character_password(string hash, char salt []);
int crack_three_character_password(string hash, char salt []);
int crack_four_character_password(string hash, char salt []);

int main(int argc, string argv[])
{
    // Ошибка, если передано не 2 аргумента
    if(check_amount_of_arguments(argc))
        return 1;
    // Получаем захешированый пароль с солью
    string hash = get_hash(argv[1]);
    // Соль
    char salt [2];
    // Выделяем соль
    for(int i = 0; i < 2; i++)  
        salt[i] = hash[i]; 
    
    printf("Program is running... Please, wait!\n");
    
    // Перебор паролей
    if(crack_one_character_password(hash, salt))
        return 0;
        
    if(crack_two_character_password(hash, salt))
        return 0;
        
    if(crack_three_character_password(hash, salt))
        return 0;
    
    if(crack_four_character_password(hash, salt))
        return 0;
    
    printf("Password wasn't cracked!\n");
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

string get_hash(string argv)
{
    return argv;
}
// Перебор паролей из одного символа
int crack_one_character_password(string hash, char salt [])
{
    // Предполагаемый пароль
    char password [] = "A";
    
    // Перебор паролей
    for (int i = 0; i < ALPHABET_LENGHT; i++)
    {
        password[0] = ALPHAS[i];
    
        if(strcmp(crypt(password, salt), hash) == 0)
        {
            printf("%s\n", password);
            return 1;
        }
    }
    
    return 0;
}
// Перебор паролей из двух символов
int crack_two_character_password(string hash, char salt [])
{
    // Предполагаемый пароль
    char password [] = "AA";

    // Перебор паролей
    for (int i = 0; i < ALPHABET_LENGHT; i++)
    {
        password[0] = ALPHAS[i];
    
        for (int j = 0; j <= ALPHABET_LENGHT; j++)
        {
            password[1] = ALPHAS[j];
            
            if(strcmp(crypt(password, salt), hash) == 0)
            {
                printf("%s\n", password);
                return 1;
            }
        }
    }
    
    return 0;
}
// Перебор паролей из трёх символов
int crack_three_character_password(string hash, char salt [])
{
    // Предполагаемый пароль
    char password [] = "AAA";
    
    // Перебор паролей
    for (int i = 0; i < ALPHABET_LENGHT; i++)
    {
        password[0] = ALPHAS[i];
    
        for (int j = 0; j <= ALPHABET_LENGHT; j++)
        {
            password[1] = ALPHAS[j];
            
            for (int k = 0; k < ALPHABET_LENGHT; k ++)
            {
                password[2] = ALPHAS[k];
                
                if(strcmp(crypt(password, salt), hash) == 0)
                {
                    printf("%s\n", password);
                    return 1;
                }
            }
        }
    }
    
    return 0;
}
// Перебор паролей из четырёх символов
int crack_four_character_password(string hash, char salt [])
{
    // Предполагаемый пароль
    char password [] = "AAAA";
    
    // Перебор паролей
    for (int i = 0; i < ALPHABET_LENGHT; i++)
    {
        password[0] = ALPHAS[i];
    
        for (int j = 0; j <= ALPHABET_LENGHT; j++)
        {
            password[1] = ALPHAS[j];
            
            for (int k = 0; k < ALPHABET_LENGHT; k ++)
            {
                password[2] = ALPHAS[k];
                
                for (int l = 0; l < ALPHABET_LENGHT; l++)
                {
                    password[3] = ALPHAS[l];
                    
                    if(strcmp(crypt(password, salt), hash) == 0)
                    {
                        printf("%s\n", password);
                        return 1;
                    }
                }
            }
        }
    }
    
    return 0;
}