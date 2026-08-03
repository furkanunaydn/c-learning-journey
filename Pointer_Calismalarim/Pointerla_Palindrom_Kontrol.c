#include <stdio.h>
#include <string.h>

int main () {
   
    char cumle[100];
    char *p1,*p2;    
    int kontrol =1;                                        
   printf("Maksimum 100 kelimelik bir cumle gir : ");
   fgets(cumle,100,stdin);
   cumle[strcspn(cumle, "\n")] = '\0';
   for(p2=cumle;*p2;p2++) ;
   
    p2--;

   for(p1=cumle;kontrol && p1<p2;p1++,p2--) {

    if(*p1 != *p2) {
        kontrol = 0;
    }
   }
  if(kontrol){
      printf("Girilen cumle Palindromdur ");
  }
    
  else {
       printf("Girilen cumle Palindrom degildir ");
  }
  
    return 0;
}
