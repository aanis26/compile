flex lex.l
bison -d syntasem.y
gcc lex.yy.c syntasem.tab.c RS.c tess.c -lfl -ly -o compiler.exe