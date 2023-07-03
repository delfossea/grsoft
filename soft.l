%x exec
%%
<<EOF>> {
	yypop_buffer_state();
        if (!YY_CURRENT_BUFFER)
		yyterminate();
}
"VAL"|"val" { return VAL; }
"POP"|"pop" { return POP; }
"CATALOG"|"catalog" { return CATALOG; }
"DELETE"|"delete" { return EFFACE; }
"ABORT"|"abort" { return ABORT; }
"STOP"|"stop" { return STOP; }
"PR#0"|"pr#0" { return PR; }
"PR#3"|"pr#3" { return COL80; }
"DEL"|"del" { return DEL; }
"DEF"|"def" { return DEF; }
"FN"|"fn" { return FN; }
"STR$"|"str$" { return STR; }
"CLEAR"|"clear" { return CLEAR; }
"DRAW"|"draw" { return DRAW; }
"LIST"|"list"	{ return LIST; }
"RUN"|"run"	{ return RUN; }
"PRINT"|"print"|"?" { return PRINT; }
"INPUT"|"input" { return ENTREE; }
"DUMP"|"dump" { return DUMP; }
"IF"|"if" { return IF; }
"THEN"|"then" { return THEN; }
"ELSE"|"else" { return ELSE; }
"FOR"|"for" { return FOR; }
"NEXT"|"next" { return NEXT; }
"STEP"|"step" { return STEP; }
"TO"|"to" { return TO; }
"GOTO"|"goto" { return GOTO; }
"GOSUB"|"gosub" { return GOSUB; }
"RETURN"|"return" { return RETOUR; }
"NEW"|"new" { return NEW; }
"TRACE"|"trace" { return TRACE; }
"NOTRACE"|"notrace" { return NOTRACE; }
"ON"|"on" { return ON; }
"OFF"|"off" { return OFF; }
"HGR"|"hgr" { return HGR; }
"HPLOT"|"hplot" { return HPLOT; }
"TEXT"|"text" { return TEXT; }
"LEN"|"len" { return LEN; }
"NOT"|"not" { return NOT; }
"END"|"end" { return END; }
"READ"|"read" { return READ; }
"DATA"|"data" { return DATA; }
"VLIN"|"vlin" { return VLIN; }
"HLIN"|"hlin" { return HLIN; }
"GR"|"gr" { return GR;}
"PLOT"|"plot" { return PLOT; }
"LET"|"let" { return LET; }
"SQR"|"sqr" { return SQR; }
"SIN"|"sin" { return SIN; }
"COS"|"cos" { return COS; }
"TAN"|"tan" { return TAN; }
"ATN"|"atn" { return ATAN; }
"EXP"|"exp" { return EXP; }
"LOG"|"log" { return LOG; }
"RANDOMIZE"|"randomize" { return RANDOMIZE; }
"DIM"|"dim" { return DIM; }
"ABS"|"abs" { return ABS; }
"OR"|"or" { return OR; }
"AND"|"and" { return AND; }
"RND"|"rnd" { return RND; }
"ASC"|"asc" { return ASC; }
"BYE"|"bye" { return SYSTEM; }
"MID$"|"mid$" { return MID; }
"LEFT$"|"left$" { return LEFT; }
"RIGHT$"|"right$" { return RIGHT; }
"HTAB"|"htab" { return HTAB; }
"VTAB"|"vtab" { return VTAB; }
"HOME"|"home" { return HOME; }
"PEEK"|"peek" { return PEEK; }
"POKE"|"poke" { return POKE; }
"GET"|"get" { return GET; }
"AT"|"at" { return AT; }
"SAVE"|"save" { return SAVE; }
"BSAVE"|"bsave" { return BSAVE; }
"BLOAD"|"bload" { return BLOAD; }
"DEBUG"|"debug" { return DEBUG; }
"INT"|"int" { return ENTIER; }
"CHR$"|"chr$" { return CHR; }
"OPEN"|"open" { return OPEN; }
"CLOSE"|"close" { return CLOSE; }
"EXEC"|"exec"	BEGIN(exec);
<exec>[ \t]*
<exec>[^ \t\n]+ {
	yyin=fopen(yytext,"r");
	if (!yyin) {
		fprintf(stderr,"error opening %s\n",yytext);
	} else {
	yypush_buffer_state(yy_create_buffer(yyin,YY_BUF_SIZE));
	BEGIN(INITIAL);
	}
}
"REM".*|"rem".* { return REM; }
[0-9]+	{ yylval=atof(yytext);return NUMBER; }
[0-9]*"."[0-9]+	{ yylval=atof(yytext);return FLOTANT; }
"\""   { return QUOTE;}
[A-Za-z0-9_\.]+   { strcpy(identifier,yytext); return IDENTIFIER;}
[A-Za-z0-9_]+"$"   { strcpy(identifier,yytext); return STRING;}
">=" { return GE; }
"<=" { return PE; }
"="	{ return EQUAL; }
"," { return COMMA; }
"[" { return CO; }
"]" { return CF; }
"(" { return PO; }
")" { return PF; }
":" { return DP; }
">" { return PG; }
"<" { return PP; }
"<>" { return DIFF; }
"%" { return MOD; }
"-" { return MINUS; }
"+" { return PLUS; }
"*" { return ASTERISK; }
"/" { return DIVIDE; }
";" { return SEMICOLOMN; }
"&" { return AMPER; }
"\n" { ll++; return CR; }
" " {}
\"[A-Za-z0-9_\?\.,\ \-\+\\\/\[\]\(\)\$\:\'\!\=]*\" { strcpy(chars,yytext); strcpy(string,yytext+1); string[strlen(yytext)-2]=0; return CHARS; }
%%
void set_input_string(const char* in) {
  yy_scan_string(in);
}

void end_lexical_scan(void) {
  yy_delete_buffer(YY_CURRENT_BUFFER);
}
