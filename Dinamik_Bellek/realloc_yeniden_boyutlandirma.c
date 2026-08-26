#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr, n = 5;

    printf("Girilen sayi %d\n", n);
    ptr = (int *)malloc(n * sizeof(int));

    if (ptr == NULL)
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
            printf("%d ", ptr[i]);
        }
        n = 10;
        printf("\nGirilen sayi %d\n", n);
        ptr = realloc(ptr, n * sizeof(int));
        printf("Bellek basarili sekilde yeniden ayrildi");
        for (int i = 0; i < n; i++)
        {
            ptr[i] = i + 1;
        }
        printf("Yeni elemanlar \n");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", ptr[i]);
        }
    }
}
