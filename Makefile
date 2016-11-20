# compiler to use
CC = clang

CFLAGS = -std=c99
CFLAGS += -I deps/linenoise
CFLAGS += -I src

SOURCE = src/ny.c
TARGET = ny

SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
OBJ += deps/linenoise/linenoise.o
OUT = ny

$(OUT): $(OBJ)
	$(CC) $^ -o $@

%.o: %.c
	$(CC) -c ${CFLAGS} $< -o $@

clean:
	rm -f $(OBJ)
