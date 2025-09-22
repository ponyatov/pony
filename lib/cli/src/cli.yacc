%{
    #include "cli.hpp"
%}

%defines %union { char c; std::string* s; int n; float f; Op op; }

%token<n>  INT HEX OCT BIN
%token<f>  NUM
%token     COLON
%token<s>  ID
%token<op> CMD0 CMD1

%%
syntax: | syntax ex

ex: NUM         { fprintf(stderr,"num:%e\n",$1); }
  | INT         { fprintf(stderr,"int:%i\n",$1); }
  | HEX         { fprintf(stderr,"hex:%x\n",$1); }
  | OCT         { fprintf(stderr,"oct:%o\n",$1); }
  | BIN         { fprintf(stderr,"bin:%b\n",$1); }
  | COLON ID    { fprintf(stderr,"%s: %.4X\n",$2->c_str(),Cp);
                    label[*$2] = Cp; }
  | CMD1        { fprintf(stderr,"%.4X: %.2X\n",Cp,$1); compile($1); }

%%
void yyerror(const char *msg) {
    fprintf(stderr, "\n\n%s:%i %s [%s]\n\n", yyfile, yylineno, msg, yytext);
    exit(-1);
}
