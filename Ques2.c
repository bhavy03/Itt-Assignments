#include <stdio.h>
int main()
{
    char input[200];
    printf("Enter the String\n");
    scanf("%[^\n]", input);
    char *str = input;
    char *wordArray[100];
    int wordCount = 0;
    while (*str != '\0')
    {
        while (*str == ' ')
            str++;
        if (*str != '\0')
        {
            wordArray[wordCount++] = str;
        }
        while (*str != ' ' && *str != '\0')
            str++;
        if (*str != '\0')
        {
            *str = '\0';
            str++;
        }
    }
    printf("%d", wordCount);
}
