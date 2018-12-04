#include <stdio.h>
#include <stdlib.h>
#define N 5


void InitialiseTab (int [], int , int*);
void AfficheTab (int [], int);
void InverseTab (int [], int);
void EchangeValeurs ( int [], int []);


int main(int argc, char *argv[])

{
  int tab [N], lgtab;

  printf("DANS LA FONCTION MAIN : \n\n");

  printf("Valeur contenue dans Pointeur 'IDENTIFICATEUR' tableau : %x\n",tab);
  printf("Entrer la 1ere valeur du tableau :\n");
  scanf("%d", tab); /* pas besoin de l'opérateur & car tab est l'adresse en M-C
                    de la 1ere composante  du tableau
                    mais cet opérateur est nécessaire pour
                    scanf("%d", &tab[0])  !!!! */
  /* tab[0] = 5; */
  printf("Valeur de la composante stockee a cette adresse : %d\n",*tab);
  printf("Incrementation de la Valeur presente a cette adresse : %d\n",++(*tab));
  /*   !!!   tab++; ERREUR à la Compilation :  wrong type argument to increment
       idem pour ++tab  car identificateur tab n'est pas une Lvalue, c-à-d
       qu'il ne peut pas se trouver à la gauche du sigle d'affectation (=).
       L'identificateur de type tableau est un pointeur constant qui contient
       l'adresse de la 1ere composante du tableau*/
  printf("Adresse de l'element d'indice tab[0]  : %x\n",&tab[0]);
  printf("Adresse du 2eme element du tableau : %x\n\n", (tab + 1));




  InitialiseTab(tab, N, &lgtab);
  printf ("Tableau saisi :\n\n");
  printf("DANS LA FONCTION AfficheTab : \n\n");
  AfficheTab (tab, lgtab);
  InverseTab (tab, lgtab);
  printf ("\n\nTableau apres inversion des valeurs :\n\n");
  AfficheTab (tab, lgtab);

  system("PAUSE");
  return 0;
}


void InitialiseTab( int t[], int dim, int* leff)
{
  int nb = 0;
  *leff = 0;
  printf("Saisissez un tableau d'entiers contenant maximum %d valeurs.\n", N);
  printf("Entrer les valeurs au clavier, -1 pour terminer la saisie .\n\n");
  do
  {
     printf("Entrer l'entier No %d :\n",*leff + 1);
     scanf("%d", &nb);
     if ( nb != -1)
       {
         (*leff)++ ;
         *t++ = nb;
         // *t = nb ; t= t+1
       }

   }
   while ((*leff < dim) && (nb != -1));
}





void AfficheTab (int *t, int leff)

{    int i;
     printf("Adresse du PARAMETRE IDENTIFICATEUR tableau : %x\n",&t);
     printf("Valeur contenue dans le PARAM IDENTIFICATEUR tableau : %x\n",t);
     printf("Adresse du PREMIER ELEMENT du tableau : %x\n",t);

     for(  i = 0; i < leff ; i++)
           {  printf("Valeur No %d du Tableau : %d\n", i + 1, *t++);
             printf("Adresse de L'ELEMENT SUIVANT du tableau : %x\n",t);
             printf("Adresse du PARAM IDENTIFICATEUR' tableau : %x\n",&t); }
}


void InverseTab (int t[], int leff)
{
     int i = 0, j = leff - 1;
     while ( i < j)
      {
       EchangeValeurs ( (t + i), (t + j)); /* adresses des él. du tableau*/
       i++;
       j--;
      }
}


void EchangeValeurs ( int *a , int *b)
{
     int tmp;
     tmp = *a;
     *a = *b;
     *b = tmp;
}
