#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int cpt;
    cpt = 0; // ou int cpt = 0;
    printf("valeur de cpt %d\n", cpt++);
    printf("valeur de cpt %d\n", cpt);
    cpt = 0;
    if(cpt++)
      printf("message1 apparaissant si cpt vaut 1\n");
     cpt = 0;
    if(++cpt)
    printf("message2 apparaissant si cpt vaut 1\n"); 
  system("PAUSE");	
  return 0;
}
