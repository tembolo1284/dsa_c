# -*- MakeFile -*-

BINARY=main

TEST=tests
TESTS=$(wildcard $(TEST)/*.c)
TESTBINS=$(patsubst $(TEST)/%.c, $(TEST)/bin/%, $(TESTS))

CODEDIRS=. src
INCDIRS=. ./include/

CC=gcc
OPT=-O0

# generate files that encode make rules for the .h dependencies
DEPFLAGS=-MP -MD

# automatically add the -I onto each include directory
CFLAGS=-Wall -Wextra -Wpedantic -g $(foreach D,$(INCDIRS),-I$(D)) $(OPT) $(DEPFLAGS)

# for-style iteration (foreach) and regular expression completions (wildcard)
CFILES=$(foreach D,$(CODEDIRS),$(wildcard $(D)/*.c))
LIB_CFILES=$(filter-out src/main.c, $(wildcard src/*.c))


# regular expression replacement
OBJECTS=$(patsubst %.c,%.o,$(filter-out $(TESTS), $(CFILES)))
LIB_OBJS=$(LIB_CFILES:.c=.o)

DEPFILES=$(patsubst %.c,%.d,$(CFILES))

all: $(BINARY)

$(BINARY): $(OBJECTS)
	$(CC) -o $@ $^

# only want the .c file dependency here, thus $< instead of $^.

%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(BINARY) $(OBJECTS) $(DEPFILES) $(TESTBINS)

# shell commands are a set of keystrokes away
distribute: clean
	tar zcvf dist.tgz *

# @ silences the printing of the command
# $(info ...) prints output
diff:
	$(info The status of the repository, and the volume of per-file changes:)
	@git status
	@git diff --stat

$(TEST)/bin/%: $(TEST)/%.c $(LIB_OBJS)
	mkdir -p $(TEST)/bin
	$(CC) $(CFLAGS) -o $@ $^ -lcriterion

test: $(TESTBINS)
	for test in $(TESTBINS) ; do ./$$test ; done

# include the dependencies
-include $(DEPFILES)

# add .PHONY so that the non-targetfile - rules work even if a file with the same name exists.
.PHONY: all clean distribute diff test
