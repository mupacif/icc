#include <stdio.h>
#include <stdlib.h>
#define N 41


void initialise_string(char *);
int indexof(char *);
int dernierepos( char * );
int longueur_str(char *);
char carenpos (char * );
void estprefixe(char *);
void estsuffixe (char *);
int nombremots(char* );
void sansblancs(char *);
int compare_str(char *, char *);
int premierepos_ssch_in_ch( char * s, char * ss);
int dernierepos_ssch_in_ch( char * s, char * ss);
void copie_partie_str( char *, char *, int);
int palindrome( char *);


int main(int argc, char *argv[])
{
  char str1 [N], str2 [N];
  int firstapparition, derapparition, cptmots, position, chainepalindrome;
  char c;
  

  printf("\n\n");
  printf("RECHERCHE D'UN CARACTERE DANS UNE CHAINE");
  printf("\n\n");
  
  initialise_string(str1);
  firstapparition = indexof(str1);
  if (firstapparition > 0)
    printf ("premiere apparition du caractere recherche dans la chaine : %d\n", firstapparition);
  else
    printf("le caractere recherche n'est pas present dans la chaine.\n"); 
  derapparition = dernierepos(str1);  
  if (derapparition > 0)
    printf ("derniere apparition du caractere recherche dans la chaine : %d\n", derapparition);
  else
    printf("le caractere recherche n'est pas present dans la chaine.\n");
  c =  carenpos(str1);
  printf("Le caractere recherche au sein de la chaine vaut : %c\n", c);
  printf("\n\n");
  printf("RECHERCHE D'UNE SOUS-CHAINE DANS UNE CHAINE");
  printf("\n\n"); 
  estprefixe(str1); 
  estsuffixe(str1);
  

  printf("Premiere apparition d'une sous-chaine dans une autre :\n\n"); 
  printf("entrez la chaine dans laquelle la recherche sera effectuee :\n"); 
  initialise_string(str1);
  printf("entrez la sous chaine recherchee :\n");  
  initialise_string(str2);   
  if ( position = premierepos_ssch_in_ch(str1, str2))
     printf("La 2eme chaine apparait pour la 1ere fois au sein de la\n"
            "1ere chaine en position %d\n ", position);
  else
     printf("La 2eme chaine entree n'apparait pas au sein de la 1ere.\n");
     
  printf("\n\n");  
  printf("Derniere apparition d'une sous-chaine dans une autre :\n\n");
  printf("entrez la chaine dans laquelle la recherche sera effectuee:\n");  
  initialise_string(str1);
  printf("entrez la sous chaine recherchee :\n");  
  initialise_string(str2);   
  if ( position = dernierepos_ssch_in_ch(str1, str2))
     printf("La 2eme chaine apparait pour la derniere fois au sein de la\n"
            "1ere chaine en position %d\n ", position);
  else
     printf("La 2eme chaine entree n'apparait pas au sein de la 1ere.\n");
 
  printf("\n\n");
  printf("NOMBRE DE MOTS CONTENUS DANS UNE CHAINE");
  printf("\n\n");  
   
  initialise_string(str1);
  cptmots = nombremots(str1);
  printf("la chaine est constituee de : %d mot(s)\n", cptmots);
  
  printf("\n\n");
  printf("SUPPRESSION DES BLANCS CONTENUS DANS UNE CHAINE");
  printf("\n\n"); 
  printf("entrez une chaine contenant des caracteres blancs\n");
  initialise_string(str1);
  sansblancs(str1);
  printf("voici la chaine apres suppression des blancs : \n");
  puts(str1);
  printf("\n\n");
  printf("LA CHAINE ENTREE EST-ELLE UN PALINDROME ?\n");
  initialise_string(str1);
  sansblancs(str1);
  chainepalindrome = palindrome(str1);
  if (chainepalindrome)
    printf("la chaine entree est un palindrome\n");
  else
	printf("la chaine entree n'est pas un palindrome\n");
  
         
                
  system("PAUSE");	
  return 0;
}


void initialise_string(char * s)
{
   do
   {  
     printf("Entrez une chaine de caracteres contenant "
            "au maximum %d caracteres :\n", N -1 );
     gets(s);
   }
   while (longueur_str(s) > N -1); // fonction définie plus bas
}


int indexof( char * s)
{
   char caractrecherche ; 
   char buf [20];
   int  pos = 0, pastrouve = 1;
   printf ("Entrez le caractere recherche \n");
   gets(buf);
   sscanf( buf,"%c", &caractrecherche);
   while ((*s) && (pastrouve)) //
     { if (*s == caractrecherche)
           pastrouve = 0;
       pos++;
       s++;   
     }
     
   if (pastrouve)
     return -1;
   else 
     return pos;  
   	
}

int dernierepos( char * s)
{
   char caractrecherche ;
   char buf [20]; 
   int pos = 1, posder = 0 , pastrouve = 1;
   printf ("Entrez le caractere recherche \n");
   gets(buf);
   sscanf( buf,"%c", &caractrecherche);
   /* Différence par rapport à la boucle de la fonction précédente : on ne sort
      pas de la boucle quand on a trouvé le caractère recherché */
   while (*s) 
     { if (*s == caractrecherche)
           { if (pastrouve)
			    pastrouve = 0;
			 posder = pos;
           }   
	   pos++;  
            
	   s++;    
     }
     
   if (pastrouve)
     return -1;
   else 
     return posder;  
   	
}



int longueur_str(char * s)
{
    int cpt = 0;
    
    while(*s++)
       cpt++;
    return cpt;
}

 char carenpos (char * s)
{
	char buf [20];
	int pos;
	do
	  { printf ("entrer la position du caractere recherche : \n");
	    gets(buf);
	    sscanf( buf,"%d", &pos);
	  }
	while ((pos > longueur_str(s)) || (pos<= 0));
	// la popsition entrée au clavier est toujours > 0 
	return *(s + pos - 1); 	
}

void estprefixe(char * s)
{
	char candidatprefixe [N];
	int i = 0;
	int egal = 1;
	
	printf("la chaine que vous allez saisir est-elle prefixe de la 1ere ?\n\n");
	initialise_string(candidatprefixe);
	if (longueur_str(candidatprefixe) > longueur_str(s))
	   printf ("la chaine entree n'est pas prefixe de la chaine saisie en premier lieu.\n\n");
	else
	  {
	    while ((i < longueur_str(candidatprefixe) && (egal)))
	      {
		    if ( *(candidatprefixe + i) != *(s + i))
	          egal = 0;
	        i++;
	      }
	    if (egal)
		   printf("La chaine saisie est prefixe de la 1ere chaine entree au clavier\n\n");
		else     
	 	   printf("La chaine saisie n'est pas prefixe de la 1ere chaine entree au clavier\n\n");
	  }
}

void estsuffixe (char * s)
{
	char candidatsuffixe [N];
	int i = 0, j;
	int egal = 1;
	
	printf("la chaine que vous allez saisir est-elle suffixe de la 1ere ?\n\n");
	initialise_string(candidatsuffixe);
	if (longueur_str(candidatsuffixe) > longueur_str(s))
	   printf ("la chaine entree n'est pas suffixe de la chaine saisie en premier lieu.\n\n");
	else
	  {
	  	j = longueur_str(s) - longueur_str(candidatsuffixe);
	    while ((j < longueur_str(s)) && (egal))
	      {
		    if ( *(candidatsuffixe + i) != *(s + j))
	          egal = 0;
	        i++;
	        j++;
	      }
	    if (egal)
		   printf("La chaine saisie est suffixe de la 1ere chaine entree au clavier\n\n");
		else     
	 	   printf("La chaine saisie n''est pas suffixe de la 1ere chaine entree au clavier\n\n");
	  }
}



int compare_str(char * s1, char * s2)
{
    while (((*s1) && (*s2))&& (*s1 == *s2))
     {
          s1++;
          s2++; 
     }         
    if ((*s1=='\0') &&  (*s2 =='\0'))
      return 0; // on retourne la valeur 0 si les 2 chaînes sont identiques
    else
       if  (*(s1) < *(s2)) 
          return -1;
       else
          return 1;
} 

void copie_partie_str( char * copy_de_str ,char * str, int lg)
{
     
     int i = 0;   
     for ( ; i < lg ; i++)
         *copy_de_str++ = *str++;
     *copy_de_str = '\0';
}  


int premierepos_ssch_in_ch( char * s, char * ss)
{ 
  int pos = 0;
  int lgss = longueur_str(ss), lgs = longueur_str(s);
  char copie_de_s [lgss + 1];
  
    if (lgss > lgs)
       return 0;
    else
     {
       while ( *(s + lgss - 1) )
        {
          pos++;
          copie_partie_str( copie_de_s , s, lgss);
          if(!(compare_str(copie_de_s,ss)))
              return pos;   // on sort dès qu'on a trouvé
          s++;
        }
       return 0;
     }
}



int dernierepos_ssch_in_ch( char * s, char * ss)
{ 
  int pos = 0, dernierepos= 0;
  int lgss = longueur_str(ss), lgs = longueur_str(s);
  char copie_de_s [lgss + 1];
  
    if (lgss > lgs)
       return 0;
    else
     {
       while ( *(s + lgss - 1) )
        {
          pos++;
          copie_partie_str( copie_de_s , s, lgss);
          if(!(compare_str(copie_de_s,ss)))
              dernierepos = pos;
          s++;
        }
        if(dernierepos)
         return dernierepos;
        else
		  return 0;
     }
}



int nombremots(char*s)
{
	int nbmots = 0, i = 0;
	char prec, cour;
	prec = ' ';
	
	while ( i < longueur_str(s))
	  {
	  	cour = *(s + i);
	  	if ((cour!= prec) && (prec ==' '))
	  	  nbmots++;
	  	prec = cour;
		i++;    
	  }
	return nbmots;  
	
  } 
  
  
void sansblancs( char * s)
{
   int indlect, indecrit = 0;
   for (indlect = 0; indlect < longueur_str(s); indlect++) 
       if( *(s + indlect) != ' ')
       {
	 
            *(s + indecrit) = *(s + indlect);
            indecrit++;
       }
   *(s + indecrit) = '\0';    
}  

int palindrome( char * s)
{
	int palin = 1, i = 0, j = longueur_str(s) - 1;
	while ((i<j) && (palin))
	   {
	   	  if (*(s + i) != *(s + j))
	   	     palin = 0;
	   	  i++;
		  j--;   
	   }
	return palin;   
} 
        
