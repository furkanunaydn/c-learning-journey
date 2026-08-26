#include <stdio.h>

struct ogrenci
{
    char isimsoyisim[50];
    char dersAdi[20];
    int vize1, vize2, final;
};

int main()
{
    FILE *dosya;
    int N, i;
    float ortalama;
    printf("Kac adet ogrenci bilgisi gireceksiniz : ");
    scanf("%d", &N);
    getchar();
    struct ogrenci obs[N];

    dosya = fopen("dersnotu.txt", "w");

    if (dosya == NULL)
    {
        printf("Dosya olusturulamdi");
    }
    else
    {
        for (i = 0; i < N; i++)
        {

            printf("Adi soyadi : ");
            fgets(obs[i].isimsoyisim, 50, stdin);

            printf("Ders adi : ");
            fgets(obs[i].dersAdi, 20, stdin);

            printf("Vize1 Notu : ");
            scanf("%d", &obs[i].vize1);

            printf("Vize2 Notu : ");
            scanf("%d", &obs[i].vize2);

            printf("Final Notu : ");
            scanf("%d", &obs[i].final);
            getchar();
            ortalama = (obs[i].vize1 * 0.2) + (obs[i].vize2 * 0.2) + (obs[i].final * 0.6);

            fprintf(dosya, "%s \t %s\t %d\t %d\t %d\t %.2f\n", obs[i].isimsoyisim, obs[i].dersAdi, obs[i].vize1, obs[i].vize2, obs[i].final, ortalama);
        }
    }
    fclose(dosya);
}
