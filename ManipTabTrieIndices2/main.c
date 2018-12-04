#include <stdio.h>
#include <stdlib.h>
#define N 32

int tailletab (void);
void initialisetabtrie(int*, int);
void affichetab(int *, int);
int saisievaleur(void);
void inserevaleurtabtrie(int*, int*, int);
void tassetab(int *, int);
int indice_egal_valeur( int*, int);
int position_dernier_min(int*, int);
int position_premier_max(int*, int);
/* Tous les prototypes des fonctions utilisent la notation de type pointeur pour
le paramètre  tableau ce qui n'empêche pas l'utilisation  des indices dans les
fonctions */
/* Egalement utilisation de la fonction scanf dans l'entièreté du programme
 possible car on a la garantiede ne saisir que des valeurs de type numérique */

int main(int argc, char *argv[])
{
    int lgeff, tab[N], val_1, val_2, indiceidemvaleur, posdermin,
     pos1ermax;
    
  lgeff = tailletab();
  initialisetabtrie(tab, lgeff);
  printf("\nVoici le tableau initial :\n\n");
  affichetab(tab, lgeff);
  printf("\n\nSaisie d'un premier nombre a inserer dans le tableau :\n\n");
  val_1 = saisievaleur();
  printf("\nSaisie d'un deuxieme nombre a inserer dans le tableau :\n\n"); 
  val_2 = saisievaleur();
  inserevaleurtabtrie(tab, &lgeff, val_1);
  inserevaleurtabtrie(tab, &lgeff, val_2);
  printf("\nVoici le tableau apres les 2 insertions :\n\n"); 
  affichetab(tab, lgeff);
  printf("\nTassage du tableau sur base d'une de ses valeurs\n\n");
  tassetab(tab, lgeff);
  printf("\nVoici le tableau apres tassage\n\n");
  affichetab(tab, lgeff);
  indiceidemvaleur = indice_egal_valeur( tab, lgeff);
  if(indiceidemvaleur == -1)
    printf("Aucune valeur du tableau ne correspond a la valeur de son indice.\n");
  else
    printf("\n1er element du tableau dont la valeur est egale a son "
           "indice : %d\n", *(tab + indiceidemvaleur)); 
  posdermin = position_dernier_min(tab, lgeff);
  printf("la valeur minimale apparait en dernier en position : %d \n", posdermin);
  pos1ermax = position_premier_max(tab, lgeff);
  printf("la valeur maximale apparait en premier en position : %d \n", pos1ermax);
           
       
  system("PAUSE");	
  return 0;
}


int tailletab(void)
{
    /* invite l'utilisateur à spécifier le nombre initial de composantes du 
    tableau en initialisant la longueur effective du tableau */
    
    int lg ;
 do
 { 
   printf("Entrez le nombre d'elements du tableau initial\n");
   printf("Celui-ci doit etre compris entre 15 et %d inclus.\n",N - 2);
   scanf("%d",&lg);
 }
 while (( lg < 15) || (lg > N - 2));
 return lg;
}

       
void initialisetabtrie(int* t, int lg)
{   
  /* Saisie de valeurs croissantes en comparant cour à prec.
     Première valeur "fictive" de prec == la + petite valeur admissible */  
     
    int prec = -100, cour, cptelem = 1;
    
  printf("Vous devez initialiser au clavier les elements du tableau.\n");
  printf("ATTENTION chaque nouvel element saisi devra etre >= au precedent \n");
  printf("et sa valeur devra etre comprise entre -100 et 100 inclus.\n\n");
  while (cptelem <= lg)
    {
        printf("Entrer la valeur de l'element '%d' du tableau :\n", cptelem);
        scanf("%d", &cour);
        while (( cour < prec) ||(cour > 100))
        {
          printf("RAPPEL :\n chaque nouvel element saisi doit etre >= au "
                     "precedent et compris entre\n-100 et 100\n");
          printf("Entrer la valeur de l'element '%d' du tableau :\n", cptelem);
          scanf("%d", &cour);
        }
        t[cptelem - 1] = cour;
        prec = cour;
        cptelem++;       
    }
}          


void affichetab(int* t, int lg)
{
     int i = 0;
     while(lg != 0)
      {
        printf("%d, ", t[i]);
        i++;
        lg--;
      }  
}


int saisievaleur(void)
{
    int nb;
  
  do
  {  
    printf("Entrer une valeur au clavier.\n"); 
    printf("La valeur entree doit etre comprise entre -100 et 100\n");
    scanf("%d", &nb);
   }  
  while( (nb < -100) || (nb > 100));
  return nb;        
}


void inserevaleurtabtrie(int* t, int* lg, int val )
{
     int j = *lg - 1; // j == indice du dernier élément du tableau
     
  while( val < t[j]) // sort de la boucle quand val >= t[j]
       {
            t[j + 1] = t[j];;
            j--;
       }
  t[j + 1] = val;
  (*lg)++; // mise à jour de la longueur effective après l'insertion
}


void tassetab(int* t, int lg)
{
     int nb, indecrit = 0, indlect ,cpt = 0;
     
  nb = saisievaleur(); 
  /* Ne recopie que les valeurs différentes de la valeur à tasser qui sera
  rejetée en fin de tableau */  
  for(indlect = 0; indlect < lg   ;indlect++)
    {
        if( t[indlect] == nb)
           cpt++;
        else
           {
                 t[indecrit] = t[indlect];
                 indecrit++;
           }
    }
  if (cpt)
     while( indecrit < lg)
       {
             t[indecrit] = nb;
             indecrit++;
       }
}                  
             
             
int indice_egal_valeur( int *t, int lg)
{
    // la valeur pos == -1 est une valeur impossible, absurde
    int pos = -1, i = 0; 
    while ((i < lg) && (pos == -1))
      {
          if (t[i] == i)
              pos = i;
          i++;
      }
    return pos;
}                


int position_dernier_min(int* t, int lg)
{
    int min = t[0], posmin = 1, i = 1;
    
    for( ; i < lg; i++)
      {
 if ( t[i] <= min )
           {
              min = t[i];
              posmin = i + 1;
           }
      }
    return posmin;
}


int position_premier_max(int* t, int lg)
{
    int max = t[0], posmax = 1, i = 1;
    
    for( ; i < lg; i++)
      {
         if ( t[i] > max )
           {
              max = t[i];
              posmax = i +1;
           }
      }
    return posmax;
}        
                    
             
                  
