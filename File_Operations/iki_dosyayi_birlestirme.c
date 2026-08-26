#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *d1, *d2, *d3;
    int karakter;
    d1 = fopen("bilgi.txt", "r");
    d2 = fopen("dersnotu.txt", "r");
    d3 = fopen("tekcift.txt", "w");

    if (d1 == NULL || d2 == NULL || d3 == NULL)
    {
        printf("HATA");
    }
    else
    {
        do
        {
            karakter = getc(d1);
            if (karakter != EOF)
            {
                fprintf(d3, "%c", karakter);
            }

        } while (karakter != EOF);
        fprintf(d3, "\n");
        do
        {
            karakter = getc(d2);
            if (karakter != EOF)
            {
                fprintf(d3, "%c", karakter);
            }
        } while (karakter != EOF);
        printf("birlestirme tamamlandı");
        fclose(d1);
        fclose(d2);
        fclose(d3);
    }
}
