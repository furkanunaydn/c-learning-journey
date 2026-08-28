#include <stdio.h>
#include <stdlib.h>

void quickSort(int *dizi, int ilk, int son)
{
    int temp, i, j, pivot;

    if (ilk < son)
    {
        pivot = ilk;
        i = ilk;
        j = son;
        while (i < j)
        {
            while (dizi[i] <= dizi[pivot] && i < son)
            {
                i++;
            }
            while (dizi[j] > dizi[pivot])
            {
                j--;
            }
            if (i < j)
            {
                temp = dizi[i];
                dizi[i] = dizi[j];
                dizi[j] = temp;
            }
        }
        temp = dizi[pivot];
        dizi[pivot] = dizi[j];
        dizi[j] = temp;

        quickSort(dizi, ilk, j - 1);
        quickSort(dizi, j + 1, son);
    }
}

int main()
{
    int size;
    int i;

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
    quickSort(dizi, 0, size - 1);

    printf("\nDizinin Son hali : \n");
    for (i = 0; i < size; i++)
    {
        printf("%d ", dizi[i]);
    }
}
