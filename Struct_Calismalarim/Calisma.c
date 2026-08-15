#include <stdio.h>
struct degerTip
{
    int tip;
    union
    {
        char kar;
        float sayi;
    } bir;
};

int main()
{
    struct degerTip degerler[20];
    int i = -1, n = 0;
    float ortalama = 0.0;

    do
    {
        i++;
        printf("Karakter girmek icin 1'i ,Reel sayi girmek icin 0'i tuslayiniz ");
        scanf("%d", &degerler[i].tip);

        if (degerler[i].tip == 1)
        {
            printf("Karakter giriniz\n");
            scanf(" %c", &degerler[i].bir.kar);
        }
        else if (degerler[i].tip == 0)
        {
            printf("Reel sayi giriniz\n");
            scanf(" %f", &degerler[i].bir.sayi);
        }
    } while (degerler[i].tip == 0 || degerler[i].tip == 1);

    for (int j = 0; j < i; j++)
    {
        if (degerler[j].tip == 0)
        {
            ortalama += degerler[j].bir.sayi;
            n++;
        }
    }
    ortalama = ortalama / n;
    printf("Reel sayilarin ortalamasi : %f", ortalama);
}
