%{
    int nb_ligne=1, Col=1;
	char S_Signe_Formatage[10];
	char Type[20];
	char s_type[20], s_idf[20] , s_idf2[20];
    char tab_OP[30],tab_EXP[60];
	int S_Cst_Int; float S_Cst_reel;
	char S_Idf[8];
	char sauvConsts[20];
	int sauvChifr;
	char sauvOpr[20];
	char expOP[1];
	#include "string.h"
%}

%union{
	int entier  ;
	float reel ;
	char* str;
	}
	
%token mc_program mc_sub mc_variabl mc_body mc_ARRAY mc_cst mc_aff exlamation
       <str>mc_int <str>mc_real <str>mc_char <str>mc_string <str>idf 
	   <entier>cst_int <reel>cst_reel <str>cst_char <str>cst_string  
	   <str>division inf sup  ou dpoint pv egale gui vr cr_ouvr cr_ferm <str>add <str>sub <str>mul par_ouvr par_ferm signe_char signe_float signe_int signe_string
	   mc_do mc_while mc_if mc_then mc_else mc_input mc_output and or not greater lower ge le eq di


	   

%start S
%%
S: inf exlamation mc_program idf sup inf mc_sub mc_variabl sup DEC inf mc_body sup INST inf division mc_program sup {printf("Programme lexicalement et syntaxiquement correct"); YYACCEPT;}
;
DEC: DEC_CONST DEC
	|DEC_VAR DEC
    |DEC_TAB DEC
	|inf division mc_sub mc_variabl sup
;
DEC_CONST : inf mc_sub mc_cst sup DEC_CONSTANT 
;
DEC_CONSTANT:inf CONSTS division sup pv DEC_CONSTANT 
             | inf division mc_sub mc_cst sup
;
CONSTS:idf egale cst_int       {if (existe($1)==0) {
										InsererTypeIdf($1,"entier"); 
										affecterconstante($1,"CONST INIT"); 
										char x[20];
										itoa($3,x,10);

										inserer_Valeur_Const($1,x);

										S_Cst_Int=$3;
										
									}                          
                                    else 
							            printf("Ligne %d : Erreur semantique : double declaration de %s  \n",nb_ligne,$1);
							        }
            |idf egale cst_reel     {if (existe($1)==0) {
										InsererTypeIdf($1,"reel"); 
										affecterconstante($1,"CONST INIT"); 
										inserer_Valeur_Const($1,$3);
										S_Cst_reel=$3;
									}	                          
                                    else 
							            printf("Ligne %d : Erreur semantique : double declaration de %s  \n",nb_ligne,$1);
							        }
			|idf egale cst_char     {if (existe($1)==0) {
										InsererTypeIdf($1,"caractere");
										affecterconstante($1,"CONST INIT"); 
										inserer_Valeur_Const($1,$3);
										}	                          
                                     else 
							            printf("Ligne %d : Erreur semantique : double declaration de %s  \n",nb_ligne,$1);
							        }
			|idf egale cst_string   {if (existe($1)==0){
										InsererTypeIdf($1,"chaine caractere");
										affecterconstante($1,"CONST INIT"); 
										inserer_Valeur_Const($1,$3);
								    }	                          
                                   else 
							            printf("Ligne %d : Erreur semantique : double declaration  de %s \n ",nb_ligne,$1)
							      }
			|idf TYPE  {if (existe($1)==0) {
			                InsererTypeIdf($1,Type);
							affecterconstante($1,"CONST INIT");
             			}            
                        else 
							printf("Ligne %d : Erreur semantique : double declaration de %s  \n",nb_ligne,$1)
					    }
;
DEC_VAR: DEC_INT 
        |DECFLOAT
		|DEC_CHAR 
		|DECSTR 
;
DEC_INT :inf ListeIDFi mc_int division sup pv
;
ListeIDFi: idf ou ListeIDFi 
          {affecterconstante($1,"NOT CONST");
            if (existe($1)==0) {InsererTypeIdf($1,"entier");	}                          
            else 
			printf("Ligne %d : Erreur semantique : double declaration de %s \n",nb_ligne,$1)
			}
       | idf 
	   {affecterconstante($1,"NOT CONST");
            if (existe($1)==0) {InsererTypeIdf($1,"entier");	}                          
            else 
			printf("Ligne %d : Erreur semantique : double declaration de %s \n",nb_ligne,$1)
			}

;
DECFLOAT :inf ListeIDFf mc_real division sup pv
;
ListeIDFf: idf ou ListeIDFf 
          {affecterconstante($1,"NOT CONST");
            if (existe($1)==0) {InsererTypeIdf($1,"reel");	}                          
            else 
			printf("Ligne %d : Erreur semantique : double declaration de %s \n",nb_ligne,$1)
			}
       | idf 
	   {affecterconstante($1,"NOT CONST");
            if (existe($1)==0) {InsererTypeIdf($1,"reel");	}                          
            else 
			printf("Ligne %d : Erreur semantique : double declaration de %s \n",nb_ligne,$1)
			}

;
DEC_CHAR :inf ListeIDFc mc_char division sup pv
;
ListeIDFc: idf ou ListeIDFc 
          {affecterconstante($1,"NOT CONST");
            if (existe($1)==0) {InsererTypeIdf($1,"caractere");	}                          
            else 
			printf("Ligne %d : Erreur semantique : double declaration de %s \n",nb_ligne,$1)
			}
       | idf 
	   {affecterconstante($1,"NOT CONST");
            if (existe($1)==0) {InsererTypeIdf($1,"caractere");	}                          
            else 
			printf("Ligne %d : Erreur semantique : double declaration de %s \n",nb_ligne,$1)
			}

;
DECSTR : inf ListeIDFs mc_string division sup pv
;
ListeIDFs: idf ou
 ListeIDFs 
          {affecterconstante($1,"NOT CONST");
            if (existe($1)==0) {InsererTypeIdf($1,"chaine caractere");	}                          
            else 
			printf("Ligne %d : Erreur semantique : double declaration de %s \n",nb_ligne,$1)
			}
       | idf 
	   {affecterconstante($1,"NOT CONST");
            if (existe($1)==0) {InsererTypeIdf($1,"chaine caractere");	}                          
            else 
			printf("Ligne %d : Erreur semantique : double declaration de %s \n",nb_ligne,$1)
			}

;
DEC_TAB: inf mc_ARRAY TYPE sup DEC_TABleau 
;
DEC_TABleau: inf idf dpoint cst_int division sup DEC_TABleau
        {
            if(existe($2)==-1) printf("Ligne %d : Erreur semantique : double declaration de %s \n",nb_ligne,$1);
				
					else{ InsererTypeIdf($1,Type);
				          affecterconstante($1,"NOT CONST");
				}			
				}
			| inf division mc_ARRAY sup
				
;
TYPE:  mc_int      {strcpy(Type,"entier");}
     | mc_real     {strcpy(Type,"reel");}
	 | mc_char     {strcpy(Type,"caractere");}
	 | mc_string   {strcpy(Type,"chaine caractere");}
;



INST: LISTE_INST INST 

	 |inf division mc_body sup
	 
;
LISTE_INST:AFFECTATION  
           |BOUCLE
		   |TEST
		   |ACCEPT
		   |DISPLAY
		   
;
AFFECTATION:inf mc_aff dpoint TYPE_IDF vr IDF_CST  division sup
            {    
                          if(const_a_Valeur(S_Idf)==1) 
                              printf("Ligne %d : Erreur semantique :la constante %s a deja une valeur  \n",nb_ligne,S_Idf);
						   else{
						      if(strcmp(s_idf,s_type)==0 && strcmp(s_type,"entier")==0) {
							            char x[20];
										itoa(S_Cst_Int,x,10);
										inserer_Valeur_Const(S_Idf,x);}
							  else{
								
									if(strcmp(s_idf,s_type)==0 && strcmp(s_type,"reel")==0){
							            char x[20];
										gcvt(S_Cst_reel,8,x);
										inserer_Valeur_Const(S_Idf,x);}
									else{
								
										if(strcmp(s_idf,s_type)==0 && strcmp(s_type,"caractere")==0) 
											inserer_Valeur_Const(S_Idf,sauvConsts);
										else{
											if(strcmp(s_idf,s_type)==0 && strcmp(s_type,"chaine caractere")==0) 
												inserer_Valeur_Const(S_Idf,sauvConsts);
											else
												printf("Ligne %d : Erreur semantique :Non compatibilite de type \n", nb_ligne);
											}
								        }
								}
						  }
						
                    }
           |inf mc_aff dpoint TYPE_IDF vr EXP division sup
		           {    
                          if(const_a_Valeur(S_Idf)==1) 
                              printf("Ligne %d : Erreur semantique :la constante %s a deja une valeur \n",nb_ligne,S_Idf);
                         if(returnTypeExp(tab_EXP,s_idf,tab_OP)==1)
                               printf("Ligne %d : Erreur semantique :Non compatibilite de type  \n", nb_ligne); 
                    }
            
;

TYPE_IDF:idf 
          {    
              strcpy(S_Idf,$1);
               if(existe($1)==0){
                    printf("Ligne %d : Erreur semantique : idf %s non declarer \n",nb_ligne,$1);
                    InsererTypeIdf($1,"Non declarer");
                    }
               typeidf($1,s_idf);
			
          }
          | idf cr_ouvr cst_int cr_ferm 
               {
                    strcpy(S_Idf,$1);
                    if(existe($1)==0) {printf("Ligne %d : Erreur semantique : idf %s non declare \n",nb_ligne,$1);
                         InsererTypeIdf($1,"Non declarer");
                    }
                    
                    
              typeidf($1,s_idf);
               }
               
          | idf cr_ouvr idf cr_ferm 
                    {
                         strcpy(S_Idf,$1);
                         if(existe($1)==0) {
                              printf("Ligne %d : Erreur semantique : idf %s non declare \n",nb_ligne,$1);
                              InsererTypeIdf($1,"Non declarer");
                              }
                    typeidf($1,s_idf);
                    }

;
EXP: IDF_CST OPERATION 
            {InsererOp(tab_OP,expOP);
             InsererTypeExp(tab_EXP,s_type);
			}
	|par_ouvr EXP par_ferm OPERATION
	|EXP OPERATION
            {InsererOp(tab_OP,expOP);
             InsererTypeExp(tab_EXP,s_type);
			}	
;
OPERATION:  add IDF_CST
            |add par_ouvr EXP par_ferm 
		   |sub IDF_CST
           |sub par_ouvr EXP par_ferm		   
		   |mul IDF_CST 
		   |mul par_ouvr EXP par_ferm
		   |division par_ouvr EXP par_ferm
		   |division IDF_CST  {if (S_Cst_Int==0 |S_Cst_reel== 0.0 )
                                         printf("Ligne %d : Erreur semantique :Division par 0\n",nb_ligne);
										}  
		  
;
IDF_CST:idf                                { if(existe($1)==0){
												printf("Ligne %d : Erreur semantique : idf %s non declare  \n",nb_ligne,$1);
												InsererTypeIdf($1,"Undeclared");
                                            }
											typeidf($1,s_type); 
											} 
       |idf cr_ouvr cst_int cr_ferm        { if(existe($1)==0){
												printf("Ligne %d : Erreur semantique : idf %s non declare  \n",nb_ligne,$1);
												InsererTypeIdf($1,"Undeclared");
                                            }
											typeidf($1,s_type); 
											} 
	   |cst_int                            {S_Cst_Int=$1; strcpy(s_type,"entier");} 
       |cst_string                         {strcpy(s_type,"chaine caractere");strcpy(sauvConsts,$1);}
       |cst_reel                           {S_Cst_reel=$1;strcpy(s_type,"reel");}
	   |cst_char                           {strcpy(s_type,"caractere");strcpy(sauvConsts,$1);}
       |idf cr_ouvr idf cr_ferm            { if(existe($1)==0){
												printf("Ligne %d : Erreur semantique : idf %s non declare  \n",nb_ligne,$1);
												InsererTypeIdf($1,"Undeclared");
                                            }
											typeidf($1,s_type); 
											} 
;

THINGS_BOUCLE : LISTE_INST THINGS_BOUCLE 
        | inf mc_while dpoint LISTE_CONDITION division sup 

BOUCLE: inf mc_do sup THINGS_BOUCLE inf division mc_do sup

;
THINGS_IF : LISTE_INST THINGS_IF
             |inf division mc_then sup 
;
THINGS_ELSE : LISTE_INST THINGS_ELSE
             |inf division mc_else sup inf division mc_if sup
;
TEST:inf mc_if dpoint LISTE_CONDITION sup inf mc_then sup THINGS_IF inf division mc_if sup 

     |inf mc_if dpoint LISTE_CONDITION sup inf mc_then sup THINGS_IF inf mc_else sup THINGS_ELSE 


;
LISTE_CONDITION: OP_LOGIC par_ouvr LISTE_CONDITION par_ferm
               | OP_LOGIC par_ouvr LEXP par_ferm
               | OP_COMPARAISON par_ouvr IDF_CST vr IDF_CST par_ferm
			   | not par_ouvr LISTE_CONDITION par_ferm
			   | not par_ouvr EXP par_ferm
			   | not par_ouvr IDF_CST par_ferm
;
LEXP: EXP vr LEXP
     |EXP
;


OP_LOGIC:and | or 
;

OP_COMPARAISON: greater |lower |ge |le |eq |di
;
ACCEPT:inf mc_input dpoint idf gui  SIGNE_FORMATAGE gui division sup
			    {if(checkaccept($4,$5)==-1)
			        printf("Ligne %d : Erreur semantique :Non compatibilite de type  \n",nb_ligne);
			    }
;

DISPLAY: inf mc_output dpoint DIS	
;
DIS:gui  SIGNE_FORMATAGE gui add idf add DIS
                            {
							    
								int M;
								M=checkaccept(S_Signe_Formatage,$5);
								if(M!=0){
								  printf("Ligne %d : Erreur semantique : signe de formatage incorrecte \n",nb_ligne);
	                            }						
							}
	| gui  SIGNE_FORMATAGE gui add idf division sup
                            {
							    
								int M;
								M=checkaccept(S_Signe_Formatage,$5);
								if(M!=0){
								  printf("Ligne %d : Erreur semantique : signe de formatage incorrecte \n",nb_ligne);
	                            }						
							}
	| gui  gui division sup
;

SIGNE_FORMATAGE:  signe_string {strcpy(S_Signe_Formatage,"#");}
                 |signe_int    {strcpy(S_Signe_Formatage,"$");}
                 |signe_float  {strcpy(S_Signe_Formatage,"%");}
				 |signe_char   {strcpy(S_Signe_Formatage,"&");}
;



%%
main()
{
yyparse();
afficher();
}
yywrap ()
{}
int yyerror ( char*  msg )  
 {
    printf ("Ligne %d : Colonne %d : Erreur Syntaxique  \n", nb_ligne,Col);
  }

 