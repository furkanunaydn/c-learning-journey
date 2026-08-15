#include <stdio.h>
#include <string.h>

struct adresDefteri
{
    char isim[20];
    char soyisim[20];
    char telefonNO[20];
    char adres[100];
    char postaKodu[20];
};
int main()
{
    int size, i;
    struct adresDefteri bilgiler[100];
    printf("Kac kisinin bilgisini gireceksiniz\n");

    scanf("%d", &size);

    for (i = 0; i < size; i++)
    {
        printf("Isim? : ");
        fgets(bilgiler[i].isim, 20, stdin);

        printf("Soyisim? : ");
        fgets(bilgiler[i].soyisim, 20, stdin);

        printf("Telefon Numarasi? : ");
        fgets(bilgiler[i].telefonNO, 20, stdin);

        printf("Adresiniz? : ");
        fgets(bilgiler[i].adres, 100, stdin);

        printf("Posta Kodunuz? : ");
        fgets(bilgiler[i].postaKodu, 20, stdin);
    }

    printf("----- BILGILERINIZ -----\n");
    for (i = 0; i < size; i++)
    {
        printf("%s\t%s\t%s\t%s\t%s\n",
               bilgiler[i].isim, bilgiler[i].soyisim,
               bilgiler[i].telefonNO, bilgiler[i].adres, bilgiler[i].postaKodu);
    }
}
