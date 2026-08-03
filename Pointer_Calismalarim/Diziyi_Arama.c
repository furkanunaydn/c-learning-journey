#include <stdio.h>
void bastir(int *dizi, int boyut)
{
    int *son_dizi;

    son_dizi = dizi + boyut - 1;

    while (dizi <= son_dizi)
    {
        scanf("%d", dizi);
        dizi++;
    }
}
int ara(int *dizi, int boyut, int aranan)
{
    int *son_dizi = dizi + boyut - 1;
    int sayac = 0;
    while (dizi <= son_dizi)
    {
        if (*dizi == aranan)
            sayac++;
        dizi++;
    }
    return sayac;
}
int main()
{

    int dizi[100], boyut, aranan, arama_sayisi;

    printf("Dizinin boyutunu giriniz: ");
    scanf("%d", &boyut);

    printf("Dizinin elemanlarini giriniz: ");
    bastir(dizi, boyut);

    printf("Aranacak sayiyi giriniz: ");
    scanf("%d", &aranan);

    arama_sayisi = ara(dizi, boyut, aranan);

    if (arama_sayisi == 0)
        printf("Aranan sayi bulunamadi.");
    else
        printf("Aranan sayi %d kez bulundu.", arama_sayisi);

    return 0;
}
