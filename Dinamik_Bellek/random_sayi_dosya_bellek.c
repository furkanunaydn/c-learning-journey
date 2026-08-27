#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

    FILE *dosya;
    int *ptr, size, i, c;

    printf("Kac adet tamsayi giriceksiniz : ");
    scanf("%d", &size);

    ptr = (int *)malloc(size * sizeof(int));
    dosya = fopen("sayi.txt", "w");

    srand(time(0));

    printf("\t---Uretilen degerler---\t \n");
    for (i = 0; i < size; i++)
    {
        *(ptr + i) = rand() % 100;
        fprintf(dosya, " %d ", *(ptr + i));
        printf(" %d ", *(ptr + i));
    }
    printf("\n");

    fclose(dosya);
    printf("\t---Okunan sayilar---\t\n");

    dosya = fopen("sayi.txt", "r");

    do
    {
        c = getc(dosya);
        if (c != EOF)
        {
            putchar(c);
        }
    } while (c != EOF);

    fclose(dosya);

    free(ptr);
}
