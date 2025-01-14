#include <stdio.h>
#include <stdlib.h>
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
    char input1[200];
    printf("Enter String 1\n");
    scanf("%[^\n]%*c", input1);

    char input2[200];
    printf("Enter String 2\n");
    scanf("%[^\n]%*c", input2);

    int len1 = strLen(input1);
    int len2 = strLen(input2);
    if (len1 != len2)
    {
        printf("false");
        exit(0);
    }

    int newLen = (2 * len1);
    char string[newLen + 1];
    for (int i = 0; i < len1; i++)
    {
        string[i] = input1[i];
        string[i + len1] = input1[i];
    }
    string[newLen] = '\0';

    int flag = 0;
    for (int i = 0; i <= len2; i++)
    {
        if (string[i] == input2[0])
        {
            for (int j = 0; j < len2; j++)
            {
                if (string[i + j] != input2[j])
                {
                    flag = 0;
                    break;
                }
                else
                {
                    flag = 1;
                }
            }
        }
        if (flag == 1)
        {
            break;
        }
    }

    if (flag == 1)
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }
    return 0;
}