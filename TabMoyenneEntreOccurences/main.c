#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#define N 15

int main(int argc, char *argv[])
{
 int tab[N], lgeff, nbreintab, cptnbreintab, entre2fois = 0;
     /* entre2fois compte le nombre de données entre 2 apparitions du nombre
        recherché au sein du tableau */
 float moy;
 inittab(tab, &lgeff);
 affichetab(tab, lgeff);
 printf ("entrer un nombre au clavier : \n");
 scanf ("%d", &nbreintab);
 cptnbreintab = apparition_nbreintab (tab, lgeff, nbreintab);
 if (cptnbreintab == 0)
   printf("le nombre entre au clavier est absent du tableau\n\n");
 else
 { 
   if (cptnbreintab == 1)
     printf("le nombre entre n' apparait qu' 1 fois dans le tableau\n\n");
   else
    {
      moy = moy_entre_2_1eresapparition_nbre(tab,nbreintab,&entre2fois);         
      if (!(entre2fois))  // if (entre2fois == 0)
        printf ("aucune donnee entre les 2 1eres fois \n");
      else
        printf("la moyenne entre les 2 1ere fois vaut : %f\n", moy); 
     }    
 }  
   
    
  system("PAUSE");	
  return 0;
}
