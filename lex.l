%{
#include <stdio.h>
#include "syntasem.tab.h"
#include "tables.h"
extern ligne;
extern col;
int i;
%}
debut "docprogram"
aprdeb "!"
start "<"
finish ">"
divfini "/"
lettre [a-zA-Z]
chiffre [0-9]
ID [a-zA-Z0-9]*
decv "SUB"
decvar "VARIABLE"
inst "body"
tabb "ARRAY"
ttype "TYPE"
mc_entier "INT"
mc_reel "FLT"
mc_bool "BOL"
mc_car "CHR"
mc_str "STR"
entier  {chiffre}+|\(\-{chiffre}+\)
reel    {chiffre}+\.{chiffre}+|\(\-{chiffre}+\.{chiffre}+\)
bool  "TRUE"|"FALSE"
car \'[a-zA-Z0-9]\'
str  \"[a-zA-Z0-9]+\"
cst "CONSTANTE"
plus "+"
moins "-"
mul "*"
div "/"
egale "="
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
saut_ligne "\n"
esp [ \t]
%%
{divfini}    {  rechercher(yytext,"Mot cle",0,0,2); col= col + strlen(yytext); printf("entité reconnu %s \n",yytext); return divfini;  }
{mc_entier} {  rechercher(yytext,"Mot cle",0,0, 1); col= col + strlen(yytext); printf("entité reconnu %s \n",yytext); return mc_entier; }
{mc_reel} {  rechercher(yytext,"Mot cle",0,0, 1); col= col + strlen(yytext); printf("entité reconnu %s \n",yytext);  return mc_reel; }
{mc_bool} {  rechercher(yytext,"Mot cle",0,0, 1); col= col + strlen(yytext); printf("entité reconnu %s \n",yytext);  return mc_bool; }
{mc_car} {  rechercher(yytext,"Mot cle",0,0, 1); col= col + strlen(yytext); printf("entité reconnu %s \n",yytext);  return mc_car; }
{mc_str} {  rechercher(yytext,"Mot cle",0,0, 1); col= col + strlen(yytext); printf("entité reconnu %s \n",yytext);  return mc_str; }
{virgule} {  rechercher(yytext,"Mot cle",0,0,2); col= col + strlen(yytext); printf("entité reconnu %s \n",yytext);  return virgule; }
{bool} { rechercher(yytext,"Cst bool","BOOLEEN",atof(yytext),0); col= col + strlen(yytext); printf("entité reconnu %s \n",yytext); return bool;  }
{tabb}   {  rechercher(yytext,"Mot cle",0,0, 1); col= col + strlen(yytext); printf("entité reconnu %s \n",yytext); return tabb;  }
{ttype}   {  rechercher(yytext,"Mot cle",0,0, 1); col= col + strlen(yytext); printf("entité reconnu %s \n",yytext); return ttype;  }
{cst} {  rechercher(yytext,"Mot cle",0,0, 1); col= col + strlen(yytext); printf("entité reconnu %s \n",yytext);  return cst; }
{et} {  rechercher(yytext,"Mot cle",0,0,2); col= col + strlen(yytext); printf("entité reconnu %s \n",yytext);  return et; }
{ou} {  rechercher(yytext,"Mot cle",0,0,2); col= col + strlen(yytext); printf("entité reconnu %s \n",yytext);  return ou; }
{no} {  rechercher(yytext,"Mot cle",0,0,2); col= col + strlen(yytext); printf("entité reconnu %s \n",yytext);  return no; }
{sup} {  rechercher(yytext,"Mot cle",0,0,2); col= col + strlen(yytext); printf("entité reconnu %s \n",yytext);  return sup; }
{supe} {  rechercher(yytext,"Mot cle",0,0,2); col= col + strlen(yytext); printf("entité reconnu %s \n",yytext);  return supe; }
{inf} {  rechercher(yytext,"Mot cle",0,0,2); col= col + strlen(yytext); printf("entité reconnu %s \n",yytext);  return inf; }
{infe} { rechercher(yytext,"Mot cle",0,0,2);  col= col + strlen(yytext); printf("entité reconnu %s \n",yytext);  return infe; }
{ega} { rechercher(yytext,"Mot cle",0,0,2);  col= col + strlen(yytext); printf("entité reconnu %s \n",yytext);  return ega; }
{dif} { rechercher(yytext,"Mot cle",0,0,2);  col= col + strlen(yytext); printf("entité reconnu %s \n",yytext);  return dif; }
{egale} {  rechercher(yytext,"Mot cle",0,0,2); col= col + strlen(yytext); printf("entité reconnu %s \n",yytext);  return egale; }
{aff} { rechercher(yytext,"Mot cle",0,0,2);  col= col + strlen(yytext); printf("entité reconnu %s \n",yytext);  return aff; }
{entre} {  rechercher(yytext,"Mot cle",0,0, 1); col= col + strlen(yytext); printf("entité reconnu %s \n",yytext);  return entre; }
{sorti} { rechercher(yytext,"Mot cle",0,0, 1);  col= col + strlen(yytext); printf("entité reconnu %s \n",yytext);  return sorti; }
{decv}     {  rechercher(yytext,"Mot cle",0,0, 1); col= col + strlen(yytext); printf("entité reconnu %s \n",yytext); return decv;  }
{decvar}   {  rechercher(yytext,"Mot cle",0,0, 1); col= col + strlen(yytext); printf("entité reconnu %s \n",yytext); return decvar;  }
{inst}     {  rechercher(yytext,"Mot cle",0,0, 1); col= col + strlen(yytext); printf("entité reconnu %s \n",yytext); return inst;  }
{as}        { rechercher(yytext,"Mot cle",0,0, 1); col= col + strlen(yytext); printf("entité reconnu %s \n",yytext);  return as; }
{aprdeb}   { rechercher(yytext,"Mot cle",0,0,2);  col= col + strlen(yytext); printf("entité reconnu %s \n",yytext);  return aprdeb; }
{start}    {  rechercher(yytext,"Mot cle",0,0,2); col= col + strlen(yytext); printf("entité reconnu %s \n",yytext);  return start; }
{finish}   {  rechercher(yytext,"Mot cle",0,0,2); col= col + strlen(yytext); printf("entité reconnu %s \n",yytext);  return finish; }
{si}  {  rechercher(yytext,"Mot cle",0,0, 1); col= col + strlen(yytext); printf("entité reconnu %s \n",yytext);  return si; }
{alors} { rechercher(yytext,"Mot cle",0,0, 1);  col= col + strlen(yytext); printf("entité reconnu %s \n",yytext);  return alors; }
{sinon} { rechercher(yytext,"Mot cle",0,0, 1);  col= col + strlen(yytext); printf("entité reconnu %s \n",yytext);  return sinon; }
{doo} {  rechercher(yytext,"Mot cle",0,0, 1); col= col + strlen(yytext); printf("entité reconnu %s \n",yytext);  return doo; }
{pour} {  rechercher(yytext,"Mot cle",0,0, 1); col= col + strlen(yytext); printf("entité reconnu %s \n",yytext); return pour;  }
{tantque} { rechercher(yytext,"Mot cle",0,0, 1);  col= col + strlen(yytext); printf("entité reconnu %s \n",yytext);  return tantque; }
{jusqua} { rechercher(yytext,"Mot cle",0,0, 1);  col= col + strlen(yytext); printf("entité reconnu %s \n",yytext);  return jusqua; }
{debut}    {  rechercher(yytext,"Mot cle",0,0, 1); col= col + strlen(yytext); printf("entité reconnu %s \n",yytext);  return debut; }
{ID}       {  rechercher(yytext,"IDF","",0,0);  col= col + strlen(yytext); printf("entité reconnu %s \n",yytext);  return ID; }
{sep}    {  rechercher(yytext,"Mot cle",0,0,2); col= col + strlen(yytext); printf("entité reconnu %s \n",yytext);  return sep; }
{entier} { rechercher(yytext,"Cst entiere","INTEGER",atof(yytext),0);  col= col + strlen(yytext); printf("entité reconnu %s \n",yytext); i=atoi(yytext); 
         if(i>32767 && i<-32767){ printf ("Erreur Lexical: entier trop long a la ligne %d a la colonne %d \n ",ligne, col); } 
          return entier;  }
{reel} {  rechercher(yytext,"Cst real","REAL",atof(yytext),0);  col= col + strlen(yytext); printf("entité reconnu %s \n",yytext); return reel;  }
{car} { rechercher(yytext,"Cst car","CHAR",atof(yytext),0);  col= col + strlen(yytext); printf("entité reconnu %s \n",yytext);  return car; }
{str} {  rechercher(yytext,"Cst string","STRING",atof(yytext),0); col= col + strlen(yytext); printf("entité reconnu %s \n",yytext);  return str; }
{plus} { rechercher(yytext,"Mot cle",0,0,2);  col= col + strlen(yytext); printf("entité reconnu %s \n",yytext);  return plus; }
{moins} { rechercher(yytext,"Mot cle",0,0,2);  col= col + strlen(yytext); printf("entité reconnu %s \n",yytext);  return moins; }
{mul} { rechercher(yytext,"Mot cle",0,0,2);  col= col + strlen(yytext); printf("entité reconnu %s \n",yytext);  return mul; }

{parouv} {  rechercher(yytext,"Mot cle",0,0,2); col= col + strlen(yytext); printf("entité reconnu %s \n",yytext);  return parouv; }
{parfer} {  rechercher(yytext,"Mot cle",0,0,2); col= col + strlen(yytext); printf("entité reconnu %s \n",yytext);  return parfer; }

{deuxpoint} {  rechercher(yytext,"Mot cle",0,0,2); col= col + strlen(yytext); printf("entité reconnu %s \n",yytext);  return deuxpoint; }

{formabol} {  rechercher(yytext,"Mot cle",0,0,2); col= col + strlen(yytext); printf("entité reconnu %s \n",yytext);  return formabol; }
{formachr} {   rechercher(yytext,"Mot cle",0,0,2); col= col + strlen(yytext); printf("entité reconnu %s \n",yytext);  return formachr; }
{formaflt} { rechercher(yytext,"Mot cle",0,0,2);  col= col + strlen(yytext); printf("entité reconnu %s \n",yytext);  return formaflt; }
{formaint} {  rechercher(yytext,"Mot cle",0,0,2); col= col + strlen(yytext); printf("entité reconnu %s \n",yytext);  return formaint; }
{formastr} {  rechercher(yytext,"Mot cle",0,0,2); col= col + strlen(yytext); printf("entité reconnu %s \n",yytext);  return formastr; }

{fin} { rechercher(yytext,"Mot cle",0,0,2);  col= col + strlen(yytext); printf("entité reconnu %s \n",yytext);  return fin; }
{saut_ligne}  { col= 1; ligne++; }
{esp}     { col= col + strlen(yytext); }
.  { printf ("Entité lexicale non reconnue a ligne %d a la colonne %d \n",ligne,col); }
%%
