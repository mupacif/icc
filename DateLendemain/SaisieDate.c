


void saisieDateValide (int *j, int *m, int *a)
{
     *j = saisieJourValide();
     *m = saisieMoisValide (*j);
     *a = saisieAnneeValide (*j,*m);
}


int saisieJourValide (void)
{
  int jour;
  do
    {
      printf("\nEntrer sous forme d'entier un jour compris entre 1 et 31 inclus :\n\n");
      scanf( "%d" , &jour);
    }
   while((jour < 1) || (jour > 31));

  return jour;
}


int saisieMoisValide (int day)
{
    int month;
    do
       {
        printf("\nEntrer sous forme d'entier compris entre 1 et 12 un mois valide \npour le jour choisi : \n\n");
        scanf( "%d" , &month);
        }
    while ((month < 1) || (month > 12));
    if (( day > 29) && (month == 2))
        do
          {
             printf("\nLe mois entre ne convient pas !\n");
             printf("Entrer sous forme d'entier un mois valide pour le jour choisi : \n\n");
                 scanf("%d", &month);
          }
        while ((month == 2) || (month > 12) ||( month < 1));
    if  ((day > 30) && (mois30j(month)))
      /*  if((day > 30) && ((month == 4) || (month == 6) || (month == 9)
                             || (month == 11)))  */
          do
           {
                 printf("\nLe mois choisi ne convient pas !\n");
                 printf("Entrer sous forme d'entier un mois valide pour le jour choisi :\n\n");
                 scanf("%d", &month);
           }
           while  ((month > 12) ||( month < 1) || (mois30j(month)) ||
                   (month == 2));

         /* while  ((month > 12) ||( month < 1) || (month == 2) ||
                    (month == 4 ) || (month == 6) ||
                    ( month == 9) || (month  == 11));  */

    return month ;
}


int saisieAnneeValide (int jour, int mois)
{
    int an;
    do
    {
        printf("\nEntrer une annee valide pour le mois et le jour choisis.\nCelle-ci devra etre comprise entre -32000 et 32000 inclus\n\n");
        scanf("%d", &an);
    }
    while (((an < -32000) || (!an) || (an > 32000)) ||
           ((!(anneeBissextile(an)))&& (jour == 29)) && (mois == 2));

    return an;
}


int anneeBissextile (int annee)
{
    if (((annee % 4 == 0) && (annee % 100 != 0))  ||  (annee % 400 == 0))
      return 1;
    return 0;
}

/* voir si une annéeest divisible par 4 et different de 100
*/

int mois30j(int mois)
{
    switch (mois)
    {

           case 4 :
           case 6 :
           case 9 :
           case 11: return 1;
           default : return 0;
    }
}


