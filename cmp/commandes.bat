flex lexical-1.l
bison -d syntaxique.y
gcc lex.yy.c syntaxique.tab.c -lfl -ly -o compilateur.exe
compilateur.exe<test.txt