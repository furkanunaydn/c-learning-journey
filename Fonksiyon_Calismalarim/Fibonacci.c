#include <stdio.h>
#include <stdlib.h>

void fibonacci(int sayi)
{
    int a = 0, b = 1, c, i;

    for (i = 1; i <= sayi; i++)
    {
        printf("%d ", a);
        c = a + b;
        a = b;
        b = c;
    }
}
int main()
{
    int sayi;

    printf("Kac tane Fibonacci sayisi gireceksiniz\n");
    scanf("%d", &sayi);
    if (sayi <= 0)
    {
        printf("Lutfen pozitif bir sayi giriniz.\n");
        return 0;
    }
    fibonacci(sayi);

    return 0;
}
