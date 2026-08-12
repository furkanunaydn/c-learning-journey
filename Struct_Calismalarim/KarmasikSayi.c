#include <stdio.h>

struct karmasikSayi
{
    float reel;
    float sanal;
};

struct karmasikSayi islemYap(struct karmasikSayi sayi1,struct karmasikSayi sayi2,int secim)
{
    struct karmasikSayi sonuc={0, 0};
    switch(secim)
    {
        case 1:
            sonuc.reel = sayi1.reel + sayi2.reel;
            sonuc.sanal = sayi1.sanal + sayi2.sanal;
            printf("Toplam: %.2f + %.2fi\n", sonuc.reel, sonuc.sanal);
            break;
        case 2:
            sonuc.reel = sayi1.reel - sayi2.reel;
            sonuc.sanal = sayi1.sanal - sayi2.sanal;
            printf("Fark: %.2f + %.2fi\n", sonuc.reel, sonuc.sanal);
            break;
        case 3:
            sonuc.reel = (sayi1.reel * sayi2.reel) - (sayi1.sanal * sayi2.sanal);
            sonuc.sanal = (sayi1.reel * sayi2.sanal) + (sayi1.sanal * sayi2.reel);
            printf("Carpim: %.2f + %.2fi\n", sonuc.reel, sonuc.sanal);
            break;
        case 4:
            float payda = (sayi2.reel * sayi2.reel) + (sayi2.sanal * sayi2.sanal);
            if(payda == 0)
            {
                printf("Hata: Sifira bolme hatasi!\n");
                return sonuc;
            }
            sonuc.reel = ((sayi1.reel * sayi2.reel) + (sayi1.sanal * sayi2.sanal)) / payda;
            sonuc.sanal = ((sayi1.sanal * sayi2.reel) - (sayi1.reel * sayi2.sanal)) / payda;
            printf("Bolum: %.2f + %.2fi\n", sonuc.reel, sonuc.sanal);
            break;
        default:
            printf("Gecersiz secim.\n");
    }
    return sonuc;
}

int main()
{
    int secim;
    struct karmasikSayi sayi1, sayi2;
    printf("Birinci karmasik sayinin reel kismini girin: ");
    scanf("%f", &sayi1.reel);
    printf("Birinci karmasik sayinin sanal kismini girin: ");
    scanf("%f", &sayi1.sanal);
    printf("Ikinci karmasik sayinin reel kismini girin: ");
    scanf("%f", &sayi2.reel);
    printf("Ikinci karmasik sayinin sanal kismini girin: ");
    scanf("%f", &sayi2.sanal);

    printf("Yapmak istediginiz islemi seCin:\n");
    printf("1. Toplama\n");
    printf("2. Cikarma\n");
    printf("3. Carpma\n");
    printf("4. Bolme\n");
    scanf("%d", &secim);
    
    islemYap(sayi1, sayi2, secim);
    return 0;
}
