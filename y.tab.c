/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "try.y"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

extern FILE* yyin;
STACK indent;

STACK scope;
int scope_cnt=0;

/*Symbol Table*/
struct symbol_table
{
    char name[10];
    int token; /*defined in tokendefs.h*/
    int attribute;
    char value[10];
    int lineno;
    int scope;
    int assigned;
}st[100];

int table_row = 0;
extern int linenum;

/*Quad Table*/
int quad_row=0;
struct Quad
{
    char op[10];
    char arg1[10];
    char arg2[10];
    char result[10];
    int leader;
};


struct Quad Quadtable[30];

/*Temporaries*/
int temp_cnt=0;

/*Labels*/
int label_cnt=0;

#line 50 "try.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union
{
    char *true;
    char *false;
    char *strval;
    int intval;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 83 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define ID 257
#define NUM 258
#define INDENT 259
#define DEDENT 260
#define END_STATEMENT 261
#define IF 262
#define ELIF 263
#define ELSE 264
#define WHILE 265
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    2,    2,    2,    2,    6,    6,    6,    3,
    8,   11,   12,   10,   10,   10,    4,   13,   14,    7,
   15,    9,   17,   18,   16,   16,   16,   16,   16,   16,
    5,    1,    1,    1,    1,    1,    1,    1,
};
static const YYINT yylen[] = {                            2,
    2,    1,    2,    2,    2,    1,    1,    1,    1,    5,
    0,    0,    0,    4,    6,    1,    5,    0,    0,    4,
    1,    5,    0,    0,    4,    3,    4,    3,    4,    4,
    3,    3,    3,    3,    3,    3,    1,    1,
};
static const YYINT yydefred[] = {                         0,
    0,    0,   18,    0,    2,    0,    0,    0,    6,    0,
    0,   11,    0,    1,    3,    4,    5,   37,   38,    0,
    0,    0,    0,   21,    0,   19,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   23,    0,    0,   36,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   20,    0,   10,    0,   16,   17,    0,    0,    0,    0,
    0,    0,    0,    0,   11,    0,   22,    0,   14,    0,
   15,
};
static const YYINT yydgoto[] = {                          4,
   21,    5,    6,    7,    8,    9,   12,   25,   38,   53,
   54,   55,   13,   39,   23,   24,   52,   64,
};
static const YYINT yysindex[] = {                      -249,
  -52,  -23,    0, -249,    0, -243, -242, -239,    0,  -36,
  -36,    0,  -23,    0,    0,    0,    0,    0,    0,  -36,
   41,   70,  -17,    0, -231,    0,  -16,  -36,  -36,  -36,
  -36,  -40,  -29,  -38,  -25,  -20,    0,    0, -231,    0,
  -32,  -32,  -32,  -32,  -36,   41,  -36,  -36,   41,  -36,
    0, -249,    0, -252,    0,    0,   41,   41,   41,   41,
 -249,  -23,  -19, -219,    0, -231,    0, -231,    0,    0,
    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,   43,   49,   53,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   30,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   20,    0,    0,
    1,    7,   14,   37,    0,    4,    0,    0,   10,    0,
    0,    0,    0,    0,    0,    0,   15,   17,   23,   24,
 -194,    0,    0,    0,    0,    0,    0,    0,    0,   20,
    0,
};
static const YYINT yygindex[] = {                        19,
   61,   -1,    0,    0,    0,    0,   -8,    8,  -33,    9,
    0,    0,    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 318
static const YYINT yytable[] = {                         20,
   33,   20,   14,   20,   26,   56,   32,    1,   10,   30,
   62,   63,    2,   34,   31,    3,   11,   15,   16,   13,
   45,   17,   48,   36,   40,   30,   29,   37,   28,   31,
   31,   47,   69,   33,   70,   50,   35,   51,   66,   32,
   67,   33,    7,   33,   26,   33,   34,   32,    8,   32,
   28,   32,    9,   65,   34,   25,   34,   29,   34,   14,
   33,   33,   33,   27,   30,   24,   32,   32,   32,   35,
   61,   22,   68,   34,   34,   34,    0,   35,   71,   35,
   27,   35,   30,   29,    0,   28,    0,   31,   41,   42,
   43,   44,   46,    0,   49,    0,   35,   35,   35,    0,
    0,    0,   35,    0,    0,   57,    0,   58,   59,    0,
   60,   30,   29,    0,   28,    0,   31,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   32,
   33,   34,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   18,   19,   18,   19,
   18,   19,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   33,    0,    0,
   33,   33,   33,   32,    0,   33,   32,   32,   32,    0,
   34,   32,    0,   34,   34,   34,   13,    0,   34,   13,
   13,   13,   12,   12,   13,    0,   31,    0,    0,   31,
   31,   31,    0,   35,   31,    0,   35,   35,   35,    7,
    0,   35,    7,    0,    7,    8,    0,    7,    8,    9,
    8,    0,    9,    8,    9,    0,    0,    9,
};
static const YYINT yycheck[] = {                         40,
    0,   40,    4,   40,   13,   39,    0,  257,   61,   42,
  263,  264,  262,    0,   47,  265,   40,  261,  261,    0,
   61,  261,   61,   41,   41,   42,   43,  259,   45,    0,
   47,   61,   66,   33,   68,   61,    0,   58,   58,   33,
  260,   41,    0,   43,   41,   45,   33,   41,    0,   43,
   41,   45,    0,   62,   41,   41,   43,   41,   45,   61,
   60,   61,   62,   41,   41,  260,   60,   61,   62,   33,
   52,   11,   65,   60,   61,   62,   -1,   41,   70,   43,
   20,   45,   42,   43,   -1,   45,   -1,   47,   28,   29,
   30,   31,   32,   -1,   34,   -1,   60,   61,   62,   -1,
   -1,   -1,   33,   -1,   -1,   45,   -1,   47,   48,   -1,
   50,   42,   43,   -1,   45,   -1,   47,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   60,
   61,   62,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  257,  258,  257,  258,
  257,  258,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,   -1,   -1,
  260,  261,  262,  257,   -1,  265,  260,  261,  262,   -1,
  257,  265,   -1,  260,  261,  262,  257,   -1,  265,  260,
  261,  262,  263,  264,  265,   -1,  257,   -1,   -1,  260,
  261,  262,   -1,  257,  265,   -1,  260,  261,  262,  257,
   -1,  265,  260,   -1,  262,  257,   -1,  265,  260,  257,
  262,   -1,  260,  265,  262,   -1,   -1,  265,
};
#define YYFINAL 4
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 265
#define YYUNDFTOKEN 286
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,0,0,0,0,0,"'('","')'","'*'","'+'",0,"'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,
"':'",0,"'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,"ID","NUM","INDENT","DEDENT","END_STATEMENT","IF","ELIF","ELSE",
"WHILE",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : statements",
"statements : statements statement",
"statements : statement",
"statement : selectionstatement END_STATEMENT",
"statement : iterationstatement END_STATEMENT",
"statement : AssignExpr END_STATEMENT",
"statement : simplestatement",
"simplestatement : selectionstatement",
"simplestatement : iterationstatement",
"simplestatement : AssignExpr",
"selectionstatement : IF condition X codeblock more",
"X :",
"Y :",
"Z :",
"more : Y ELSE ':' codeblock",
"more : Y ELIF condition X codeblock more",
"more : Z",
"iterationstatement : WHILE M condition N codeblock",
"M :",
"N :",
"condition : '(' cond ')' ':'",
"cond : relexp",
"codeblock : INDENT PUSH statements POP DEDENT",
"PUSH :",
"POP :",
"relexp : E '<' '=' E",
"relexp : E '<' E",
"relexp : E '>' '=' E",
"relexp : E '>' E",
"relexp : E '=' '=' E",
"relexp : E '!' '=' E",
"AssignExpr : ID '=' E",
"E : E '+' E",
"E : E '-' E",
"E : E '*' E",
"E : E '/' E",
"E : '(' E ')'",
"E : ID",
"E : NUM",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 160 "try.y"

char* new_label() {

    label_cnt++;
    char *m = malloc(3);
    m[0]='L';
    sprintf(m+1, "%d", label_cnt);
    return m;
}

char* add_quad(char* op, char *arg1, char *arg2, char *result) {
    
    strncpy(Quadtable[quad_row].op, op, sizeof(op));
    strncpy(Quadtable[quad_row].arg1, arg1, sizeof(arg1));
    strncpy(Quadtable[quad_row].arg2, arg2, sizeof(arg2));
    char *temp = malloc(3);
    if(result[0]=='\0' ) {
        temp_cnt++;
        temp[0]='T';
        sprintf(temp+1, "%d", temp_cnt);
        strncpy(Quadtable[quad_row].result, temp, sizeof(temp));
    }
    else {
        strncpy(Quadtable[quad_row].result, result, sizeof(result));
    }
    quad_row++;
    return temp; 
}

int print_quad() {
    printf("\n\nOp\tArg1\tArg2\tResult\n");
    for(int i=0;i<quad_row;i++){
        printf("%s\t%s\t%s\t%s\t%d\n",Quadtable[i].op,Quadtable[i].arg1,Quadtable[i].arg2,Quadtable[i].result, Quadtable[i].leader);
    }
}

int already(char*n, int s)
{
    for(int i = table_row -1; i >= 0; --i) {
        if (strcmp(st[i].name, n) == 0 && st[i].scope == peek(&scope)) {
            return i;
        }
        else if (strcmp(st[i].name, n) == 0 && st[i].scope <= peek(&scope) && st[i].assigned==1) {
            return i;
        }
    } 
    return -1;
}

int insert(char *n, int t, int a, char *val, int line, int scop)
{
    int already_value = already(n, scop);
    if(already_value == -1) {
        strncpy(st[table_row].name, n, sizeof(n));
        st[table_row].token = t;
        st[table_row].attribute = a;
        strncpy(st[table_row].value, val, sizeof(val));
        st[table_row].lineno = line;
        st[table_row].scope = scop;
        st[table_row].assigned = 0;
        // int i=table_row;
        // printf("%s\t%d\t%d\t%s\t%d\t%d\t%d\n", st[i].name, st[i].token, st[i].attribute, st[i].value, st[i].lineno, st[i].scope, st[i].assigned);
        ++table_row;
        return -1;
    }
    else {
        return already_value;
    }
}

int install_id(char *n) //can return row number in symbol table
{
    int insert_val;
    insert_val = insert(n, table_row, ID, "0", linenum+1, peek(&scope));
    if(insert_val == -1) {
        return(table_row-1);
    }
    else {
        return insert_val;
    }
}

void print_table()
{
    printf("\n\nName\tToken\tAttr\tValue\tLine\tScope\n");
    for(int i = 0; i < table_row; ++i) {
        printf("%s\t%d\t%d\t%s\t%d\t%d\n", st[i].name, st[i].token, st[i].attribute, st[i].value, st[i].lineno, st[i].scope);
    }
}

int rid_labels() {
    int flag_found = 0; // no label found

    for(int i=2; i< quad_row; i++) {
        
        if(strcmp(Quadtable[i].op,Quadtable[i-1].op)==0 && strcmp(Quadtable[i].op,"Label")==0 )
        {
            char old_label[4] ,new_label[4];
            strcpy(old_label,Quadtable[i-1].result);
            Quadtable[i-1].result[0]='\0';
            Quadtable[i-1].op[0]='\0';
            strcpy(new_label,Quadtable[i].result);
            for(int j = i-2; j>0;j--)
            {
                if(strcmp(Quadtable[j].op,"GOTO")==0 && strcmp(Quadtable[j].result,old_label)==0)
                {
                 strcpy(Quadtable[j].result,new_label);
                    
                }
            }

        }

    }
    return 1;
}

int fold() {
    for(int i = 0; i < quad_row; ++i) {
        
    }
}

int main()
{
    initStack(&indent, 20);
    initStack(&scope, 20);
    push(&scope, 0);
    yyin = fopen("try.py", "r");
    yyparse();
    print_table();
    print_quad();
    rid_labels();
    print_quad();
    // printf("Valid program");
    return 0;
}

void yyerror()
{
    printf("Error in line %d\n", linenum);
    print_quad();
    exit(0);
}
#line 488 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 11:
#line 90 "try.y"
	{yyval.strval=new_label(); add_quad("IFFALSE", yystack.l_mark[0].strval, "", yyval.strval);}
break;
case 12:
#line 94 "try.y"
	{yyval.strval=new_label(); add_quad("GOTO", "", "", yyval.strval); add_quad("Label", "", "", yystack.l_mark[-1].strval);}
break;
case 13:
#line 98 "try.y"
	{add_quad("Label", "", "", yystack.l_mark[-1].strval);}
break;
case 14:
#line 101 "try.y"
	{add_quad("Label", "", "", yystack.l_mark[-3].strval);}
break;
case 17:
#line 107 "try.y"
	{add_quad("GOTO", "", "", yystack.l_mark[-3].strval); add_quad("Label", "", "", yystack.l_mark[-1].strval);}
break;
case 18:
#line 111 "try.y"
	{yyval.strval=new_label(); add_quad("Label", "", "", yyval.strval);}
break;
case 19:
#line 115 "try.y"
	{yyval.strval=new_label(); add_quad("IFFALSE", yystack.l_mark[0].strval, "", yyval.strval);}
break;
case 20:
#line 120 "try.y"
	{yyval.strval = yystack.l_mark[-2].strval;}
break;
case 21:
#line 123 "try.y"
	{yyval.strval = yystack.l_mark[0].strval;}
break;
case 23:
#line 131 "try.y"
	{++scope_cnt; push(&scope, scope_cnt);}
break;
case 24:
#line 134 "try.y"
	{--scope_cnt; pop(&scope);}
break;
case 25:
#line 137 "try.y"
	{yyval.strval = add_quad("<=", yystack.l_mark[-3].strval, yystack.l_mark[-1].strval, "");}
break;
case 26:
#line 138 "try.y"
	{yyval.strval = add_quad("<", yystack.l_mark[-2].strval, yystack.l_mark[0].strval, "");}
break;
case 27:
#line 139 "try.y"
	{yyval.strval = add_quad(">=", yystack.l_mark[-3].strval, yystack.l_mark[-1].strval, "");}
break;
case 28:
#line 140 "try.y"
	{yyval.strval = add_quad(">", yystack.l_mark[-2].strval, yystack.l_mark[0].strval, "");}
break;
case 29:
#line 141 "try.y"
	{yyval.strval = add_quad("==", yystack.l_mark[-3].strval, yystack.l_mark[-1].strval, "");}
break;
case 30:
#line 142 "try.y"
	{yyval.strval = add_quad("!=", yystack.l_mark[-3].strval, yystack.l_mark[-1].strval, "");}
break;
case 31:
#line 146 "try.y"
	{add_quad("=",  yystack.l_mark[0].strval, "", st[yystack.l_mark[-2].intval].name); st[yystack.l_mark[-2].intval].assigned =1; printf("%s\t%d\n", st[yystack.l_mark[-2].intval].name, st[yystack.l_mark[-2].intval].assigned);}
break;
case 32:
#line 150 "try.y"
	{yyval.strval = add_quad("+", yystack.l_mark[-2].strval, yystack.l_mark[0].strval, "");}
break;
case 33:
#line 151 "try.y"
	{yyval.strval = add_quad("-", yystack.l_mark[-2].strval, yystack.l_mark[0].strval, "");}
break;
case 34:
#line 152 "try.y"
	{yyval.strval = add_quad("*", yystack.l_mark[-2].strval, yystack.l_mark[0].strval, "");}
break;
case 35:
#line 153 "try.y"
	{yyval.strval = add_quad("/", yystack.l_mark[-2].strval, yystack.l_mark[0].strval, "");}
break;
case 36:
#line 154 "try.y"
	{yyval.strval = yystack.l_mark[-1].strval;}
break;
case 37:
#line 155 "try.y"
	{if(st[yystack.l_mark[0].intval].assigned ==0) yyerror("unassigned variable\n"); yyval.strval = st[yystack.l_mark[0].intval].name;}
break;
case 38:
#line 156 "try.y"
	{yyval.strval = yystack.l_mark[0].strval;}
break;
#line 790 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
