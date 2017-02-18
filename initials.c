#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

string get_name();
void show_initials(string name);

int main(void)
{
    show_initials(get_name());
    printf("\n");
}

string get_name()
{
    return get_string();
}

void show_initials(string name)
{
    for(int i = 0, n = strlen(name); i < n; i++)
    {
        // Если текущий символ буква
        if(isalpha(name[i]))
        {
            // Выводим в верхнем регистре
            printf("%c", toupper(name[i]));
            
            // Пропускаем все последующие символы пока не встретим пробел
            while(name[i + 1] != ' ' && i < strlen(name))
                i++;
        }
    }
}