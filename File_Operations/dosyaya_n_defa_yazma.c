#include <stdio.h>

int main()
{

    FILE *dosya;
    char dizi[30];
    int i, N;

    dosya = fopen("bilgi.txt", "w");
    if (dosya == NULL)
    {
        printf("dosya olusturulamadi");
    }
    else
    {
        printf("Bir cumle giriniz\n");
        fgets(dizi, 30, stdin);
        printf("Kac satir yazilacak\n");
        scanf("%d", &N);

        for (i = 0; i < N; i++)
        {
            fprintf(dosya, "Satir no : %d Cumle : %s", i, dizi);
        }
    }
    fclose(dosya);
    printf("Dosya tamamlandi");
}
