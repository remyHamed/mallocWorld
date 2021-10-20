CFLAGS=-Wall -Wextra -Werror
LDFLAGS=
SRC=$(wildcard *.c) 
OBJ=$(SRC:.c=.o)

CC ?= gcc
RM ?= rm -rf

all: mallocworld
.PHONY: all

mallocworld: $(OBJ)
  $(CC) -o $@ $^ $(LDFLAGS)
.PHONY: mallocworld

clean:
  $(RM) $(OBJ)
.PHONY: clean

mrproper: clean
  $(RM) mallocworld
.PHONY: mrproper