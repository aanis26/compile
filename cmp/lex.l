%{
	#include "syntaxique.tab.h" 
	// #include "ts.h"   
	#include "Table.h"
	extern nbligne;
	extern col;
	extern YYSTYPE yylval;
%}


%option yylineno

lettre [a-zA-Z]
lettremaj [A-Z]
chiffre [0-9]
IDF	{lettre}({lettre}|{chiffre}){0,10}
entier	\(-{chiffre}+\)
flt {cst}\.{cst}|\(-{cst}\.{cst}\)
char	\'[^']\'
string	\"[^("|\|)]*\"
cst {chiffre}+
comm "/*"((("*"[^/])?)|[^*])*"*/"
boolt  "TRUE"
boolf  "FALSE"
pour "FOR"
doo "DO"
jusqua "UNTIL"
tantque "WHILE"
dif "DIF"
sup "SUP"
inf "INF"
supe "SUPE"
infe "INFE"
ega "EGA"
si "IF"
alors "THEN"
sinon "ELSE"
et "AND"
ou "OR"
no "NOT"
aff "AFF"
formaint "$"
formaflt "%"
formastr "#"
formachr "&"
formabol "@"
mc_entier "INT"
mc_reel "FLT"
mc_bool "BOL"
mc_car "CHR"
mc_str "STR"
as "AS"
parouv "("
parfer ")"
sep "|"
plus "+"
moins "-"
mul "*"
div "/"
egale "="
fin ";"
virgule ","
deuxpoint ":"
decvar "VARIABLE"
inst "body"
tabb "ARRAY"
debut "docprogram"
decv "SUB"
cste "CONSTANTE"
%%



"</" {  col+=yyleng; return strt_tag; }
"/>" {  col+=yyleng; return end_tag; }
"<" {  col+=yyleng; return op_tag; }
">" {  col+=yyleng; return close_tag; }
"!docprogram" {  col+=yyleng; return op_doc; }
{debut} {  col+=yyleng; return end_doc; }
"SUB" {  col+=yyleng; return sb; }
{decvar} {  col+=yyleng; return mc_var; }
"CONSTANTE" { col+=yyleng; return mc_cnst; }
{inst} {  col+=yyleng; return body; }
{tabb} {  col+=yyleng; return mc_array; }

{mc_entier} {  col+=yyleng; return tint;} 
{mc_reel} {  col+=yyleng; return treel; }
{mc_car} {  col+=yyleng; return tchar; }
{mc_str} {  col+=yyleng; return tstring;}
{mc_bool} {  col+=yyleng; return tbool; }
{as} {   col+=yyleng; return as;}

"CONST" {   col+=yyleng; return tcst; }

{egale} {   col+=yyleng; return egg; }
{deuxpoint} {   col+=yyleng; return dp; }
{virgule} {   col+=yyleng; return vg; }
{fin} {   col+=yyleng; return pvg; }

{plus} {   col+=yyleng; return add; }
{moins} {   col+=yyleng; return dec; }
{mul}	{   col+=yyleng; return mult; }
{div} {   col+=yyleng; return divi; }

"[" {   col+=yyleng; return cros; }
"]" {   col+=yyleng; return croe; }
{parouv} {   col+=yyleng; return prnts; }
{parfer} {   col+=yyleng; return prnte; }
{sep} {   col+=yyleng; return pipe; }

\<INPUT {   col+=yyleng; return readd; }

\<OUTPUT {   col+=yyleng; return writee; }

{formaint} {   col+=yyleng; return forint; }
{formaflt} {   col+=yyleng; return forreal; }
{formastr} {   col+=yyleng; return forstr; }
{formachr} {   col+=yyleng; return forchar; }
{formabol} {   col+=yyleng; return forbool; }

"\"" {   col+=yyleng; return qot; }

{et} {   col+=yyleng; return mc_and; }
{ou} {   col+=yyleng; return mc_or; }
{no} {   col+=yyleng; return mc_not; }
\<AFF {   col+=yyleng; return mc_affstrt; }
{aff} {   col+=yyleng; return mc_aff; }

\<IF {   col+=yyleng; return mc_ifstrt; }
{si} {   col+=yyleng; return mc_if; }
\<THEN {   col+=yyleng; return mc_thenstrt; }
{alors} {   col+=yyleng; return mc_then; }
\<ELSE {   col+=yyleng; return mc_elsestrt; }
{sinon} {   col+=yyleng; return mc_else; }
{ega} {   col+=yyleng; return egal; }
{inf} {   col+=yyleng; return inf; }
{sup} {   col+=yyleng; return sup; }
{infe} {   col+=yyleng; return infe; }
{supe} {   col+=yyleng; return supe; }
{dif}  {   col+=yyleng; return diff; }
{tantque} {   col+=yyleng; return mc_while; }
{jusqua} {   col+=yyleng; return mc_until; }
\<FOR {   col+=yyleng; return mc_forstrt; }
{pour} {   col+=yyleng; return mc_for; }
{doo} {   col+=yyleng; return mc_do; }
\<DO {   col+=yyleng; return mc_dostrt; }


{boolt} TRUE {col+=yyleng;yylval.str=strdup(yytext); return true;}
{boolf} {col+=yyleng;yylval.str=strdup(yytext); return false;}
{flt} {
	yylval.str=strdup(yytext);
	col+=yyleng; return flt; }
{IDF} { yylval.str=strdup(yytext); col+=yyleng; return idf; }
{cst} {	yylval.str=strdup(yytext);
	col+=yyleng; return cst;	}
{entier} {yylval.str=strdup(yytext); if (atoi(yytext)< -32768 || atoi(yytext)>32767)  printf("erreur lexicale a la ligne %d et la colonne %d : entite lexciale non reconnue %s \n",nbligne,col,yytext); 
	col+=yyleng; return ent; }
{char} { 
	yylval.str=strdup(yytext);
 col+=yyleng; return ch; }
{string} {
	yylval.str=strdup(yytext);
	col+=yyleng; return strr; }
{comm}
[ \t] { col+=yyleng; }
\n {nbligne++; col=1; }
. printf("erreur lexicale a la ligne %d et la colonne %d : entite lexciale non reconnue %s \n",nbligne,col,yytext);

%%