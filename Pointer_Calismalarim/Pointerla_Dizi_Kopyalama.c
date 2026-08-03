#include <stdio.h>

void bastir(int *dizi, int n)
{
    printf("Dizinin elemanlari: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", *dizi);
        dizi++;
    }
    printf("\n");
}

int main()
{

    int ilk_dizi[100];
    int hedef_dizi[100];
    int n, i;
    int *ilk_ptr;
    int *hedef_ptr;
    int *son_ptr;

    ilk_ptr = ilk_dizi;
    hedef_ptr = hedef_dizi;

    printf("Dizinin boyutunu giriniz: ");

    scanf("%d", &n);

    printf("Dizinin elemanlarini giriniz: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", (ilk_ptr + i));
    }
    son_ptr = &ilk_dizi[n - 1];

    printf("Dizinin kopyalamadan onceki hali: \n");
    bastir(ilk_dizi, n);

    while (ilk_ptr <= son_ptr)
    {
        *hedef_ptr = *ilk_ptr;
        ilk_ptr++;
        hedef_ptr++;
    }

    printf("Dizinin kopyalandiktan sonraki hali: \n");
    bastir(hedef_dizi, n);

    return 0;
}
