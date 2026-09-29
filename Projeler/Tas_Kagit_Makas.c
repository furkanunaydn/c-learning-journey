#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void game(char *user, char *computer)
{
    printf("Bilgisayar secimi : %c\n", *computer);
    if (*user == *computer)
    {
        printf("Berabere\n");
    }
    else if (*user == 'T' && *computer == 'M')
    {
        printf("Kazandiniz\n");
    }
    else if (*user == 'K' && *computer == 'T')
    {
        printf("Kazandiniz\n");
    }
    else if (*user == 'M' && *computer == 'K')
    {
        printf("Kazandiniz\n");
    }
    else
    {
        printf("Kaybettiniz\n");
    }
}
int main()
{
    int n;
    char user, computer;
    srand(time(NULL));
    n = rand() % 3;

    if (n == 0)
    {
        computer = 'K';
    }
    else if (n == 1)
    {
        computer = 'M';
    }
    else
    {
        computer = 'T';
    }
    do
    {
        printf("Tas(T), Kagit(K), Makas(M) seciniz: ");
        scanf(" %c", &user);

        if (user != 'T' && user != 'K' && user != 'M')
        {
            printf("Hatali secim! Lutfen T, K veya M giriniz.\n");
        }

    } while (user != 'T' && user != 'K' && user != 'M');

    game(&user, &computer);

    return 0;
}
