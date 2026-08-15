#include <stdio.h>
#include <string.h>

struct personel
{
    int sifre;
    char isim[100];
    char soyisim[100];
    int yas;
    float maas;
    char cinsiyet[10];
};
void sirala(struct personel kisiler[], int size)
{
    int i, j;
    struct personel temp;
    for (i = 0; i < size - 1; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (strcmp(kisiler[i].isim, kisiler[j].isim) > 0)
            {
                temp = kisiler[i];
                kisiler[i] = kisiler[j];
                kisiler[j] = temp;
            }
        }
    }
}
void listele(struct personel kisiler[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d  %s  %s  %s  %d  %.2f \n", kisiler[i].sifre, kisiler[i].isim, kisiler[i].soyisim, kisiler[i].cinsiyet, kisiler[i].yas, kisiler[i].maas);
    }
}

int main()
{
    int size, i;
    struct personel kisiler[100];
    printf("Kac adet personel bilgisi gireceksiniz : ");
    scanf("%d", &size);

    for (i = 0; i < size; i++)
    {
        printf("Sifre : ");
        scanf("%d", &kisiler[i].sifre);
        getchar();

        printf("Isim : ");
        fgets(kisiler[i].isim, 100, stdin);
        kisiler[i].isim[strcspn(kisiler[i].isim, "\n")] = '\0';

        printf("Soyisim : ");
        fgets(kisiler[i].soyisim, 100, stdin);
        kisiler[i].soyisim[strcspn(kisiler[i].soyisim, "\n")] = '\0';

        printf("Cinsiyet : ");
        fgets(kisiler[i].cinsiyet, 100, stdin);
        kisiler[i].cinsiyet[strcspn(kisiler[i].cinsiyet, "\n")] = '\0';

        printf("Yas : ");
        scanf("%d", &kisiler[i].yas);
        getchar();

        printf("Maas : ");
        scanf("%f", &kisiler[i].maas);
        getchar();
    }
    sirala(kisiler, size);
    listele(kisiler, size);
}
