%x exec
%%
<<EOF>> {
	yypop_buffer_state();
        if (!YY_CURRENT_BUFFER)
		yyterminate();
}
"PR#0"|"pr#0" { return PR; }
"DEL"|"del" { return DEL; }
"STR$"|"str$" { return STR; }
"CLEAR"|"clear" { return CLEAR; }
"COLOR"|"color" { return COLOR; }
"DRAW"|"draw" { return DRAW; }
"LIST"|"list"	{ return LIST; }
"RUN"|"run"	{ return RUN; }
"PRINT"|"print"|"?" { return PRINT; }
"INPUT"|"input" { return INPUT; }
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
"RETURN"|"return" { return RETURN; }
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
"EXP"|"exp" { return EXP; }
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
"CHR$"|"chr$" { return CHR; }
"HTAB"|"htab" { return HTAB; }
"VTAB"|"vtab" { return VTAB; }
"HOME"|"home" { return HOME; }
"PEEK"|"peek" { return PEEK; }
"POKE"|"poke" { return POKE; }
"GET"|"get" { return GET; }
"AT"|"at" { return AT; }
"SAVE"|"save" { return SAVE; }
"DEBUG"|"debug" { return DEBUG; }
"INT"|"int" { return INT; }
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
[0-9]*"."[0-9]+	{ yylval=atof(yytext);return FLOAT; }
"\""   { return QUOTE;}
[A-Za-z0-9_]+   { strcpy(identifier,yytext); return IDENTIFIER;}
[A-Za-z0-9_]+"$"   { strcpy(String,yytext); return CHAINE;}
">=" { return GE; }
"<=" { return PE; }
"="	{ return EQUAL; }
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
"." { return DOT; }
"," { return COMMA; }
";" { return SEMICOLOMN; }
"&" { return AMPER; }
"\n" { ll++; return CR; }
" " {}
\".*\" { strcpy(chars,yytext); strcpy(string,yytext+1); string[strlen(yytext)-2]=0; return CHARS; }
%%
