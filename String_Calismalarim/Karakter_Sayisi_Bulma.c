#include <stdio.h>
#include <string.h>

int main()
{

    char mesaj[100], karakter;
    int i, sayac = 0;
    printf("Bir mesaj giriniz: ");
    fgets(mesaj, sizeof(mesaj), stdin);

    printf("Kontrol etmek istediginiz karakteri giriniz: ");
    scanf(" %c", &karakter);

    for (i = 0; mesaj[i] != '\0'; i++)
    {
        if (mesaj[i] == karakter)
        {
            sayac++;
        }
    }

    printf("%s degerinde %c karakteri %d kez gecmektedir.", mesaj, karakter, sayac);

    return 0;
}
