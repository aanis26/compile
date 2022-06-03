%{
	#include<stdlib.h>
	#include<stdio.h>
	int nbligne = 1;
	int col = 1;
	char temp[30];
	int cstVal;
	char sauvAffType[30] = "";
	char sauvType[20] = "";
	char *sauv;
	int sauvIf[100],sauvIfFin[100],debWhile[100],debFOR[100];
	int sauvIfP=0,sauvIfFinP=0,debWhileP=0,debFORP=0;

	void push(int* tab,int*pos,int val){

		tab[*pos]=val;
		*pos=*pos+1;
	}
	int pop(int* tab,int* pos){

		*pos=*pos-1;
		return tab[*pos];
	}

	int tmp = -1;
	int cpt = 0;
	int cptSF = 0;
	int cptIDF = 0;
	char buffer[50];
	char tabSF[30][10];
	char tabIDF[30][10];
	int activesigne = 0;
	
	extern int yylineno;
	int processToggle = 0, arrayToggle = 0, loopToggle = 0;
	
	// quad variables
	int qc=0;
	char tmpq[20];
	int deb_while;
%}

%union 
{ 
   int entier; 
   char* str;
   float reelf;
   
}
%type <str>CST_VALEUR 
%type <str>COND COND_STRT  COND_ARG IDF_SWITCH LIST_EXP LIST_EXP_ARITHM 
%type <str>COND_CMP_LOG


%token 	op_tag close_tag strt_tag end_tag op_doc end_doc sb mc_var mc_cnst body
		mc_array tint treel tchar tstring tbool as dp 
		mc_aff vg mc_do mc_for mc_until
		mc_affstrt  mc_ifstrt mc_thenstrt mc_elsestrt mc_forstrt mc_dostrt readd writee
		tcst pvg  cros croe
		prnts prnte pipe  forint forreal
		forstr forchar forbool   qot <str>mc_and <str>mc_or mc_if mc_else 
		mc_not mc_then <str>egal <str>inf <str>sup <str>infe <str>supe <str>diff mc_while 
		true false <str>idf <str>cst ent <str>flt <str>ch <str>strr msg egg



%left  add dec 
%left  mult divi



%%

// !------------------------------Main Programme----------------------------------------

S  : debutprogramme partie_declaration  partie_instruction fin_body finprogramme
        {printf("\n\t ___ La Syntaxe Est Correcte ! ___ \n\n");
        YYACCEPT;}
;

partie_declaration: op_tag sb list_var  partie_declaration
		| op_tag sb DEC_CSTS partie_declaration
		| op_tag debut_body
;
debutprogramme: op_tag op_doc idf close_tag
;

finprogramme: strt_tag end_doc close_tag
;

// !-----------------------------Partie Declaration---------------------------------------
list_var : start_partie_var list_dec end_partie_var
;
start_partie_var: mc_var close_tag
;
end_partie_var: strt_tag sb mc_var close_tag
;

list_dec : dec_var list_dec
		 | dec_var
;

dec_var : op_tag LISTE_IDF as TYPE {insererType(temp);} end_tag pvg
		| op_tag mc_array as TYPE close_tag LIST_ARRAY {insererType(temp);} strt_tag mc_array close_tag
;

TYPE : tint { strcpy(temp,"ENTIER");}
	 | treel { strcpy(temp,"REEL");}
	 | tchar { strcpy(temp,"CHAR");}
	 | tstring { strcpy(temp,"STRING");}
	 | tbool { strcpy(temp,"BOOL");}
;

// ? x | y | z 
LISTE_IDF : idf pipe LISTE_IDF  {inserer($1,"idf");}
		  | idf {inserer($1,"idf");}
;

LIST_ARRAY : op_tag idf dp cst end_tag { inserer($2,"idf"); insertTable($2,"Table",$4);} LIST_ARRAY 
		   | 
;

//?--------------------------Declaration des constants-----------------------------------
DEC_CSTS : START_CST_PART CSTS END_CST_PART
;

START_CST_PART:  mc_cnst close_tag
;

END_CST_PART: strt_tag sb mc_cnst close_tag
;

CSTS : CST_DEC_TYPE CSTS
	 |
;
// <nom_constante1 = valeur/>;  <nom_constante1 AS TYPE /> ;
CST_DEC_TYPE: VAL_CST
		    | TYPE_CST
;

// ? <nom_constante1 = valeur/>;
VAL_CST : op_tag idf egg {inserer($2,"CST");} CST_VALEUR {insererType(temp);insererVal($2,$5);}  end_tag pvg
;

CST_VALEUR  : flt {strcpy(temp,"REEL"); $$=$1;}
		    |cst {strcpy(temp,"ENTIER"); $$=$1;}
		    |ent {strcpy(temp,"ENTIER"); $$=$1;}
		    |ch {strcpy(temp,"CHAR"); $$=$1;}
		    |strr {strcpy(temp,"STRING"); $$=$1;}
		    |true {strcpy(temp,"BOOL"); $$=$1;}
		    |false {strcpy(temp,"BOOL"); $$=$1;} 
;

// <nom_constante1 AS TYPE /> ;
TYPE_CST :  op_tag LISTE_CST as TYPE {insererType(temp);} end_tag pvg
;

LISTE_CST : idf pipe  LISTE_CST {inserer($1,"CST");}
		  | idf  {inserer($1,"CST");}
;

// !-----------------------------Partie Instructions---------------------------------------
debut_body: body close_tag
;

fin_body: strt_tag  body close_tag
;

partie_instruction : mc_affstrt AFFECTATION partie_instruction
		| readd INPUT partie_instruction
		| writee OUTPUT  partie_instruction
		| mc_dostrt WHILE partie_instruction
		| mc_forstrt FOR partie_instruction
		| CONDITION partie_instruction
		|
;

//?--------------------------1)Affectation--------------------------------------------------

AFFECTATION :  dp IDF_SWITCH vg LIST_EXP end_tag {TypeCheck("AFF",$2,$4);checkCST($2);quadr("AFF",$4,"",$2);}
;
// nrml idf or tab !
IDF_SWITCH : idf {checkDeclaration($1);  $$=$1;}
	       | idf cros cst croe {
			 checkDeclaration($1); checkOverFlowTab($1,$3);
			 if(atoi($3)>tabTaille($1)){printf("Erreur semantique : vous avez depassé la taille du tableau !\n");}
	        }
;

LIST_EXP : LIST_EXP_ARITHM {$$=$1;}
		 | COND_STRT {$$=$1;}
;

LIST_EXP_ARITHM : COND_ARG {$$=$1;}
		        | LIST_EXP_ARITHM  add LIST_EXP_ARITHM  {TypeCheck("ADD",$1,$3);sauv=(char*) generateNameNUM();$$=sauv;quadr("ADD",$1,$3,sauv);}
		  		| LIST_EXP_ARITHM  dec LIST_EXP_ARITHM  {TypeCheck("DEC",$1,$3);sauv=(char*) generateNameNUM();$$=sauv;quadr("DEC",$1,$3,sauv);}
				| LIST_EXP_ARITHM  mult LIST_EXP_ARITHM {TypeCheck("MUL",$1,$3);sauv=(char*) generateNameNUM();$$=sauv;quadr("MUL",$1,$3,sauv);}
				| LIST_EXP_ARITHM  divi LIST_EXP_ARITHM {TypeCheck("DIV",$1,$3);sauv=(char*) generateNameNUM();$$=sauv;quadr("DIV",$1,$3,sauv);}		
				| prnts LIST_EXP_ARITHM prnte {$$=$2;}
;

COND_STRT: COND_CMP_LOG prnts COND vg COND prnte {sauv=(char*) generateNameBOOL(); $$=sauv;TypeCheck($1,$3,$5);quadr($1,$3,$5,sauv);}
;

COND : COND_CMP_LOG prnts COND vg COND prnte {sauv=(char*) generateNameBOOL();$$=sauv;TypeCheck($1,$3,$5);quadr($1,$3,$5,sauv);}
	|LIST_EXP_ARITHM {$$=$1;}
	|mc_not prnts COND prnte {sauv=(char*) generateNameBOOL();$$=sauv;quadr("NOT",$3,"",sauv);}
;

COND_ARG : idf {checkDeclaration($1); $$=$1;}
		| cst {$$=$1;}
		| ent {$$=$1;}
		| idf cros cst croe {checkDeclaration($1); $$=$1; checkOverFlowTab($1,$3);}
		| strr {$$=$1;}
		| ch {$$=$1;}
		| flt {$$=$1;}
		| true {$$=$1; }
		| false {$$=$1; }
;

//?--------------------------)Boucle-------------------------------------------------------

WHILE :  {push(debWhile,&debWhileP,qc);}
		 close_tag  partie_instruction  op_tag mc_while dp COND end_tag strt_tag mc_do close_tag 
		 {quadr("BNZ",itoa(pop(debWhile,&debWhileP),buffer,10),$7,"");}
;

FOR: IDF_SWITCH egg COND_ARG  mc_until COND_ARG
     {quadr("AFF",$3,"",$1);sauv=(char*) generateNameBOOL(); push(debFOR,&debFORP,qc); quadr("EGG",$1,$5,sauv);quadr("BNZ","ENDFOR",sauv,"");}
	 close_tag partie_instruction strt_tag mc_for close_tag 
	 {quadr("INC","","",$1); quadr("BR",itoa(pop(debFOR,&debFORP),buffer,10),"","");ajour_quad(debFOR[debFORP]+1,1,itoa(qc,buffer,10));}
;


COND_CMP_LOG : sup {$$=strdup("SUP");}
			 | supe {$$=strdup("SUPE");}
		     | egal {strdup("EGG");}
		     | diff {$$=strdup("DIF");}
		     | infe {$$=strdup("INFE");}
		     | inf {$$=strdup("INF");}
		     | mc_and {$$=strdup("AND");}
		     | mc_or {$$=strdup("OR");}
;
//?--------------------------)Condition IF-------------------------------------------------

CONDITION :  mc_ifstrt dp COND {push(sauvIf,&sauvIfP,qc);quadr("BZ","ELSE",$3,"");} close_tag 
			THEN {push(sauvIfFin,&sauvIfFinP,qc);} 
			ELSE strt_tag  mc_if close_tag
;
THEN : mc_thenstrt close_tag  partie_instruction strt_tag  mc_then close_tag
;

ELSE:	{quadr("BR","FIN","","");ajour_quad(pop(sauvIf,&sauvIfP),1,itoa(qc,buffer,10));}
		mc_elsestrt close_tag partie_instruction strt_tag  mc_else close_tag 
		{ajour_quad(pop(sauvIfFin,&sauvIfFinP),1,itoa(qc,buffer,10));}

	|	{ajour_quad(pop(sauvIf,&sauvIfP),1,itoa(qc,buffer,10));}
;



//?--------------------------)ENTREE/SORTIE-------------------------------------------------

INPUT: dp IDF_SWITCH strr end_tag
;

OUTPUT: dp MSG end_tag
;

MSG :strr  
	|strr add IDF_SWITCH 
	|strr add MSG
	|strr add IDF_SWITCH add MSG 
;

//! --------------------------)FIN-------------------------------------------------

%%
main () 
{
	/* initialisation(); */
	yyparse();
	/* afficher(); */
	afficher_qdr();
	optimisation(); 
	afficher();
	afficher_qdr(); 
}
yywrap()
{}
yyerror (char* msg)
{
	printf("\nErreur Syntaxique a la ligne %d et a la colonne %d \n\n",nb_ligne,nbcol);
}