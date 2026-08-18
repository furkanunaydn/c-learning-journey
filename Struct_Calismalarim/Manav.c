#include <stdio.h>
#include <string.h>
#define fruitAmount 2

struct fruit
{
    char name[50];
    float weight,
        unitPrice;
    int shape,
        count;
};
struct basket
{
    struct fruit f[fruitAmount];
};
enum shape
{

    yuvarlak = 1,
    kare,
    dikdortgen
};

void fillFruit(struct fruit *tab)
{
    printf("Aldiginiz meyvenin ismi : \n");
    scanf("%s", tab->name);

    printf("Aldiginiz meyvenin kilosu : \n");
    scanf("%f", &tab->weight);

    printf("Aldiginiz meyvenin birim fiyati : \n");
    scanf("%f", &tab->unitPrice);

    printf("Aldiginiz meyvenin sekli yuvarlak ise 1'i , kare ise 2'yi , dikdortgen ise 3'u tuslayiniz: \n");
    scanf("%d", &tab->shape);

    printf("Aldiginiz meyvenin sayisi : \n");
    scanf("%d", &tab->count);
}
void fillBasket(struct basket *basket)
{
    int i;
    for (i = 0; i < fruitAmount; i++)
    {
        fillFruit(&basket->f[i]);
    }
}
void weightCalculate(struct basket tab, float *totalWeight)
{
    int i;
    *totalWeight = 0;
    for (i = 0; i < fruitAmount; i++)
    {
        *totalWeight += tab.f[i].weight * tab.f[i].count;
    }
}
void priceCalculate(struct basket tab, float *totalPrice)
{
    int i;
    float price = 0.0;
    *totalPrice = 0;

    for (i = 0; i < fruitAmount; i++)
    {
        price = tab.f[i].unitPrice;

        if (tab.f[i].shape == yuvarlak)
        {
            price *= 2;
        }
        if (tab.f[i].weight > 200)
        {
            price += 3;
        }
        *totalPrice += tab.f[i].count * price;
    }
}

int main()
{
    float totalPrice, totalWeight;
    struct basket tab;

    fillBasket(&tab);
    weightCalculate(tab, &totalWeight);
    priceCalculate(tab, &totalPrice);

    printf("Toplam agirliginiz : %.2f \n", totalWeight);
    printf("Odenecek toplam fiyat : %.2f \n", totalPrice);

    return 0;
}
