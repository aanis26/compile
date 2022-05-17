#include <stdio.h>
#include <string.h>
#include "tess.h"


int yyerror(char *);

void dec (char * e1)
{
    int index ;
    elem* adr;
    if (!recherche(e1,&index,&adr))
    {
        yyerror("erreur semantique idf non declarer \n");
      
    }
    
    
}

void doubleDec(char *e1)
{
    int index;
    elem *adr;
    if(recherche(e1,&index,&adr))
    {
        yyerror("erreur semantique double declaration d'un idf \n");
    
    }
    
    
}
