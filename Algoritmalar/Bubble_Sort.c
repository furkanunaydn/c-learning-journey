#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size, temp;
    int i, j;

    printf("Kac tane sayi basilacak : ");
    scanf("%d", &size);
    int dizi[size];

    printf("Dizi elemanlarini giriniz\n");
    for (i = 0; i < size; i++)
    {
        printf("%d. eleman : ", i + 1);
        scanf("%d", &dizi[i]);
    }
    printf("Dizi elemanlari\n");
    for (i = 0; i < size; i++)
    {
        printf("%d ", dizi[i]);
    }
    for (i = 0; i < size - 1; i++)
    {
        int swapped = 0;
        for (j = 0; j < size - 1 - i; j++)
        {
            if (dizi[j] > dizi[j + 1])
            {
                temp = dizi[j];
                dizi[j] = dizi[j + 1];
                dizi[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0){
            printf("\nGirilen siralama zaten dogru bir siralamadir degisiklige ihtiyac duymaz");
            break; 
        }
            
    }
    printf("\nSiralanmis dizi elemanlari \n");
    for (i = 0; i < size; i++)
    {
        printf("%d ", dizi[i]);
    }
}
