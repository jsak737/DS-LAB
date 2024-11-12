//Fibonacci
#include <stdio.h>
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void main() {
    int n, i;
    printf("Enter Number of Terms in Fibonacci series: ");
    scanf("%d", &n);

    printf("Fibonacci Series: ");
    for (i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
}


//Factorial
#include <stdio.h>
int factorial(int n)
{
    if (n<=1)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

void main()
{
    int num;

    printf("Enter Number to Calculate Factorial: ");
    scanf("%d", &num);

    if (num < 0)
    {
        printf("Factorial Not Possible\n");
    }
    else
    {
        printf("Factorial of %d is %d\n", num, factorial(num));
    }
}


//Tower of Hanoi
#include <stdio.h>
void TOH(int n, char s, char t, char d)
{
    if (n == 1)
    {
        printf("Move Disk %d from %c to %c\n", n, s, d);
        return;
    }
    TOH(n - 1, s, d, t);
    printf("Move disk %d from %c to %c\n", n, s, d);
    TOH(n - 1, t, s, d);
}

void main()
{
    int n = 3;
    TOH(n, 'S', 'T', 'D');
}

