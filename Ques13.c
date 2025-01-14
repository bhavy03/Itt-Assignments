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
int ifContainAll(char *input1, char *input2)
{
    int hash1[256] = {0}, hash2[256] = {0};
    int len1 = strLen(input1);
    int len2 = strLen(input2);

    for (int i = 0; i < len2; i++)
    {
        hash2[input2[i]]++;
    }

    for (int i = 0; i < len1; i++)
    {
        hash1[input1[i]]++;
    }

    for (int i = 0; i < 256; i++)
    {
        if (hash2[i] > hash1[i])
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    char input1[200];
    printf("Enter the first String\n");
    scanf("%[^\n]%*c", input1);
    int len1 = strLen(input1);

    char input2[200];
    printf("Enter the senond String\n");
    scanf("%[^\n]%*c", input2);
    int len2 = strLen(input2);

    int minLength = len1;
    int startIdx = 0;

    for (int i = 0; input1[i] != '\0'; i++)
    {
        for (int j = i + 1; j < len1; j++)
        {
            char *temp = findSubstring(input1, i, j);
            if (ifContainAll(temp, input2))
            {
                int currentLen = j - i + 1;
                if (currentLen < minLength)
                {
                    minLength = currentLen;
                    startIdx = i;
                }
            }
            free(temp);
        }
    }
    char *longestPalindrome = findSubstring(input1, startIdx, startIdx + minLength - 1);
    printf("%s\n", longestPalindrome);
    free(longestPalindrome);

    return 0;
}
