%{
	#include "syntaxique.tab.h" 
	// #include "ts.h"   
	#include "Table.h"
	extern nb_ligne;
	extern nbcol;
	extern YYSTYPE yylval;
%}

%option yylineno

lettre [a-zA-Z]
lettremaj [A-Z]
chiffre [0-9]
IDF	{lettre}({lettre}|{chiffre}){0,10}
entier	\(-{chiffre}+\)
reel {cst}\.{cst}|\(-{cst}\.{cst}\)
char	\'[^']\'
string	\"[^("|\|)]*\"
cst {chiffre}+
commentaire "/*"((("*"[^/])?)|[^*])*"*/"

%%



"</" {  nbcol+=yyleng; return strt_tag; }
"/>" {  nbcol+=yyleng; return end_tag; }
"<" {  nbcol+=yyleng; return op_tag; }
">" {  nbcol+=yyleng; return close_tag; }
"!docprogram" {  nbcol+=yyleng; return op_doc; }
"docprogram" {  nbcol+=yyleng; return end_doc; }
"SUB" {  nbcol+=yyleng; return sb; }
"VARIABLE" {  nbcol+=yyleng; return mc_var; }
"CONSTANTE" { nbcol+=yyleng; return mc_cnst; }
"body" {  nbcol+=yyleng; return body; }
"ARRAY" {  nbcol+=yyleng; return mc_array; }

"INT" {  nbcol+=yyleng; return tint;} 
"FLT" {  nbcol+=yyleng; return treel; }
"CHR" {  nbcol+=yyleng; return tchar; }
"STR" {  nbcol+=yyleng; return tstring;}
"BOL" {  nbcol+=yyleng; return tbool; }
"AS" {   nbcol+=yyleng; return as;}

"CONST" {   nbcol+=yyleng; return tcst; }

"=" {   nbcol+=yyleng; return egg; }
":" {   nbcol+=yyleng; return dp; }
"," {   nbcol+=yyleng; return vg; }
";" {   nbcol+=yyleng; return pvg; }

"+" {   nbcol+=yyleng; return add; }
"-" {   nbcol+=yyleng; return dec; }
"*"	{   nbcol+=yyleng; return mult; }
"/" {   nbcol+=yyleng; return divi; }

"[" {   nbcol+=yyleng; return cros; }
"]" {   nbcol+=yyleng; return croe; }
"(" {   nbcol+=yyleng; return prnts; }
")" {   nbcol+=yyleng; return prnte; }
"|" {   nbcol+=yyleng; return pipe; }

\<INPUT {   nbcol+=yyleng; return readstrt; }

\<OUTPUT {   nbcol+=yyleng; return writestrt; }

"$" {   nbcol+=yyleng; return repint; }
"%" {   nbcol+=yyleng; return repreal; }
"#" {   nbcol+=yyleng; return repstr; }
"&" {   nbcol+=yyleng; return repchar; }
"@" {   nbcol+=yyleng; return repbool; }

"\"" {   nbcol+=yyleng; return qot; }

AND {   nbcol+=yyleng; return my_and; }
OR {   nbcol+=yyleng; return my_or; }
NOT {   nbcol+=yyleng; return my_not; }
\<AFF {   nbcol+=yyleng; return mc_affstrt; }
AFF {   nbcol+=yyleng; return mc_aff; }

\<IF {   nbcol+=yyleng; return my_ifstrt; }
IF {   nbcol+=yyleng; return my_if; }
\<THEN {   nbcol+=yyleng; return my_thenstrt; }
THEN {   nbcol+=yyleng; return my_then; }
\<ELSE {   nbcol+=yyleng; return my_elsestrt; }
ELSE {   nbcol+=yyleng; return my_else; }
EGA {   nbcol+=yyleng; return egal; }
INF {   nbcol+=yyleng; return inf; }
SUP {   nbcol+=yyleng; return sup; }
INFE {   nbcol+=yyleng; return infe; }
SUPE {   nbcol+=yyleng; return supe; }
DIF   {   nbcol+=yyleng; return diff; }
WHILE {   nbcol+=yyleng; return my_while; }
UNTIL {   nbcol+=yyleng; return my_until; }
\<FOR {   nbcol+=yyleng; return my_forstrt; }
FOR {   nbcol+=yyleng; return my_for; }
DO {   nbcol+=yyleng; return my_do; }
\<DO {   nbcol+=yyleng; return my_dostrt; }

TRUE {nbcol+=yyleng;yylval.str=strdup(yytext); return true;}
FALSE {nbcol+=yyleng;yylval.str=strdup(yytext); return false;}
{reel} {
	yylval.str=strdup(yytext);
	nbcol+=yyleng; return reelr; }
{IDF} { yylval.str=strdup(yytext); nbcol+=yyleng; return idf; }
{cst} {	yylval.str=strdup(yytext);
	nbcol+=yyleng; return cst;	}
{entier} {yylval.str=strdup(yytext); if (atoi(yytext)< -32768 || atoi(yytext)>32767)  printf("erreur lexicale a la ligne %d et la colonne %d : entite lexciale non reconnue %s \n",nb_ligne,nbcol,yytext); 
	nbcol+=yyleng; return entierr; }
{char} { 
	yylval.str=strdup(yytext);
 nbcol+=yyleng; return charr; }
{string} {
	yylval.str=strdup(yytext);
	nbcol+=yyleng; return stringr; }
{commentaire}
[ \t] { nbcol+=yyleng; }
\n {nb_ligne++; nbcol=1; }
. printf("erreur lexicale a la ligne %d et la colonne %d : entite lexciale non reconnue %s \n",nb_ligne,nbcol,yytext);

%%