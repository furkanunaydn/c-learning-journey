#include <stdio.h>
#include <stdlib.h>

void ortakHarf(char kelime1[], char kelime2[], int *sayac, char ortakHarfler[])
{
    int i, j, k, tekrarVar;

    for (i = 0; kelime1[i] != '\0'; i++)
    {
        for (j = 0; kelime2[j] != '\0'; j++)
        {
            if (kelime1[i] == kelime2[j])
            {
                tekrarVar = 0;
                for (k = 0; k < *sayac; k++)
                {
                    if (ortakHarfler[k] == kelime1[i])
                    {
                        tekrarVar = 1;
                        break;
                    }
                }
                if (!tekrarVar)
                {
                    ortakHarfler[*sayac] = kelime1[i];
                    (*sayac)++;
                }
                break;
            }
        }
    }
    ortakHarfler[*sayac] = '\0';
}

int main()
{

    char kelime1[100], kelime2[100], ortakHarfler[100];
    int sayac = 0;

    printf("Ilk kelimeyi giriniz: ");
    scanf("%s", kelime1);
    printf("Ikinci kelimeyi giriniz: ");
    scanf("%s", kelime2);

    ortakHarf(kelime1, kelime2, &sayac, ortakHarfler);

   
    printf("Ortak harf sayisi: %d\n", sayac);
    printf("Ortak harfler: %s\n", ortakHarfler);
}
