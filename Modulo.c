#include <stdio.h>
#include <stdlib.h>

long long mod_exp(long long base, long long exponent, long long modulo)
{
    long long result = 1;
    base = base % modulo;

    while (exponent > 0)
    {
        if (exponent % 2 == 1)
        {
            result = (result * base) % modulo;
        }
        base = (base * base) % modulo;
        exponent = exponent / 2;
    }
    return result;
}

int main()
{
    long long base, exponent, modulo;

    printf("Enter base : ");
    scanf("%lld", &base);
    printf("Enter exponent : ");
    scanf("%lld", &exponent);
    printf("Enter modulus : ");
    scanf("%lld", &modulo);

    if (modulo <= 1)
    {
        printf("Error: Modulus must be greater than 1.\n");
        return 1;
    }

    if (exponent < 0)
    {
        printf("Error: Exponent must be a positive integer.\n");
        return 1;
    }

    long long result = mod_exp(base, exponent, modulo);
    printf("Result: %lld\n", result);

    return 0;
}
