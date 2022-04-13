# compile
réaliser un mini compilateur en effectuant les différentes phases de  la compilation 

INTRODUCTION :
Le but de ce projet est de réaliser un mini-compilateur en effectuant les différentes phases de la compilation à savoir l'analyse lexicale en utilisant 
l'outil FLEX et l'analyse syntaxicosémantique en utilisant l'outil BISON, du langage « Lang». Les traitements parallèles concernant la gestion de la table 
des symboles ainsi que le traitement des différentes erreurs doivent être également réalisés lors des différentes phases d'analyse du processus de 
compilation. 

1. Analyse Lexicale avec l’outil FLEX : 
Son but est d’associer à chaque mot du programme source la catégorie lexicale à laquelle il 
appartient. Pour cela, il est demandé de définir les différentes entités lexicales à l’aide d’expressions 
régulières et de générer le programme FLEX correspondant. 


2. Analyse syntaxico-sémantique avec l’outil BISON : 
 Pour implémenter l’analyseur syntaxico-sémantique, il va falloir écrire la grammaire qui génère 
le langage défini au-dessus. La grammaire associée doit être LALR. En effet l’outil BISON est un 
analyseur ascendant qui opère sur des grammaires LALR. Il faudra spécifier dans le fichier BISON, 
les différentes règles de la grammaire ainsi que les règles de priorités pour les opérateurs afin de 
résoudre les conflits. Les routines sémantiques doivent être associées aux règles dans le fichier 
BISON. 


3. Gestion de la table de symboles : 
La table de symboles doit être créée lors de la phase de l’analyse lexicale. Elle doit regrouper 
l’ensemble des variables et constantes définies par le programmeur avec toutes les informations 
nécessaires pour le processus de compilation. Cette table sera mises à jour au fur et à mesure de 
l’avancement de la compilation. Il est demandé de prévoir des procédures pour permettre de 
recherche et d’insérer des éléments dans la table des symboles. Les variables structurées de type 
tableau doivent aussi figurer dans la table de symboles.


4. Génération du code intermédiaire :
Le code intermédiaire doit être généré sous forme des quadruplets. 


5. Traitement des erreurs : 
Il est demandé d’afficher les messages d’erreurs adéquats à chaque étape du processus de 
compilation. Ainsi, lorsqu’une erreur lexicale ou syntaxique est détectée par votre compilateur, elle 
doit être signalée le plus précisément possible, par sa nature et sa localisation dans le fichier source. 
On adoptera le format suivant pour cette signalisation : 
 File "Test", line 4, character 56:syntax error 
 
 
6. Optimisation 
On considère quatre types de transformations successives appliquées au code intermédiaire: 
• Propagation de copie (e.g. remplacer t1=t2 ; t3=4*t1 par t1=t2 ; t3=4*t2). 
• Propagation d’expression (e.g. remplacer t1=expr; t3=4*t1 par t1=expr; t3=4*expr). 
• Élimination d’expressions redondantes (communes) (e.g. remplacer t6=4*j ; t12=4*j par 
t6=4*j ; t12=t6 ). 
• Simplification algébrique (e.g. remplacer t1+1-1 par t1). 
• Élimination de code inutile (code mort).


7. Génération du code machine 
Enfin le code objet doit être généré selon la syntaxe de l’assembleur 8086
