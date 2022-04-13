%{
    int ligne=1, col=1;
	 
	 
%}

%token divfini mc_entier mc_reel mc_bool mc_car mc_str bool tabb ttype cst et ou no sup supe inf infe ega dif aff
%token entre sorti decv decvar inst as aprdeb start finish si alors sinon doo pour tantque jusqua debut ID sep entier reel car str plus moins mul parouv parfer deuxpoint
%token formabol formachr formaflt formaint formastr fin egale virgule
%start S
%%

S :   debutprogramme deblocvar variable finblocvar debinst fininst finprogramme { printf(" Le programme est correcte syntaxiquement\n");  }
      | debutprogramme  finprogramme { printf(" Le programme est correcte syntaxiquement\n");  }
;

debutprogramme:  start aprdeb debut ID finish
;
finprogramme: start divfini debut finish
;
deblocvar: start decv decvar finish
;
finblocvar: start divfini decv decvar finish
;
debinst: start inst finish
;
fininst: start divfini inst finish
;
variable: start listvar as mc_bool divfini finish fin 
         | start listvar as mc_car divfini finish fin
		 | start listvar as mc_entier divfini finish fin
		 | start listvar as mc_reel divfini finish fin
		 | start listvar as mc_str divfini finish fin
		 
;


listvar: sep  listvar
        | ID listvar 
		| ID
;


%%
main () 
{
initialisation();
afficher();
yyparse();
afficher();
}
yywrap()
{}
int yyerror ( char*  msg )  
 {
    printf ("Erreur Syntaxique a ligne %d a colonne %d \n",ligne,col);
  }