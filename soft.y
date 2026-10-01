%{
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<sys/time.h>
#include<time.h>
/*
int yydebug=1;
*/
#define YYDEBUG 1
#define YYSTYPE float
#define PROMPT "]"
int ll=0;
char identifier[256];
char a[512];
char chars[256];
struct var {
char name[80];
float value;
struct var * next;
};
struct str {
char name[80];
char value[1024];
struct str * next;
};
char A[80];
char cstr[1024];
char string[1024];
struct var *r=NULL;
struct var *d;
struct str * root = NULL;
struct str *D;
int c=0;
float cv;
int cx,cy;
char lines[65536][512];
int im=1;
int l=0;
int notdef=1;
extern char * yytext;
extern void destroy();
char s[1024];
int trace=0;
int b1,b2,e1,e2;
void yyerror(char *s);
int basic2c(FILE *fp);
int yylex();
char oper[4];
int infor=0;
%}
%token PR
%token STR
%token NOTRACE
%token SAVE
%token GET
%token PEEK
%token POKE
%token RUN
%token RND
%token PRINT
%token IDENTIFIER
%token PLUS
%token MINUS
%token ASTERISK
%token DIVIDE
%token NUMBER
%token LIST
%token INPUT
%token LET
%token SQR
%token SIN
%token COS
%token TAN
%token EXP
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
%token FLOAT
%token SYSTEM
%token DUMP
%token CLEAR
%token COLOR
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
%token RETURN
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
%token INT
%%
pgm: 
 | pgm line { printf("]"); } CR
 | pgm CR { printf("]"); }
 ;

line: NUMBER { im=0; l=atoi(yytext); strcpy(lines[l],""); } inst { if (!im&&!infor) strcat(lines[l],";"); else infor=0;  }
 |	{ im=1; } inst 
 ;

inst: PRINT { if (!im) strcat(lines[l],"printf(\"%"); } multi_expr { if (!im) strcat(lines[l],")"); } opt_print
 | { notdef=1; } IDENTIFIER { d=r; while(d) { if (strcmp(d->name,identifier)==0) notdef=0; d=d->next; } if (notdef&&!im) strcat(lines[l],"float "); strcpy(a,identifier); } EQUAL { if (!im) sprintf(lines[l],"%s%s=",lines[l],identifier);  } expr { 
	if (notdef) {
		d=(struct var*)malloc(sizeof(struct var));
		d->value=$6; strcpy(d->name,a); d->next=r; r=d;
	} else {	
		if (im) d->value=$6;
	}
}

 
 | LET { notdef=1; } IDENTIFIER { if (!im&&notdef) strcat(lines[l],"float "); d=r; strcpy(a,identifier); while (d) { if (strcmp(d->name,identifier)==0) { notdef=0; break; } d=d->next; } } EQUAL { if (!im) sprintf(lines[l],"%s%s=",lines[l],identifier);  } expr { if(im) {
	if (notdef) {
		d=(struct var*)malloc(sizeof(struct var));
		d->value=$7; strcpy(d->name,a); d->next=r; r=d;
	} else
		d->value=$7;
} }
 | STRING { if (im) strcpy(A,yytext); }  EQUAL sexpr { if (im) {
	D=(struct str*)malloc(sizeof(struct str));
	strcpy(D->value,cstr);strcpy(D->name,A); D->next=root; root=D;	
} else {
        sprintf(lines[l],"char * %s = %s",identifier,chars);
}
}
 | inst DP { if (!im) sprintf(lines[l],"%s;",lines[l]); } inst
 | LIST {
	if (im) for(int i=0;i<65536;i++) if (strcmp(lines[i],"")) printf("%d %s\n",i,lines[i]);
 }
 | RUN { if (im) {
	struct timeval * tv1;
	struct timeval * tv2;
	int diff;
	if (trace) {
		tv1=(struct timeval*)malloc(sizeof(struct timeval));
		tv2=(struct timeval*)malloc(sizeof(struct timeval));
	}
		FILE *fp=fopen("soft.c","w");
		if (!fp) fprintf(stderr,"erreur ouverture soft.c\n");
		basic2c(fp);
		fclose(fp);
#ifdef WIN32
		system("gcc soft.c -lm");
#else
		system("gcc soft.c -lm -lSDL2");
#endif
	if (trace)
		gettimeofday(tv1,NULL);
#ifdef WIN32
		system("a.exe");
#else
		system("./a.out");
#endif
	if (trace) {
		gettimeofday(tv2,NULL);
		diff=tv2->tv_sec - tv1->tv_sec;
		printf("µsec=%d\n",(int)(diff*1000000 + tv2->tv_usec - tv1->tv_usec));
	}
	
 }
}
 | SYSTEM { if (im) exit(0); else sprintf(lines[l],"%s exit(0)",lines[l]); }
 | DUMP { if (im) {
	struct var *d =r;
	struct str *D=root;
	while(d) {
		printf("%s %g\n",d->name,d->value);
		d=d->next;
	}
	while(D) {
		printf("%s %s\n",D->name,D->value);
		D=D->next;
	}
 }
}
 | TRACE { trace=1; }
 | NOTRACE { trace=0; }
 | DEBUG ON { yydebug=1; }
 | DEBUG OFF { yydebug=0; }
 | REM
 | IF { sprintf(lines[l],"%sif ",lines[l]);} cond opt_then inst
 | GOTO { sprintf(lines[l],"%s%s",lines[l],"goto L"); } expr
 | GOSUB { if (!im) strcat(lines[l],"if (!setjmp(buf)) goto L"); } expr
 | INPUT { if (!im) strcat(lines[l],"fgets(s,1024,stdin);float "); } IDENTIFIER { if (!im) sprintf(lines[l],"%s%s=atof(s)",lines[l],identifier); else fprintf(stderr,"NO DIRECT COMMAND\n"); }
 | INPUT opt_prompt STRING { if (!im) sprintf(lines[l],"%schar %s[256];fgets(%s,256,stdin)",lines[l],identifier,identifier); } 
 | HTAB { if (!im) sprintf(lines[l],"%sprintf(\"%%c[%d;",lines[l],cx); } expr { if (!im) sprintf(lines[l],"%sH\",27)",lines[l]); }
 | VTAB { if (!im) strcat(lines[l],"printf(\"%c["); } expr { if (!im) sprintf(lines[l],"%s;%dH\",27)",lines[l],cy); }
 | HOME { if (im) 
#ifdef WIN32
system("cls");
#else /* ANSI */
printf("%c[2J",27);
#endif
else strcat (lines[l],"printf(\"%c[2J\",27)");   }
 | TEXT { if (im) { fprintf(stderr,"Already in text mode\n"); } }
 | AMPER GR 
 | HGR { if (im) {
	fprintf(stderr,"NO GRAPHICS ERROR USE GRSOFT!\n");
 }
}
 | PEEK PO expr PF
 | POKE expr COMMA expr
 | GET STRING
 | FOR { infor = 1; } IDENTIFIER EQUAL { strcat(lines[l],"for(I="); } expr TO { strcat(lines[l],";I<="); } expr { strcat(lines[l],";I++) {"); }
 | NEXT { if (!im) strcat(lines[l],"}"); } 
 | DATA list
 | READ IDENTIFIER
 | RETURN { if (!im) strcat(lines[l],"longjmp(buf,1)"); }
 | END { if (!im) strcat(lines[l],"return"); else return 0;  }
 | HPLOT { if (!im) strcat(lines[l],"hplot(renderer,(int)("); } expr { if(im) b1=atoi(yytext); } COMMA { if (!im) strcat(lines[l],"),(int)("); } expr { b2=atoi(yytext); if (!im) strcat(lines[l],"));\nSDL_RenderPresent(renderer)"); }  
 | HPLOT { if (!im) strcat(lines[l],"SDL_RenderDrawLine(renderer,b1,b2,(int)("); } TO expr COMMA { if (!im) strcat(lines[l],"),(int)("); } expr { if (!im) strcat(lines[l],"));\nSDL_RenderPresent(renderer)"); }
 | HLIN expr COMMA expr AT expr
 | VLIN expr COMMA expr AT expr
 | SAVE IDENTIFIER {
	if (im) {
		FILE * fp;
		fp=fopen(identifier,"w");
		for(int i=0;i<65536;i++) if (strcmp(lines[i],"")) fprintf(fp,"L%d: %s\n",i,lines[i]);
		fclose(fp);
 }
 }
 | NEW { for(int i=0;i<65536;i++) strcpy(lines[i],""); }
 | DRAW expr AT expr COMMA expr
 | CLEAR { if (im) { r=NULL; root=NULL; } }
 ;
/*
toext: { if (!im) strcat(lines[l],"));\nSDL_RenderPresent(renderer)"); }
     | TO { if (!im) strcat(lines[l],","); } expr { e1=atoi(yytext); } COMMA { if (!im) strcat(lines[l],","); } expr { if (im) {
   e2=atoi(yytext);
   SDL_RenderDrawLine(renderer, b1, b2, e1, e2);
   SDL_RenderPresent(renderer);
}
else {
	strcat(lines[l],");\nSDL_RenderPresent(renderer)"); 
	}
}
*/

opt_prompt:
	  | CHARS SEMICOLOMN
	;

opt_then:
	| THEN
	;

list: expr
    | list COMMA expr
    ;

cond: { sprintf(lines[l],"%s ( ",lines[l]); } expr oper { sprintf(lines[l],"%s %s ",lines[l],oper); } expr { sprintf(lines[l],"%s ) ",lines[l]); }
	| PEEK PO expr PF
	| PO cond PF
	| cond OR cond
 	| NOT cond
	| { if (!im) strcat(lines[l],"(strcmp("); } string EQUAL { if (!im) strcat(lines[l],","); } string { if (!im) strcat(lines[l],")==0) "); }
;

oper: EQUAL { strcpy(oper,"=="); }
	| PG { strcpy(oper,">"); }
	| PP { strcpy(oper,"<"); }
	| GE { strcpy(oper,">="); }
	| PE { strcpy(oper,"<="); }
	;

sexpr: string 
	| sexpr PLUS string
	| MID PO string COMMA expr COMMA expr PF
	| LEFT PO string COMMA expr PF
	| RIGHT PO string COMMA expr PF
	| STR PO expr PF
	;

multi_expr: { if (!im) strcat(lines[l],"g\","); } expr { if (im) {
	  $$=$2;
	printf("%g\n",$2);
}
}
        | { if (!im) strcat(lines[l],"s\","); } sexpr { if (im) {
        D=root;
        while (D) {
                if (strcmp(D->name,identifier)==0)
                        printf("%s\n",D->value);
                D=D->next;
        }
}
}
        | { if (!im) strcat(lines[l],"c\","); } CHR PO { if (!im) strcat(lines[l],"(int)"); } expr PF { if (im) printf("%c",(int)$5); }
	| { printf("\n"); }
	;

opt_print: { if (!im) strcat(lines[l],";printf(\"\\n\")"); }
 | sep expr
 | sep sexpr
 | opt_print sep expr
 | opt_print sep sexpr
 ;

sep: COMMA
 | SEMICOLOMN
 ;

string: STRING { if (im) strcpy(identifier,yytext); else sprintf(lines[l],"%s%s",lines[l],identifier); }
        | CHARS { if (!im) strcat(lines[l],chars); else strcpy(string,chars+1);string[strlen(string)-1]=0; }
        ;

expr: expr PLUS { if (!im) strcat(lines[l],"+"); } expr { if (im) $$=$1+$4; }
 | expr MINUS { if (!im) strcat(lines[l],"-"); } expr { if (im) $$=$1-$4; }
 | expr ASTERISK { if (!im) strcat(lines[l],"*"); } expr { if (im) $$=$1*$4; }
 | expr DIVIDE  { if (!im) strcat(lines[l],"/"); } expr { if (im) $$=$1/$4; }
 | PO { if (!im) strcat(lines[l],"("); } expr PF { if (im) $$=$2; else strcat(lines[l],")"); }
 | NUMBER { if (im) $$=$1; else strcat(lines[l],yytext); }
 | FLOAT { if (im) $$=$1; else strcat(lines[l],yytext); }
 | IDENTIFIER { if (!im) {
	strcat(lines[l],identifier);
	struct var * c=r;
	while(c) {
		if (strcmp(c->name,identifier)==0) {
                        notdef=0;
		}
		c=c->next;
	}
        } else {
	int fin=0;
	struct var* c=r;
	while(c) {
		if (strcmp(c->name,identifier)==0) {
			fin=1; notdef=0;
			$$=c->value;
		}
		c=c->next;
	}
	if (!fin) $$=0;
}
 }
 | COS PO { if (!im) strcat(lines[l],"cos(");  } expr PF { if (im) $$=cos($4); else strcat(lines[l],")"); }
 | SIN PO { if (!im) strcat(lines[l],"sin(");  } expr PF { if (im) $$=sin($4); else strcat(lines[l],")"); }
 | TAN PO expr PF { if (im) $$=tan($3); }
 | SQR PO { if (!im) strcat(lines[l],"sqrt("); } expr PF { if (im) $$=sqrt($4); else strcat(lines[l],")"); }
 | EXP PO expr PF { if (im) $$=exp($3); }
 | MINUS { if (!im) strcat(lines[l],"-"); } expr { if (im) $$=-$3; }
 | ASC PO STRING PF
 | RND PO { if (!im) 
#ifdef WIN32
strcat(lines[l],"rand()*");
#else
strcat(lines[l],"drand48()*");
#endif
} expr { if (im) 
#ifdef WIN32
$$=rand()*$4;
#else
$$=drand48()*$4;
#endif
} PF
 | INT { if (!im) strcat(lines[l],"roundf("); } PO expr PF { if (im) $$=(int)$4; else strcat(lines[l],")");  }
;

%%
#include"lex.yy.c"
void  yyerror(char *s) {
if (im) 
	fprintf(stderr,"%s on %s at %d\n",s,yytname[yychar-255],ll);
else
	fprintf(stderr,"%s on %s line %d\n",s,yytname[yychar-255],l);
	yyparse();
}

int main(int argc,char * argv[]) {
char rcsrev[]="$Revision: 1.3 $";

strtok(rcsrev,".");
r=(struct var*)malloc(sizeof(struct var));
strcpy(r->name,"HCOLOR");
r->value=7;
r->next=(struct var*)malloc(sizeof(struct var));
r->next->value=atof(strtok(NULL,"."));
r->next->next=NULL;
strcpy(r->next->name,"VERSION");
#ifdef WIN32
srand(12345);
#else
srand48(12345);
#endif
printf(PROMPT);
yyparse();
fprintf(stderr,"FIN\n");
}

int WinMain() {
char rcsrev[]="$Revision: 1.3 $";

strtok(rcsrev,".");
r=(struct var*)malloc(sizeof(struct var));
strcpy(r->name,"HCOLOR");
r->value=7;
r->next=(struct var*)malloc(sizeof(struct var));
r->next->value=atof(strtok(NULL,"."));
r->next->next=NULL;
strcpy(r->next->name,"VERSION");

srand(12345);
printf(PROMPT);
fflush(stdout);
return yyparse();
}

int yywrap() {
}

int process(char *s) {
}

int basic2c(FILE *fp) {
	fprintf(fp,"#include<stdio.h>\n");
	fprintf(fp,"#include<setjmp.h>\n");
	fprintf(fp,"#include<stdlib.h>\n");
	fprintf(fp,"#include<string.h>\n");
	fprintf(fp,"#include<math.h>\n");

	fprintf(fp,"int b1,b2;\n");
	fprintf(fp,"static jmp_buf buf;\n");

	fprintf(fp,"void main(int argc, char * argv[]) {\n");
	fprintf(fp,"char s[1024];\n");
	fprintf(fp,"float I;\n");
	fprintf(fp,"float VERSION=15;\n");
#ifdef WIN32
	fprintf(fp,"srand(1234);\n");
#else
	fprintf(fp,"srand48(1234);\n");
#endif
	for(int i=0;i<65536;i++) {
		if (strcmp(lines[i],"")) {
                        if (trace)
                                fprintf(fp,"fprintf(stderr,\"#%%d\",%d);",i);
			fprintf(fp,"L%d: %s\n",i,lines[i]);
		}
	}
	fprintf(fp,"}\n");
}

void destroy() {
//	gtk_main_quit();
}
/*
GTypeInstance* g_type_check_instance_cast(GTypeInstance *i,GType iface) {
return i;
}
*/
