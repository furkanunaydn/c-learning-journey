#include <stdio.h>
#include <string.h>

int palindrom(char cumle[100])
{
    char ters[100];
    int i, j = 0, uzunluk;

    for (i = 0; cumle[i] != '\0'; i++)
    {

        if (cumle[i] != ' ')
        {
            cumle[j] = cumle[i];
            j++;
        }
    }
    cumle[j] = '\0';

    uzunluk = strlen(cumle);

    for (i = 0; i < uzunluk; i++)
    {
        ters[i] = cumle[uzunluk - i - 1];
    }
    ters[uzunluk] = '\0';
    for (i = 0; i < uzunluk; i++)
    {
        if (ters[i] != cumle[i])
        {
            return 0;
        }
    }
    return 1;
}
int main()
{

    char cumle[100], ters[100];
    printf("Bir cumle girin: ");
    scanf(" %[^\n]", cumle);
    if (palindrom(cumle))
    {
        printf("Girilen cumle palindromdur.\n");
    }
    else
    {
        printf("Girilen cumle palindrom degildir.\n");
    }
    return 0;
}
