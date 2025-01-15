#include <stdio.h>
int strLen(char *str)
{
    int count = 0;
    while (str[count] != '\0')
    {
        count++;
    }
    return count;
}
int main()
{
    char input[200];
    printf("Enter the String\n");
    scanf("%[^\n]", input);
    char *str = input;
    char *wordArray[100];
    int wordCount = 0;
    char *output;
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
    int maxLen = 0;
    for (int i = 0; i < wordCount; i++)
    {
        int len = strLen((wordArray[i]));
        if (len > maxLen)
        {
            maxLen = len;
            output = wordArray[i];
        }
    }
    printf("%s", output);
}
