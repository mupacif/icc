#include <stdio.h>
#include <stdlib.h>
#include "SaisieDate.h"
#include "FormatAffichageDate.h"
#include "CalculProchaineDate.h"
   

int main( int argc, char *argv[])
{
  int jour_in, mois_in, annee_in, jour_out, mois_out, annee_out;
  
  saisieDateValide(&jour_in, &mois_in, &annee_in);
  printf("\nVoici la date valide que vous avez saisie :\n\n");
  afficheDate(jour_in, mois_in, annee_in);
  jour_out = jourLendemain(jour_in, mois_in, annee_in);
  mois_out = moisLendemain(jour_out, mois_in);
  annee_out = anneeLendemain(annee_in, jour_out, mois_out);
  printf("Voici la date du lendemain :\n\n");
  afficheDate(jour_out, mois_out, annee_out);

  system("PAUSE");	
  return 0;
}
