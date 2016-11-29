CC = clang
YACC = bison
LEX = flex

CFLAGS = -std=c99 -c
CFLAGS += -I deps/linenoise

SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
OBJ += deps/linenoise/linenoise.o
OUT = bin/ny

$(OUT): $(OBJ)
	@$(CC) $(OBJ) -o $@

%.o: %.c
	@$(CC) -c ${CFLAGS} $< -o $@
	@printf "\033[0;32mCC\e[0m %s\n" $@

src/parse.tab.c src/parse.tab.h: src/parse.y
	@$(YACC) -d -o src/parse.tab.c src/parse.y

src/parse.tab.o: src/parse.tab.c
	$(CC) -c src/parse.tab.c -o src/parse.tab.o

src/node.o: src/parse.tab.h

clean:
	@rm -f $(OBJ)
	@rm -f src/*.tab.c src/*.tab.h
