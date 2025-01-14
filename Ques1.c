#include <stdio.h>

int main()
{
    char input[100];
    char output[100];
    int outIndex = 0;
    printf("Enter the string: ");
    scanf("%s", input);
    for (int i = 0; input[i] != '\0'; i++)
    {
        int isUnique = 1;
        for (int j = 0; j < outIndex; j++)
        {
            if (input[i] == output[j])
            {
                isUnique = 0;
                break;
            }
        }
        if (isUnique)
        {
            output[outIndex++] = input[i];
        }
    }
    output[outIndex] = '\0';
    printf("%s", output);
    return 0;
}