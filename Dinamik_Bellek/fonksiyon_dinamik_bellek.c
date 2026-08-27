#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void diziOlustur(int *ptr, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        ptr[i] = rand() % 100;
        printf("%d  ", ptr[i]);
    }
    printf("\n");
}
void diziSirala(int *ptr, int size)
{
    int i, j, temp;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (ptr[j] > ptr[j + 1])
            {
                temp = ptr[j];
                ptr[j] = ptr[j + 1];
                ptr[j + 1] = temp;
            }
        }
    }
    printf("Dizinin siralanmis hali : \n");
    for (i = 0; i < size; i++)
    {
        printf("%d  ", ptr[i]);
    }
}
void diziMaxMin(int *ptr, int size)
{
    int max, min;
    max = ptr[0];
    min = ptr[0];
    for (int i = 0; i < size; i++)
    {
        if (ptr[i] > max)
            max = ptr[i];
        if (ptr[i] < min)
            min = ptr[i];
    }
    printf("\nDizinin en buyuk elemani : %d", max);
    printf("\nDizinin en kucuk elemani : %d", min);
}

int main()
{
    int size, i;
    int *ptr;

    printf("Kac adet sayi uretilecek : ");
    scanf("%d", &size);
    srand(time(0));

    ptr = (int *)malloc(size * sizeof(int));
    diziOlustur(ptr, size);
    diziSirala(ptr, size);
    diziMaxMin(ptr, size);

    free(ptr);
}
