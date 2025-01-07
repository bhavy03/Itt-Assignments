#include <stdio.h>
#include <ctype.h>
int strLen(const char *str)
{
    int length = 0;
    while (str[length] != '\0')
    {
        length++;
    }
    return length;
}
void strcopy(char *dest, const char *src)
{
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}
int is_vowel(char c)
{
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main()
{
    int m, n;
    printf("Enter number of rows: ");
    scanf("%d", &m);
    printf("Enter number of columns: ");
    scanf("%d", &n);

    if (m < 1 || m > 10 || n < 1 || n > 10)
    {
        printf("Rows and columns must be in range.\n");
        return 1;
    }

    char arr[m][n][50];
    int vowelCount = 0;
    char longest_name[50] = "";
    int max_length = 0;

    printf("Enter the names:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Name at (%d,%d): ", i, j);
            scanf("%s", arr[i][j]);

            if (is_vowel(arr[i][j][0]))
            {
                vowelCount++;
            }

            int len = strLen(arr[i][j]);
            if (len > max_length)
            {
                max_length = len;
                strcopy(longest_name, arr[i][j]);
            }
        }
    }

    printf("The 2D array of names is:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%s ", arr[i][j]);
        }
        printf("\n");
    }

    printf("Number of names starting with a vowel: %d\n", vowelCount);
    printf("The longest name: %s\n", longest_name);

    return 0;
}