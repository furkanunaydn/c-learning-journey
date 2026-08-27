#include <stdio.h>
#include <stdlib.h>

int main()
{

    int *sayi1, *sayi2, temp;
    sayi1 = (int *)malloc(sizeof(int));
    sayi2 = (int *)malloc(sizeof(int));

    printf("Yerlerini degistirmek istediginiz sayilari giriniz : ");
    scanf("%d %d", &(*sayi1), &(*sayi2));

    printf("Yer degistirmeden onceki halleri sayi1 = %d | sayi2 = %d \n", *sayi1, *sayi2);

    temp = *sayi1;
    *sayi1 = *sayi2;
    *sayi2 = temp;

    printf("Yer degistirdikten sonraki halleri sayi1 = %d | sayi2 = %d \n", *sayi1, *sayi2);
    free(sayi1);
    free(sayi2);
}
