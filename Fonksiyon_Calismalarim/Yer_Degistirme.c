#include <stdio.h>

void yerDegistir(int x, int y)
{
    int gecici;

    gecici = x;
    x = y;
    y = gecici;

    printf("Yer degistirme islemi sonrasi: x = %d, y = %d\n", x, y);
}
int main()
{

    int x, y;

    printf("2 degerini giriniz: ");
    scanf("%d%d", &x, &y);

    printf("Yer degistirme islemi oncesi: x = %d, y = %d\n", x, y);
    yerDegistir(x, y);

    printf("Fonksiyondan sonra main'de: x = %d, y = %d\n", x, y);

    return 0;
}
