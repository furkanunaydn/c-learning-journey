#include <stdio.h>

void matrisElemanlariniAl(int matris[100][100], int A, int B)
{
    int i, j;
    printf("Matrisin elemanlarini giriniz:\n");
    for (i = 0; i < A; i++)
    {
        for (j = 0; j < B; j++)
        {
            printf("Matrisin [%d][%d] elemanini giriniz: ", i, j);
            scanf("%d", &matris[i][j]);
        }
    }
}
void matrisYaz(int matris[100][100], int A, int B)
{
    int i, j;
    printf("Matrisin elemanlari:\n");
    for (i = 0; i < A; i++)
    {
        for (j = 0; j < B; j++)
        {
            printf("%d ", matris[i][j]);
        }
        printf("\n");
    }
}
void matrisiAnalizEt(int matris[100][100], int A, int B, int *max, int *min, int *toplam)
{
    int i, j;
    *max = matris[0][0];
    *min = matris[0][0];
    *toplam = 0;

    for (i = 0; i < A; i++)
    {
        for (j = 0; j < B; j++)
        {
            if (matris[i][j] > *max)
            {
                *max = matris[i][j];
            }
            if (matris[i][j] < *min)
            {
                *min = matris[i][j];
            }
            *toplam += matris[i][j];
        }
    }
}
int main()
{
    int A, B, max, min, toplam;
    int matris[100][100];
    printf("Matrisin satir sayisini giriniz: ");
    scanf("%d", &A);
    printf("Matrisin sutun sayisini giriniz: ");
    scanf("%d", &B);

    matrisElemanlariniAl(matris, A, B);
    matrisYaz(matris, A, B);
    matrisiAnalizEt(matris, A, B, &max, &min, &toplam);
    printf("Matrisin en buyuk elemani: %d\n", max);
    printf("Matrisin en kucuk elemani: %d\n", min);
    printf("Matrisin elemanlarinin toplami: %d\n", toplam);

    return 0;
}
