#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"

int main(int argc, char *argv[])
{
    int tab[15],lgeff, cpt, croissant;
    float moy, moy3;
    inittab(tab, &lgeff);
    affichetab(tab, lgeff);
    moy = moyenne(tab, lgeff);
    printf("La moyenne des nbres presents au sein du tableau vaut : %f\n", moy);
    moy3 = moyenne3(tab, lgeff);
    if(moy3 == 0)
      printf("Aucun multiple de 3 different de 0 au sein du tableau \n");
    else  
    printf("La moyenne des multiples de 3 vaut : %f\n", moy3);
    cpt = nbdanstab(tab, lgeff);
    if (cpt == 0)
      printf("Le nbre entre au clavier est absent du tableau\n");
    else
      printf("Nombre de fois qu'apparait le nbre saisi : %d\n", cpt );
    croissant = tabcroissant(tab, lgeff);
    if (croissant != 0)
      printf("Le tableau contient des valeurs croissantes \n");
    else
      printf ("Le tableau ne contient pas des valeurs croissantes \n");     
    
  system("PAUSE");	
  return 0;
}

    
