#include <stdio.h>
#include <stdlib.h>

void birlestir(int dizi1[], int N, int dizi2[], int K, int birlesikDizi[])
{
    int i;

    for (i = 0; i < N; i++)
    {
        birlesikDizi[i] = dizi1[i];
    }

    for (i = 0; i < K; i++)
    {
        birlesikDizi[N + i] = dizi2[i];
    }

    printf("Birlesik dizi: ");
    for (i = 0; i < N + K; i++)
    {
        printf("%d ", birlesikDizi[i]);
    }
    printf("\n");
}
int main()
{
    int N,K,i;
    int dizi1[100], dizi2[100], birlesikDizi[200];

    printf("Ilk dizinin eleman sayisini giriniz: ");
    scanf("%d", &N);

    if (N <= 0 || N > 100)
    {
        printf("Lutfen 1 ile 100 arasinda bir sayi giriniz.\n");
        return 0;
    }

    for(i = 0; i < N; i++)
    {
        printf("Ilk dizinin %d. elemanini giriniz: ", i + 1);
        scanf("%d", &dizi1[i]);
    }

    printf("Ikinci dizinin eleman sayisini giriniz: ");
    scanf("%d", &K);   
    
    if (K <= 0 || K > 100)
    {
        printf("Lutfen 1 ile 100 arasinda bir sayi giriniz.\n");
        return 0;
    }
       for ( i = 0; i < K; i++)
    {
        printf("Ikinci dizinin %d. elemanini giriniz: ", i + 1);
        scanf("%d", &dizi2[i]);
    }

    birlestir(dizi1, N, dizi2, K, birlesikDizi);
 return 0;
}
