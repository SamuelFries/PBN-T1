CC = gcc
CFLAGS = -Wall -Wextra -g3
SRC = main.c imagem_ppm.c cinza.c negativo.c raiox.c envelhecida.c rotacao.c
OBJ = $(SRC:.c=.o)
TARGET = output/main

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ) $(TARGET)