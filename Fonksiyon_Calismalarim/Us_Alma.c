#include <stdio.h>

int usAlma(int taban, int us, int *sonuc)
{
    int i;
    *sonuc = 1;
    if (us < 0)
    {
        us = -us;
        for (i = 0; i < us; i++)
        {
            *sonuc *= taban;
        }
    }
    else
    {
        if (us == 0)
        {
            *sonuc = 1;
        }
        else
        {
            for (int i = 0; i < us; i++)
            {
                *sonuc *= taban;
            }
        }
    }
}
int main()
{
    int taban, us, sonuc = 1;
    printf("Taban degerini giriniz: ");
    scanf("%d", &taban);
    printf("Us degerini giriniz: ");
    scanf("%d", &us);

    usAlma(taban, us, &sonuc);

    if (us >= 0)
    {
        printf("%d uzeri %d = %d\n", taban, us, sonuc);
    }
    else
    {
        printf("%d uzeri %d = 1/%d = %f\n", taban, us, sonuc, 1.0 / sonuc);
    }
}
