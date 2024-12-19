#include <stdio.h>
#include <stdlib.h>

void removeWhitespaces(char *exp)
{
    int i = 0, j = 0;

    while (exp[i] != '\0')
    {
        if (exp[i] != ' ' && exp[i] != '\t' && exp[i] != '\n')
        {
            exp[j] = exp[i]; 
            j++;
        }
        i++;
    }
    exp[j] = '\0';
}

int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int checkValidity(char *exp)
{
    char oprs[4] = {'+', '-', '*', '/'};
    for (int i = 0; exp[i] != '\0'; i++)
    {
        char c = exp[i];

        if (!(c >= '0' && c <= '9') && !isOperator(c))
        {
            return 0;
        }

        if (isOperator(c) && isOperator(exp[i + 1]))
        {
            return 0;
        }

        if (exp[i] == '/' && exp[i + 1] == '0')
        {
            return 2;
        }
    }
    return 1;
}

int ifIsdigit(char c)
{
    return (c >= '0' && c <= '9');
}

int strLen(const char *exp)
{
    int length = 0;
    while (exp[length] != '\0')
    {
        length++;
    }
    return length;
}

int calculate(const char *exp)
{
    int stack[100];
    int top = -1;
    char sign = '+';
    int num = 0;
    int i = 0;
    int len = strLen(exp);

    for (i = 0; i < len; i++)
    {
        char c = exp[i];

        if (ifIsdigit(c))
        {
            num = num * 10 + (c - '0');
        }

        if (!ifIsdigit(c) || i == len - 1)
        {
            if (sign == '+')
            {
                stack[++top] = num;
            }
            else if (sign == '-')
            {
                stack[++top] = -num;
            }
            else if (sign == '*')
            {
                stack[top] = stack[top] * num;
            }
            else if (sign == '/')
            {
                stack[top] = stack[top] / num;
            }

            sign = c;
            num = 0;
        }
    }

    int result = 0;
    for (i = 0; i <= top; i++)
    {
        result += stack[i];
    }

    return result;
}

int main()
{
    int ans;
    char exp[100];
    printf("Enter the mathematical expression: ");
    fgets(exp, 100, stdin);
    removeWhitespaces(exp);
    ans = checkValidity(exp);
    if (ans == 1)
    {
        int result = calculate(exp);
        printf("Result: %d\n", result);
    }
    else if (ans == 2)
    {
        printf("Error: Division by zero.\n");
    }
    else
    {
        printf("Invalid expression\n");
    };
    return 0;
}
