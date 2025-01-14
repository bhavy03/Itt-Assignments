#include <stdio.h>
int main()
{
    char input[200];
    printf("Enter the String\n");
    scanf("%[^\n]", input);
    char ch;
    printf("Enter the char:\n");
    scanf(" %c", &ch);
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == ch)
        {
            input[i] = '1';
        }
    }
    char *str = input;
    while(*str != '\0'){
        if(*str != '1'){
            printf("%c",*str);
        }
        str++;
    }
    return 0;
}