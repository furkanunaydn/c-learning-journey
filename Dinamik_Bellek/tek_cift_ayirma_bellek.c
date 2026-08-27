#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size, *ptr1, *ptr2;
    int i, cift = 0, tek = 0;

    printf("Hangi degere kadar sayi alinacak : ");
    scanf("%d", &size);

    ptr1 = (int *)malloc(size * sizeof(int));
    ptr2 = (int *)malloc(size * sizeof(int));

    for (i = 0; i < size; i++)
    {
        if (i % 2 == 0)
        {
            *(ptr1 + cift) = i;
            cift++;
        }
        else
        {
            *(ptr2 + tek) = i;
            tek++;
        }
    }
    printf("\t---Cift sayilar---\t");
    for (i = 0; i < cift; i++)
    {
        printf("%d ", ptr1[i]);
    }
    printf("\n");
    printf("\t---Tek Sayilar---\t");
    for (i = 0; i < tek; i++)
    {
        printf("%d ", ptr2[i]);
    }
    free(ptr1);
    free(ptr2);
}
