#define ID 257
#define NUM 258
#define INDENT 259
#define DEDENT 260
#define END_STATEMENT 261
#define IF 262
#define ELIF 263
#define ELSE 264
#define WHILE 265
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
extern YYSTYPE yylval;
