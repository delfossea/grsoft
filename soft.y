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
#include<ctype.h>
/*
int yydebug=1;
*/
#define YYDEBUG 1
#define YYSTYPE float
#define PROMPT "]"
int dos=0;
int ll=0;
char identifier[256];
char a[512];
char chars[256];
char fvar[80];
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
struct open_file {
    char name[256];
    FILE *fp;
    struct open_file *next;
};
struct open_file *open_files = NULL;
FILE *current_file = NULL;
FILE *output_file = NULL;
FILE *input_file = NULL;
float cond_lhs = 0;
int execute_actions = 1;
int c=0;
float cv;
int cx,cy;
char lines[65536][512];
char mem[65536];
#ifndef WIN32
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
#else
#include<conio.h>
#endif

int peek_func(int addr) {
    if (addr == 49152) {
#ifdef WIN32
        if (_kbhit()) {
            int c = _getch();
            mem[49152] = (char)(c | 0x80);
        }
        int val = (unsigned char)mem[addr];
        mem[49152] &= ~0x80;
        return val;
#else
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
#endif
    }
    return (unsigned char)mem[addr];
}
char aux[65536];
char aux1[1024];
char aux2[1024];
int im=1;
int l=0;
int notdef=1;
extern char * yytext;
char s[1024];
int trace=0;
void yyerror(char *s);
int basic2c(FILE *fp);
int yylex();
char oper[4];
char ext[40];
int infor=0;
int color=2;
int bcolor=0;
int plot_len;
float data_values[4096];
int data_count = 0;
int data_ptr = 0;
typedef struct yy_buffer_state *YY_BUFFER_STATE;
YY_BUFFER_STATE yy_scan_string (const char * yy_str);
void yy_delete_buffer (YY_BUFFER_STATE b);
void yy_switch_to_buffer (YY_BUFFER_STATE new_buffer);
void yy_push_buffer_state (YY_BUFFER_STATE b);
void yy_pop_buffer_state (void);
char *soft_readline(const char *prompt);
void soft_add_history(const char *line);
int p[512][512];


float eval_cond(float v1, const char* op, float v2) {
    if (strcmp(op, "==") == 0) return (v1 == v2) ? 1.0 : 0.0;
    if (strcmp(op, ">") == 0) return (v1 > v2) ? 1.0 : 0.0;
    if (strcmp(op, "<") == 0) return (v1 < v2) ? 1.0 : 0.0;
    if (strcmp(op, ">=") == 0) return (v1 >= v2) ? 1.0 : 0.0;
    if (strcmp(op, "<=") == 0) return (v1 <= v2) ? 1.0 : 0.0;
    return 0.0;
}

char* left_str(const char* s, int n) {
    static char buf[1024];
    if (!s) return "";
    int len = strlen(s);
    if (n < 0) n = 0;
    if (n > len) n = len;
    strncpy(buf, s, n);
    buf[n] = '\0';
    return buf;
}

char* right_str(const char* s, int n) {
    static char buf[1024];
    if (!s) return "";
    int len = strlen(s);
    if (n < 0) n = 0;
    if (n > len) n = len;
    strncpy(buf, s + len - n, n);
    buf[n] = '\0';
    return buf;
}

char* mid_str(const char* s, int start, int n) {
    static char buf[1024];
    if (!s) return "";
    int len = strlen(s);
    if (start < 1) start = 1;
    int idx = start - 1;
    if (idx > len) idx = len;
    if (n < 0) n = 0;
    if (idx + n > len) n = len - idx;
    strncpy(buf, s + idx, n);
    buf[n] = '\0';
    return buf;
}

float for_start_val = 0;
float for_limit_val = 0;
float for_step_val = 1;
char for_var_name[80];
float func_arg1 = 0;
float func_arg2 = 0;

char file_buffer[65536] = {0};

char *find_matching_next(char *p) {
    int depth = 1;
    char *curr = p + 3;
    while (*curr != '\0' && depth > 0) {
        if ((curr == file_buffer || !isalpha((unsigned char)curr[-1])) &&
            strncasecmp(curr, "FOR", 3) == 0 && !isalpha((unsigned char)curr[3])) {
            depth++;
            curr += 3;
        } else if ((curr == file_buffer || !isalpha((unsigned char)curr[-1])) &&
                   strncasecmp(curr, "NEXT", 4) == 0 && !isalpha((unsigned char)curr[4])) {
            depth--;
            if (depth == 0) return curr;
            curr += 4;
        } else {
            curr++;
        }
    }
    return NULL;
}

struct loop_info {
    char var_name[80];
    float limit;
    float step;
    char *body_start;
    char *body_end;
};
struct loop_info im_loop_stack[32];
int im_loop_sp = 0;
%}
%token DEL
%token CREATE
%token PR
%token STR
%token NOTRACE
%token SAVE
%token OPEN
%token CLOSE
%token WRITE
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
%left OR
%left AND
%nonassoc NOT
%%
pgm:
 | pgm line CR
 | pgm CR
 ;

line: NUMBER { im=0; l=atoi(yytext); strcpy(lines[l],""); } insts { if (!im&&!infor) strcat(lines[l],";"); else infor=0;  }
 |	{ im=1; } insts
 ;

insts : inst
		| insts DP  { strcat(lines[l],";"); } inst
		| { lines[l][0]=0; }
		;

inst: PRINT multi_expr {
    if (im && execute_actions) {
        fprintf(output_file, "%s", cstr);
        if (cstr[0]==4) 
            fprintf(stderr,"DOS\n");
    }
} opt_print {
    if (im && execute_actions) {
        fprintf(output_file, "\n");
    }
    if (!im) strcat(lines[l],";printf(\"\\n\")");
}

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

 | opt_let IDENTIFIER PO {
		if (!im) {
			strcat(lines[l], identifier);
			strcat(lines[l], "[(int)");
		}
		strcpy(a, identifier);
	} expr {
		if (!im) {
			strcat(lines[l], "]=");
		}
	} PF EQUAL expr {
		if (im && execute_actions) {
			d = r;
			while (d && strcmp(d->name, a) != 0)
				d = d->next;
			if (d) {
				int idx = (int)$5;
				d->values[idx] = $9;
			}
		}
	 }
	 | CHAINE { strcpy(A,yytext); }  EQUAL sexpr { if (im) {
		D=(struct str*)malloc(sizeof(struct str));
		D->size=1;
		D->type=STRING;
		D->values = malloc(sizeof(char *));
		D->values[0]=(char*)malloc(1024);
		strcpy(D->values[0],cstr);strncpy(D->name,A,strlen(A)-1); D->next=root; root=D;
	} else {
		char varname[80];
		strcpy(varname, String);
		varname[strlen(varname)-1] = 0;
		sprintf(lines[l], "char *%s = %s;", varname, chars);
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
			sprintf(buf, "%s[(int)", varname);
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
			if (!res) res=system("./a.out");
	#endif
	#ifdef WIN32
			system("del a.exe");
	#else
			if (!res) res=system("rm a.out soft.c");
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
	 | IF {
	     if (!im) strcat(lines[l],"if ");
	 } cond opt_then {
	     if (im) {
	         execute_actions = ($3 != 0.0);
	     }
	     if (!im) strcat(lines[l],"{");
	 } insts {
	     if (im) {
	         execute_actions = 1;
	     }
	     if (!im) strcat(lines[l],";}");
	 } opt_else
	 | GOTO { strcat(lines[l],"goto L"); } expr
	 | GOSUB { if (!im) strcat(lines[l],"if (!setjmp(stack[sp++])) goto L"); } expr
	 | INPUT opt_prompt { if (!im) strcat(lines[l],"fgets(s,1024,stdin);float "); } IDENTIFIER opt_index {
	     if (im && execute_actions) {
	         char buf[1024];
	         if (fgets(buf, sizeof(buf), input_file)) {
	             buf[strcspn(buf, "\r\n")] = 0;
	             float val = atof(buf);
	             notdef = 1;
	             d = r;
	             while (d) {
	                 if (strcmp(d->name, identifier) == 0) {
	                     notdef = 0;
	                     d->values[0] = val;
	                     break;
	                 }
	                 d = d->next;
	             }
	             if (notdef) {
	                 d = (struct var*)malloc(sizeof(struct var));
	                 d->values = malloc(sizeof(float));
	                 d->size = 1;
	                 d->values[0] = val;
	                 strcpy(d->name, identifier);
	                 d->next = r;
	                 r = d;
	             }
	         }
	     } else if (!im) {
	         strcat(lines[l],identifier);
	         strcat(lines[l],"=atof(s)");
	     }
	 }
	 | INPUT opt_prompt CHAINE opt_index { if (!im) { String[strlen(String)-1]=0;
if (strcmp(chars,""))
	sprintf(lines[l],"%sprintf(%s);char %s[256];fgets(%s,256,stdin)",lines[l],chars,String,String);
	else sprintf(lines[l],"%schar %s[256];fgets(%s,256,stdin)",lines[l],String,String);
 } else fprintf(stderr,"NO DIRECT COMMAND\n");  }
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
	 | TEXT { if (im) { fprintf(stderr,"Already in text mode\n"); } }
	 | GR { if (im) {
		printf("%c[40m,%c[2J",27,27);
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
			} else { sprintf(lines[l],"float %s[%d]",identifier,(int)$4); }
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
			sprintf(lines[l],"char * %s[%d]",varname,(int)$4);
		}
	 } opt_dims
	 | POKE expr COMMA expr { if (im) { mem[(int)$2]=(char)$4; } }
	 | GET { strcat(lines[l],"*"); } CHAINE { if (im) fprintf(stderr,"DIRECT ERROR\n"); else { yytext[strlen(yytext)-1]=0;strcat(lines[l],yytext); strcat(lines[l],"=(char)getchar_unlocked()"); } }
	 | FOR { infor = 1; for_step_val = 1.0; } IDENTIFIER EQUAL {
	     if (!im) {
		strcpy(fvar,identifier);
	         sprintf(lines[l],"%sfor(float %s=", lines[l], identifier);
	     }
	     strcpy(for_var_name, identifier);
	 } expr TO {
	     if (!im) {
	         strcat(lines[l],";");
	         strcat(lines[l],identifier);
	         strcat(lines[l],"<=");
	     }
	     for_start_val = $6;
	 } expr {
	     for_limit_val = $9;
	     for_step_val = 1.0;
	 } opt_step {
	     if (im) {
	         char *for_ptr = file_buffer;
	         while (*for_ptr != '\0') {
	             if (strncasecmp(for_ptr, "FOR", 3) == 0 && !isalpha((unsigned char)for_ptr[3])) {
	                 if (strstr(for_ptr, for_var_name) != NULL) {
	                     break;
	                 }
	             }
	             for_ptr++;
	         }
	         char *next_ptr = find_matching_next(for_ptr);
	         char *body_start = for_ptr;
	         while (*body_start != '\0' && *body_start != '\n' && *body_start != ':') {
	             body_start++;
	         }
	         if (*body_start != '\0') body_start++;

	         notdef = 1;
	         d = r;
	         while (d) {
	             if (strcmp(d->name, for_var_name) == 0) {
	                 notdef = 0;
	                 d->values[0] = for_start_val;
	                 break;
	             }
	             d = d->next;
	         }
	         if (notdef) {
	             d = (struct var*)malloc(sizeof(struct var));
	             d->values = malloc(sizeof(float));
	             d->size = 1;
	             d->values[0] = for_start_val;
	             strcpy(d->name, for_var_name);
	             d->next = r;
	             r = d;
	         }

	         if (next_ptr != NULL) {
	             int body_len = next_ptr - body_start;
	             char *body_str = (char*)malloc(body_len + 1);
	             strncpy(body_str, body_start, body_len);
	             body_str[body_len] = '\0';
	             while (body_len > 0 && (body_str[body_len-1] == ' ' || body_str[body_len-1] == '\t' || body_str[body_len-1] == '\r' || body_str[body_len-1] == '\n' || body_str[body_len-1] == ':')) {
	                 body_str[--body_len] = '\0';
	             }
	             char *p_body = body_str;
	             while (*p_body == ' ' || *p_body == '\t') p_body++;

	             while (1) {
	                 float cur_val = for_start_val;
	                 d = r;
	                 while (d) {
	                     if (strcmp(d->name, for_var_name) == 0) {
	                         cur_val = d->values[0];
	                         break;
	                     }
	                     d = d->next;
	                 }
	                 int continue_loop = (for_step_val >= 0) ? (cur_val <= for_limit_val) : (cur_val >= for_limit_val);
	                 if (!continue_loop) break;

	                 int b_len = strlen(p_body);
	                 char *body_line = (char*)malloc(b_len + 2);
	                 strcpy(body_line, p_body);
	                 body_line[b_len] = '\n';
	                 body_line[b_len+1] = '\0';

	                 YY_BUFFER_STATE b = yy_scan_string(body_line);
	                 yyparse();
	                 yy_delete_buffer(b);
	                 free(body_line);

	                 d = r;
	                 while (d) {
	                     if (strcmp(d->name, for_var_name) == 0) {
	                         d->values[0] += for_step_val;
	                         break;
	                     }
	                     d = d->next;
	                 }
	             }
	             free(body_str);
	             yy_switch_to_buffer(yy_scan_string(next_ptr + 4));
	         }
	     } else {
	         strcat(lines[l],";");
	         strcat(lines[l],fvar);
	         strcat(lines[l],"++){");
	     }
	 }
	 | NEXT {
	     if (!im) {
	         strcat(lines[l],"}");
	     } else {
	         infor = 0;
	     }
	 } opt_var
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
	 | READ read_target {
	     struct open_file *of = open_files;
	     int is_file = 0;
	     while (of) {
	         if (strcmp(of->name, identifier) == 0) {
	             is_file = 1;
	             input_file = of->fp;
	             current_file = of->fp;
	             break;
	         }
	         of = of->next;
	     }
	     if (!is_file && im) {
	         FILE *fp = fopen(identifier, "r");
	         if (fp) {
	             struct open_file *new_of = (struct open_file*)malloc(sizeof(struct open_file));
	             strcpy(new_of->name, identifier);
	             new_of->fp = fp;
	             new_of->next = open_files;
	             open_files = new_of;
	             input_file = fp;
	             current_file = fp;
	             is_file = 1;
	         }
	     }
	     if (!is_file) {
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
	     } else {
	         if (!im) {
	             strcat(lines[l], "");
	         }
	     }
	 }
	 | RETURN { if (!im) strcat(lines[l],"longjmp(stack[--sp],1)"); }
	 | END { if (!im) strcat(lines[l],"return 0"); else return 0;  }
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
		if ( (int)$6 % 2) {
		 bcolor=p[(int)$6+1][(int)$3];
	         printf("%c[4%dm%c[3%dm%c[%d;%dH\u2580",27,bcolor,27,color,27,(int)(($6+1)/2),(int)$3);
               } else {
		 bcolor=p[(int)$6-1][(int)$3];
	         printf("%c[4%dm%c[3%dm%c[%d;%dH\u2584",27,bcolor,27,color,27,(int)(($6+1)/2),(int)$3);
		}
		p[(int)$6][(int)$3]=color;
	     } else {
	         char y_code[512];
	         strcpy(y_code, lines[l] + plot_len);
	         lines[l][plot_len] = '\0';
	         sprintf(lines[l] + plot_len, "{int _x=(int)(%s); int _y=(int)(%s); int _col=(int)COLOR; if(_y %% 2){ bcolor=p[_y+1][_x]; printf(\"%%c[4%%dm%%c[3%%dm%%c[%%d;%%dH\\u2580\",27,bcolor,27,_col,27,(_y+1)/2,_x); } else { bcolor=p[_y-1][_x]; printf(\"%%c[4%%dm%%c[3%%dm%%c[%%d;%%dH\\u2584\",27,bcolor,27,_col,27,(_y+1)/2,_x); } p[_y][_x]=_col;}", aux1, y_code);
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
	         for(int _x=(int)$3; _x<=(int)$6; _x++) {
	             int _y = (int)$9;
	             if (_y % 2) {
	                 bcolor = p[_y+1][_x];
	                 printf("%c[4%dm%c[3%dm%c[%d;%dH\u2580", 27, bcolor, 27, color, 27, (_y+1)/2, _x);
	             } else {
	                 bcolor = p[_y-1][_x];
	                 printf("%c[4%dm%c[3%dm%c[%d;%dH\u2584", 27, bcolor, 27, color, 27, (_y+1)/2, _x);
	             }
	             p[_y][_x] = color;
	         }
	     } else {
	         char y_code[512];
	         strcpy(y_code, lines[l] + plot_len);
	         lines[l][plot_len] = '\0';
	         sprintf(lines[l] + plot_len, "{int _x1=(int)(%s); int _x2=(int)(%s); int _y=(int)(%s); int _col=(int)COLOR; for(int _x=_x1; _x<=_x2; _x++){ if(_y %% 2){ bcolor=p[_y+1][_x]; printf(\"%%c[4%%dm%%c[3%%dm%%c[%%d;%%dH\\u2580\",27,bcolor,27,_col,27,(_y+1)/2,_x); } else { bcolor=p[_y-1][_x]; printf(\"%%c[4%%dm%%c[3%%dm%%c[%%d;%%dH\\u2584\",27,bcolor,27,_col,27,(_y+1)/2,_x); } p[_y][_x]=_col; }}", aux1, aux2, y_code);
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
	         for(int _y=(int)$3; _y<=(int)$6; _y++) {
	             int _x = (int)$9;
	             if (_y % 2) {
	                 bcolor = p[_y+1][_x];
	                 printf("%c[4%dm%c[3%dm%c[%d;%dH\u2580", 27, bcolor, 27, color, 27, (_y+1)/2, _x);
	             } else {
	                 bcolor = p[_y-1][_x];
	                 printf("%c[4%dm%c[3%dm%c[%d;%dH\u2584", 27, bcolor, 27, color, 27, (_y+1)/2, _x);
	             }
	             p[_y][_x] = color;
	         }
	     } else {
	         char y_code[512];
	         strcpy(y_code, lines[l] + plot_len);
	         lines[l][plot_len] = '\0';
	         sprintf(lines[l] + plot_len, "{int _y1=(int)(%s); int _y2=(int)(%s); int _x=(int)(%s); int _col=(int)COLOR; for(int _y=_y1; _y<=_y2; _y++){ if(_y %% 2){ bcolor=p[_y+1][_x]; printf(\"%%c[4%%dm%%c[3%%dm%%c[%%d;%%dH\\u2580\",27,bcolor,27,_col,27,(_y+1)/2,_x); } else { bcolor=p[_y-1][_x]; printf(\"%%c[4%%dm%%c[3%%dm%%c[%%d;%%dH\\u2584\",27,bcolor,27,_col,27,(_y+1)/2,_x); } p[_y][_x]=_col; }}", aux1, aux2, y_code);
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
	 | OPEN {
		strcat(lines[l],"FILE * fq;");
	} filename {
	     if (im) {
	         FILE *fp = fopen(identifier, "r+");
	         if (!fp) {
	             fp = fopen(identifier, "w+");
	         }
	         if (!fp) {
	             fprintf(stderr, "I/O ERROR\n");
	         } else {
	             struct open_file *of = (struct open_file*)malloc(sizeof(struct open_file));
	             strcpy(of->name, identifier);
	             of->fp = fp;
	             of->next = open_files;
	             open_files = of;
	             current_file = fp;
	         }
	     }
	 }
	 | CLOSE {
	     if (im) {
	         struct open_file *of = open_files;
	         while (of) {
	             if (of->fp && of->fp != stdin && of->fp != stdout) {
	                 if (of->fp == output_file) output_file = stdout;
	                 if (of->fp == input_file) input_file = stdin;
	                 fclose(of->fp);
	             }
	             struct open_file *next = of->next;
	             free(of);
	             of = next;
	         }
	         open_files = NULL;
	         current_file = NULL;
	         output_file = stdout;
	         input_file = stdin;
	     }
	 }
	 | CLOSE filename {
	     if (im) {
	         struct open_file *of = open_files;
	         struct open_file *prev = NULL;
	         while (of) {
	             if (strcmp(of->name, identifier) == 0) {
	                 if (of->fp && of->fp != stdin && of->fp != stdout) {
	                     if (of->fp == output_file) output_file = stdout;
	                     if (of->fp == input_file) input_file = stdin;
	                     fclose(of->fp);
	                 }
	                 if (prev) prev->next = of->next;
	                 else open_files = of->next;
	                 if (current_file == of->fp) current_file = NULL;
	                 free(of);
	                 break;
	             }
	             prev = of;
	             of = of->next;
	         }
	     }
	 }
	 | WRITE {
		if (!im)
			strcat(lines[l],"fq=fopen(\"");
	} filename {
	     if (im) {
	         struct open_file *of = open_files;
	         FILE *fp = NULL;
	         while (of) {
	             if (strcmp(of->name, identifier) == 0) {
	                 fp = of->fp;
	                 break;
	             }
	             of = of->next;
	         }
	         if (!fp) {
	             fp = fopen(identifier, "w");
	             if (fp) {
	                 struct open_file *new_of = (struct open_file*)malloc(sizeof(struct open_file));
	                 strcpy(new_of->name, identifier);
	                 new_of->fp = fp;
	                 new_of->next = open_files;
	                 open_files = new_of;
	             }
	         }
	         if (fp) {
	             output_file = fp;
	             current_file = fp;
	         } else {
	             fprintf(stderr, "I/O ERROR\n");
	         }
	     } else
		strcat(lines[l],"\",\"a\")");
	 }
	 | WRITE {
	     if (im) {
	         if (current_file) output_file = current_file;
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
	 #ifdef WIN32
	         if (mkdir(identifier) < 0)
	 #else
	         if (mkdir(identifier, 0755) < 0)
	 #endif
	         {
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
	 | NEW { for(int i=0;i<65536;i++) strcpy(lines[i],""); data_count=0; data_ptr=0;
	     struct open_file *of = open_files;
	     while (of) {
	         if (of->fp && of->fp != stdin && of->fp != stdout) fclose(of->fp);
	         struct open_file *next = of->next;
	         free(of);
	         of = next;
	     }
	     open_files = NULL;
	     current_file = NULL;
	     output_file = stdout;
	     input_file = stdin;
	 }
	 | DRAW expr AT expr COMMA expr
	 | CLEAR { if (im) { r=NULL; root=NULL; data_ptr=0;
	     struct open_file *of = open_files;
	     while (of) {
	         if (of->fp && of->fp != stdin && of->fp != stdout) fclose(of->fp);
	         struct open_file *next = of->next;
	         free(of);
	         of = next;
	     }
	     open_files = NULL;
	     current_file = NULL;
	     output_file = stdout;
	     input_file = stdin;
	 } }
	 ;

	opt_index:
		| PO expr PF
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

	opt_else:
		| ELSE { strcat(lines[l]," else { "); } insts { strcat(lines[l],";}"); }
		;

	opt_var:
		| IDENTIFIER
		;

	opt_step:
		| STEP expr { for_step_val = $2; }
		;

	list: expr {
	    data_values[data_count++] = $1;
	}
	| list COMMA expr {
	    data_values[data_count++] = $3;
	}
	;

	cond: { if (!im) strcat(lines[l]," ( (int)"); } expr { if (im) cond_lhs = $2; } oper { if (!im) strcat(lines[l],oper); } expr {
	    if (im) {
	        $$ = eval_cond(cond_lhs, oper, $6);
	    } else {
	        strcat(lines[l]," ) ");
	        $$ = 0;
	    }
	}
		| PO { strcat(lines[l],"("); } cond PF { if (im) $$ = $2; else strcat(lines[l],")");  }
		| cond OR { if (!im) strcat(lines[l]," || "); } cond { if (im) $$ = ($1 != 0.0 || $4 != 0.0) ? 1.0 : 0.0; }
		| cond AND { if (!im) strcat(lines[l]," && "); } cond { if (im) $$ = ($1 != 0.0 && $4 != 0.0) ? 1.0 : 0.0; }
	 	| NOT { if (!im) strcat(lines[l],"(!"); } cond { if (im) $$ = ($2 == 0.0) ? 1.0 : 0.0; else strcat(lines[l],")"); }
		| sexpr {
	        if (im) strcpy(aux1, cstr);
	        if (!im) strcat(lines[l], "(strcmp(");
	    } EQUAL {
	        if (!im) strcat(lines[l], ",");
	    } sexpr {
	        if (im) {
	            $$ = (strcmp(aux1, cstr) == 0) ? 1.0 : 0.0;
	        }
	        if (!im) {
	            strcat(lines[l], ")==0) ");
	        }
	    }
		| PEEK PO { strcat(lines[l],"peek_func("); } expr PF { if (im) $$ = $2; else strcat(lines[l],")");  }
	;

	oper: EQUAL { strcpy(oper,"=="); }
		| PG { strcpy(oper,">"); }
		| PP { strcpy(oper,"<"); }
		| GE { strcpy(oper,">="); }
		| PE { strcpy(oper,"<="); }
		;

	sarg: string { if (im) strcpy(cstr, string); }
		| string PO { if (!im) {
			strcat(lines[l], "[(int)");
		} } expr PF { if (!im) strcat(lines[l],"]"); }
		;

	func_args: sarg COMMA { if (!im) strcat(lines[l],","); } expr { if (im) func_arg1 = $4; } ;
	func_args3: sarg COMMA { if (!im) strcat(lines[l],","); } expr { if (im) func_arg1 = $4; } COMMA { if (!im) strcat(lines[l],","); } expr { if (im) func_arg2 = $8; } ;

	sexpr: sarg
		| sexpr PLUS string { if (im) strcat(cstr, identifier); }
		| MID { if (!im) strcat(lines[l],"mid_str("); } PO func_args3 PF {
			if (im) {
				strcpy(cstr, mid_str(cstr, (int)func_arg1, (int)func_arg2));
			} else {
				strcat(lines[l],")");
			}
		}
		| LEFT { if (!im) strcat(lines[l],"left_str("); } PO func_args PF {
			if (im) {
				strcpy(cstr, left_str(cstr, (int)func_arg1));
			} else {
				strcat(lines[l],")");
			}
		}
		| RIGHT { if (!im) strcat(lines[l],"right_str("); } PO func_args PF {
			if (im) {
				strcpy(cstr, right_str(cstr, (int)func_arg1));
			} else {
				strcat(lines[l],")");
			}
		}
		| STR PO expr PF { if (im) sprintf(cstr, "%g", $3); }
		;

	multi_expr: { if (!im) strcat(lines[l],"printf(\"%f\",(float)"); } expr { if (im) {
		  $$=$2;
		sprintf(cstr, "%f", $2);
	} else
		strcat(lines[l],")");
	}
		| { if (!im) strcat(lines[l],"printf(\"%s\","); } sexpr { /* strcpy(cstr,string); */
		if (!im) {
                    strcat(lines[l],")");
                    if (strcmp(string,"D$")==0)
		        dos=1;
		}
	 }
	        | { if (!im) strcat(lines[l],"printf(\"%c\","); } CHR PO { if (!im) strcat(lines[l],"(int)"); } expr PF { if (im) sprintf(cstr, "%c", (int)$5);
		strcat(lines[l],")");
	 }
		| { printf("\n"); }
		;

	opt_print: { if (!im) strcat(lines[l],""); }
	 | sep
	 | sep { if (im && execute_actions && c == ',') fprintf(output_file, "\t"); } { if (!im) strcat(lines[l],";printf(\"%f\",(float)"); } expr {
	     if (im && execute_actions) {
	         fprintf(output_file, "%f", $4);
	     }
	     if (!im) strcat(lines[l],")");
	 }
	 | sep { if (im && execute_actions && c == ',') fprintf(output_file, "\t"); } { if (!im) strcat(lines[l],";printf(\"%s\","); } sexpr {
	     if (im && execute_actions) {
	         fprintf(output_file, "%s", cstr);
	     }
	     if (!im) strcat(lines[l],")");
	 }
	 | opt_print sep { if (im && execute_actions && c == ',') fprintf(output_file, "\t"); } { if (!im) strcat(lines[l],";printf(\"%f\",(float)"); } expr {
	     if (im && execute_actions) {
	         fprintf(output_file, "%f", $5);
	     }
	     if (!im) strcat(lines[l],")");
	 }
	 | opt_print sep { if (im && execute_actions && c == ',') fprintf(output_file, "\t"); } { if (!im) strcat(lines[l],";printf(\"%s\","); } sexpr {
	     if (im && execute_actions) {
	         fprintf(output_file, "%s", cstr);
	     }
	     if (!im) strcat(lines[l],")");
	 }
	 ;

	sep: COMMA { c = ','; }
	 | SEMICOLOMN { c = ';'; }
	 ;

	string: CHAINE { if (im) strcpy(identifier,yytext); else { yytext[strlen(yytext)-1]=0;strcat(lines[l],yytext); } }
	        | CHARS { if (!im) strcat(lines[l],chars); else { strcpy(string,chars+1);string[strlen(string)-1]=0;strcpy(cstr,string); } }
	        ;

	expr: expr PLUS { if (!im) strcat(lines[l],"+"); } expr { if (im) $$=$1+$4; }
	 | expr MINUS { if (!im) strcat(lines[l],"-"); } expr { if (im) $$=$1-$4; }
	 | expr ASTERISK { if (!im) strcat(lines[l],"*"); } expr { if (im) $$=$1*$4; }
	 | expr DIVIDE  { if (!im) strcat(lines[l],"/"); } expr { if (im) $$=$1/$4; }
	 | expr MOD  { if (!im) strcat(lines[l],"%"); } expr { if (im) $$=(int)$1%(int)$4; }
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
	 | EXP PO { if (!im) strcat(lines[l],"exp(");  } expr PF { if (im) $$=exp($3); else strcat(lines[l],")"); }
	 | MINUS { if (!im) strcat(lines[l],"-"); } expr %prec UMINUS { if (im) $$=-$3; }
	 | ASC { if (!im) strcat(lines[l],"(float)(*"); } PO sexpr PF { if (im) $$=$3; else strcat(lines[l],")"); }
	 | RND PO { if (!im)
	#ifdef WIN32
	strcat(lines[l],"(float)rand()/RAND_MAX*");
	#else
	strcat(lines[l],"(float)drand48()*");
	#endif
	} expr PF { if (im) $$=
	#ifdef WIN32
	(float)rand()/RAND_MAX
	#else
	(float)drand48()
	#endif
	; }
	 | INT { if (!im) strcat(lines[l],"roundf("); } PO expr PF { if (im) $$=(int)$4; else strcat(lines[l],")");  }
	 | PEEK PO { if (!im) strcat(lines[l],"peek_func("); } expr PF { if (im) { int addr = (int)$4; if (addr == 49152) {
	#ifdef WIN32
	    if (_kbhit()) { int c = _getch(); mem[49152] = (char)(c | 0x80); }
	#else
	    int bytes = 0; ioctl(0, FIONREAD, &bytes); if (bytes > 0) { char c = getchar(); mem[49152] = (char)(c | 0x80); }
	#endif
	} $$ = (unsigned char)mem[addr]; if (addr == 49152) { mem[49152] &= ~0x80; } } else { strcat(lines[l], ")"); } }
	 | LEN PO { if (!im) strcat(lines[l],"strlen("); } sarg PF { if (im) $$=strlen(string); else strcat(lines[l],")"); }
	;

	filename: IDENTIFIER { if (im) strcpy(a,identifier); else strcat(lines[l],identifier); }
		| IDENTIFIER { strcpy(a,identifier); } DOT extension { strcat(a,".");strcat(a,ext); strcpy(identifier,a); };

	read_target: IDENTIFIER { if (im) strcpy(a,identifier); }
		| IDENTIFIER { strcpy(a,identifier); } DOT extension { strcat(a,".");strcat(a,ext); strcpy(identifier,a); };

	extension: IDENTIFIER { strcpy(ext,identifier); }
		;

	%%
	#include"lex.yy.c"
	void  yyerror(char *s) {
	if (im)
		fprintf(stderr,"%s on %s (text: %s) at %d\n",s,yytname[yychar-255],yytext,ll);
	else
		fprintf(stderr,"%s on %s (text: %s) line %d\n",s,yytname[yychar-255],yytext,l);
		yyparse();
	}

	char rcsrev[]="$Revision: 1.68 $";
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
		if (!yyin) {
			fprintf(stderr,"Error opening %s\n",argv[1]);
			exit(1);
		}
	}
	if (!yyin) yyin = stdin;

        struct winsize w;
        ioctl(0,TIOCGWINSZ,&w);

        int lines=w.ws_row;
        int cols=w.ws_col;

	if (!output_file) output_file = stdout;
	if (!input_file) input_file = stdin;
	#ifdef WIN32
	srand(time(NULL));
	#else
	srand48(time(NULL));
	#endif
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

	if (!isatty(fileno(yyin))) {
	    int len = 0;
	    int c_ch;
	    while ((c_ch = fgetc(yyin)) != EOF && len < 65535) {
	        file_buffer[len++] = (char)c_ch;
	    }
	    file_buffer[len] = '\0';
	    if (yyin != stdin) fclose(yyin);

	    if (!output_file) output_file = stdout;
	    if (!input_file) input_file = stdin;
	    #ifdef WIN32
	srand(time(NULL));
	#else
	srand48(time(NULL));
	#endif
	    strtok(rcsrev,".");
	    r=(struct var*)malloc(sizeof(struct var));
	    strcpy(r->name,"COLOR");
	    r->values=malloc(sizeof(float));
	    r->size=1;
	    r->values[0]=2;
	    r2=(struct var*)malloc(sizeof(struct var));
	    r->next=r2;
	    r2->values=malloc(sizeof(float));
	    r2->size=1;
	    r2->values[0]=1;
	    r2->next=NULL;
	    strcpy(r2->name,"VERSION");
	    srand48(12345);

	    yy_scan_string(file_buffer);
	    yyparse();
//	    fprintf(stderr,"FIN\n");
	    exit(0);
	}

	    char *line;
	    char buf[4096];
	    while (1) {
	        line = soft_readline(PROMPT);
	        if (!line) break;
	        if (line[0] != '\0') {
	            soft_add_history(line);
	            int len = strlen(line);
	            if (len < sizeof(buf) - 2) {
	                snprintf(buf, sizeof(buf), "%s\n", line);
	                YY_BUFFER_STATE b = yy_scan_string(buf);
	                yyparse();
	                yy_delete_buffer(b);
	            }
	        }
	        free(line);
	    }
	    //fprintf(stderr,"FIN\n");
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

	printf(PROMPT);
	fflush(stdout);
	return yyparse();
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
		fprintf(fp,"#include<time.h>\n");
		fprintf(fp,"#include<unistd.h>\n");
		fprintf(fp,"#ifndef WIN32\n");
		fprintf(fp,"#include<sys/ioctl.h>\n");
		fprintf(fp,"#include<termios.h>\n");
		fprintf(fp,"static struct termios orig_t;\n");
		fprintf(fp,"static int orig_t_saved = 0;\n");
		fprintf(fp,"static int tty_fd = -1;\n");
		fprintf(fp,"static void restore_terminal() {\n");
		fprintf(fp,"    if (orig_t_saved && tty_fd != -1) {\n");
		fprintf(fp,"        tcsetattr(tty_fd, TCSANOW, &orig_t);\n");
		fprintf(fp,"    }\n");
		fprintf(fp,"}\n");
		fprintf(fp,"#else\n");
		fprintf(fp,"#include<conio.h>\n");
		fprintf(fp,"#endif\n");
		fprintf(fp,"unsigned char mem[65535];\n");

		fprintf(fp,"int peek_func(int addr) {\n");
		fprintf(fp,"    if (addr == 49152) {\n");
		fprintf(fp,"#ifdef WIN32\n");
		fprintf(fp,"        if (_kbhit()) {\n");
		fprintf(fp,"            int c = _getch();\n");
		fprintf(fp,"            mem[49152] = (char)(c | 0x80);\n");
		fprintf(fp,"        }\n");
		fprintf(fp,"        int val = (unsigned char)mem[addr];\n");
		fprintf(fp,"        mem[49152] &= ~0x80;\n");
		fprintf(fp,"        return val;\n");
		fprintf(fp,"#else\n");
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
		fprintf(fp,"\n");
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
		fprintf(fp,"#endif\n");
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

		fprintf(fp,"int main(int argc, char * argv[]) {\n");
		fprintf(fp,"char s[1024];\n");
		fprintf(fp,"char KEY[1];\n");

		fprintf(fp,"float data_values[] = {");
		for(int i=0; i<data_count; i++) {
			fprintf(fp,"%f%s", data_values[i], (i < data_count - 1) ? "," : "");
		}
		fprintf(fp,"};\n");
		fprintf(fp,"int data_ptr = 0;\n");

		fprintf(fp,"float COLOR=0;\n");
		fprintf(fp,"int p[512][512] = {0};\n");
		fprintf(fp,"int bcolor = 0;\n");
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
		fprintf(fp,"return 0;\n");
		fprintf(fp,"}\n");
		return 0;
	}
