#include <stdio.h>
#define ARRLEN 26
int main()
{
    char input1[200];
    printf("Enter the String \n");
    scanf("%[^\n]%*c", input1);
    int arr1[ARRLEN] = {0};

    for (int i = 0; input1[i] != '\0'; i++)
    {
        int index = 0;
        index = input1[i] - 'a';
        arr1[index] = arr1[index] + 1;
    }
    int flag = 0;
    for (int i = 0; i < ARRLEN; i++)
    {
        if (!(arr1[i] > 1))
        {
            flag = 0;
        }
        else
        {
            flag = 1;
            break;
        }
    }
    for (int i = 0; i < ARRLEN; i++)
    {
        if (arr1[i] != 0 && flag == 1)
        {
            printf("%c%d", i + 'a', arr1[i]);
        }
    }
    if (flag == 0)
    {
        printf("%s", input1);
    }
    return 0;
}