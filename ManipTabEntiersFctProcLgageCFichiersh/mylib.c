void inittab(int t[], int * lg)
{
     int nblu;
     
   *lg = 0;
   printf("Entrer un nbre entier, la valeur 100 mettra fin a la saisie \n");
   scanf("%d", &nblu);
   while( (nblu != 100) && (*lg < 15) )
     {
       t[*lg] = nblu;
       *lg = *lg + 1;
       printf("Entrer un nbre entier, la valeur 100 mettra fin a la saisie \n");
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
 
 
 float moyenne(int t[], int lg)
 {
       int  i;
       float somme;
       
    somme = 0;   
    for( i = 0; i< lg; i = i + 1)
        somme = somme + t[i];
    return somme / lg;       
 }
 
 
  float moyenne3(int t[], int lg)
 {
       int cpt3, i;
       float somme3;
       
    somme3 = 0;
    cpt3 = 0;   
    for( i = 0; i< lg; i = i + 1)
      if ( (t[i] != 0) &&  (t[i] % 3 == 0) )
        {
           somme3 = somme3 + t[i];
           cpt3 = cpt3 + 1;
        }
    if (cpt3 != 0)       
       return somme3 / cpt3;
    else
       return 0;           
 }
 
 
 int nbdanstab(int t[], int lg)
 {   
     int cpt, nblu, i;
     
   cpt = 0;
   printf("Entrer un nbre entier \n");
   scanf("%d", &nblu);
   for( i = 0; i< lg; i = i + 1)
       if( t[i] == nblu)
            cpt = cpt + 1;
   return cpt;
 } 
 
 
 int tabcroissant(int t[], int lg)
 {
     int croissant, i;
     
    croissant = 1;
    i = 1;
    while (( i < lg) && (croissant == 1))
      {
          if ( t[i] < t[i - 1])
             croissant = 0;
          i = i + 1;
      }
    return croissant;
 }           
