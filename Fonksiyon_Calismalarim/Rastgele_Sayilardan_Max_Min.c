#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int maxminBul(int dizi[], int n, int *max, int *min)
{
    *max = dizi[0];
    *min = dizi[0];

    for (int i = 1; i < n; i++)
    {
        if (dizi[i] > *max)
        {
            *max = dizi[i];
        }
        if (dizi[i] < *min)
        {
            *min = dizi[i];
        }
    }

    printf("\nDizinin en buyuk elemani: %d\n", *max);
    printf("Dizinin en kucuk elemani: %d\n", *min);
}

int main()
{

    int dizi[30], i, max, min;
    srand(time(NULL));

    for (i = 0; i < 30; i++)
    {
        dizi[i] = rand() % 100 + 1;
        printf("%d ", dizi[i]);
    }

    maxminBul(dizi, 30, &max, &min);
}
