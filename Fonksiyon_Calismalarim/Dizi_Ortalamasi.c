#include <stdio.h>
#include <stdlib.h>

float ortalamaBul(int dizi[], int n)
{
    int i;
    float toplam = 0.0;

    for (i = 0; i < n; i++)
    {
        toplam += dizi[i];
    }
    return toplam / n;
}

int main()
{

    int n, i;
    int dizi[100];
    float ort;

    printf("Dizinin eleman sayisini giriniz: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100)
    {
        printf("Lutfen 1 ile 100 arasinda bir sayi giriniz.\n");
        return 0;
    }
    for (i = 0; i < n; i++)
    {
        printf("Dizinin %d. elemanini giriniz: ", i + 1);
        scanf("%d", &dizi[i]);
    }

    ort = ortalamaBul(dizi, n);

    printf("Dizinin ortalamasi: %.2f\n", ort);
    return 0;
}
