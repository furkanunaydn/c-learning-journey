#include <stdio.h>
#include <string.h>
#define storeSize 3
#define productSize 5
struct worker
{
    char name[50],
        lastname[50];
    int age;
};

struct product
{
    char refCode[50];
    float price;
};

struct store
{
    char name[50],
        street[50],
        district[50],
        phone[20];
    float sales;
    struct worker workers[3];
    struct product products[5];
};
void fillProduct(struct product products[5])
{
    for (int i = 0; i < 5; i++)
    {
        printf("%d. urunun referans kodunu giriniz : \n", i + 1);
        scanf("%s", products[i].refCode);

        printf("%d. urunun fiyatini giriniz : \n", i + 1);
        scanf("%f", &products[i].price);
    }
}

void fillWorker(struct worker *workers)
{
    for (int i = 0; i < 3; i++)
    {
        printf("%d. Iscinin isim ve soyismi : \n", i + 1);
        scanf("%s %s", workers[i].name, workers[i].lastname);

        printf("%d. Iscinin yasi: \n", i + 1);
        scanf("%d", &workers[i].age);
    }
}

void fillStore(struct store *tab)
{
    int i;
    printf("Magaza ismini giriniz: \n");
    scanf("%s", tab->name);

    printf("Magazanin bulundugu sokagi giriniz: \n");
    scanf("%s", tab->street);

    printf("Magazanin bulundugu mahallesini giriniz: \n");
    scanf("%s", tab->district);

    printf("Magazanin telefon numarasini giriniz: \n");
    scanf("%s", tab->phone);

    printf("Magazanin satis miktarini giriniz : \n");
    scanf("%f", &tab->sales);

    printf("Calisan bilgilerini giriniz : \n");
    fillWorker(tab->workers);
    printf("Urun bilgilerini giriniz : \n");
    fillProduct(tab->products);
}

void printProduct(struct product products)
{
    printf("Referans kodu : %s \n", products.refCode);
    printf("Urunun fiyati : %.2f \n", products.price);
}

void printWorker(struct worker workers)
{
    printf("Isim : %s \n", workers.name);
    printf("Soyisim : %s \n", workers.lastname);
    printf("Yasi : %d \n", workers.age);
}

void printStore(struct store tab)
{
    printf("========================================\n");
    printf("Magaza ismi        : %s\n", tab.name);
    printf("Sokak              : %s\n", tab.street);
    printf("Mahalle            : %s\n", tab.district);
    printf("Telefon            : %s\n", tab.phone);
    printf("Satis miktari      : %.2f\n", tab.sales);
    printf("--- Isciler ---\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%d. Isci:\n", i + 1);
        printWorker(tab.workers[i]);
    }
    printf("--- Urunler ---\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d. Urun:\n", i + 1);
        printProduct(tab.products[i]);
    }
    printf("========================================\n\n");
}

void oldestWorker(struct store tab)
{
    struct worker oldest = tab.workers[0];
    for (int i = 1; i < 3; i++)
    {
        if (tab.workers[i].age > oldest.age)
        {
            oldest = tab.workers[i];
        }
    }
    printf("En yasli isci : \n");
    printWorker(oldest);
}

void averagePrice(struct store tab[storeSize])
{
    int i, j;
    for (i = 0; i < storeSize; i++)
    {
        float totalPrice = 0;
        for (j = 0; j < productSize; j++)
        {
            totalPrice += tab[i].products[j].price;
        }
        printf("%s magazasinin urunlerinin ortalama fiyati %.2f \n", tab[i].name, (totalPrice / productSize));
    }
}

void printDistrict(struct store tab[storeSize], char estimate[20])
{
    for (int i = 0; i < storeSize; i++)
    {
        if (strcmp(tab[i].district, estimate) == 0)
        {
            printf("%s mahallesinde %s magazasi bulunur \n", tab[i].district, tab[i].name);
        }
    }
}
void topStore(struct store tab[storeSize])
{
    struct store best = tab[0];
    for (int i = 1; i < storeSize; i++)
    {
        if (tab[i].sales > best.sales)
        {
            best = tab[i];
        }
    }
    printf("En cok satis yapan magaza %s , Satis miktari = %.2f \n", best.name, best.sales);
}

int main()
{
    int i;
    struct store tab[storeSize];

    for (i = 0; i < storeSize; i++)
    {
        printf("%d. ", i + 1);
        fillStore(&tab[i]);
    }
    for (i = 0; i < storeSize; i++)
    {
        printStore(tab[i]);
    }

    oldestWorker(tab[0]);
    averagePrice(tab);
    printDistrict(tab, "Besiktas");
    topStore(tab);

    return 0;
}
