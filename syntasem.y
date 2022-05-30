%{
	#include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include "tess.h"
    #include "RS.h"
	extern FILE* yyin;
    int yylex();
    int yyerror(char *);
	int ligne=1, col=1; 
	char sauvIDFs [50][50];
	int tablength = 0;
	
%}

%union{
	char* nom;
	int integer;
    struct{
		int type;
        char* res;
    }NT;
}

%token divfini mc_entier mc_reel mc_bool mc_car mc_str bool tabb ttype cst et ou no sup supe inf infe ega dif aff
%token entre sorti decv decvar body as aprdeb start finish si alors sinon doo pour tantque jusqua debut 
<nom>ID sep <integer>entier_pos <integer>entier_neg reel car str plus  moins mul parouv parfer croch1 croch2 deuxpoint
%token formabol formachr formaflt formaint formastr fin egale virgule doublecot msg noteq doubleegale
%type <nom> listvar

%left ou
%left et
%left sup inf supe infe doubleegale noteq
%left plus moins
%left mul divfini
%left no
%left '(' ')'

%start S
%%
// [✔] : Exists 
// [✘] : Doesn't exist


// !------------------------------Main Programme----------------------------------------
	// * Partie declaration [✔] Partie instruction [✘]
S:	|debutprogramme  debvar partie_declaration finvar finprogramme 
	{printf(" Le programme est correcte syntaxiquement\n");}
	// * Partie declaration [✘] Partie instruction [✔]
	|debutprogramme  debinst partie_instruction fininst finprogramme 
	{printf(" Le programme est correcte syntaxiquement\n");}
	// * Partie declaration [✔] Partie instruction [✔]
    |debutprogramme debvar partie_declaration finvar debinst partie_instruction fininst finprogramme 
	{printf(" Le programme est correcte syntaxiquement\n");}
	// * Partie declaration [✘] Partie instruction [✘] 
    |debutprogramme  finprogramme 
	{printf(" Le programme est correcte syntaxiquement\n");}
;

// !--------------------------------------------------------------------------------------
// <!docprogram ID_program>
debutprogramme:  start aprdeb debut ID finish
;
//</docprogram>
finprogramme: start divfini debut finish
;

// !-----------------------------Partie Declaration---------------------------------------
// <SUB VARIABLE> 
debvar: start decv decvar finish
;
// </SUB VARIABLE >
finvar: start divfini decv decvar finish
;
// partie declaration des variables
partie_declaration:	partie_declaration dec_variable 
				  | partie_declaration dec_table
				  | partie_declaration dec_cst
				  |
;

//?--------------------------1)Declaration des variables----------------------------------- 
// < nom_variable AS TYPE />; < Liste_variable AS TYPE /> ;
// // dec_variable: start listvar as mc_bool divfini finish fin 
// //          	| start listvar as mc_car divfini finish fin
// // 		    | start listvar as mc_entier divfini finish fin 
// // 		 	| start listvar as mc_reel divfini finish fin
// // 			| start listvar as mc_str divfini finish fin
// // ;
dec_variable: start listvar as list_types divfini finish fin {
	int j = 0;
	for(j = 0;j<tablength;j++){
		printf("[ %s ]\t",sauvIDFs[j]);
	}
	}
;
// <nom_variable | nom_variable2 AS TYPE />; < nom_variable AS TYPE /> ;
listvar: ID  sep  listvar
	   | ID 
;	

//?--------------------------2)Declaration des tables-------------------------------------- 
/* 
    <ARRAY AS TYPE >
	<nom_tableau1: taille1/>
	<nom_tableau2: taille2/>
	………
   </ARRAY> 
*/
//todo: add other types
dec_table: start tabb as mc_entier finish list_tab_variable start divfini tabb finish
		 | start tabb as mc_bool finish list_tab_variable start divfini tabb finish
;
//<nom_tableau1: taille1/>
list_tab_variable: list_tab_variable start ID deuxpoint entier_pos divfini finish {printf("entier : %d",$4);}
				 |
; 

//?--------------------------3)Declaration des constants-----------------------------------
/* 
   <SUB CONSTANTE>
   <nom_constante1 = valeur/>;
   <nom_constante1 = valeur/>;
   </SUB CONSTANTE> 
*/
dec_cst : start decv cst finish list_cst start divfini decv cst finish
;
//todo : add other types like char and string
		// <nom_constante1 = valeur/>; 
list_cst: list_cst start ID egale entier_pos divfini finish fin
		//<nom_constante1 AS TYPE /> ;
        | list_cst start listcst as mc_entier divfini finish fin
        |
;
// <nom_constante1 AS TYPE />; <Liste_constante2 AS TYPE/>;
listcst: ID sep  listcst
       | ID
;		 
// !-----------------------------Partie Instructions---------------------------------------
// <body>
debinst: start body finish
;
// </body>
fininst: start divfini body finish
;
partie_instruction: partie_instruction inst_aff 
				  |partie_instruction inst_entree
				  |partie_instruction inst_sortie
				  |partie_instruction cdt_if
				  |
;

//?--------------------------1)Affectation--------------------------------------------------
inst_aff: start aff deuxpoint variable virgule exp divfini finish
;

variable: ID
        | case_tab	
;

exp: exp_log
   | exp_arith
;
//todo : add / the operation 
exp_arith: exp_arith plus exp_arith 
		 | exp_arith  moins exp_arith
		 | exp_arith  mul exp_arith
		 | ID
		 | entier_pos
		 | entier_neg
		 | reel
		 | parouv exp_arith parfer	
		 | car
		 | str
		 | case_tab

;

exp_log: et parouv list_exp_arith parfer
	   | et parouv list_comparaison parfer
	   | no parouv exp_log parfer
	   | ou parouv list_exp_arith parfer	 
;

list_exp_arith: list_exp_arith virgule exp_arith
			  | exp_arith virgule exp_arith
;

//?--------------------------2)Entrées/Sorties----------------------------------------------
//todo : somehow , "yasser" is wrong ,  " yasser" wroks -_-
//todo add case when ID is vide (empty msg)
inst_entree : start entre deuxpoint ID doublecot ID sign_forma doublecot divfini finish
;
inst_sortie : start sorti deuxpoint list_sortie divfini finish
;
list_sortie:  doublecot ID sign_forma doublecot plus ID plus list_sortie
		   |  doublecot ID sign_forma doublecot plus ID
;
//?--------------------------3)Condition IF-------------------------------------------------
cdt_if: start si deuxpoint ID finish start alors finish partie_instruction start divfini alors finish bloc_else start divfini si finish
	  |start si deuxpoint ID finish start alors finish partie_instruction start divfini alors finish start divfini si finish
;
bloc_else: start sinon finish partie_instruction start divfini sinon finish
;
//?--------------------------4)Boucle-------------------------------------------------------

//?--------------------------5)Conditions---------------------------------------------------

comparaison : sup parouv exp_arith virgule exp_arith parfer
			| inf parouv exp_arith virgule exp_arith parfer
			| supe parouv exp_arith virgule exp_arith parfer
			| infe parouv exp_arith virgule exp_arith parfer
			| ega parouv exp_arith virgule exp_arith parfer
			| dif parouv exp_arith virgule exp_arith parfer
;

list_comparaison : comparaison virgule comparaison 
			     | list_comparaison virgule comparaison
;
sign_forma: formaint 
          | formabol 
		  | formachr 
		  | formaflt 
		  | formastr
;
list_types : mc_entier {} 
			| mc_bool {} 
;
case_tab : ID croch1 ID croch2
			 | ID croch1 entier_pos croch2 		 
;
%%
main (){
yyin =fopen ("test.txt" ,"r");
init();
yyparse();
afficherTS();
// // afficherQuad();
affii();
fclose(yyin);	
// // initialisation();
// // // afficher();
// // yyparse();
// // // afficher();
}
void yywrap(){}
int yyerror ( char*  msg ){
	printf ("Erreur Syntaxique a ligne %d a colonne %d \n",ligne,col);
}