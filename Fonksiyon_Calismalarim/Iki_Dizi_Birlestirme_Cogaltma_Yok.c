#include <stdio.h>
#include <stdlib.h>

int birlestirDuplicateSiz(int dizi1[], int N, int dizi2[], int K, int birlesikDizi[])
{
    int i,j, mevcutBoyut = 0;

    for (i = 0; i < N; i++)
    {
        int tekrarVar = 0;

        for (j = 0; j < mevcutBoyut; j++)
        {
            if (dizi1[i] == birlesikDizi[j])
            {
                tekrarVar = 1;
                break;
            }
        }
        if (!tekrarVar)
        {
            birlesikDizi[mevcutBoyut] = dizi1[i];
            mevcutBoyut++;
        }
        
    }

    for (i = 0; i < K; i++)
    {
        int tekrarVar = 0;
        for (j = 0; j < mevcutBoyut; j++)
        {
            if (dizi2[i] == birlesikDizi[j])
            {
                tekrarVar = 1;
                break;
            }
        }
        if (!tekrarVar)
        {
            birlesikDizi[mevcutBoyut] = dizi2[i];
            mevcutBoyut++;
        }
    }
return mevcutBoyut;

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

    int birlesikBoyut = birlestirDuplicateSiz(dizi1, N, dizi2, K, birlesikDizi);
    printf("Birlesik dizi (tekrarsiz): ");
    for (i = 0; i < birlesikBoyut; i++)
    {
        printf("%d ", birlesikDizi[i]);
    }

    
 return 0;
}
