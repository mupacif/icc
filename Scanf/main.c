#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    
    
    int nb1, nb2;
    char c,c1 ;
    char s [25], buf[20];
    printf("Entrez un nombre :\n");
    scanf("%d", &nb1);
    printf("Entrez un nombre :\n");
    scanf("%d", &nb2);
    printf("la somme des 2 nbres vaut : %d\n\n ", nb1+nb2);
    
    
    printf("Entrez un nombre :\n");
    scanf("%d", &nb1);
    printf("Entrez un caractere :\n");
    scanf("%c", &c);
    printf("merci pour le caractere\n");
    
    
    printf("Entrez un nombre :\n");
    scanf("%d", &nb1);
    printf("Entrez une chaine de caracteres :\n");
    gets(s); /*   !!!! travaille avec le même tampon que scanf */
    printf("merci pour la chaine\n");
    
    
    
    printf("Entrez un nombre :\n");
    gets(buf);
    sscanf(buf,"%d", &nb1);
    printf("Entrez un caractere :\n");
    gets(buf);
    sscanf(buf,"%c", &c);
    printf("Entrez un nombre :\n");
    /* scanf("%d", &nb1);   stockerait le car '\n' dans tampon ,récupéré par
                            prochaine tentative recuperer 1 caractere */  
    gets(buf); 
    sscanf(buf,"%d", &nb1); 
   
    printf("merci pour le nombre\n");
    printf("Entrer un caractere :\n");
    c = getchar();   /*   !!!! travaille avec le même tampon que scanf */
    printf("merci pour le caractere\n");
    
    printf("Entrer un caractere :\n");
    c = getchar();   /*   !!!! travaille avec le même tampon que scanf */
    printf("merci pour le caractere\n");

     
  
  system("PAUSE");	
  return 0;
}
