#include<stdio.h>
int gcd(int a, int b)
{
    if (b == 0) 
	{
        return a;
    }
    return gcd(b, a % b);
}
int areCoprime(int num1, int num2) 
{
    int commonDivisor = gcd(num1, num2);
    if (commonDivisor == 1) 
	{
        return 1; 
    } else 
	{
        return 0; 
    }
}
int main() 
{
    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    if (areCoprime(num1, num2)) {
        printf("%d and %d are coprime.\n", num1, num2);
    } else {
        printf("%d and %d are not coprime.\n", num1, num2);
    }

    return 0;
}
 


