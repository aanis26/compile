#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tess.h"

void init ()
{
    int i;
    for ( i = 0; i < taille ; i++)
    {
            tess[i]=NULL;
    }
    
}

int fhach (char* e)
{
    int i=0, count=0;
    while (e[i]!='\0')
    {
        count+=e[i]*i*(10*(i+1));
        i++;
    }
    return (count%taille);
    
}

int recherche(char* e1,int* index,elem** adr)
{
    elem* p;
    *index =fhach(e1);
    p=tess[*index];
    *adr=p;
    if(p==NULL) return 0;
    if (!strcmp(p->nom,e1)) return 1;
    p=p->svt;
    while (p!=NULL && strcmp(p->nom,e1)) 
    {
        p=p->svt;
        *adr=p;
    }

    if(p==NULL) return 0;
    return 1;
    
}
/*
void inserer(char* e1,int type)
{
    int index;
    elem* p;
    elem* adr;
    index=fhach(e1);
    p=malloc(sizeof(elem));
    p->nom=e1;
    p->type=type;
    if(tess[index]==NULL){
        p->svt=NULL;
        tess[index]=p;
    }else {p->svt =tess[index];tess[index]=p;}
}*/

void insererTS(char* e1,int type)
{
    int index;
    elem* p;
    elem* adr;
    int b=recherche(e1,&index,&adr);
    if(b==0)
    p=malloc(sizeof(elem));
    p->nom=e1;
    p->type=type;
    if(tess[index]==NULL){
        p->svt=NULL;
        tess[index]=p;
        }else {p->svt =tess[index];
        tess[index]=p;
    }
}

void saveLesIdfs(char* e1){


}
void affii(){
	int j = 0;
	
}
int typeIdf(char* e1)
{
    int index; elem* adr;
    recherche (e1,&index,&adr);
    return(adr->type);
}

void afficherTS()
{
    int i=0; elem* p;
    for ( i = 0; i < taille; i++)
    {
        if(tess[i]!=NULL){
            p=tess[i];
            while (p!=NULL)
            {
                printf("%s ---> %d\n",p->nom ,p->type);
                p=p->svt;
            }
            
        }
    }
    
}

