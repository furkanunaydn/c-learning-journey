#include <stdio.h>
#include <stdlib.h>

int main()
{

    int *ptr, N;

    printf("N degerini giriniz : ");
    scanf("%d", &N);

    ptr = (int *)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++)
    {
        printf("%d. sayimiz ", i + 1);
        scanf("%d", &ptr[i]);
    }
    for (int i = 0; i < N; i++)
    {
        printf("%d ", *(ptr + i));
    }
    free(ptr);
}
