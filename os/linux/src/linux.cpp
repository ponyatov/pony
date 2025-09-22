#include "os.hpp"
#include "vm.hpp"
#include "cli.hpp"

__attribute__((weak)) void cli(char* filename) {
    yyfile = filename;
    yylineno = 1;
    assert(yyin = fopen(yyfile, "r"));
    yyparse();
    fclose(yyin);
    yyfile = nullptr;
    yylineno = 0;
}

__attribute__((weak)) int main(int argc, char* argv[]) {
    arg(0, argv[0]);
    nop();
    for (int i = 1; i < argc; i++) {
        arg(i, argv[i]);
        cli(argv[i]);
    }
    halt();
    return 0;
}

__attribute__((weak)) void arg(int argc, char* argv) {  //
    fprintf(stderr, "arg[%i] = <%s>\n", argc, argv);
}
