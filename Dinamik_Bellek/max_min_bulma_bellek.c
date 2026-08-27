#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int size, i, max, min;
    int *ptr;

    printf("Kac adet sayi uretilecektir : ");
    scanf("%d", &size);

    ptr = (int *)malloc(size * sizeof(int));

    srand(time(0));
    for (i = 0; i < size; i++)
    {
        *(ptr + i) = rand() % 1000;
        printf("%d ", *(ptr + i));
    }
    printf("\n");
    min = *ptr;
    max = *ptr;

    for (i = 1; i < size; i++)
    {
        if (*(ptr + i) < min)
        {
            min = *(ptr + i);
        }
    }
    for (i = 1; i < size; i++)
    {
        if (*(ptr + i) > min)
        {
            max = *(ptr + i);
        }
    }
    printf("En kucuk sayi = %d\n", min);
    printf("En buyuk sayi = %d\n", max);
    free(ptr);
}
