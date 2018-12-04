#include <stdio.h>
#include <stdlib.h>
# define N 26


void InitialiseChaine (char [], int);
void AfficheChaine (char []);
void InverseChaine (char *);
void EchangeValeurs ( char [], char []);
void remplacecarxparcary (char * str);

int main(int argc, char *argv[])

{
  char S1 [N], S2 [7],S3 [10];
  char S4[10];
  char *S5[10];

  S2 = "coucou";
  S3 [3] = "truc";
  S5 = "bonjour";
 /* printf("Entrez une nouvelle chaine de caracteres pour S5\n");
  gets(S5);
  Erreur : l'utilisation de gets est réservée au tableau de char !!!!*/
  printf("Voici S5 :\n");
  puts(S5);
  printf("Voici S2 :\n");
  puts(S2);
  printf("Entrez une nouvelle chaine pour S2 : \n");
  gets(S2);
  printf("Voici S2 :\n");
  puts(S2);
  printf("Voici S3 :\n");
  puts(S3);   /* chaîne tronquée */

 /* S4 = "hello"; compil : incompatible types in assignment .
                  S4 est l'identificateur d'un tableau !!!
                  Ce ne peut donc pas etre une Lvalue.
              */
  printf("Entrez une chaine de caracteres pour initialiser S4\n");
  gets(S4);
  puts(S4);
  S5 = "bazarchouette";
  printf("Voici S5 :\n");
  puts(S5);

  InitialiseChaine(S1, N);  /* OU  gets(S1); */
  printf("Voici la chaine que vous avez saisie : " );
  AfficheChaine (S1);  /* OU  puts(S1); */
  InverseChaine (S1);
  printf("Voici la chaine apres inversion : ");
  puts(S1);/* OU AfficheChaine (S1); */
  printf("Voici la chaine apres remplacement de tous les caracteres 'x' "
         "par 'y' :\n");
  remplacecarxparcary (S1);
  puts(S1);



  system("PAUSE");
  return 0;
}


void InitialiseChaine( char str[], int dim)
{
  do
  {
     printf("Saisissez une chaine de caracteres contenant maximum %d "
            "caracteres pour S1\n", N - 1);
     printf("Terminer la saisie en appuyant sur la touche 'Enter'.\n\n");
     gets(str);

  /* scanf("%s", str); la fct scanf termine la saisie au 1er caractere ' ',
                       elle n'est pas réellement adaptée à la saisie de
                       chaînes de caractères */
   }
   while (*strlen(str) !="\0");
}


void AfficheChaine (char * str)

{
             printf("%s\n", str); /* Ou  puts(str); */
}


void InverseChaine (char str[])
{
     int i = 0, j = strlen(str) - 1;/* strlen renvoie la longueur (nb de
                                        caract) de la chaîne passée en param. */
     while ( i < j)
      {
       EchangeValeurs ( (str + i), (str + j)); /* adresses des él. du tableau
                  donc pas besoin operateur & dans l'appel  */
       i++;
       j--;
      }
}


void EchangeValeurs ( char *a , char *b)
{
     char tmp;
     tmp = *a;
     *a = *b;
     *b = tmp;
}


void remplacecarxparcary (char * str)
{
     while(*str)
     {
                if (*str == 'x')
                    *str = 'y';
                str++;
     }

}

