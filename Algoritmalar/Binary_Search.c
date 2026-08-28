#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size;
    int i, j, temp;
    int ilk, son, orta, aranan;

    printf("Kac adet sayi girilecek : ");
    scanf("%d", &size);

    int dizi[size];

    printf("Dizi elemanlarini giriniz : \n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &dizi[i]);
    }
    printf("Girilen elemanlar : \n");
    for (i = 0; i < size; i++)
    {
        printf("%d ", dizi[i]);
    }
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - 1 - i; j++)
        {
            if (dizi[j] > dizi[j + 1])
            {
                temp = dizi[j];
                dizi[j] = dizi[j + 1];
                dizi[j + 1] = temp;
            }
        }
    }
    printf("\nSiralanmis hali\n");
    for (i = 0; i < size; i++)
    {
        printf("%d ", dizi[i]);
    }
    printf("\nAranan degeri giriniz\n");
    scanf("%d", &aranan);
    ilk = 0;
    son = size - 1;
    orta = (ilk + son) / 2;

    while (ilk <= son)
    {
        if (dizi[orta] < aranan)
        {
            ilk = orta + 1;
        }
        else if (dizi[orta] == aranan)
        {
            printf("%d sayisi %d. sirada bulundu\n", aranan, orta + 1);
            break;
        }
        else
        {
            son = orta - 1;
        }
        orta = (ilk + son) / 2;
    }
    if (ilk > son)
    {
        printf("%d bulunamadi", aranan);
    }
}