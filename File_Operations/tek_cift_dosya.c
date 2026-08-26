#include <stdio.h>

int main()
{
    FILE *dosya;
    int sayi, karakter;
    dosya = fopen("tekcift.txt", "w");
    if (dosya == NULL)
    {
        printf("dosya olusturulamadi");
    }
    else
    {
        printf("Kac sayi gireceksiniz : ");
        scanf("%d", &sayi);
        for (int i = 1; i <= sayi; i++)
        {
            if (i % 2 == 0)
            {
                fprintf(dosya, "%d = Cift sayi\n", i);
            }
            else
            {
                fprintf(dosya, "%d = Tek sayi \n", i);
            }
        }
    }

    fclose(dosya);
    printf("Yazma islemi tamamlandi");
    printf("\nDosyalar okunuyor ... \n");

    dosya = fopen("tekcift.txt", "r");
    
    do
    {
        karakter = getc(dosya);
        if (karakter != EOF)
        {
            putchar(karakter);
        }
    } while (karakter != EOF);
    fclose(dosya);
    printf("Okuma islemi bitti");
}
