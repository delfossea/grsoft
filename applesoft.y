%{
#define YYERROR_VERBOSE
#define YYDEBUG 1
#define YYSTYPE float
char identifier[20];
char chars[1024];
char string[1024];
int ll=0;
%}
%token OPEN
%token CLOSE
%token BSAVE
%token BLOAD
%token CATALOG
%token DEF
%token POP
%token VAL
%token FN
%token EFFACE
%token ABORT
%token PR
%token COL80
%token STR
%token NOTRACE
%token SAVE
%token GET
%token PEEK
%token POKE
%token RUN
%token STOP
%token RND
%token PRINT
%token IDENTIFIER
%token DEL
%token PLUS
%token MINUS
%token ASTERISK
%token DIVIDE
%token NUMBER
%token LIST
%token ENTREE
%token LET
%token SQR
%token SIN
%token COS
%token TAN
%token ATAN
%token EXP
%token LOG
%token DIM
%token ABS
%token OR
%token AND
%token ASC
%token REM
%token QUOTE
%token EQUAL
%token PO
%token PF
%token CO
%token CF
%token DP
%token PG
%token PP
%token GE
%token PE
%token DIFF
%token DOT
%token COMMA
%token SEMICOLOMN
%token CR
%token RANDOMIZE
%token MOD
%token CHARS
%token FLOTANT
%token SYSTEM
%token DUMP
%token CLEAR
%token DRAW
%token IF
%token THEN
%token ELSE
%token FOR
%token NEXT
%token STEP
%token TO
%token DEBUG
%token GOTO
%token GOSUB
%token RETOUR
%token NEW
%token TRACE
%token ON
%token OFF
%token TEXT
%token HTAB
%token VTAB
%token HOME
%token GR
%token PLOT
%token HGR
%token HPLOT
%token END
%token NOT
%token READ
%token DATA
%token VLIN
%token HLIN
%token MID
%token LEFT
%token RIGHT
%token LEN
%token STRING
%token AMPER
%token AT
%token CHR
%token ENTIER
%%

pgm: line
	| pgm CR line
	;

line: 
 | NUMBER inst
 | inst 
 ;

inst: PRINT multi_expr opt_print
 | let_op IDENTIFIER array_op EQUAL expr
 | let_op STRING EQUAL sexpr
 | inst DP inst
 | LIST
 | RUN
 | TRACE
 | NOTRACE
 | DEBUG ON { yydebug=1; }
 | DEBUG OFF { yydebug=0; }
 | REM
 | IF cond opt_then inst
 | GOTO expr
 | GOSUB expr
 | ENTREE opt_prompt IDENTIFIER
 | ENTREE opt_prompt STRING 
 | HTAB expr
 | VTAB expr 
 | HOME
 | TEXT
 | GR 
 | HGR
 | POKE expr COMMA expr
 | GET STRING
 | FOR IDENTIFIER EQUAL expr TO expr
 | NEXT opt_identifier
 | DATA list
 | READ multi_expr
 | RETOUR
 | END
 | HPLOT expr COMMA expr to_ext 
 | HPLOT TO expr COMMA expr
 | HLIN expr COMMA expr AT expr
 | VLIN expr COMMA expr AT expr
 | SAVE IDENTIFIER
 | NEW
 | BSAVE IDENTIFIER
 | BLOAD IDENTIFIER
 | DRAW expr AT expr COMMA expr
 | CLEAR
 | DEL expr 
 | CATALOG
 | EFFACE IDENTIFIER
 | ABORT
 | DIM string PO expr PF
 | DIM IDENTIFIER PO expr PF
 | STOP 
 | DEF FN IDENTIFIER PO IDENTIFIER PF EQUAL expr
 | PLOT expr COMMA expr
 | PLOT expr COMMA expr TO expr COMMA expr
 | COL80
 | ON IDENTIFIER GOTO list
 | POP
 | OPEN IDENTIFIER
 | CLOSE IDENTIFIER
 ;

array_op :
	| PO expr PF
	;

let_op :
	| LET
	;

to_ext: 
     | TO expr COMMA expr

opt_prompt:
	  | CHARS SEMICOLOMN
	;

opt_then:
	| THEN
	;

list: expr
    | list COMMA expr
    | CHARS
    | list COMMA CHARS
    ;

cond: expr oper expr
	| expr
 	| NOT expr
	| string EQUAL string
	| PO cond PF
;

oper: PG
	| PP
	| GE
	| PE
	| DIFF
	| AND
	| OR
	;

sexpr: string 
	| sexpr PLUS string
	| MID PO string COMMA expr COMMA expr PF
	| LEFT PO string COMMA expr PF
	| RIGHT PO string COMMA expr PF
	| STR PO expr PF
	| STRING PO expr PF
	| CHR PO expr PF
	;

multi_expr: expr
        | sexpr 
	|
	;

opt_print:
 | sep expr
 | sep sexpr
 | opt_print sep
 | sep
 ;

sep: COMMA
 | SEMICOLOMN
 ;

string: STRING 
        | CHARS
        ;

expr: expr PLUS expr
 | expr MINUS expr
 | expr ASTERISK expr
 | expr DIVIDE expr
 | PO expr PF
 | NUMBER
 | FLOTANT
 | IDENTIFIER
 | COS PO expr PF
 | SIN PO expr PF
 | TAN PO expr PF
 | ATAN PO expr PF
 | SQR PO expr PF
 | EXP PO expr PF
 | MINUS expr
 | ASC PO sexpr PF
 | RND PO expr PF
 | ENTIER PO expr PF
 | ABS PO expr PF
 | PEEK PO expr PF 
 | LEN PO sexpr PF
 | LOG PO expr PF
 | IDENTIFIER PO expr PF
 | VAL PO sexpr PF
 | expr EQUAL expr
;

opt_identifier:
	     | IDENTIFIER
	;
%%
#include"lex.yy.c"
#include<stdio.h>

int ERROR_CODE=0;
int standalone=1;

void  yyerror(const char *s) {
ERROR_CODE=16; /* syntax error */
	if (yychar>255) 
		fprintf(stderr,"%s on %s\n",s,yytname[yychar-255]);
	else
		fprintf(stderr,"%s\n",s);
}

int init() {
char rcsrev[]="$Revision: 1.1 $";
}

int main(int argc, char * argv[]) 
{
	char opt;

 while ((opt = getopt(argc, argv, "sd")) != -1) {
               switch (opt) {
               case 's':
		standalone=1;
		break;
               case 'd':
		yydebug=1;
		break;
		}
	}
	
        init();
	return yyparse();
}

int yywrap() {
}
