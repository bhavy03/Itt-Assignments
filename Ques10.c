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
char *findSubstring(char *str, int start, int end)
{
    char *subString = (char *)malloc(sizeof(char) * (end - start + 2));
    int index = 0;
    for (int i = start; i <= end; i++)
    {
        subString[index++] = str[i];
    }
    subString[index] = '\0';
    return subString;
}
int isPalindrome(char str[])
{
    int start = 0;
    int end = strLen(str) - 1;
    while (start < end)
    {
        if (str[start] != str[end])
        {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}
int main()
{
    char input[200];
    printf("Enter the String\n");
    scanf("%[^\n]%*c", input);
    int len = strLen(input);

    int maxLength = 0;
    int startIdx = 0;
    if (len == 1)
    {
        printf("%s", input);
        return 0;
    }
    for (int i = 0; input[i] != '\0'; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            char *temp = findSubstring(input, i, j);
            if (isPalindrome(temp))
            {
                int currentLen = j - i + 1;
                if (currentLen > maxLength)
                {
                    maxLength = currentLen;
                    startIdx = i;
                }
            }
            free(temp);
        }
    }
    char *longestPalindrome = findSubstring(input, startIdx, startIdx + maxLength - 1);
    printf("%s\n", longestPalindrome);
    free(longestPalindrome);

    return 0;
}