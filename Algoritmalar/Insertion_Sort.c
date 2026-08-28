#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size;
    int i, j, temp;

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
    for (i = 1; i < size; i++)
    {
        j = i;

        while (j > 0 && dizi[j] < dizi[j - 1])
        {
            temp = dizi[j];
            dizi[j] = dizi[j - 1];
            dizi[j - 1] = temp;
            j--;
        }
    }
    printf("\nDizinin Son hali : \n");
    for (i = 0; i < size; i++)
    {
        printf("%d ", dizi[i]);
    }
}