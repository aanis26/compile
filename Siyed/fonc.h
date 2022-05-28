/****************CREATION DE LA TABLE DES SYMBOLES ******************/
/***Step 1: Definition des structures de données ***/
#include<stdlib.h>

typedef struct
{

	char Nom[40];
	char Code[20];
	char Type_D_Entite[20];
	char Type_idf[20];
	char Valconst[30];
	char constante[20];
    int taille ;

	
		
}TabSym;

TabSym ts[100];
int cpTS = 0 ;

//fonction de  detection de l'existence d'une entité 
int recherche(char entite[])
{
	int i=0;
	while (i<cpTS)
	{
		if (strcmp(entite,ts[i].Nom)==0)
			return i;
		i++ ;
		
	}
	return -1 ;
}
	

void inserer(char entite[],char code[],char Type[])
{

	if (recherche(entite)==-1)
    {
		strcpy(ts[cpTS].Nom,entite);
		strcpy(ts[cpTS].Code,code);
		strcpy(ts[cpTS].Type_D_Entite,Type);
		cpTS ++ ;
	}
}

void afficher()
{
	printf("\n                        ********************** Table des symboles **********************\n");
	printf("        ------------------------------------------------------------------------------------------------------------\n");
	printf("\t|             Nom               |    Code     | Type D'Entite  |     Type_idf     |   Valeur    | Constate | \n");    
	printf("        ------------------------------------------------------------------------------------------------------------\n");
	

	
	int i=0 ;
	while(i<cpTS)
	{
	printf("\t|%30s |%12s |%15s |%17s |%12s |%10s| \n", ts[i].Nom ,ts[i].Code ,ts[i].Type_D_Entite,ts[i].Type_idf,ts[i].Valconst,ts[i].constante);
		i++ ;
	}
	
}

//fonction qui permet l'insertion du type de la variable donné 
void InsererTypeIdf(char entite[] ,char Type[])
{

    int pos;
	pos = recherche(entite);
	if (pos !=-1)
    {
		strcpy(ts[pos].Type_idf,Type);
	
	}
}

//fonction de  detection d une existence de double declaration
int existe(char entite[])
{
	int pos;
	pos = recherche(entite);
	if(strcmp(ts[pos].Type_idf,"")==0) // si le type idf n'exixte pas alors ellr return 0
		return 0;
	else // sinin return -1
		return -1;
}

// fonction d'AFFECTATION  de CONST and NOT CONST
	void affecterconstante(char entite[],char cnst[]){
	int i=recherche(entite); 
	strcpy(ts[i].constante,cnst);
	}

// recherche l existence d'une valeur donné deja a un idf

	int const_a_Valeur(char entite[]){
		int pos=recherche(entite);

		if(strcmp(ts[pos].constante,"CONST INIT")==0) return 1;
		return -1;
	}

//insertion  d une nouvelle  valeur pour chaque idf existant déja 
	void inserer_Valeur_Const(char entite[],char s[]){
		int pos=recherche(entite);
		strcpy(ts[pos].Valconst,s);
	}

//verifier si un type existe dans la table des  symboles colonne : des types
int substring(char c1[],char c2[]){
   int i,j;
   for(i=0;i<strlen(c1);i++){
      j=0;
      while(c1[i]==c2[j] && i<strlen(c1) && j<strlen(c2)){
         j++;i++;
      }
      if(j==strlen(c2)){
         return 1;
      }
   
   }
   return 0;
}


// verif du type d expression si =0 correct sinon cest faux 
int returnTypeExp(char exp[],char svtyp[],char op[]){
	if (strcmp(exp,svtyp)==0) return 0;
	if(strcmp(svtyp,"chaine caractere")==0) 
		if(substring(exp,"entier")==1 || substring(exp,"reel")==1) return 1;
			else if(substring(op,"/")==1 && substring(op,"-")==1 && substring(op,"*")==1) return 1;
					else return 0;
		
	if(strcmp(svtyp,"entier")==0) 
		if(substring(exp,"chaine caractere")==1 || substring(exp,"reel")==1) return 1;
			else if(substring(op,"/")==1) return 1;
					else return 0;

	if(strcmp(svtyp,"reel")==0)
		if(substring(exp,"chaine caractere")==1 ) return 1;
		 else return 0;
				
}

//fonction qui permet de copier  un type donné d idf dans la TS

void typeidf(char entite[],char tp[]){
	int i=recherche(entite);
	strcpy(tp,ts[i].Type_idf);
}

//fonction qui permet le remplissage  des operations d'une expression

void InsererOp(char tab[],char x[]){
	strcat(tab,x);
}
void InsererTypeExp(char OP[],char x[]){
	strcat(OP,x);
}
	
//cas output
//fct insertion de tout les signes de formatage d un idf  

	void insererSigneIdf(char tab[],char entite[]){
		int pos =recherche(entite);
		if(strcmp(ts[pos].Type_idf,"entier")==0) strcat(tab,"$");
		if(strcmp(ts[pos].Type_idf,"reel")==0)strcat(tab,"%");
		if(strcmp(ts[pos].Type_idf,"chaine caractere")==0) strcat(tab,"#");
		if(strcmp(ts[pos].Type_idf,"caractere")==0)strcat(tab,"&");
	}
//fct d insertion de  tout les signes de formatage d une phrase

	void insererSignePhrase(char tab[],char sauvSigne[]){	
		strcat(tab,sauvSigne);
	}
	
//cas input
//fct vérification du  signe de formatage  
int checkaccept(char a [],char b [])
{
  int i=recherche(b);

  if(i!=-1)
    {if(a[0]=='$')
       { 
         if(strcmp(ts[i].Type_idf,"entier")!=0) return -1;
         else {return 0;} 
    }  
  
    if(a[0]=='%')
       {
		   if(strcmp(ts[i].Type_idf,"reel")!=0) return -1;
         else {return 0;}  
       }
     
  if(a[0]=='#')
       {if(strcmp(ts[i].Type_idf,"chaine caractere")!=0)return -1;
         else {return 0;}
       }
  
  if(a[0]=='&')
       {if(strcmp(ts[i].Type_idf,"caractere")!=0) return -1;
         else {return 0;}
       }     
   }
  else{return -1;}
}
//verifier (-int)
int verif_int(char ch[20]){
     char sh[20];
    int i=0,j=0,l=0;

    l=strlen(ch);
    if(ch[0]=='('&&ch[1]=='-'&&ch[l-1]==')'){
        i=1;
            while(i<l-2){
                sh[j]=ch[i];
                i++;
                j++;
            }
           if(atoi(sh)<0 && atoi(sh)>-32768){return 1;}
           else{return 0;}
    }

    else{ return 0;}

}
//verifier (-float)
int verif_f(char ch[20]){
     char sh[20];
    int i=0,j=0,l=0;

    l=strlen(ch);
    if(ch[0]=='('&&ch[1]=='-'&&ch[l-1]==')'){
        i=1;
            while(i<l-2){
                sh[j]=ch[i];
                i++;
                j++;
            }
           if(atof(sh)<0 && atof(sh)>-32768){return 1;}
           else{return 0;}
    }

    else{ return 0;}

}

/*float extraire(char ch[20]){

    char sh[20];
    int i=0,j=0,l=0;

    l=strlen(ch);
        i=1;
            while(i<l-2){
                sh[j]=ch[i];
                i++;
                j++;
            }
    return(atof(sh));
}
*/

