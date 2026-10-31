%{
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<sys/time.h>
#include<time.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/ioctl.h>
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
struct str *ds;
struct str * root = NULL;
struct str *D;
int c=0;
float cv;
int cx,cy;
char lines[65536][512];
char mem[65536];
#include<sys/ioctl.h>
#include<termios.h>

static struct termios orig_t;
static int orig_t_saved = 0;
static int tty_fd = -1;

static void restore_terminal() {
    if (orig_t_saved && tty_fd != -1) {
        tcsetattr(tty_fd, TCSANOW, &orig_t);
    }
}

int peek_func(int addr) {
    if (addr == 49152) {
        static FILE *tty = NULL;
        static int initialized = 0;
        if (!tty) {
            tty = fopen("/dev/tty", "r+");
            if (!tty) tty = stdin;
        }
        tty_fd = fileno(tty);
        if (!initialized && isatty(tty_fd)) {
            tcgetattr(tty_fd, &orig_t);
            orig_t_saved = 1;
            atexit(restore_terminal);

            struct termios t = orig_t;
            t.c_lflag &= ~(ICANON | ECHO);
            tcsetattr(tty_fd, TCSANOW, &t);
            initialized = 1;
        }
        int bytes = 0;
        ioctl(tty_fd, FIONREAD, &bytes);
        if (bytes > 0) {
            int c = fgetc(tty);
            mem[49152] = (char)(c | 0x80);
        }
        int val = (unsigned char)mem[addr];
        mem[49152] &= ~0x80;
        return val;
    }
    return (unsigned char)mem[addr];
}
char aux[65536];
char aux1[1024];
char aux2[1024];
int im=1;
int gr=0;
int l=0;
int notdef=1;
extern char * yytext;
extern void destroy();
char s[1024];
int trace=0;
void yyerror(char *s);
int basic2c(FILE *fp);
int yylex();
char oper[4];
int infor=0;
int color=2;
int plot_len;
float data_values[4096];
int data_count = 0;
int data_ptr = 0;
%}
%token DEL
%token CREATE
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
%token CATALOG
%token PREFIX
%token STORE
%token RESTORE
%left PLUS MINUS
%left ASTERISK DIVIDE
%nonassoc UMINUS
%%
pgm: 
 | pgm line { if (!gr || !im) printf("]"); } CR
 | pgm CR { if (!gr || !im) printf("]"); }
 ;

line: NUMBER { im=0; l=atoi(yytext); strcpy(lines[l],""); } insts { if (!im&&!infor) strcat(lines[l],";"); else infor=0;  }
 |	{ im=1; } insts
 ;

insts : inst
	| insts DP  { strcat(lines[l],";"); } inst
	| { lines[l][0]=0; }
	;

inst: PRINT multi_expr { if (im) printf("%s\n",cstr); } opt_print { if (!im) strcat(lines[l],";printf(\"\\n\")"); }

 | opt_let IDENTIFIER { 
	notdef=1; 
	d=r; 
	while(d) { 
		if (strcmp(d->name,identifier)==0) { notdef=0; break; } 
		d=d->next; 
	} 
	if (notdef) {
		if (!im) strcat(lines[l],"float "); 
		d=(struct var*)malloc(sizeof(struct var));
		d->values=malloc(sizeof(float));
		d->size=1;
		d->values[0]=0; 
		strcpy(d->name,identifier); 
		d->next=r; 
		r=d;
	}
	strcpy(a,identifier); 
} EQUAL { 
	if (!im) {
		strcat(lines[l],identifier);
		strcat(lines[l],"=");  
	}
} expr { 
	if (im) {
		d=r;
		while(d) {
			if (strcmp(d->name,a)==0) {
				d->values[0]=$6;
				break;
			}
			d=d->next;
		}
		if (strncmp(a,"COLOR",5)==0) {
			color=(int)$6;
			mem[48]=color;
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
		res=system("gcc soft.c -lm");
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
		res=system("rm a.out soft.c");
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
 | INPUT opt_prompt CHAINE { if (!im) sprintf(lines[l],"%schar %s[256];fgets(%s,256,stdin)",lines[l],identifier,identifier); else fprintf(stderr,"NO DIRECT COMMAND\n");  } 
 | INPUT opt_prompt CHAINE PO expr PF { if (!im) sprintf(lines[l],"%schar %s[256];fgets(%s,256,stdin)",lines[l],identifier,identifier);  else fprintf(stderr,"NO DIRECT COMMAND\n"); } 
 | HTAB {
     if (!im) {
         plot_len = strlen(lines[l]);
     }
 } expr {
     if (im) {
         printf("%c[%dG", 27, (int)$3);
     } else {
         char expr_code[256];
         strcpy(expr_code, lines[l] + plot_len);
         lines[l][plot_len] = '\0';
         sprintf(lines[l] + strlen(lines[l]), "printf(\"%%c[%%dG\", 27, (int)(%s))", expr_code);
     }
 }
 | VTAB {
     if (!im) {
         plot_len = strlen(lines[l]);
     }
 } expr {
     if (im) {
         printf("%c[%dd", 27, (int)$3);
     } else {
         char expr_code[256];
         strcpy(expr_code, lines[l] + plot_len);
         lines[l][plot_len] = '\0';
         sprintf(lines[l] + strlen(lines[l]), "printf(\"%%c[%%dd\", 27, (int)(%s))", expr_code);
     }
 }
 | HOME { if (im) 
#ifdef WIN32
system("cls");
#else /* ANSI */
printf("%c[2J",27);
#endif
else strcat (lines[l],"printf(\"%c[2J\",27)");   }
 | TEXT { if (im) { gr=0; } }
 | GR { if (im) {
	gr=1;
	printf("%c[2J",27);
} else {
	strcat(lines[l],"printf(\"%c[2J\",27);");
}}
 | HGR { if (im) {
	fprintf(stderr,"NO GRAPHICS ERROR USE GRSOFT!\n");
} }
 | DIM IDENTIFIER PO expr PF {
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
 | DIM CHAINE PO expr PF {
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
 | POKE expr COMMA expr { if (im) { mem[(int)$2]=(char)$4; } }
 | GET CHAINE { if (im) fprintf(stderr,"DIRECT ERROR\n"); }
 | FOR { infor = 1; } IDENTIFIER EQUAL { if (!im) {
sprintf(lines[l],"%sfor(float %s=", lines[l], identifier);  }
 } expr TO { if (!im) strcat(lines[l],";");strcat(lines[l],identifier);strcat(lines[l],"<="); }
 expr { if (!im) strcat(lines[l],";"); strcat(lines[l],identifier);strcat(lines[l],"++){"); }
 | NEXT { if (!im) strcat(lines[l],"}"); } opt_var
 | DATA {
     if (!im) {
         plot_len = strlen(lines[l]);
     }
 } list {
     if (!im) {
         lines[l][plot_len] = '\0';
         strcat(lines[l], "/* DATA */");
     }
 }
 | READ IDENTIFIER {
     struct var *v;
     int found = 0;
     if (im) {
         struct var *d = r;
         while(d) {
             if (strcmp(d->name, identifier) == 0) {
                 found = 1;
                 if (data_ptr < data_count) {
                     d->values[0] = data_values[data_ptr++];
                 } else {
                     fprintf(stderr, "OUT OF DATA ERROR\n");
                 }
                 break;
             }
             d = d->next;
         }
         if (!found) {
             d = (struct var*)malloc(sizeof(struct var));
             strcpy(d->name, identifier);
             d->values = malloc(sizeof(float));
             d->size = 1;
             if (data_ptr < data_count) {
                 d->values[0] = data_values[data_ptr++];
             } else {
                 d->values[0] = 0;
                 fprintf(stderr, "OUT OF DATA ERROR\n");
             }
             d->next = r;
             r = d;
         }
     } else {
         notdef = 1;
         struct var *d = r;
         while(d) {
             if (strcmp(d->name, identifier) == 0) {
                 notdef = 0;
                 break;
             }
             d = d->next;
         }
         if (notdef) {
             strcat(lines[l], "float ");
             d = (struct var*)malloc(sizeof(struct var));
             d->values = malloc(sizeof(float));
             d->size = 1;
             d->values[0] = 0;
             strcpy(d->name, identifier);
             d->next = r;
             r = d;
         }
         char buf[256];
         sprintf(buf, "%s=data_values[data_ptr++]", identifier);
         strcat(lines[l], buf);
     }
 }
 | RETURN { if (!im) strcat(lines[l],"longjmp(stack[--sp],1)"); }
 | END { if (!im) strcat(lines[l],"return"); else return 0;  }
 | PLOT {
     if (!im) {
         plot_len = strlen(lines[l]);
     }
 } expr {
     if (!im) {
         strcpy(aux1, lines[l] + plot_len);
         lines[l][plot_len] = '\0';
     }
 } COMMA expr {
     if (im) {
         printf("%c[4%dm%c[%d;%dH ",27,color,27,(int)$6,(int)$3);
     } else {
         char y_code[512];
         strcpy(y_code, lines[l] + plot_len);
         sprintf(lines[l] + plot_len, "printf(\"%%c[4%%dm%%c[%%d;%%dH \",27,(int)COLOR,27,(int)(%s),(int)(%s))", y_code, aux1);
     }
 }
 | HPLOT { fprintf(stderr,"USE GRSOFT\n"); }  expr COMMA expr
 | HLIN {
     if (!im) {
         plot_len = strlen(lines[l]);
     }
 } expr {
     if (!im) {
         strcpy(aux1, lines[l] + plot_len);
         lines[l][plot_len] = '\0';
     }
 } COMMA expr {
     if (!im) {
         strcpy(aux2, lines[l] + plot_len);
         lines[l][plot_len] = '\0';
     }
 } AT expr {
     if (im) {
         for(int p=(int)$3; p<=(int)$6; p++)
             printf("%c[4%dm%c[%d;%dH ",27,color,27,(int)$9,p);
     } else {
         char y_code[512];
         strcpy(y_code, lines[l] + plot_len);
         sprintf(lines[l] + plot_len, "for(int p=(int)(%s); p<=(int)(%s); p++) printf(\"%%c[4%%dm%%c[%%d;%%dH \",27,(int)COLOR,27,(int)(%s),p)", aux1, aux2, y_code);
     }
 }
 | VLIN {
     if (!im) {
         plot_len = strlen(lines[l]);
     }
 } expr {
     if (!im) {
         strcpy(aux1, lines[l] + plot_len);
         lines[l][plot_len] = '\0';
     }
 } COMMA expr {
     if (!im) {
         strcpy(aux2, lines[l] + plot_len);
         lines[l][plot_len] = '\0';
     }
 } AT expr {
     if (im) {
         for(int p=(int)$3; p<=(int)$6; p++)
             printf("%c[4%dm%c[%d;%dH ",27,color,27,p,(int)$9);
     } else {
         char y_code[512];
         strcpy(y_code, lines[l] + plot_len);
         sprintf(lines[l] + plot_len, "for(int p=(int)(%s); p<=(int)(%s); p++) printf(\"%%c[4%%dm%%c[%%d;%%dH \",27,(int)COLOR,27,p,(int)(%s))", aux1, aux2, y_code);
     }
 }
 | SAVE filename {
	if (im) {
		FILE * fp;
		fprintf(stderr,"saving %s\n",identifier);
		fp=fopen(identifier,"w");
		if (fp==NULL)
			fprintf(stderr,"erreur %s\n",identifier);
		else {
			for(int i=0;i<65536;i++) if (strcmp(lines[i],"")) fprintf(fp,"L%d: %s\n",i,lines[i]);
			fclose(fp);
		}
 }
 }
 | LOAD filename {
     if (im) {
         FILE *fp;
         fprintf(stderr, "loading %s\n", identifier);
         fp = fopen(identifier, "r");
         if (fp == NULL) {
             fprintf(stderr, "I/O ERROR\n");
         } else {
             for(int i=0; i<65536; i++) strcpy(lines[i], "");
             char buf[1024];
             int f = 0;
             int l_num = 0;
             while (fgets(buf, sizeof(buf), fp) != NULL) {
                 if (sscanf(buf, "L%d: %[^\n]", &l_num, lines[l_num]) == 2) {
                     size_t len = strlen(lines[l_num]);
                     if (len > 0 && lines[l_num][len-1] == '\r') {
                         lines[l_num][len-1] = '\0';
                     }
                     f++;
                 }
             }
             fclose(fp);
             fprintf(stderr, "%d lines read\n", f);
         }
     }
 }
 | CALL NUMBER { fprintf(stderr,"unimp.\n"); }
 | CATALOG { int res; if (im) res=system("ls -la"); }
 | PREFIX {
     if (im) {
         char cwd[1024];
         if (getcwd(cwd, sizeof(cwd))) {
             printf("%s\n", cwd);
         }
     }
 }
 | PREFIX IDENTIFIER { if (im) { if (chdir(identifier) < 0) fprintf(stderr, "I/O ERROR\n"); } }
 | CREATE IDENTIFIER {
     if (im) {
         if (mkdir(identifier, 0755) < 0) {
             fprintf(stderr, "I/O ERROR\n");
         }
     }
 }
 | DEL filename {
     if (im) {
         if (unlink(identifier) < 0 && rmdir(identifier) < 0) {
             fprintf(stderr, "I/O ERROR\n");
         }
     }
 }
 | STORE IDENTIFIER { fprintf(stderr,"unimp.\n"); }
 | RESTORE IDENTIFIER { fprintf(stderr,"unimp.\n"); }
 | NEW { for(int i=0;i<65536;i++) strcpy(lines[i],""); data_count=0; data_ptr=0; }
 | DRAW expr AT expr COMMA expr
 | CLEAR { if (im) { r=NULL; root=NULL; data_ptr=0; } }
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
	  | CHARS SEMICOLOMN
	;

opt_then:
	| THEN
	;

opt_var:
	| IDENTIFIER
	;

list: expr {
    data_values[data_count++] = $1;
}
| list COMMA expr {
    data_values[data_count++] = $3;
}
;

cond: { strcat(lines[l]," ( "); } expr oper { strcat(lines[l],oper); } expr { strcat(lines[l]," ) "); }
	| PEEK PO expr PF
	| PO cond PF
	| cond OR cond
 	| NOT cond
	| { if (!im) strcat(lines[l],"(strcmp("); } sexpr EQUAL { if (!im) strcat(lines[l],","); } sexpr { if (!im) strcat(lines[l],")==0) "); }
;

oper: EQUAL { strcpy(oper,"=="); }
	| PG { strcpy(oper,">"); }
	| PP { strcpy(oper,"<"); }
	| GE { strcpy(oper,">="); }
	| PE { strcpy(oper,"<="); }
	;

sarg: string { if (im) strcpy(cstr, string); }
	| string PO { if (!im) {
		strcat(lines[l], "[");
	} } expr PF { if (!im) strcat(lines[l],"]"); }
	| CHARS { if (!im) strcat(lines[l],chars); else { strcpy(string,chars+1);string[strlen(string)-1]=0; } }
	;

func_args: sarg COMMA { if (!im) strcat(lines[l],","); } expr ;
func_args3: sarg COMMA { if (!im) strcat(lines[l],","); } expr COMMA { if (!im) strcat(lines[l],","); } expr ;

sexpr: sarg
	| sexpr PLUS string { if (im) strcat(cstr, identifier); }
	| MID { if (!im) strcat(lines[l],"mid_str("); } PO func_args3 PF { if (im) {} else strcat(lines[l],")"); }
	| LEFT { if (!im) strcat(lines[l],"left_str("); } PO func_args PF { if (im) {} else strcat(lines[l],")"); }
	| RIGHT { if (!im) strcat(lines[l],"right_str("); } PO func_args PF { if (im) {} else strcat(lines[l],")"); }
	| STR PO expr PF { if (im) sprintf(cstr, "%g", $3); }
	;

multi_expr: { if (!im) strcat(lines[l],"printf(\"%f\","); } expr { if (im) {
	  $$=$2;
	sprintf(cstr, "%f", $2);
} else
	strcat(lines[l],")");
}
	| { if (!im) strcat(lines[l],"printf(\"%s\","); } sexpr { strcpy(cstr,string);
	strcat(lines[l],")");
 }
        | { if (!im) strcat(lines[l],"printf(\"%c\","); } CHR PO { if (!im) strcat(lines[l],"(int)"); } expr PF { if (im) sprintf(cstr, "%c", (int)$5);
	strcat(lines[l],")");
 }
	| { printf("\n"); }
	;

opt_print: { if (!im) strcat(lines[l],""); }
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
			$$=*(c->values);
		}
		c=c->next;
	}
	if (!fin) $$=0;
}
 }
 | IDENTIFIER PO expr PF {
	if (im)  {
		struct var *d = r;
		while(d) {
			if (strcmp(d->name, identifier) == 0) {
				if (d->type == ARRAY) {
					int idx =(int)$3;
					$$= d->values[idx];
					break;
				}
			}
			d = d->next;
		}
	}
 }
 | COS PO { if (!im) strcat(lines[l],"cos(");  } expr PF { if (im) $$=cos($4); else strcat(lines[l],")"); }
 | SIN PO { if (!im) strcat(lines[l],"sin(");  } expr PF { if (im) $$=sin($4); else strcat(lines[l],")"); }
 | TAN PO { if (!im) strcat(lines[l],"tan(");  } expr PF { if (im) $$=tan($4); else strcat(lines[l],")"); }
 | SQR PO { if (!im) strcat(lines[l],"sqrt("); } expr PF { if (im) $$=sqrt($4); else strcat(lines[l],")"); }
 | EXP PO expr PF { if (im) $$=exp($3); }
 | MINUS { if (!im) strcat(lines[l],"-"); } expr %prec UMINUS { if (im) $$=-$3; }
 | ASC PO CHAINE PF
 | RND PO { if (!im) 
#ifdef WIN32
strcat(lines[l],"(float)rand()/RAND_MAX");
#else
strcat(lines[l],"(float)drand48()*");
#endif
} expr PF { if (im) $$=(float)drand48(); }
 | INT { if (!im) strcat(lines[l],"roundf("); } PO expr PF { if (im) $$=(int)$4; else strcat(lines[l],")");  }
 | PEEK PO { if (!im) strcat(lines[l],"peek_func("); } expr PF { if (im) { int addr = (int)$4; if (addr == 49152) { int bytes = 0; ioctl(0, FIONREAD, &bytes); if (bytes > 0) { char c = getchar(); mem[49152] = (char)(c | 0x80); } } $$ = (unsigned char)mem[addr]; if (addr == 49152) { mem[49152] &= ~0x80; } } else { strcat(lines[l], ")"); } }
 | LEN PO { if (!im) strcat(lines[l],"strlen("); } sarg PF { if (im) $$=strlen(string); else strcat(lines[l],")"); }
;

filename: IDENTIFIER { strcpy(a,identifier); }
	| IDENTIFIER { strcpy(a,identifier); } DOT extension { strcat (a,".bas"); strcpy(identifier,a); };

extension: IDENTIFIER 
	;

%%
#include"lex.yy.c"
void  yyerror(char *s) {
if (im) 
	fprintf(stderr,"%s on %s at %d\n",s,yytname[yychar-255],ll);
else
	fprintf(stderr,"%s on %s line %d\n",s,yytname[yychar-255],l);
	printf(PROMPT);
	yyparse();
}

char rcsrev[]="$Revision: 1.35 $";
struct var *r2;

int main(int argc,char * argv[]) {
int ch;
string=malloc(1024);

while ((ch = getopt(argc,argv,"d")) != -1) {
	switch(ch) {
	case 'd':
		yydebug=1;
		break;
	}
}

if (argc>1) {
	yyin=fopen(argv[1],"r");
	if (!yyin)
		fprintf(stderr,"Error opening %s\n",argv[1]);
	else {
		yypush_buffer_state(yy_create_buffer(yyin,YY_BUF_SIZE));
	}
}

srand48(time(NULL));
strtok(rcsrev,".");
r=(struct var*)malloc(sizeof(struct var));
strcpy(r->name,"COLOR");
r->values=malloc(sizeof(float));
r->size=1;
r->values[0]=2; /* bleu */
r2=(struct var*)malloc(sizeof(struct var));
r->next=r2;
r2->values=malloc(sizeof(float));
r2->size=1;
r2->values[0]=atoi(strtok(NULL,"."));
r2->next=NULL;
strcpy(r2->name,"VERSION");
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

strtok(rcsrev,".");
r=(struct var*)malloc(sizeof(struct var));
strcpy(r->name,"HCOLOR");
r->values=malloc(sizeof(float));
r->size=1;
r->values[0]=7;
r->next=(struct var*)malloc(sizeof(struct var));
r->next->values=malloc(sizeof(float));
r->next->size=1;
r->next->values[0]=atof(strtok(NULL,"."));
r->next->next=NULL;
strcpy(r->next->name,"VERSION");

srand(12345);
printf(PROMPT);
fflush(stdout);
return yyparse();
}

int yywrap() {
    yypop_buffer_state();
    
    /* Si YY_CURRENT_BUFFER est NULL, la pile est vide (fin globale) */
    if (!YY_CURRENT_BUFFER) {
        return 1; /* 1 = arrêt de l'analyse lexicale */
    }
    
    return 0; /* 0 = continuer l'analyse avec le buffer dépilé */
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
	fprintf(fp,"#include<unistd.h>\n");
	fprintf(fp,"#include<sys/ioctl.h>\n");
	fprintf(fp,"#include<termios.h>\n");
	fprintf(fp,"unsigned char mem[65535];\n");
	fprintf(fp,"static struct termios orig_t;\n");
	fprintf(fp,"static int orig_t_saved = 0;\n");
	fprintf(fp,"static int tty_fd = -1;\n");
	fprintf(fp,"static void restore_terminal() {\n");
	fprintf(fp,"    if (orig_t_saved && tty_fd != -1) {\n");
	fprintf(fp,"        tcsetattr(tty_fd, TCSANOW, &orig_t);\n");
	fprintf(fp,"    }\n");
	fprintf(fp,"}\n");

	fprintf(fp,"int peek_func(int addr) {\n");
	fprintf(fp,"    if (addr == 49152) {\n");
	fprintf(fp,"        static FILE *tty = NULL;\n");
	fprintf(fp,"        static int initialized = 0;\n");
	fprintf(fp,"        if (!tty) {\n");
	fprintf(fp,"            tty = fopen(\"/dev/tty\", \"r+\");\n");
	fprintf(fp,"            if (!tty) tty = stdin;\n");
	fprintf(fp,"        }\n");
	fprintf(fp,"        tty_fd = fileno(tty);\n");
	fprintf(fp,"        if (!initialized && isatty(tty_fd)) {\n");
	fprintf(fp,"            tcgetattr(tty_fd, &orig_t);\n");
	fprintf(fp,"            orig_t_saved = 1;\n");
	fprintf(fp,"            atexit(restore_terminal);\n");
	fprintf(fp,"            struct termios t = orig_t;\n");
	fprintf(fp,"            t.c_lflag &= ~(ICANON | ECHO);\n");
	fprintf(fp,"            tcsetattr(tty_fd, TCSANOW, &t);\n");
	fprintf(fp,"            initialized = 1;\n");
	fprintf(fp,"        }\n");
	fprintf(fp,"        int bytes = 0;\n");
	fprintf(fp,"        ioctl(tty_fd, FIONREAD, &bytes);\n");
	fprintf(fp,"        if (bytes > 0) {\n");
	fprintf(fp,"            int c = fgetc(tty);\n");
	fprintf(fp,"            mem[49152] = (char)(c | 0x80);\n");
	fprintf(fp,"        }\n");
	fprintf(fp,"        int val = (unsigned char)mem[addr];\n");
	fprintf(fp,"        mem[49152] &= ~0x80;\n");
	fprintf(fp,"        return val;\n");
	fprintf(fp,"    }\n");
	fprintf(fp,"    return (unsigned char)mem[addr];\n");
	fprintf(fp,"}\n");

	fprintf(fp,"char* left_str(const char* s, int n) {\n");
	fprintf(fp,"    static char buf[1024];\n");
	fprintf(fp,"    if (!s) return \"\";\n");
	fprintf(fp,"    int len = strlen(s);\n");
	fprintf(fp,"    if (n < 0) n = 0;\n");
	fprintf(fp,"    if (n > len) n = len;\n");
	fprintf(fp,"    strncpy(buf, s, n);\n");
	fprintf(fp,"    buf[n] = '\\0';\n");
	fprintf(fp,"    return buf;\n");
	fprintf(fp,"}\n");

	fprintf(fp,"char* right_str(const char* s, int n) {\n");
	fprintf(fp,"    static char buf[1024];\n");
	fprintf(fp,"    if (!s) return \"\";\n");
	fprintf(fp,"    int len = strlen(s);\n");
	fprintf(fp,"    if (n < 0) n = 0;\n");
	fprintf(fp,"    if (n > len) n = len;\n");
	fprintf(fp,"    strncpy(buf, s + len - n, n);\n");
	fprintf(fp,"    buf[n] = '\\0';\n");
	fprintf(fp,"    return buf;\n");
	fprintf(fp,"}\n");

	fprintf(fp,"char* mid_str(const char* s, int start, int n) {\n");
	fprintf(fp,"    static char buf[1024];\n");
	fprintf(fp,"    if (!s) return \"\";\n");
	fprintf(fp,"    int len = strlen(s);\n");
	fprintf(fp,"    if (start < 1) start = 1;\n");
	fprintf(fp,"    int idx = start - 1;\n");
	fprintf(fp,"    if (idx > len) idx = len;\n");
	fprintf(fp,"    if (n < 0) n = 0;\n");
	fprintf(fp,"    if (idx + n > len) n = len - idx;\n");
	fprintf(fp,"    strncpy(buf, s + idx, n);\n");
	fprintf(fp,"    buf[n] = '\\0';\n");
	fprintf(fp,"    return buf;\n");
	fprintf(fp,"}\n");

	fprintf(fp,"jmp_buf stack[100]; int sp=0;\n");

	fprintf(fp,"void main(int argc, char * argv[]) {\n");
	fprintf(fp,"char s[1024];\n");

	fprintf(fp,"float data_values[] = {");
	for(int i=0; i<data_count; i++) {
		fprintf(fp,"%f%s", data_values[i], (i < data_count - 1) ? "," : "");
	}
	fprintf(fp,"};\n");
	fprintf(fp,"int data_ptr = 0;\n");

	fprintf(fp,"float COLOR=0;\n");
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
//	gtk_main_quit();
}
/*
GTypeInstance* g_type_check_instance_cast(GTypeInstance *i,GType iface) {
return i;
}
*/
