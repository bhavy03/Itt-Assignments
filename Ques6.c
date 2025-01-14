#include <stdio.h>
int main()
{
    char input1[200];
    printf("Enter the String 1\n");
    scanf("%[^\n]%*c", input1);
    int arr1[26] = {0};

    char input2[200];
    printf("Enter the String 2\n");
    scanf("%[^\n]%*c", input2);
    int arr2[26] = {0};

    for (int i = 0; input1[i] != '\0'; i++)
    {
        int index = 0;
        index = input1[i] - 'a';
        arr1[index] = arr1[index] + 1;
    }

    for (int i = 0; input2[i] != '\0'; i++)
    {
        int index = 0;
        index = input2[i] - 'a';
        arr2[index] = arr2[index] + 1;
    }
    int flag = 0;
    for (int i = 0; i < 26; i++)
    {
        if (arr1[i] != arr2[i])
        {
            flag = 0;
            break;
        }
        else
        {
            flag = 1;
        }
    }
    if (flag == 1)
    {
        printf("True");
    }
    else
    {
        printf("False");
    }
    return 0;
}