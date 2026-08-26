#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *dosya;
    char kelime[30];

    while (1)
    {
        printf("Bir kelime gir : ");
        fgets(kelime, 30, stdin);
        if (kelime[0] == '0')
        {
            break;
        }
        else
        {
            dosya = fopen("bilgi.txt", "a");
            if (dosya == NULL)
            {
                printf("HATA");
            }
            else
            {
                fprintf(dosya, "%s \n", kelime);
                fclose(dosya);
            }
        }
    }
}
