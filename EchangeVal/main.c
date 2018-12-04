#include <stdio.h>
#include <stdlib.h>
#include "Echangevaleurs.c"

int main(int argc, char *argv[])
{
    int un,deux;

   printf("Entrez un premier entier :\n");
   scanf("%d",&un);
   printf("Entrez un deuxieme entier :\n");
   scanf("%d",&deux);
   Echange1(un,deux);
   printf("Apres appel de la fonction Echange1,\n");
   printf("le premier entier vaut : %d \n", un);
   printf("le deuxieme entier vaut : %d \n", deux);
   Echange2(&un,&deux);
   printf("Apres appel de la fonction Echange2,\n");
   printf("le premier entier vaut : %d \n", un);
   printf("le deuxieme entier vaut : %d \n", deux);
  system("PAUSE");
  return 0;
}
