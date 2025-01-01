#include <stdio.h>
#include <stdlib.h>

long long mod_exp(long long B, long long N, long long M)
{
    long long result = 1;
    B = B % M;

    while (N > 0)
    {
        if (N % 2 == 1)
        {
            result = (result * B) % M;
        }
        B = (B * B) % M;
        N = N / 2;
    }
    return result;
}

int main()
{
    long long B, N, M;

    printf("Enter base (B): ");
    scanf("%lld", &B);
    printf("Enter exponent (N): ");
    scanf("%lld", &N);
    printf("Enter modulus (M): ");
    scanf("%lld", &M);

    if (M <= 1)
    {
        printf("Error: Modulus M must be greater than 1.\n");
        return 1;
    }

    if (N < 0)
    {
        printf("Error: Exponent N must be a positive integer.\n");
        return 1;
    }

    long long result = mod_exp(B, N, M);
    printf("Result: %lld\n", result);

    return 0;
}
