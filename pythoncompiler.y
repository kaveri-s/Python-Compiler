%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

extern FILE* yyin;
STACK indent;

#define LOCAL 0
#define GLOBAL 1
extern int scope;
//extern YYSTYPE yylval;

//Symbol Table
struct symbol_table
{
    char name[80];
    int token; //defined in tokendefs.h
    int attribute;
    char value;
    int lineno;
    char scope[80];
}st[100];

int table_row = 0;
extern int linenum;

//Quad Table
struct Quad
{
    char op[20];
    char arg1;
    char arg2;
    char result;
};

struct Quad Quadtable[500];

int quad_row=0;
char temp='A';

//Labels
int l_no=0;
%}

%union
{
    char* strval;
    char charval;
    int intval;
};

%start statements
%token ID NUM NOT AND OR ROP LPAREN RPAREN LBRACE RBRACE RBRACK LBRACK SEMI COMMA ASOP MDOP COLON
%token EQUALS CONTINUE BREAK RETURN IF ELIF ELSE WHILE CALL DEF LEADSPACE LEADTAB SOP 
%token TEXT INDENT DEDENT END_STATEMENT

%%

statements
    : statements statement
    | statement
    ;
 
statement
    : selectionstatement END_STATEMENT
    | iterationstatement END_STATEMENT
    | AssignExpr END_STATEMENT
    | jump_stmt END_STATEMENT
    | call_stmt END_STATEMENT
    | func_def END_STATEMENT
    | simplestatement
    ;
 
simplestatement
    : selectionstatement
    | iterationstatement
    | AssignExpr
    | jump_stmt
    | call_stmt
    | func_def
    ;
 
condition: LPAREN cond RPAREN COLON

selectionstatement
    : IF condition COLON codeblock more
    ;

more
    : ELSE COLON codeblock
    | ELIF condition COLON codeblock more
    | 
    ;
 
iterationstatement
    : WHILE condition COLON codeblock
    ;
 
codeblock
    : INDENT statements DEDENT
    ;


cond
    : relexp
    | cond logop relexp
    | NOT relexp
    ;

jump_stmt 
    : CONTINUE  
    | BREAK  
    | RETURN E
    ;

relexp 
    : E ROP E
    ;

AssignExpr 
    : ID EQUALS E
    {
        
    }
    | Unary_operation
    | ID EQUALS call_stmt
    ; 

E
    : E ASOP T  {printf("val %s\n", yylval.strval); $<charval>$ = add_quad(yylval.strval, $<charval>1, $<charval>3); printf("%c\t=\t%c\t%s\t%c\n",$<charval>$,$<charval>1,yylval.strval,$<charval>3);}
    | T         {printf("val %s\n", yylval.strval); $<charval>$ = add_quad("=", $<charval>1, 0); printf("%c\t=\t%c\t%s\t%c\n",$<charval>$,$<charval>1,"",0);}
    ;
T 
    : T MDOP F  {printf("val %s\n", yylval.strval);$<charval>$ = add_quad(yylval.strval, $<charval>1, $<charval>3); printf("%c\t=%c\t%s\t%c\n",$<charval>$,$<charval>1,yylval,$<charval>3);}
    | F         {printf("val %s\n", yylval.strval);$<charval>$ = add_quad("=", $<charval>1, 0); printf("%c\t=\t%c\t%s\t%c\n",$<charval>$,$<charval>1,"",0);}
    ;
F 
    : ID                {printf("val %s\n", yylval.strval);$<charval>$ = add_quad("=", st[$<intval>1].value, 0); printf("%c\t=\t%c\t%s\t%c\n",$<charval>$,st[$<intval>1].value,"",0);}
    | NUM               {$<charval>$ = add_quad("=", $<charval>1, 0); printf("%c\t=\t%c\t%s\t%c\n",$<charval>$,$<charval>1,"",0);}
    | LPAREN E RPAREN   {$<charval>$ = add_quad("=", $<charval>2, 0); printf("%c\t=\t%c\t%s\t%c\n",$<charval>$,$<charval>2,"",0);}
    | Unary_operation 
    ;

Unary_operation 
    : ID SOP ID 
    | ID SOP NUM 
    | ID SOP LPAREN E RPAREN
    ;

       
logop 
    : AND | OR
    ;


func_def
    : DEF call_stmt COLON codeblock
    ;

call_stmt
    : CALL VARLIST RPAREN
    ;

VARLIST 
    : VARLIST COMMA VAR;
    | VAR
    ;

VAR : TEXT | ID | NUM
    ;
%%

int add_quad(char* op, char arg1, char arg2) {
    // Quadtable[quad_row] = (struct Quad)malloc(sizeof(struct Quad));
    memcpy(Quadtable[quad_row].op, op, sizeof(op));
    // memcpy(Quadtable[quad_row].arg1, arg1, sizeof(arg1));
    // memcpy(Quadtable[quad_row].arg2, arg2, sizeof(arg2));
    Quadtable[quad_row].arg1=arg1;
    Quadtable[quad_row].arg2=arg2;
    quad_row++;
    temp++;
    // memcpy(Quadtable[quad_row].result, temp, sizeof(temp));
    Quadtable[quad_row].result=temp;
    return temp; 
}

int print_quad() {
    for(int i=0;i<quad_row;i++){
        printf("%s\t%c\t%c\t%c\n",Quadtable[i].op,Quadtable[i].arg1,Quadtable[i].arg2,Quadtable[i].result);
    }
}

int already(char*n, char*s) //checks if it is already in the table
{
    // printf("In already");
    for(int i = 0; i < table_row; ++i) {
        if (strcmp(st[i].name, n) == 0 && strcmp(st[i].scope, s) == 0) {
            return i; //can also be zero - return the row where it was found
        }
    } 
    return -1;//if nothing was found
}

int insert(char *n, int t, int a, char val, int line, char *scop)
{
    // printf("In insert");
    int already_value = already(n, scop);
    if(already_value == -1) {
        strcpy(st[table_row].name, n);
        st[table_row].token = t;
        st[table_row].attribute = a;
        st[table_row].value = val;
        st[table_row].lineno = line;
        strcpy(st[table_row].scope, scop);
        ++table_row;
        return -1; //here, -1 means that the insertion was done
    }
    else {
        return already_value;
    }
}

int install_id(char *n) //can return row number in symbol table
{
    // printf("value of n = %s\n", n);
    int insert_val;
    // printf("value of tablerow = %d\n",table_row);
    if(scope == GLOBAL)
        insert_val = insert(n, ID, table_row, 0, linenum, "global");
    else
        insert_val = insert(n, ID, table_row, 0, linenum, "local"); //or insert 0?
    // printf("in the install_id()\n");
    if(insert_val == -1) {
        return(table_row-1); //if inserting now, it's where you just inserted it
    }
    else {
        return insert_val; //the value it was originally inserted at
    }
}

void print_table()
{
    printf("Name\tToken\tAttr\tValue\tLine\tScope\n");
    for(int i = 0; i < table_row; ++i) {
        //printf("About to print\n");
        printf("%s\t%d\t%d\t%s\t%d\t%s\n", st[i].name, st[i].token, st[i].attribute, st[i].value, st[i].lineno, st[i].scope);
    }
}

int main()
{
    printf("Hi");
    //fflush(stdout);
    initStack(&indent, 20);
    yyin = fopen("pyeg2.py", "r");
    print_table();
    yyparse();
    print_table();
    print_quad();
    printf("Bye");
    //fflush(stdout);
    printf("Valid program");
    //fflush(stdout);
    return 0;
}

void yyerror()
{
 printf("Error in line %d\n", linenum);
 exit(0);
}
