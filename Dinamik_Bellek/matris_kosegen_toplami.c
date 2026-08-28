#include <stdio.h>
#include <stdlib.h>

int main()
{

    int boyut;
    int **matris;
    int i, j, toplam = 0;

    printf("Kare matrisiniz boyutunu giriniz : ");
    scanf("%d", &boyut);

    matris = (int **)malloc(boyut * sizeof(int *));

    for (i = 0; i < boyut; i++)
    {
        matris[i] = (int *)calloc(boyut, sizeof(int));
        for (j = 0; j < boyut; j++)
        {
            printf("Matris[%d][%d] : ", i, j);
            scanf("%d", &matris[i][j]);
        }
    }
    for (i = 0; i < boyut; i++)
    {
        toplam += matris[i][i];
    }

    printf("Toplam = %d", toplam);
    for (i = 0; i < boyut; i++)
    {
        free(matris[i]);
    }
    free(matris);
}
