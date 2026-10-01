%x exec
%%
<<EOF>> {
	yypop_buffer_state();
        if (!YY_CURRENT_BUFFER)
		yyterminate();
}
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
"SYSTEM"|"system" { return SYSTEM; }
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
"EXEC"|"exec"	BEGIN(exec);
<exec>[ \t]*
<exec>[^ \t\n]+ {
	yyin=fopen(yytext,"r");
	if (!yyin) 
		fprintf(stderr,"Error opening %s\n",yytext);
	else {
		yypush_buffer_state(yy_create_buffer(yyin,YY_BUF_SIZE));
		BEGIN(INITIAL);
	}
}
"REM".*|"rem".* { return REM; }
[0-9]+	{ yylval=atof(yytext);return NUMBER; }
[0-9]+"."[0-9]+	{ yylval=atof(yytext);return FLOAT; }
"\""   { return QUOTE;}
[A-Za-z0-9_]+   { strcpy(identifier,yytext); return IDENTIFIER;}
[A-Za-z0-9_]+"$"   { return STRING;}
"="	{ return EQUAL; }
"[" { return CO; }
"]" { return CF; }
"(" { return PO; }
")" { return PF; }
":" { return DP; }
">" { return PG; }
"<" { return PP; }
">=" { return GE; }
"<=" { return PE; }
"<>" { return DIFF; }
"%" { return MOD; }
"-" { return MINUS; }
"+" { return PLUS; }
"*" { return ASTERISK; }
"/" { return DIVIDE; }
"." { return DOT; }
"," { return COMMA; }
"&" { return AMPER; }
"\n" { ll++; return CR; }
\".*\" { strcpy(chars,yytext); return CHARS; }
%%
