//Makefile para windows
//Feito para MinGWn

CC = gcc
CFLAGS = -Wall -Wextra -g3

SRC = main.c imagem_ppm.c cinza.c negativo.c raiox.c envelhecida.c rotacao.c
TARGET = output/imagens.exe

# Crie o diretório de saída se não existir
output:
	mkdir -p output

all: output $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f output/imagens.exe
	rm -rf output

.PHONY: all clean output