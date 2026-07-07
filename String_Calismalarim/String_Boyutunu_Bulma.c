#include <stdio.h>
#include <string.h>

int main() {

    char mesaj[100];
    printf("Bir mesaj giriniz: ");
   // scanf("%s",&mesaj);

    fgets(mesaj, sizeof(mesaj), stdin);
    printf("%s degerinin boyutu %d",mesaj,strlen(mesaj));

    return 0;

}