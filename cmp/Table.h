#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern int nb_ligne;

extern int nbcol;
extern int qc;

extern char sauvAffType[20];
extern char sauvType[20];

typedef struct
{
    char NomEntite[20];
    char CodeEntite[20];
    char TypeEntite[20];
    int TailleEntite;
    int ConstantEntite;
    char val[100];
} TypeTS;

typedef struct
{
    char NomFonction[20];
    char TypeEntite[20];

} TypeTF;

typedef struct qdr
{

    char oper[100];
    char op1[100];
    char op2[100];
    char res[100];

} qdr;
qdr quad[1000];
int markquad[1000];

TypeTS ts[100];

int CpTabSym = 0;
int cptTypeEntit = 0;

int recherche(char entite[])
{
    int i = 0;

    while (i < CpTabSym)
    {
        if (strcmp(entite, ts[i].NomEntite) == 0)
            return i;
        i++;
    }
    return -1;
}

void inserer(char entite[], char code[])
{
    if (recherche(entite) == -1)
    {
        strcpy(ts[CpTabSym].NomEntite, entite);
        strcpy(ts[CpTabSym].CodeEntite, code);
        CpTabSym++;
        cptTypeEntit++;
    }
    else
    {

        printf("Double Declaration %s a la ligne %d posTab = %d \n", entite, nb_ligne, recherche(entite));
    }
}
float checkDeclaration(char entite[])
{
    int x = recherche(entite);
    if (x == -1)
    {
        printf("Erreur semantique : %s variable non declare a la ligne %d\n", entite, nb_ligne);
        return 33333; // the magical error number
    }
    else
    {
        return x;
    }
}
char *checkOverFlowTab(char entite[], int pos)
{
    char *snum;
    int x = recherche(entite);
    if (ts[x].TailleEntite - 1 < pos)
    {
        printf("Erreur semantique : la position depasse la taille du tableau %s a la ligne %d\n", entite, nb_ligne);
        char *smthn = strcat(entite, "[");
        snprintf(snum, 2, "%d", pos);
        smthn = strcat(smthn, snum);
        smthn = strcat(smthn, "]");
        return strdup(smthn);
    }
    else
    {
        return strdup(entite);
    }
    char *smthn = strcat(entite, "[");
    snprintf(snum, 2, "%d", pos);
    smthn = strcat(smthn, "]");
    return strdup(smthn);
}
int checkCST(char entite[])
{
    int pos = recherche(entite);
    if(strcmp(ts[pos].CodeEntite, "CST") == 0 ){
        if (pos >= 0 &&  strcmp(ts[pos].val, "") != 0)
        {
            printf("Erreur semantique: impossible daffecter la constante %s une valeur",entite);
            return 0;
        }
    }else return 0;
}
void afficher()
{
    printf("\n/***************Table des symboles ******************/\n");
    printf("___________________________________________________________________________________________________\n");
    printf("\t| NomEntite | CodeEntite  |  TypeEntite  | Taille Entite|    Constant  | Value   \n");
    printf("___________________________________________________________________________________________________\n");
    int i = 0;
    while (i < CpTabSym)
    {
        printf("\t|%10s |%12s | %12s | %12d | %12d | %12s |\n", ts[i].NomEntite,
               ts[i].CodeEntite, ts[i].TypeEntite, ts[i].TailleEntite, ts[i].ConstantEntite, ts[i].val);

        i++;
    }
}

void insererType(char type[])
{
    int i;
    for (i = cptTypeEntit; i >= 0; i--)
    {
        strcpy(ts[CpTabSym - i].TypeEntite, type);
    }
    cptTypeEntit = 0;
}

void insertTable(char entite[], char code[], int taille)
{
    int x = recherche(entite);
    if (x != -1)
    {
        strcpy(ts[x].CodeEntite, "Table");
        ts[x].TailleEntite = taille;
    }
}
void insererVal(char entite[], char val[])
{
    int pos = recherche(entite);
    strcpy(ts[pos].val, val);
}

void quadr(char opr[], char op1[], char op2[], char res[])
{

    strcpy(quad[qc].oper, opr);
    strcpy(quad[qc].op1, op1);
    strcpy(quad[qc].op2, op2);
    strcpy(quad[qc].res, res);

    qc++;
}

void ajour_quad(int num_quad, int colon_quad, char val[])
{
    if (colon_quad == 0)
        strcpy(quad[num_quad].oper, val);
    else if (colon_quad == 1)
        strcpy(quad[num_quad].op1, val);
    else if (colon_quad == 2)
        strcpy(quad[num_quad].op2, val);
    else if (colon_quad == 3)
        strcpy(quad[num_quad].res, val);
}

void afficher_qdr()
{
    printf("*********************Les Quadruplets***********************\n");

    int i;

    for (i = 0; i < qc; i++)
    {

        printf("\n %d - ( %s  ,  %s  ,  %s  ,  %s ) status: %d", i, quad[i].oper, quad[i].op1, quad[i].op2, quad[i].res,markquad[i]);
        printf("\n--------------------------------------------------------\n");
    }
}

void getTYPE(char entite[])
{
    int pos;

    pos = recherche(entite);
    strcpy(sauvAffType, ts[pos].TypeEntite);
}

/*** fct pour la sauvgarde d'un type entite dans une variable sauvType ***/
void getTYPE2(char entite[])
{
    int pos;
    pos = recherche(entite);
    strcpy(sauvType, ts[pos].TypeEntite);
}

int tabTaille(char entite[])
{
    int pos;
    pos = recherche(entite);
    return ts[pos].TailleEntite;
}
int typeParse(char entite[])
{

    if (entite[0] <= '0' || entite[0] <= '9')
    {
        return 1111;
    }

    if (!strcmp(entite, "TRUE") || !strcmp(entite, "FALSE"))
    {
        return 1112;
    }
    if (entite[0] == '\'')
    {
        return 1113;
    }
    if (entite[0] == '\"')
    {
        return 1114;
    }
    int pos = recherche(entite);
    if (pos == -1)
    {
        return 33333;
    }
    else
    {
        if (!strcmp(ts[pos].TypeEntite, "tmpNUM") || !strcmp(ts[pos].TypeEntite, "ENTIER") || !strcmp(ts[pos].TypeEntite, "REEL"))
        {
            return 1111;
        }
        else if (!strcmp(ts[pos].TypeEntite, "tmpBOOL") || !strcmp(ts[pos].TypeEntite, "BOOL"))
            return 1112;
        else if (!strcmp(ts[pos].TypeEntite, "CHAR"))
            return 1113;
        else if (!strcmp(ts[pos].TypeEntite, "STRING"))
            return 1114;
    }
}

// for expressions
char *TypeCheck(char *op, char *prt1, char *prt2)
{
    int var1, var2;

    var1 = typeParse(prt1);
    var2 = typeParse(prt2);
    // variable does not exist shouldnt cause the other error msgs
    if (var1 == 33333 || var2 == 33333)
    {
        return strdup("T");
    }
    else
    {
        if (!strcmp(op, "AFF"))
        {
            if (var1 != var2)
            {
                printf("type d'affectation impossible a la ligne %d et colon %d\n", nb_ligne, nbcol);
            }
        }
        // printf("OP:%d,var1:%d var2:%d \n",op,var1,var2);
        if (!strcmp(op, "EGG"))
        {
            if (var1 != var2)
            {
                printf("type incompatible des variables a la ligne  %d et colon %d\n", nb_ligne, nbcol);
                return;
            }
        }

        if (!strcmp(op, "ADD") || !strcmp(op, "DEC") || !strcmp(op, "MUL") || !strcmp(op, "DIV"))
        {
            if (var1 == 1111 && var2 == 1111)
            {
            }
            else
            {
                printf("type incompatible des variables a la ligne  %d et colon %d\n", nb_ligne, nbcol);
                return;
            }
        }
        if (!strcmp(op, "SUP") || !strcmp(op, "SUPE") || !strcmp(op, "INF") || !strcmp(op, "INFE"))
        {
            if (var1 == 1111 && var2 == 1111)
            {
            }
            else
            {
                printf("type incompatible des variables a la ligne  %d et colon %d\n", nb_ligne, nbcol);
                return;
            }
        }
        if (!strcmp(op, "AND") || !strcmp(op, "OR"))
        {
            if (var1 == 1112 && var2 == 1112)
            {
                return;
            }
            else
            {
                printf("type incompatible des variables a la ligne  %d et colon %d\n", nb_ligne, nbcol);
                return;
            }
        }
        return strdup("T");
    }
}

int tmpNum = 0;
int tmpBool = 0;
char *generateNameNUM()
{
    char buffer[40], *tmp1 = strdup("tmpNUM");

    itoa(tmpNum, buffer, 10);
    strcat(tmp1, strdup(buffer));
    tmpNum++;
    inserer(tmp1, "tmpNum");
    insererType("tmpNum");
    return tmp1;
}
char *generateNameBOOL()
{
    char buffer[40], *tmp1 = strdup("tmpBOOL");
    itoa(tmpBool, buffer, 10);
    strcat(tmp1, strdup(buffer));
    tmpBool++;
    inserer(tmp1, "tmpBOOL");
    insererType("tmpBOOL");

    return tmp1;
}

int searchInString(char s, char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == s)
        {
            return 1;
        }
    }
    return 0;
}

void ecrireCheck(char str[], char entite[])
{
    int i = 0, first = 0;
    char *type = strdup(ts[recherche(entite)].TypeEntite);

    // int $ float %  str # chr & BOL @
    if (!strcmp(type, "ENTIER"))
    {
        if (!searchInString('$', str))
        {
            printf("erreur symantique: la variable donne et le signe n'ont pas le meme type\n");
            return;
        }
    }
    if (!strcmp(type, "REEL"))
    {
        if (!searchInString('%', str))
        {
            printf("erreur symantique: la variable donne et le signe n'ont pas le meme type\n");
            return;
        }
    }
    if (!strcmp(type, "CHAR"))
    {
        if (!searchInString('&', str))
        {
            printf("erreur symantique: la variable donne et le signe n'ont pas le meme type\n");
            return;
        }
    }
    if (!strcmp(type, "STRING"))
    {
        if (!searchInString('#', str))
        {
            printf("erreur symantique: la variable donne et le signe n'ont pas le meme type\n");
            return;
        }
    }
    if (!strcmp(type, "BOOL"))
    {
        if (!searchInString('@', str))
        {
            printf("erreur symantique: la variable donne et le signe n'ont pas le meme type\n");
            return;
        }
    }
}
int checkVal(char entite[])
{
    if (!strcmp(entite, "TRUE"))
    {
        return 1;
    }
    if (!strcmp(entite, "FALSE"))
    {
        return 1;
    }
    if (entite[0] == 't')
    {
        // if it tmp got a value
        if (strcmp(ts[recherche(entite)].val, ""))
        {
            return 1;
        }
    }
    if ('0' <= entite[0] && '9' >= entite[0])
    {
        return 1;
    }
    if(recherche(entite)!=-1 && !strcmp(ts[recherche(entite)].CodeEntite,"CST")){
        return 1;
    }
    return 0;
}
int getValue(char entite[])
{
    if (!strcmp(entite, "TRUE"))
    {
        return 1;
    }
    if (!strcmp(entite, "FALSE"))
    {
        return 0;
    }
    if (entite[0] == 't')
    {   
        if (!strcmp(ts[recherche(entite)].val, "TRUE"))
        {
        printf("checking tmp");
            return 1;
        }
        if (!strcmp(ts[recherche(entite)].val, "FALSE"))
        {
            return 0;
        }
        return atoi(ts[recherche(entite)].val);
    }
    if ('0' <= entite[0] && '9' >= entite[0])
    {
        return atoi(entite);
    }
    if(recherche(entite)!=-1 && !strcmp(ts[recherche(entite)].CodeEntite,"CST")){
        return atoi(ts[recherche(entite)].val);
    }
}
void suppQuad(int begin){
    int i=begin;
    char buffer[20];
    while(i<qc){
        quad[i]=quad[i+1];
        
        i++;
    }
    qc--;
    for ( i = 0; i < qc; i++)
    {
        // if its a jump and after our delete reduce the jump pos 
        if((!strcmp(quad[i].oper,"BNZ") || !strcmp(quad[i].oper,"BZ") ||!strcmp(quad[i].oper,"BR"))&&begin<atoi(quad[i].op1)){
            ajour_quad(i,1,itoa(atoi(quad[i].op1)-1,buffer,10));
        }
    }
    
}

void removeDeadCode(int start){
    char buffer[20];
    for (; start < qc && markquad[start]!=1; start++)
    {
        markquad[start]=1;
        //sstart -1 so we dont skip the quad we jumped to 
        if(!strcmp(quad[start].oper,"BR")){
            start= atoi(quad[start].op1)-1;
        }
        if(!strcmp(quad[start].oper,"BNZ")){
            if (checkVal(quad[start].op2))
            {
                if(getValue(quad[start].op2)==1){
                    markquad[start]=0;
                    start= atoi(quad[start].op1)-1;
                }
            }else{
                removeDeadCode(atoi(quad[start].op1));
            }
        }
        if(!strcmp(quad[start].oper,"BZ")){
            if (checkVal(quad[start].op2))
            {
                if(getValue(quad[start].op2)==0){
                    markquad[start]=0;
                    start= atoi(quad[start].op1)-1;
                }
            }else{
                removeDeadCode(atoi(quad[start].op1));
            }
        }
    }
    
}
// void elimExp(){
//     // take an equation i (quad?)
//     int i,j;
//     for ( i = 0; i < qc; i++)
//     {
//     // if equation found again without a change in the variables replace it with that quad resu
//         for ( j = 0; j < qc; j++)
//         {
//             if((quad[j].op1==quad[i].op1 && quad[j].op2==quad[i].op2)||(quad[j].op1==quad[i].op2 && quad[j].op2==quad[i].op1)){

//             }
//         }
        
//     }
//     // change in variables means AFF or INC NOTE:gotta check for LOOPS
//     return;
// }
void optimisation()
{
    int i;
    int val1, val2, resu;
    char buffer[20];

    // propagation de constante
    for (i = 0; i < qc; i++)
    {
        if (!strcmp(quad[i].oper, "AFF"))
        {
            if (checkVal(quad[i].op1) && checkCST(quad[i].res))
            {   
                printf("removed an aff  ");
                val1 = getValue(quad[i].op1);
                resu = val1;
                insererVal(quad[i].res, (char *)itoa(resu, buffer, 10));
            }
        }
        if (!strcmp(quad[i].oper, "ADD"))
        {
            // if they csts 1,1 or TRUE false or tmps with a value
            if (checkVal(quad[i].op1) && checkVal(quad[i].op2))
            {
                val1 = getValue(quad[i].op1);
                val2 = getValue(quad[i].op2);
                resu = val1 + val2;
                insererVal(quad[i].res, (char *)itoa(resu, buffer, 10));
            }
        }
        if (!strcmp(quad[i].oper, "DEC"))
        {
            if (checkVal(quad[i].op1) && checkVal(quad[i].op2))
            {
                val1 = getValue(quad[i].op1);
                val2 = getValue(quad[i].op2);
                resu = val1 - val2;
                insererVal(quad[i].res, (char *)itoa(resu, buffer, 10));
            }
        }
        if (!strcmp(quad[i].oper, "MUL"))
        {
            if (checkVal(quad[i].op1) && checkVal(quad[i].op2))
            {
                val1 = getValue(quad[i].op1);
                val2 = getValue(quad[i].op2);
                resu = val1 * val2;
                insererVal(quad[i].res, (char *)itoa(resu, buffer, 10));
            }
        }
        if (!strcmp(quad[i].oper, "DIV"))
        {
            if (checkVal(quad[i].op1) && checkVal(quad[i].op2))
            {
                val1 = getValue(quad[i].op1);
                val2 = getValue(quad[i].op2);
                resu = val1 / val2;
                insererVal(quad[i].res, (char *)itoa(resu, buffer, 10));
            }
        }
        ////
        ////////////////////
        ////////////////////
        if (!strcmp(quad[i].oper, "SUP"))
        {
            if (checkVal(quad[i].op1) && checkVal(quad[i].op2))
            {
                val1 = getValue(quad[i].op1);
                val2 = getValue(quad[i].op2);
                if (val1 > val2)
                {
                    insererVal(quad[i].res, "TRUE");
                }
                else
                {
                    insererVal(quad[i].res, "FALSE");
                }
            }
        }
        if (!strcmp(quad[i].oper, "SUPE"))
        {
            if (checkVal(quad[i].op1) && checkVal(quad[i].op2))
            {
                val1 = getValue(quad[i].op1);
                val2 = getValue(quad[i].op2);
                if (val1 >= val2)
                {
                    insererVal(quad[i].res, "TRUE");
                }
                else
                {
                    insererVal(quad[i].res, "FALSE");
                }
            }
        }
        if (!strcmp(quad[i].oper, "EGG"))
        {
            if (checkVal(quad[i].op1) && checkVal(quad[i].op2))
            {
                val1 = getValue(quad[i].op1);
                val2 = getValue(quad[i].op2);
                if (val1 == val2)
                {
                    insererVal(quad[i].res, "TRUE");
                }
                else
                {
                    insererVal(quad[i].res, "FALSE");
                }
            }
        }
        if (!strcmp(quad[i].oper, "DIF"))
        {
            if (checkVal(quad[i].op1) && checkVal(quad[i].op2))
            {
                val1 = getValue(quad[i].op1);
                val2 = getValue(quad[i].op2);
                if (val1 != val2)
                {
                    insererVal(quad[i].res, "TRUE");
                }
                else
                {
                    insererVal(quad[i].res, "FALSE");
                }
            }
        }
        if (!strcmp(quad[i].oper, "INF"))
        {
            if (checkVal(quad[i].op1) && checkVal(quad[i].op2))
            {
                val1 = getValue(quad[i].op1);
                val2 = getValue(quad[i].op2);
                if (val1 < val2)
                {
                    insererVal(quad[i].res, "TRUE");
                }
                else
                {
                    insererVal(quad[i].res, "FALSE");
                }
            }
        }
        if (!strcmp(quad[i].oper, "INFE"))
        {
            if (checkVal(quad[i].op1) && checkVal(quad[i].op2))
            {
                val1 = getValue(quad[i].op1);
                val2 = getValue(quad[i].op2);
                if (val1 <= val2)
                {
                    insererVal(quad[i].res, "TRUE");
                }
                else
                {
                    insererVal(quad[i].res, "FALSE");
                }
            }
        }
        if (!strcmp(quad[i].oper, "AND"))
        {
            if (checkVal(quad[i].op1) && checkVal(quad[i].op2))
            {
                val1 = getValue(quad[i].op1);
                val2 = getValue(quad[i].op2);
                if (val1 == 1 && val2 == 1)
                {
                    insererVal(quad[i].res, "TRUE");
                }
                else
                {
                    insererVal(quad[i].res, "FALSE");
                }
            }
        }
        if (!strcmp(quad[i].oper, "OR"))
        {
            if (checkVal(quad[i].op1) && checkVal(quad[i].op2))
            {
                val1 = getValue(quad[i].op1);
                val2 = getValue(quad[i].op2);
                if (val1 || val2)
                {
                    insererVal(quad[i].res, "TRUE");
                }
                else
                {
                    insererVal(quad[i].res, "FALSE");
                }
            }
        }
    //////////////////////////////
    //////////////////////////////

    }
    for(i=0;i<qc;i++){
        if(strcmp(ts[recherche(quad[i].res)].val,"")!=0){
            suppQuad(i);
            i--;
        }
    }
    // remove dead code
    removeDeadCode(0);
    for(i=0;i<qc;i++){
        if(markquad[i]==0){
            suppQuad(i);
            i--;
        }
    }
    // elimination d'expression redondante
    // elimExp();
}
