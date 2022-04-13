#include <stdio.h>
#include <stdlib.h>


typedef struct
{
   int state;
   char name[20];
   char code[20];
   char type[20];
   float val;
 } element;
 
 typedef struct
{ 
   int state; 
   char name[20];
   char type[20];
} elt;


element tab[1000];
elt tabs[100],tabm[40];
extern char sav[20];
char chaine [] = "";



void initialisation()
{
  int i;
  for (i=0;i<1000;i++)
  tab[i].state=0;
  
  

  for (i=0;i<40;i++)
    {tabs[i].state=0;
    tabm[i].state=0;}

}



void afficher()
{int i;

printf("/***************Table des symboles IDF*************/\n");
printf("____________________________________________________________________\n");
printf("\t| Nom_Entite |  Code_Entite | Type_Entite | Val_Entite\n");
printf("____________________________________________________________________\n");
  
for(i=0;i<50;i++)
{	
	
    if(tab[i].state==1)
      { 
        printf("\t|%10s |%15s | %12s | %12f\n",tab[i].name,tab[i].code,tab[i].type,tab[i].val);
         
      }
}

 
printf("\n/***************Table des symboles mots clés*************/\n");

printf("_____________________________________\n");
printf("\t| NomEntite |  CodeEntite | \n");
printf("_____________________________________\n");
  
for(i=0;i<40;i++)
    if(tabm[i].state==1)
      { 
        printf("\t|%10s |%12s | \n",tabm[i].name, tabm[i].type);
               
      }

printf("\n/***************Table des symboles séparateurs*************/\n");

printf("_____________________________________\n");
printf("\t| NomEntite |  CodeEntite | \n");
printf("_____________________________________\n");
  
for(i=0;i<100;i++)
    if(tabs[i].state==1)
      { 
        printf("\t|%10s |%12s | \n",tabs[i].name,tabs[i].type );
        
      }

}



void inserer (char entite[], char code[],char type[],float val,int i, int y)
{
  switch (y)
 { 
   case 0:
       tab[i].state=1;
       strcpy(tab[i].name,entite);
       strcpy(tab[i].code,code);
	   strcpy(tab[i].type,type);
	   tab[i].val=val;
	   break;

   case 1:
       tabm[i].state=1;
       strcpy(tabm[i].name,entite);
       strcpy(tabm[i].type,code);
       break; 
    
   case 2:
      tabs[i].state=1;
      strcpy(tabs[i].name,entite);
      strcpy(tabs[i].type,code);
      break;
 }

}


void rechercher (char entite[], char code[],char type[],float val,int y)	
{

int j,i;

switch(y) 
  {
   case 0:
        for (i=0;((i<1000)&&(tab[i].state==1))&&(strcmp(entite,tab[i].name)!=0);i++); 
        if((i<1000)&&(strcmp(entite,tab[i].name)!=0))
        { 
	        
			inserer(entite,code,type,val,i,0); 
	      
         }
        else
          printf("entité existe déjà\n");
        break;

   case 1:
       i=0;
	   for (i=0;((i<40)&&(tabm[i].state==1))&&(strcmp(entite,tabm[i].name)!=0);i++); 
        if(i<40)
          inserer(entite,code,type,val,i,1);
        else
          printf("entité existe déjà\n");
        break; 
    
   case 2:
         for (i=0;((i<100)&&(tabs[i].state==1))&&(strcmp(entite,tabs[i].name)!=0);i++); 
        if(i<100)
         inserer(entite,code,type,val,i,2);
        else
   	       printf("entité existe déjà\n");
        break;

  }

}


	
    int Recherche_position(char entite[])
		{
		int i=0;
		while(i<1000)
		{
		
		if (strcmp(tab[i].name,entite)==0) { return i; }	
		i++;
		}
 
		return -1;
		
		}

	 void insererTYPE(char entite[], char type[])
	{
       int pos;
	   pos=Recherche_position(entite);
	   if(pos!=-1)  { strcpy(tab[pos].type,type); }
	}
    
	
	int doubleDeclaration(char entite[])   
	{
	int pos;
	pos=  Recherche_position(entite);
	if(strcmp(tab[pos].type,"")==0) return 0;
	   else return -1;
	  
	
	}
	
	
	
	int cmparr(char entite[])   
	{
	
	
	if(strcmp(entite,"ARRAY")==0) return 0;
	   else return -1;
	  
	
	}
	
	int cmproc(char entite[])   
	{
	
	
	if(strcmp(entite,"PROCESS")==0) return 0;
	   else return -1;
	  
	
	}
	
	
	
	
	int cmploop(char entite[])   
	{
	
	
	if(strcmp(entite,"LOOP")==0) return 0;
	   else return -1;
	  
	
	}
	
	
	
	
	 void insererT(char entite[], char type[])
	{
       int pos;
	   pos=Recherche_position(entite);
	   if(pos!=-1)  { strcpy(tab[pos].type,type);
                      strcpy(tab[pos].code,"IDF_CST");

	   }
	}
	
	
	int aninis(char entite[])   
	{
	int pos;
	pos=  Recherche_position(entite);
	if(strcmp(tab[pos].code,"IDF_CST")==0) return 0;
	   else return -1;
	  
	
	}





typedef struct
{ 
   
   char name[20];
   int taille;
} taillemax;

taillemax titi[50];
int k=0;
void inseree(char nom[],int qtt){
	
	strcpy(titi[k].name,nom);
       titi[k].taille=qtt;
	k=k+1;
	printf("insertion faite \n");
}
int bobo(char nom[],int qtt){
	int n=0;
	while(n<50){
		
		
		
		if(strcmp(titi[n].name,nom)==0) {   

		if(qtt>titi[n].taille){ 
		     return 0;
                       		} 
	 else { return -1; }     }
		n=n+1;
	}
}


int Recherche_compatibilite(char entite[])
		{
		int i=0;
		while(i<1000)
		{
		
		if (strcmp(tab[i].name,entite)==0) {  if(strcmp(tab[i].type,"INTEGER")==0) {  return 0;} 
		if(strcmp(tab[i].type,"REAL")==0) {return 1;}
		if(strcmp(tab[i].type,"STRING")==0) {return 2;}
	if(strcmp(tab[i].type,"CHAR")==0) {return 3;}		
	
		}	
		i++;
		}
 
		return -1;
		
		}


