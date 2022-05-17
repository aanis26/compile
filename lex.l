%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "syntasem.tab.h"
	#include "tables.h"
	extern ligne;
	extern col;
	extern YYSTYPE yylval;
	int i;
%}
debut "docprogram"
aprdeb "!"
start "<"
finish ">"
lettre [a-zA-Z]
chiffre [0-9]
decv "SUB"
decvar "VARIABLE"
body "body"
tabb "ARRAY"
ttype "TYPE"
mc_entier "INT"
mc_reel "FLT"
mc_bool "BOL"
mc_car "CHR"
mc_str "STR"
entier_pos  {chiffre}+
entier_neg   "("[-]{chiffre}+")"

ID [a-zA-Z]({lettre}|{chiffre})*


reel    {chiffre}+\.{chiffre}+|\(\-{chiffre}+\.{chiffre}+\)
bool  "TRUE"|"FALSE"
car \'[a-zA-Z0-9]\'

str  \"[a-zA-Z0-9]+\"
cst "CONSTANTE"
plus "+"
moins "-"
mul "*"
egale "="
divfini "/"
virgule ","
as "AS"
sep "|"
fin ";"
parouv "("
parfer ")"
et "AND"
ou "OR"
no "NOT"
sup "SUP"
inf "INF"
supe "SUPE"
infe "INFE"
ega "EGA"
dif "DIF"
aff "AFF"
deuxpoint ":"
entre "INPUT"
sorti "OUTPUT"
formaint "$"
formaflt "%"
formastr "#"
formachr "&"
formabol "@"
si "IF"
alors "THEN"
sinon "ELSE"
doo "DO"
tantque "WHILE"
pour "FOR"
jusqua "UNTIL"
saut_ligne "\n"+
esp   [ \t]+
%%
{divfini}    {   col= col + yyleng; printf("entité reconnu %s \n",yytext); return divfini;  }
{mc_entier} {   col= col + yyleng; printf("entité reconnu %s \n",yytext); return mc_entier; }
{mc_reel} {   col= col + yyleng; printf("entité reconnu %s \n",yytext);  return mc_reel; }
{mc_bool} {   col= col + yyleng; printf("entité reconnu %s \n",yytext);  return mc_bool; }
{mc_car} {   col= col + yyleng; printf("entité reconnu %s \n",yytext);  return mc_car; }
{mc_str} {   col= col + yyleng; printf("entité reconnu %s \n",yytext);  return mc_str; }
{virgule} {   col= col + yyleng; printf("entité reconnu %s \n",yytext);  return virgule; }
{bool} { rechercher(yytext,"Cst bool","BOOLEEN",atof(yytext),0); col= col + yyleng; printf("entité reconnu %s \n",yytext); return bool;  }
{tabb}   {   col= col + yyleng; printf("entité reconnu %s \n",yytext); return tabb;  }
{ttype}   {   col= col + yyleng; printf("entité reconnu %s \n",yytext); return ttype;  }
{cst} {   col= col + yyleng; printf("entité reconnu %s \n",yytext);  return cst; }
{et} {   col= col + yyleng; printf("entité reconnu %s \n",yytext);  return et; }
{ou} {   col= col + yyleng; printf("entité reconnu %s \n",yytext);  return ou; }
{no} {   col= col + yyleng; printf("entité reconnu %s \n",yytext);  return no; }
{sup} {   col= col + yyleng; printf("entité reconnu %s \n",yytext);  return sup; }
{supe} {   col= col + yyleng; printf("entité reconnu %s \n",yytext);  return supe; }
{inf} {   col= col + yyleng; printf("entité reconnu %s \n",yytext);  return inf; }
{infe} {   col= col + yyleng; printf("entité reconnu %s \n",yytext);  return infe; }
{ega} {   col= col + yyleng; printf("entité reconnu %s \n",yytext);  return ega; }
{dif} {   col= col + yyleng; printf("entité reconnu %s \n",yytext);  return dif; }
{egale} {   col= col + yyleng; printf("entité reconnu %s \n",yytext);  return egale; }
{aff} {   col= col + yyleng; printf("entité reconnu %s \n",yytext);  return aff; }
{entre} {   col= col + yyleng; printf("entité reconnu %s \n",yytext);  return entre; }
{sorti} {   col= col + yyleng; printf("entité reconnu %s \n",yytext);  return sorti; }
{decv}     {   col= col + yyleng; printf("entité reconnu %s \n",yytext); return decv;  }
{decvar}   {   col= col + yyleng; printf("entité reconnu %s \n",yytext); return decvar;  }
{body}     {   col= col + yyleng; printf("entité reconnu %s \n",yytext); return body;  }
{as}        {  col= col + yyleng; printf("entité reconnu %s \n",yytext);  return as; }
{aprdeb}   {   col= col + yyleng; printf("entité reconnu %s \n",yytext);  return aprdeb; }
{start}    {   col= col + yyleng; printf("entité reconnu %s \n",yytext);  return start; }
{finish}   {   col= col + yyleng; printf("entité reconnu %s \n",yytext);  return finish; }
{si}  {   col= col + yyleng; printf("entité reconnu %s \n",yytext);  return si; }
{alors} {   col= col + yyleng; printf("entité reconnu %s \n",yytext);  return alors; }
{sinon} {   col= col + yyleng; printf("entité reconnu %s \n",yytext);  return sinon; }
{doo} {   col= col + yyleng; printf("entité reconnu %s \n",yytext);  return doo; }
{pour} {   col= col + yyleng; printf("entité reconnu %s \n",yytext); return pour;  }
{tantque} {   col= col + yyleng; printf("entité reconnu %s \n",yytext);  return tantque; }
{jusqua} {   col= col + yyleng; printf("entité reconnu %s \n",yytext);  return jusqua; }
{debut}    {   col= col + yyleng; printf("entité reconnu %s \n",yytext);  return debut; }
{ID}       {  rechercher(yytext,"IDF","",0,0);  col= col + yyleng; yylval.nom=strdup(yytext);  return ID; }
{sep}    {   col= col + yyleng; printf("entité reconnu %s \n",yytext);  return sep; }
{entier_pos} {  
	col= col + yyleng; 
	printf("from lex : %s",strdup(yytext));
		yylval.integer=atoi(yytext);
    printf("entité reconnu %s \n",yytext); 
	i=atoi(yytext); 
    if(i>32767 && i<-32767){ 
		printf ("Erreur Lexical: entier trop long a la ligne %d a la colonne %d \n ",ligne, col); 
	} 
     return entier_pos;  
	}
{entier_neg} {  
	col= col + yyleng; 
	printf("from lex : %s",strdup(yytext));
		yylval.integer=atoi(yytext);
    printf("entité reconnu %s \n",yytext); 
	i=atoi(yytext); 
    if(i>32767 && i<-32767){ 
		printf ("Erreur Lexical: entier trop long a la ligne %d a la colonne %d \n ",ligne, col); 
	} 
     return entier_neg;  
	}           
			 	
{reel} {  rechercher(yytext,"Cst real","REAL",atof(yytext),0);  col= col + yyleng; printf("entité reconnu %s \n",yytext); return reel;  }
{car} { rechercher(yytext,"Cst car","CHAR",atof(yytext),0);  col= col + yyleng; printf("entité reconnu %s \n",yytext);  return car; }
{str} {  rechercher(yytext,"Cst string","STRING",atof(yytext),0); col= col + yyleng; printf("entité reconnu %s \n",yytext);  return str; }
{plus} {   col= col + yyleng; printf("entité reconnu %s \n",yytext);  return plus; }
{moins} {   col= col + yyleng; printf("entité reconnu %s \n",yytext);  return moins; }
{mul} {   col= col + yyleng; printf("entité reconnu %s \n",yytext);  return mul; }

{parouv} {   col= col + yyleng; printf("entité reconnu %s \n",yytext);  return parouv; }
{parfer} {   col= col + yyleng; printf("entité reconnu %s \n",yytext);  return parfer; }
"["          {col= col + yyleng; printf("entité reconnu %s \n",yytext); return croch1;}
"]"          {col= col + yyleng; printf("entité reconnu %s \n",yytext); return croch2;}
\"         {col= col + yyleng; printf("entité reconnu %s \n",yytext); return doublecot;}
{deuxpoint} {   col= col + yyleng; printf("entité reconnu %s \n",yytext);  return deuxpoint; }

{formabol} {   col= col + yyleng; printf("entité reconnu %s \n",yytext);  return formabol; }
{formachr} {    col= col + yyleng; printf("entité reconnu %s \n",yytext);  return formachr; }
{formaflt} {   col= col + yyleng; printf("entité reconnu %s \n",yytext);  return formaflt; }
{formaint} {   col= col + yyleng; printf("entité reconnu %s \n",yytext);  return formaint; }
{formastr} {   col= col + yyleng; printf("entité reconnu %s \n",yytext);  return formastr; }

{fin} {   col= col + yyleng; printf("entité reconnu %s \n",yytext);  return fin; }
[\n]         {col=1; ligne++;}
{esp}     { col= col + yyleng; }
.  { printf ("Entité lexicale non reconnue a ligne %d a la colonne %d \n",ligne,col); }
%%
