#include <stdio.h>
#include <string.h>

int main()
{

    char ad[100], soyad[100], isim[200];
    printf("Adinizi giriniz: ");
    fgets(ad, sizeof(ad), stdin);
    printf("Soyadinizi giriniz: ");
    fgets(soyad, sizeof(soyad), stdin);

    strcpy(isim, ad);
    strcat(isim, soyad);

    printf("Isminiz: %s", isim);

    return 0;
}
