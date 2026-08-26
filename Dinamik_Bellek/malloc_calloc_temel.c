#include <stdio.h>
#include <stdlib.h>

int main()
{

    int *ptr, *ptr1, n = 5;

    printf("Girilen sayi %d\n", n);
    ptr = (int *)malloc(n * sizeof(int));
    ptr1 = (int *)calloc(n, sizeof(int));

    if (ptr == NULL || ptr1 == NULL)
    {
        printf("Data bolumedi");
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            ptr[i] = i + 1;
        }
        printf("Elemanlarim\n");
        for (int i = 0; i < n; i++)
        {
            printf("%d , ", ptr[i]);
        }
    }
}
