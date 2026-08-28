#include <stdio.h>
#include <stdlib.h>

int main(){
    int size;
    int i,aranan;

    printf("Kac adet sayi girilecek : ");
    scanf("%d", &size);

    int dizi[size];

    printf("Dizi elemanlarini giriniz : \n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &dizi[i]);
    }
    printf("Girilen elemanlar : \n");
    for (i = 0; i < size; i++)
    {
        printf("%d ", dizi[i]);
    }
    printf("\nAranacak sayi nedir : ");
    scanf("%d",&aranan);

    for(i=0;i<size;i++){
        if(dizi[i]==aranan){
            printf("%d sayisi %d. siradadir\n",aranan,i+1);
            break;
        }
        
    }
    if(i==size){
        printf("%d Bulunamadi\n",aranan);
    }

}