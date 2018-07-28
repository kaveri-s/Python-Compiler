lex pythoncompiler.l
yacc -d pythoncompiler.y
gcc -g lex.yy.c y.tab.c stack.h -ll

