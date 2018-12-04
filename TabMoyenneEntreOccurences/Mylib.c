#define N 15

void inittab(int t[], int * lg)
{
     int nblu;
     
   *lg = 0;
   printf("Entrer un nbre entier, la valeur -1 mettra fin a la saisie \n");
   scanf("%d", &nblu);
   while( (nblu != -1) && (*lg < N) )
     {
       t[*lg] = nblu;
       *lg = *lg + 1;
       printf("Entrer un nbre entier, la valeur -1 mettra fin a la saisie \n");
       scanf("%d", &nblu);
     }            
 }
 
 
 void affichetab(int t[], int lg)
 { 
      int i;
      
    printf("Voici les valeurs du tableau :\n\n"); 
    for( i = 0; i< lg; i = i + 1)
       printf("%d\n", t[i]);
      
 }
 

 
 
int apparition_nbreintab (int t[], int lg, int nbre)
 {   
     int cpt, i;
     
   cpt = 0;
   for( i = 0; i< lg; i = i + 1)
       if( t[i] == nbre)
            cpt = cpt + 1;
   return cpt;
 } 
 
 
float moy_entre_2_1eresapparition_nbre(int t[],int nbin,int * cptentre2fois)
{
    int i = 0, unefois = 0, deuxfois = 0;
    float moyenne, somme = 0.0;

  /* attention, dans le while ci-dessous à ne pas changer l'ordre des 2
  premières structures if , faites le test. Si vous vouler modifier l'ordre des 
  conditions posées utilisez plutôt la structure if ... else */  
    while  (!(deuxfois)) // while ( deuxfois == 0)
     {
        if ( (t[i] == nbin) && (unefois) )  // ou (unefois != 0)
           deuxfois = 1;     
        if ( (t[i] == nbin) && (!(unefois)) ) // ou (unefois ==0)
           unefois = 1;

        if ( (t[i] != nbin) && (unefois) )
           {
                *cptentre2fois = *cptentre2fois + 1;
                somme = somme + t[i] ;
                   
           } 
         i++;       
     }
     /* regarder le résultat affiché par la variable moyenne si la valeur
     de celle-ci est bien une valeur réelle mais que les 2 opérandes (somme et 
     *cptentre2fois sont déclarés de type entier (int))*/
     
     if (*cptentre2fois != 0) 
       moyenne = somme / *cptentre2fois;
     return moyenne;
} 

