#include <stdio.h>

struct musteri
{
    char name[50];
    char lastname[50];
    int breakfast, dinner;
    int hotelService;
    int roommate;
};

void musteriBilgi(struct musteri *tab)
{

    printf("Isim ve Soyisim girin : ");
    scanf(" %s %s", tab->name, tab->lastname);

    printf("Kahvalti ya da aksam yemegi yemek istiyorsaniz 1'i, istemiyorsaniz 0'i tuslayin \n");
    scanf(" %d %d", &tab->breakfast, &tab->dinner);

    printf("Konaklama hizmeti istiyorsaniz 1'i , istemiyorsaniz 0'i tuslayin \n");
    scanf(" %d", &tab->hotelService);

    if (tab->hotelService == 1)
    {
        printf("Konaklamak istediginiz otel 2 yildizli olsun istiyorsaniz 2'yi , 3 yildizli olsun istiyorsaniz 3'u tuslayiniz\n");
        scanf("%d", &tab->hotelService);
    }

    printf("Odayi tek kullanacaksaniz 1'i , ekstra bir kisiyle kullanacaksaniz 0'i tuslayin\n");
    scanf("%d", &tab->roommate);
}
void ikiyildizliOtel(struct musteri *tab, int size)
{
    int i;
    printf("2 Yildizli otelde konaklayan musteriler\n");
    for (i = 0; i < size; i++)
    {
        if (tab[i].hotelService == 2)
        {
            printf(" Isim %s Soyisim %s \n", tab[i].name, tab[i].lastname);
        }
    }
}
void kahvalti(struct musteri *tab, int size, int *breakfastAreas)
{
    int i;
    *breakfastAreas = 0;
    for (i = 0; i < size; i++)
    {
        if (tab[i].breakfast == 1)
{
    if (tab[i].roommate == 0)
        *breakfastAreas += 2;
    else
        *breakfastAreas += 1;
}
    }
}
void fatura(struct musteri *tab)
{
    int mealFee, hotelFee;
    int totalPrice = 0;

    if (tab->breakfast == 1 && tab->dinner == 1)
    {
        mealFee = 50;
    }
    else if (tab->breakfast == 1 && tab->dinner == 0)
    {
        mealFee = 15;
    }
    else if (tab->breakfast == 0 && tab->dinner == 1)
    {
        mealFee = 35;
    }
    else
    {
        mealFee = 0;
    }
    if (tab->hotelService == 2)
    {
        hotelFee = 75;
    }
    else if (tab->hotelService == 3)
    {
        hotelFee = 100;
    }
    else
    {
        hotelFee = 0;
    }

    if (tab->roommate == 0)
    {
        mealFee *= 2;
    }
    totalPrice = mealFee + hotelFee;

    printf(" \n %s %s isimli musterinin odeyecegi toplam tutar : %d", tab->name, tab->lastname, totalPrice);
};

int main()
{
    struct musteri tab[100];
    int size, i, breakfastAreas;

    printf("Kac musteri olacagini girin\n");
    scanf("%d", &size);

    for (i = 0; i < size; i++)
    {
        musteriBilgi(&tab[i]);
    }
    ikiyildizliOtel(tab, size);
    kahvalti(tab, size, &breakfastAreas);

    for (i = 0; i < size; i++)
    {
        fatura(&tab[i]);
    }
    printf("\nKahvalti yapan musteri sayisi : %d", breakfastAreas);
}
