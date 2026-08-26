#include <stdio.h>
#include <string.h>

int main()
{
    FILE *giris, *cikis;
    char kaynak[50], hedef[50];
    int karakter;
    printf("Yedeklenecek dosyanin adini ve uzantisini gir : ");
    fgets(kaynak, 50, stdin);
    kaynak[strcspn(kaynak, "\n")] = '\0';
    giris = fopen(kaynak, "r");

    if (giris == NULL)
    {
        printf("Dosya okunamadi\n");
    }
    else
    {
        printf("Yedeklenecek dosyanin yerini,dosya adini ve uzantisini girin\n");
        fgets(hedef, 50, stdin);
        hedef[strcspn(hedef, "\n")] = '\0';

        cikis = fopen(hedef, "w");
        if (cikis == NULL)
        {
            printf("Dosya olusturulamadi\n");
        }
        else
        {
            for (karakter = getc(giris); karakter != EOF; karakter = getc(giris))
            {
                putc(karakter, cikis);
            }
        }
    }
    fclose(giris);
    fclose(cikis);
    printf("Yedekleme tamamlandi");
}
