#ifndef TS_H
#define TS_H

#define taille 100
typedef struct elt {
    char* nom;
    int type;
    struct elt* svt;
}elem;

elem* tess[taille];
void init();

int fhach (char*);
int recherche (char* ,int* ,elem**);
void insererTS(char*,int );
int typeIdf(char*);
void afficherTS();
void affii();
void saveLesIdfs(char* e1);
#endif //TS_H
