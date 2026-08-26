#include <stdio.h>
#include <string.h>

int main()
{
    FILE *dosya;
    char cumle[30];
    int i;
    dosya = fopen("bilgi.txt", "a");

    if (dosya == NULL)
    {
        printf("Dosya bulunmadi");
    }
    else
    {
        printf("Bir cumle giriniz : ");
        fgets(cumle, 30, stdin);
        for (i = 0; cumle[i]; i++)
        {
            putc(cumle[i], dosya);
        }
        putc('\n', dosya);
    }

    fclose(dosya);
    printf("Bilgiler eklendi");
}
