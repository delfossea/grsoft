%{
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<sys/time.h>
#include<time.h>
#include<SDL2/SDL.h>
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
enum var_type { SCALAR, ARRAY };
enum str_type { STRING, STRING_ARRAY };
struct var {
	char name[80];
	enum var_type type;
	float *values;
	int size;
	struct var * next;
};
struct str {
	char name[80];
	enum str_type type;
	int size;
	struct str * next;
	char **values;
};
char A[80];
char cstr[1024];
char * string;
char String[1024];
struct var *r=NULL;
struct var *d;
struct var *r2;
struct str *ds;
struct str * root = NULL;
struct str *D;
int c=0;
float cv;
int cx,cy;
char lines[65536][512];
char mem[65536];
char aux[65536];
int im=1;
int l=0;
int notdef=1;
extern char * yytext;
extern void destroy();
char s[1024];
int trace=0;
int b1,b2,e1,e2;
SDL_Window* pWindow = NULL;
SDL_Renderer* renderer = NULL;
SDL_bool done;
SDL_Rect pos;
SDL_Surface * temp;
SDL_Texture * sprite;
int hgr=0;
void yyerror(char *s);
int basic2c(FILE *fp);
int yylex();
char oper[4];
int infor=0;
int page0[255];
%}
%token EXEC
%token PR
%token STR
%token NOTRACE
%token SAVE
%token GET
%token PEEK
%token POKE
%token RUN
%token RND
%token INT
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
%token DEL
%token SQR
%token SIN
%token COS
%token TAN
%token ATAN
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
%token PE
%token GE
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
%token CHAINE
%token AMPER
%token AT
%token CHR
%token LOAD
%token CALL
%%
pgm: 
 | pgm line { printf("]"); } CR
 | pgm CR { printf("]"); }
 ;

line: NUMBER { im=0; l=atoi(yytext); strcpy(lines[l],""); } inst { if (!im&&!infor) strcat(lines[l],";"); else infor=0;  }
 |	{ im=1; } inst 
 ;

inst: PRINT { if (!im) strcat(lines[l],"printf(\"%"); } multi_expr { if (!im) strcat(lines[l],")"); else printf("%s\n",cstr); } opt_print

 | opt_let IDENTIFIER { notdef=1; d=r; while(d) { if (strcmp(d->name,identifier)==0) { notdef=0; break; } d=d->next; } if (notdef&&!im) strcat(lines[l],"float "); strcpy(a,identifier); } EQUAL { if (!im) strcat(lines[l],identifier);strcat(lines[l],"=");  } expr { 
	if (im) {
	if (notdef) {
		d=(struct var*)malloc(sizeof(struct var));
		d->values=malloc(sizeof(float));
		d->size=1;
		d->values[0]=$6; strcpy(d->name,a); d->next=r; r=d;
	} else {	
		d->values[0]=$6;
	}
    }
}

 
 | opt_let IDENTIFIER PO NUMBER PF EQUAL {
		strcat(lines[l], identifier);
                char buf[32];
                sprintf(buf, "[%d]=", (int)$4);
                strcat(lines[l], buf);
} expr {
	if(im) {
		d=r;
		while (strcmp(d->name,identifier)!=0)
			d=d->next;
		d->values[(int)$4]=$8;
	}
 }
 | CHAINE { if (im) strcpy(A,yytext); }  EQUAL sexpr { if (im) {
	D=(struct str*)malloc(sizeof(struct str));
	D->size=1;
	D->type=STRING;
	D->values = malloc(sizeof(char *));
	D->values[0]=(char*)malloc(1024);
	strcpy(D->values[0],cstr);strncpy(D->name,A,strlen(A)-1); D->next=root; root=D;	
} else {
        strcat(lines[l],"char *");
	identifier[strlen(A)-1]=0;
	strcat(lines[l],A);
	strcat(lines[l],"=");
	strcat(lines[l],chars);
}
}
 | inst DP { if (!im) strcat(lines[l],";"); } inst
 | CHAINE { 
	if (im) {
		strncpy(A,String,strlen(String)-1); 
	} else {
		char varname[256];
		strcpy(varname, String);
		varname[strlen(varname)-1] = 0;
		char buf[512];
		sprintf(buf, "%s[", varname);
		strcat(lines[l], buf);
	}
 }  PO expr PF EQUAL {
	if (!im) {
		strcat(lines[l], "]=");
	}
 } sexpr { if (im) {
	struct str *  du=root;
	while(du) {
		if (strcmp(du->name,A)==0) {
			break;
		}
		du=du->next;
	}
        du->values[(int)$4]=(char*)malloc(strlen(cstr) + 1);
        strcpy(du->values[(int)$4],cstr); 

} else {
}
}
 | LIST {
	if (im) for(int i=0;i<65536;i++) if (strcmp(lines[i],"")) printf("%d %s\n",i,lines[i]);
 }
 | RUN { if (im) {
	struct timeval * tv1;
	struct timeval * tv2;
	int diff,res;
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
		res=system("gcc soft.c -lm -lSDL2");
#endif
	if (trace)
		gettimeofday(tv1,NULL);
#ifdef WIN32
		system("a.exe");
#else
		res=system("./a.out");
#endif
#ifdef WIN32
		system("del a.exe");
#else
		res=system("rm a.out");
#endif
	if (trace) {
		gettimeofday(tv2,NULL);
		diff=tv2->tv_sec - tv1->tv_sec;
		printf("\nµsec=%d\n",(int)(diff*1000000 + tv2->tv_usec - tv1->tv_usec));
	}
	
 }
}
 | SYSTEM { if (im) exit(0); else sprintf(lines[l],"%s exit(0)",lines[l]); }
 | DUMP { if (im) {
	struct var *d =r;
	struct str *D=root;
	while(d) {
		printf("%d: ",d->size);
		printf("%s: ",d->name);
		for (int i=0;i<d->size;i++)
			printf("%f ",d->values[i]);
		printf("\n");
		d=d->next;
	}
	while(D) {
		printf("%d: ",D->size);
		printf("%s: ",D->name);
		for (int i=0;i<D->size;i++)
			printf("%s ",D->values[i]);
		printf("\n");
		D=D->next;
	}
 }
}
 | TRACE { trace=1; }
 | NOTRACE { trace=0; }
 | DEBUG ON { yydebug=1; }
 | DEBUG OFF { yydebug=0; }
 | REM { if (!im) {
	strcat(lines[l],"/*");
	strcat(lines[l],yytext);
	strcat(lines[l],"*/");
	}
 }
 | IF { if (!im) strcat(lines[l],"if ");} cond opt_then { if (!im) strcat(lines[l],"{"); } inst { if (!im) strcat(lines[l],";}"); }
 | GOTO { strcat(lines[l],"goto L"); } expr
 | GOSUB { if (!im) strcat(lines[l],"if (!setjmp(stack[sp++])) goto L"); } expr
 | INPUT { if (!im) strcat(lines[l],"fgets(s,1024,stdin);float "); } IDENTIFIER { if (!im) { strcat(lines[l],identifier);strcat(lines[l],"=atof(s)"); } else fprintf(stderr,"NO DIRECT COMMAND\n"); }
 | INPUT opt_prompt CHAINE { if (!im) sprintf(lines[l],"%schar %s[256];fgets(%s,256,stdin)",lines[l],identifier,identifier); } 
 | INPUT opt_prompt CHAINE PO expr PF { if (!im) sprintf(lines[l],"%schar %s[256];fgets(%s,256,stdin)",lines[l],identifier,identifier); } 
 | HTAB
	{ if (!im) strcat(lines[l],"printf(\"%c[%d;"); } expr { if (!im) strcat(lines[l],"%dH\",27,20,20)"); else printf("%c[%d;%dH",27,cx,(int)$3); }
 | VTAB { if (!im) strcat(lines[l],"printf(\"%c["); } expr { if (!im) strcat(lines[l],"%d;%dH\",27,20,20)"); else printf("%c[%d;%dH",27,(int)$3,cy); }
 | HOME { if (im) 
#ifdef WIN32
system("cls");
#else /* ANSI */
printf("%c[2J",27);
#endif
else strcat (lines[l],"printf(\"%c[2J\",27)");   }
 | TEXT { if (im) { SDL_Quit(); hgr=0; } }
 | GR { if (im) {
if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS )) fprintf(stderr, "Echec SDL retour au mode texte (%s)", SDL_GetError());
        if (SDL_CreateWindowAndRenderer(40,48,0,&pWindow,&renderer)==0) {
            done = SDL_FALSE;
               SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
               SDL_RenderClear(renderer);

               SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
                SDL_QueryTexture(sprite, NULL, NULL, &pos.w, &pos.h);

} }
 }
 | HGR { if (im) {
hgr=1;
if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS )) fprintf(stderr, "Echec SDL retour au mode texte (%s)", SDL_GetError());
	if (SDL_CreateWindowAndRenderer(281,192,0,&pWindow,&renderer)==0) {
            done = SDL_FALSE;
               SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
               SDL_RenderClear(renderer);

               SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
                SDL_QueryTexture(sprite, NULL, NULL, &pos.w, &pos.h);
	}
} else {
	hgr=1;
	strcat(lines[l],"if (SDL_Init(SDL_INIT_VIDEO)) fprintf(stderr, \"Echec SDL (%s)\", SDL_GetError());\n");
	strcat(lines[l],"if (SDL_CreateWindowAndRenderer(280,192,0,&pWindow,&renderer)==0) {\n");
	strcat(lines[l],"done = SDL_FALSE;\n");
        strcat(lines[l],"SDL_SetRenderDrawColor(renderer,0,0,0,SDL_ALPHA_OPAQUE);\n");
        strcat(lines[l],"SDL_RenderClear(renderer);\n");
        strcat(lines[l],"SDL_SetRenderDrawColor(renderer,255,255,255,SDL_ALPHA_OPAQUE);\n } else fprintf(stderr,\"Erreur SDL\")\n");
}
 }
 | DIM IDENTIFIER PO NUMBER PF {
	if (im) {
		d=(struct var*)malloc(sizeof(struct var));
		strcpy(d->name,identifier);
		d->type=ARRAY;
		d->next=r;
		r=d; 
		d->size = (int)$4;
		d->values = calloc(d->size, sizeof(float));
		} else { sprintf(lines[l],"%sfloat %s[%d]",lines[l],identifier,(int)$4); }
	} opt_dim
 | DIM CHAINE PO NUMBER PF {
	if (im) {
		ds=(struct str*)malloc(sizeof(struct str));
		String[strlen(String)-1]=0;
		strcpy(ds->name,String);
		ds->type=STRING_ARRAY;
		ds->next=root;
		root=ds; 
		ds->size = (int)$4;
		ds->values = malloc(ds->size * sizeof(char *));
		for (int i=0;i<(int)$4;i++){
			ds->values[i]=malloc(1024);
			strcpy(ds->values[i],"");
		}
	} else { 
		char varname[256];
		strcpy(varname, String);
		varname[strlen(varname)-1] = 0;
		sprintf(lines[l],"%schar * %s[%d]",lines[l],varname,(int)$4); 
	}
 } opt_dims
 | PEEK PO expr PF { if (im) { printf("%d\n",mem[(int)$3]); } }
 | POKE expr COMMA expr { if (im) { mem[(int)$2]=(char)$4; } }
 | GET CHAINE { if (im) fprintf(stderr,"DIRECT ERROR\n"); }
 | FOR { infor = 1; } IDENTIFIER EQUAL { if (!im) {
sprintf(lines[l],"%sfor(float %s=", lines[l], identifier);  }
 } expr TO { if (!im) strcat(lines[l],";");strcat(lines[l],identifier);strcat(lines[l],"<="); }
 expr { if (!im) strcat(lines[l],";"); strcat(lines[l],identifier);strcat(lines[l],"++){"); }
 | NEXT { if (!im) strcat(lines[l],"}"); } opt_var
 | DATA list
 | READ IDENTIFIER
 | RETURN { if (!im) strcat(lines[l],"longjmp(stack[--sp],1)"); }
 | END { if (!im) strcat(lines[l],"return"); else return 0;  }
 | HPLOT { if (!im) strcat(lines[l],"hplot(renderer,(int)("); } expr { if(im) b1=atoi(yytext); } COMMA { if (!im) strcat(lines[l],"),(int)("); } expr { b2=atoi(yytext); if (!im) strcat(lines[l],"));\nSDL_RenderPresent(renderer)"); }  
 | HPLOT { if (!im) strcat(lines[l],"SDL_RenderDrawLine(renderer,b1,b2,(int)("); } TO expr COMMA { if (!im) strcat(lines[l],"),(int)("); } expr { if (!im) strcat(lines[l],"));\nSDL_RenderPresent(renderer)"); else {
SDL_RenderDrawLine(renderer,0,0,100,100);
SDL_RenderPresent(renderer);
}
}
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
 | LOAD IDENTIFIER { fprintf(stderr,"unimp.\n"); }
 | CALL NUMBER { fprintf(stderr,"unimp.\n"); }
 | NEW { for(int i=0;i<65536;i++) strcpy(lines[i],""); }
 | DRAW expr AT expr COMMA expr { if (im) { pos.x=(int)$4; pos.y=(int)$6; SDL_RenderCopy(renderer,sprite,NULL,&pos); SDL_RenderPresent(renderer); } }
 | CLEAR { if (im) { r=NULL; root=NULL; } }
 | PR
 | DEL NUMBER
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

opt_i :
      | IDENTIFIER
	;

opt_dim :
	;

opt_dims: 
	| opt_dims COMMA CHAINE PO NUMBER PF

	;
opt_let:
	| LET
	;

opt_prompt:
	  | CHARS SEMICOLOMN { if (!im) sprintf(lines[l],"%sprintf(%s);",lines[l],chars); }
	;

opt_then: 
	| THEN
	;

opt_var:
	| IDENTIFIER
	;

list: expr
    | list COMMA expr
    ;

cond: { strcat(lines[l]," ( "); } expr oper { strcat(lines[l],oper); } expr { strcat(lines[l]," ) "); }
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

sexpr: string { if (im) strcpy(cstr, string); }
	| string PO { if (!im) strcat(lines[l],identifier); strcat(lines[l],"["); } expr PF { strcat(lines[l],"]"); }
	| sexpr PLUS string { if (im) strcat(cstr, identifier); }
	| MID PO string COMMA expr COMMA expr PF
	| LEFT PO string COMMA expr PF { if (im)  string[(int)$5]=0; }
	| RIGHT PO string COMMA expr PF { if (im) string=string+(strlen(string)-(int)$5); }
	| STR PO expr PF { if (im) sprintf(cstr, "%g", $3); }
	;

multi_expr: { if (!im) strcat(lines[l],"f\","); } expr { if (im) {
	  $$=$2;
	sprintf(cstr, "%f", $2);
}
}
	| { if (!im) strcat(lines[l],"s\","); } sexpr { strcpy(cstr,string); }
        | { if (!im) strcat(lines[l],"c\","); } CHR PO { if (!im) strcat(lines[l],"(int)"); } expr PF { if (im) sprintf(cstr, "%c", (int)$5); }
	| { printf("\n"); }
	;

opt_print: { if (!im) strcat(lines[l],";printf(\"\\n\")"); }
 | sep
 | sep  { if (!im) strcat(lines[l],";printf(\"%f\","); } expr { if (!im) strcat(lines[l],")"); }
 | sep sexpr
 | opt_print sep expr
 | opt_print sep sexpr
 ;

sep: COMMA
 | SEMICOLOMN
 ;

string: CHAINE { if (im) strcpy(identifier,yytext); else { yytext[strlen(yytext)-1]=0;strcat(lines[l],yytext); } }
        | CHARS { if (!im) strcat(lines[l],chars); else { strcpy(string,chars+1);string[strlen(string)-1]=0; } }
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
			$$=c->values[0];
		}
		c=c->next;
	}
	if (!fin) $$=0;
}
 }
 | IDENTIFIER PO expr PF {
	int fin=0;
	struct var* c=r;
	while(c) {
		if (strcmp(c->name,identifier)==0) {
			fin=1;
			$$=c->values[(int)$3];
		}
		c=c->next;
	}
	if (!fin) $$=0;
 }
 | COS PO { if (!im) strcat(lines[l],"cos(");  } expr PF { if (im) $$=cos($4); else strcat(lines[l],")"); }
 | SIN PO { if (!im) strcat(lines[l],"sin(");  } expr PF { if (im) $$=sin($4); else strcat(lines[l],")"); }
 | TAN PO expr PF { if (im) $$=tan($3); }
 | SQR PO { if (!im) strcat(lines[l],"sqrt("); } expr PF { if (im) $$=sqrt($4); else strcat(lines[l],")"); }
 | EXP PO expr PF { if (im) $$=exp($3); }
 | MINUS { if (!im) strcat(lines[l],"-"); } expr { if (im) $$=-$3; }
 | ASC PO CHAINE PF
 | RND PO { if (!im) 
#ifdef WIN32
strcat(lines[l],"(float)rand()/RAND_MAX");
#else
strcat(lines[l],"(float)drand48()*");
#endif
} expr PF { if (im) $$=(float)drand48(); }
 | INT { if (!im) strcat(lines[l],"roundf("); } PO expr PF { if (im) $$=(int)$4; else strcat(lines[l],")");  }
 | PEEK PO expr PF { if (im) $$=page0[(int)$3]; }
 ;

%%
#include"lex.yy.c"
void  yyerror(char *s) {
if (im) 
	fprintf(stderr,"%s on %d\n",s,yychar);
else
	fprintf(stderr,"%s on %d line %d\n",s,yychar,l);
	yyparse();
}

int main(int argc,char * argv[]) {
char rcsrev[]="$Revision: 1.3 $";
string=malloc(1024);

strtok(rcsrev,".");
r=(struct var*)malloc(sizeof(struct var));
strcpy(r->name,"HCOLOR");
r->values=malloc(sizeof(float));
r->size=1;
r->values[0]=7;
r2=(struct var*)malloc(sizeof(struct var));
r->next=r2;
r2->values=malloc(sizeof(float));
r2->size=1;
r2->values[0]=atof(strtok(NULL,"."));
r2->next=NULL;
strcpy(r2->name,"VERSION");
#ifdef WIN32
srand(12345);
#else
srand48(12345);
#endif
temp = SDL_LoadBMP("/usr/lib64/sprite.bmp");
if (temp) {
	sprite = SDL_CreateTextureFromSurface(renderer, temp);
} else {
	fprintf(stderr, "Error /usr/lib64/sprite.bmp\n");
}

yyparse();
fprintf(stderr,"FIN\n");
}

int WinMain() {
char rcsrev[]="$Revision: 1.3 $";
string=malloc(1024);

strtok(rcsrev,".");
r=(struct var*)malloc(sizeof(struct var));
strcpy(r->name,"HCOLOR");
r->values=malloc(sizeof(float));
r->size=1;
r->values[0]=7;
r2=(struct var*)malloc(sizeof(struct var));
r->next=r2;
r2->values=malloc(sizeof(float));
r2->size=1;
r2->values[0]=atof(strtok(NULL,"."));
r2->next=NULL;
strcpy(r2->name,"VERSION");
}

int yywrap() {
    yypop_buffer_state();
    if (!YY_CURRENT_BUFFER) {
        return 1;
    }
    return 0;
}

int process(char *s) {
	return 0;
}

int basic2c(FILE *fp) {
	int v;
	fprintf(fp,"#include<stdio.h>\n");
	fprintf(fp,"#include<setjmp.h>\n");
	fprintf(fp,"#include<stdlib.h>\n");
	fprintf(fp,"#include<string.h>\n");
	fprintf(fp,"#include<math.h>\n");

	fprintf(fp,"jmp_buf stack[100]; int sp=0;\n");

	fprintf(fp,"void main(int argc, char * argv[]) {\n");
	fprintf(fp,"char s[1024];\n");

	fprintf(fp,"float VERSION=%f;\n",r2->values[0]);
#ifdef WIN32
	fprintf(fp,"srand(time(NULL));\n");
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
	return 0;
}

void destroy() {
}
