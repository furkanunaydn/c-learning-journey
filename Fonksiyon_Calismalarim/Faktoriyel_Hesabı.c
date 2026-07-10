#include <stdio.h>
#include <stdlib.h>

int faktoriyel(int sayi)
{

    int i, sonuc;
    sonuc = 1;

    for (i = 1; i <= sayi; i++)
    {
        sonuc *= i;
    }
    return sonuc;
}
int main()
{

    int sayi;

    printf("Faktoriyelini hesaplamak istediginiz sayiyi giriniz: ");
    scanf("%d", &sayi);

    if (sayi < 0)
    {
        printf("Negatif sayilarin faktoriyeli hesaplanamaz.\n");
        return 0;
    }
    printf("%d! = %d\n", sayi, faktoriyel(sayi));

    return 0;
}
