#include <stdio.h>
int main()
{
    char sInput[200];
    printf("Enter the String\n");
    scanf("%[^\n]%*c", sInput);

    char subInput[200];
    printf("Enter the Substring\n");
    scanf("%[^\n]%*c", subInput);

    int flag = 0;
    int index = 0;
    for (int i = 0; sInput[i] != '\0'; i++)
    {
        if (sInput[i] == subInput[0])
        {
            index = i;
            for (int j = 0; subInput[j] != '\0'; j++)
            {
                if (sInput[i + j] != subInput[j])
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
        printf("%d", index);
    }
    else
    {
        printf("-1");
    }
}