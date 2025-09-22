.PHONY: ai tmp/$(APP).ai.md
ai: tmp/$(APP).ai.md
tmp/$(APP).ai.md:
	cat README.md doc/*.md $(C) $(H) $(S) lib/vm/inc/vm.hpp lib/cli/src/cli.lex lib/cli/src/cli.yacc > $@ ; touch $@
