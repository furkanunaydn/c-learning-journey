#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size;
    int min, temp;
    int i, j;

    printf("Kac adet sayi girilecektir : ");
    scanf("%d", &size);
    int dizi[size];
    printf("Dizi elemanlarini giriniz :\n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &dizi[i]);
    }
    printf("Girilen elemanlariniz : ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", dizi[i]);
    }
    for (i = 0; i < size - 1; i++)
    {
        min = i;
        for (j = i + 1; j < size; j++)
        {
            if (dizi[min] > dizi[j])
            {
                min = j;
            }
        }
        if (min != i)
        {
            temp = dizi[i];
            dizi[i] = dizi[min];
            dizi[min] = temp;
        }
    }

    printf("Dizinin son hali\n");
    for (i = 0; i < size; i++)
    {
        printf("%d ", dizi[i]);
    }
}
