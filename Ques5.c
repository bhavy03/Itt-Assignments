#include <stdio.h>
int isDigit(char c)
{
    return (c >= '0' && c <= '9');
}
int main()
{
    char input[200];
    printf("Enter the String \n");
    scanf("%[^\n]%*c", input);
    char *str = input;
    int flag = 0;
    while ((*str != '\0'))
    {
        if (!((isDigit(*str) || *str == '-')))
        {
            flag = 0;
            break;
        }
        else
        {
            flag = 1;
        }
        str++;
    }
    if (flag == 0)
    {
        printf("0");
    }
    else
    {
        int sign = 1;
        int num = 0;
        for (int i = 0; input[i] != '\0'; i++)
        {
            if (input[i] == '-')
            {
                sign = -1;
                i++;
            }
            num = num * 10 + (input[i] - '0');
        }
        printf("%d", num * sign);
    }

    return 0;
}