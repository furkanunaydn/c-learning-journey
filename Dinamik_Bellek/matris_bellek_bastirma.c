#include <stdio.h>
#include <stdlib.h>

int main()
{

    int satir, sutun;
    int **matris;
    int i, j;

    printf("Satir ve sutun sayisini giriniz : ");
    scanf("%d %d", &satir, &sutun);

    matris = (int **)calloc(satir, sizeof(int *));

    for (i = 0; i < satir; i++)
    {
        matris[i] = (int *)calloc(sutun, sizeof(int));
        for (j = 0; j < sutun; j++)
        {
            printf("Matris[%d][%d] = ", i, j);
            scanf("%d", &matris[i][j]);
        }
    }
    for (i = 0; i < satir; i++)
    {
        for (j = 0; j < sutun; j++)
        {
            printf("%3d", matris[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < satir; i++)
    {
        free(matris[i]);
    }
    free(matris);
}
