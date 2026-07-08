#include <stdio.h>
#include <string.h>

int main()
{

    char mesaj[100];
    char yeniMesaj[100] = "";
    int i, j = 0;

    printf("Bir mesaj giriniz: ");
    fgets(mesaj, sizeof(mesaj), stdin);

    for (i = 0; mesaj[i] != '\0'; i++)
    {
        if ((mesaj[i] >= 'a' && mesaj[i] <= 'z') || (mesaj[i] >= 'A' && mesaj[i] <= 'Z'))
            yeniMesaj[j++] = mesaj[i];
    }

    printf("Yeni mesaj: %s", yeniMesaj);
}
