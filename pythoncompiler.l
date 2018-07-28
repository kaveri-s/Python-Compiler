%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.c"
#include "y.tab.h"

#define LOCAL 0
#define GLOBAL 1
int scope = GLOBAL;

int linenum =0;
extern YYSTYPE yylval; //temporary. should it be extern?
extern int install_id(char *n);
%}


letter [A-Za-z]
digit  [0-9]
id {letter}({letter}|{digit})*
number {digit}+

%%

\n[ \t]*	{ 
            linenum++; printf("%d\n", linenum);
		    if (yyleng == 1)
		    {
			    if (indent.size > 0)
			    {
			        pop(&indent);
			        if (peek(&indent) > yyleng && indent.size != 0)
				        yyless(0);
					scope = GLOBAL; //scope
			        return(DEDENT);
			        
                  //   printf("dedent");
			    }
			    return(END_STATEMENT);
			//     printf("END_STATEMENT");
		    }
		    else
		    {
			    if (peek(&indent) < yyleng || indent.size == 0)
			    {
			        push(&indent, yyleng);
			        scope = LOCAL; 
			        return (INDENT);
			      //   printf("INDENT");
			    }
			    else if (peek(&indent) > yyleng && indent.size != 0)
			    {
			        pop(&indent);
			        if (peek(&indent) > yyleng && indent.size != 0)
				        yyless(0);
				        scope = GLOBAL; 
			        return (DEDENT);
			      //   printf("DEDENT");
			    }
			    else
			    {
			        return(END_STATEMENT);
			      //   printf("END_STATEMENT");
			    }
		    }
		    }

<<EOF>>		{   
                if (indent.size > 0)
                {
                    pop(&indent);
                    // return(DEDENT);
                    printf("DEDENT");
                }
                yyterminate();
            }

#[A-Za-z0-9 \t\(\"\);]* {;/*comment*/}
\"\"\"[A-Za-z0-9 \t\n\/]*\"\"\" {;/*multiline double quote comment*/}
\'\'\'[A-Za-z0-9 \t\n\/]*\'\'\' {;/*multiline single quote comment*/}
\"[A-Za-z0-9 \.\'\t\n\/\\]*\"     {
	char* line = strdup(yytext); 
	int j = 0;
	for (int i = 0; i < strlen(line); i++)
	{
    	if (line[i] == '\\')
    	{
        	line[j++] = line[i++];
        	line[j++] = line[i];
        	if (line[i] == '\0')
            	break;
    	}
    	else if (line[i] != '"')
        	line[j++] = line[i];
	}
	line[j] = '\0';
	yylval.strval = strdup(line);
	return(TEXT);
}

"+=" {yylval.strval = yytext; return(SOP);}
"-=" {yylval.strval = yytext; return(SOP);}
"*=" {yylval.strval = yytext; return(SOP);}
"/=" {yylval.strval = yytext; return(SOP);}

"<=" 	{yylval.strval = yytext; return(ROP);} 
"<" 	{yylval.strval = yytext; return(ROP);}
">=" 	{yylval.strval = yytext; return(ROP);}
">" 	{yylval.strval = yytext; return(ROP);}
"!=" 	{yylval.strval = yytext; return(ROP);}
"==" 	{yylval.strval = yytext; return(ROP);}

"("         {return(LPAREN);}
")"         {return(RPAREN);}
"["         {return(LBRACK);}
"]"         {return(RBRACK);}
"{"         {return(LBRACE);}
"}"         {return(RBRACE);}

and {yylval.strval = yytext; return(AND);}
or  {yylval.strval = yytext; return(OR);}
not {yylval.strval = yytext; return(NOT);}

if 		{return(IF);}
else 	{return(ELSE);}
elif 	{return(ELIF);}
while 	{return(WHILE);}
return 	{return(RETURN);}

continue {return(CONTINUE);}
break    {return(BREAK);}

{id}\((.*)\) 	{return(CALL);}
def 			{return(DEF);}

";" {return(SEMI);}
":" {return(COLON);}
"," {return(COMMA);}

\+ {yylval.strval = yytext; return(ASOP);}
-  {yylval.strval = yytext; return(ASOP);}
\/  {yylval.strval = yytext; return(MDOP);}
\* {yylval.strval = yytext; return(MDOP);}
= {yylval.strval = yytext; return(EQUALS);}

{id}\( 		{yylval.intval = install_id(yytext); return(CALL);}
{id}       {yylval.intval = install_id(yytext); return(ID);}
{number}   {yylval.charval = yytext; return(NUM);}

.   {;}


%%
/*
int main()
{
  initStack(&indent, 20);
 yyin=fopen("pyeg2.py","r   ");
 yylex();
 return 0;
}
*/
