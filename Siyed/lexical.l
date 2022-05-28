%{
#include "fonc.h"
#include "syntaxique.tab.h"
extern nb_ligne;
extern Col;
extern YYSTYPE yylval;


%}

lettreM       [A-Z]
lettre        [a-zA-Z]
chiffre       [0-9]
IDF           {lettreM}({lettre}|{chiffre})*
VAR           {lettre}({lettre}|{chiffre})* 
cst           {chiffre}+
entier        [(]?[-+]?{chiffre}+[)]?
reel          [(]?[-+]?{chiffre}+"."{chiffre}+[)]?
ap            '
gui           "\"" 
cstChar       {ap}({lettre}|{lettreM}){ap}
espace        " "
string        {gui}{lettre}({lettre}|{chiffre}|{espace})+{gui}
chaine        ({lettre}|{lettreM})+
commentaire       (.*)


%%
"docprogram"              { Col= Col + strlen(yytext);  inserer(yytext,"docprogram","mot cle"); printf (" L entite lexicale reconnue est %s \n", yytext); return mc_program;  }
"SUB"                     { Col= Col + strlen(yytext);  inserer(yytext,"SUB","mot cle");        printf (" L entite lexicale reconnue est %s \n", yytext); return mc_sub;      }
"VARIABLE"                { Col= Col + strlen(yytext);  inserer(yytext,"VARIABLE","mot cle");     printf (" L entite lexicale reconnue est %s \n", yytext); return mc_variabl; }
"body"                    { Col= Col + strlen(yytext);  inserer(yytext,"body","mot cle");    printf (" L entite lexicale reconnue est %s \n", yytext); return mc_body;     }
"ARRAY"                   { Col= Col + strlen(yytext);  inserer(yytext,"ARRAY","mot cle");    printf (" L entite lexicale reconnue est %s \n", yytext); return mc_ARRAY;    }
"CONSTANTE"               { Col= Col + strlen(yytext);  inserer(yytext,"CONSTANTE","mot cle");    printf (" L entite lexicale reconnue est %s \n", yytext); return mc_cst;      }
"AFF"                     { Col= Col + strlen(yytext);  inserer(yytext,"AFF","affectatio");    printf (" L entite lexicale reconnue est %s \n", yytext); return mc_aff;      }
"DO"     				  {Col= Col + strlen(yytext);  inserer(yytext,"DO","boule"); return mc_do;              }
"WHILE"     			  {Col= Col + strlen(yytext);  inserer(yytext,"WHILE","boucle"); return mc_while;              }
"IF"     				  {Col= Col + strlen(yytext);  inserer(yytext,"IF","TEST"); return mc_if;              }
"THEN"     				  {Col= Col + strlen(yytext);  inserer(yytext,"THEN","TEST"); return mc_then;              }
"ELSE"     				  {Col= Col + strlen(yytext);  inserer(yytext,"ELSE","TEST"); return mc_else;              }
"INPUT"     			  {Col= Col + strlen(yytext);  inserer(yytext,"INPUT","ENTRE"); return mc_input;              }
"OUTPUT"     			  {Col= Col + strlen(yytext);  inserer(yytext,"OUTPUT","SORTIE"); return mc_output;              }
"AND" 				      { Col= Col + strlen(yytext);   inserer(yytext,"and","op_logique"); return and;}
"OR"  				      { Col= Col + strlen(yytext);   inserer(yytext,"or","op_logique"); return or;}
"NOT"  				      { Col= Col + strlen(yytext);   inserer(yytext,"not","op_logique"); return not;}
"SUP"   				  { Col= Col + strlen(yytext);   inserer(yytext,"greater","op_compar"); return greater;}
"INF"   				  { Col= Col + strlen(yytext);   inserer(yytext,"lower","op_compar"); return lower;}
"SUPE"  				  { Col= Col + strlen(yytext);   inserer(yytext,"ge","op_compar"); return ge;}
"INFE"  				  { Col= Col + strlen(yytext);   inserer(yytext,"le","op_compar"); return le;}
"EGA"  				      { Col= Col + strlen(yytext);   inserer(yytext,"eq","op_compar"); return eq;}
"DIF"  				      { Col= Col + strlen(yytext);   inserer(yytext,"di","op_compar"); return di;}


INT     {Col= Col + strlen(yytext);
         yylval.str=strdup(yytext);
		 inserer(yytext,"mc_int","mot cle");
         return mc_int ;  }

FLT   {Col= Col + strlen(yytext); 
         inserer(yytext,"mc_real","mot cle"); 
		 yylval.str=strdup(yytext);
		 return mc_real ;  }


CHR    {Col= Col + strlen(yytext);
		 inserer(yytext,"mc_char","mot cle"); 
		 yylval.str=strdup(yytext);
		 return mc_char ;  }


STR  {Col= Col + strlen(yytext); 
         inserer(yytext,"mc_string","mot cle"); 
		 yylval.str=strdup(yytext);
		 return mc_string ;  }

{IDF}      {  Col= Col + strlen(yytext); inserer(yytext,"idf","identificateur");
			 if (yyleng<=8) {yylval.str=strdup(yytext);
                             return idf ;}
			 else 
			 {
			 printf ("Erreur Lexical: IDF trop long a la ligne %d a la colonne %d \n ",nb_ligne, Col);}
			 
		   }
		 


{entier}    {Col= Col + strlen(yytext);
			yylval.entier=atoi(yytext);
			if(verif_int==0 | yylval.entier>32768 | yylval.entier<-32768 ){
        	printf("integer invalide ligne:%d,colonne:%d \n",nb_ligne,Col);
         	}
         	else{Col+=yyleng;
	
			return cst_int ; } 
			}

{reel}    {Col= Col + strlen(yytext);
            yylval.reel=atof(yytext);
            if(verif_f==0){
 	        printf("float invalide ligne:%d,colonne: %d\n",nb_ligne,Col);
 	        }
	        else{printf("float valide : %s\n",yytext);  
	        Col+=yyleng;} return cst_reel ;
            }
			
{cstChar}   {Col= Col + strlen(yytext);
            yylval.str=strdup(yytext);
            inserer(yytext,"cst_char","constant"); return cst_char ;  }	

{string}  { Col= Col + strlen(yytext);
            yylval.str=strdup(yytext);
            inserer(yytext,"cst_string","constant"); return cst_string ;  }


{gui}     {Col= Col + strlen(yytext); inserer(yytext,"gui","separateur"); return gui ;  }




"/"                     { Col= Col + strlen(yytext);   inserer(yytext,"division","op mathematique");           return division;}
"<"                     { Col= Col + strlen(yytext);   inserer(yytext,"inf","op mathematique");                return inf;     }
">"                     { Col= Col + strlen(yytext);   inserer(yytext,"sup","op mathematique");                return sup;     } 
"!"                     { Col= Col + strlen(yytext);   inserer(yytext,"exlamation","operateur");               return exlamation;}
"|"                     { Col= Col + strlen(yytext);   inserer(yytext,"or","op_logique");                      return ou;}
":"                     { Col= Col + strlen(yytext);   inserer(yytext,"deux point","operateur");               return dpoint;}
";"                     { Col= Col + strlen(yytext);   inserer(yytext,"point virgule","operateur");            return pv;}
"="                     { Col= Col + strlen(yytext);   inserer(yytext,"egale","separateur"); return egale ;}
","                     { Col= Col + strlen(yytext);   inserer(yytext,"virgule","separateur"); return vr ;}
"["						{ Col= Col + strlen(yytext);   inserer(yytext,"cr_ouvr","separateur"); return cr_ouvr;}
"]"     				{ Col= Col + strlen(yytext);   inserer(yytext,"cr_ferm","separateur"); return cr_ferm;}
"+"     				{ Col= Col + strlen(yytext);   inserer(yytext,"add","separateur"); return add ;}
"-"     				{ Col= Col + strlen(yytext);   inserer(yytext,"sub","separateur"); return sub ;}
"*"     				{ Col= Col + strlen(yytext);   inserer(yytext,"mul","separateur"); return mul ;}
"("						{ Col= Col + strlen(yytext);   inserer(yytext,"par_ouvr","separateur"); return par_ouvr;}
")"     				{ Col= Col + strlen(yytext);   inserer(yytext,"par_ferm","separateur"); return par_ferm;}
"&"     				{ Col= Col + strlen(yytext);   inserer(yytext,"signe_char","signe formatage"); return signe_char;}
"%"     				{ Col= Col + strlen(yytext);   inserer(yytext,"signe_float","signe formatage"); return signe_float;}
"$"     				{ Col= Col + strlen(yytext);   inserer(yytext,"signe_int","signe formatage"); return signe_int;}
"#"    				 	{ Col= Col + strlen(yytext);   inserer(yytext,"signe_string","signe formatage"); return signe_string ;  }


[ \t]     Col= Col + strlen(yytext);
\n        {Col= 1; nb_ligne++;} 
"#"{commentaire}"!" { Col= Col + strlen(yytext);}
. { printf ("Entité lexicale non reconnue a ligne %d a la colonne %d \n", nb_ligne, Col);}
%%