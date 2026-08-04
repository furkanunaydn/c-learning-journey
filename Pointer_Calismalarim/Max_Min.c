#include <stdio.h>

int main()
{
    int dizi[100], boyut, *deger, max, min;
    printf("Dizinin boyutunu giriniz: ");
    scanf("%d", &boyut);
    printf("Dizinin elemanlarini giriniz: ");
    for (deger = dizi; deger < dizi + boyut; deger++)
    {
        scanf("%d", deger);
    }
    max = dizi[0];
    min = dizi[0];
    for (deger = dizi; deger < dizi + boyut; deger++)
    {
        if (*deger > max)
        {
            max = *deger;
        }
        if (*deger < min)
        {
            min = *deger;
        }
    }
    printf("Maximum deger: %d\n", max);
    printf("Minimum deger: %d\n", min);

    return 0;
}
