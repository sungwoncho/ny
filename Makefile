# compiler to use
CC = clang

CFLAGS = -std=c99
CFLAGS += -I deps/linenoise
CFLAGS += -I src

SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
OBJ += deps/linenoise/linenoise.o
OUT = ny

$(OUT): $(OBJ)
	@$(CC) $^ -o $@

%.o: %.c
	@$(CC) -c ${CFLAGS} $< -o $@
	@printf "\033[0;32mCC\e[0m %s\n" $@

clean:
	@rm -f $(OBJ)
