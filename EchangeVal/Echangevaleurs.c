void Echange1 (int a, int b)
{
     int temp;
     
   temp  = a;
   a = b;
   b = temp;  
   
   printf("A l'interieur de Echange1,\n");
   printf("le premier entier vaut : %d \n", a);
   printf("le deuxieme entier vaut : %d \n", b);
   
}

void Echange2 (int *a, int *b)
{
     int temp;
     
   temp  = *a;
   *a = *b;
   *b = temp;  
   
   printf("A l'interieur de Echange2,\n");
   printf("le premier entier vaut : %d \n", *a);
   printf("le deuxieme entier vaut : %d \n", *b);
   
}
