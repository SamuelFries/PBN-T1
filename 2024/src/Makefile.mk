//Makefile para Windows

CC = gcc
CFLAGS = -Wall -Wextra -g3

SRC = main.c imagem_ppm.c cinza.c negativo.c raiox.c envelhecida.c rotacao.c
TARGET = output\imagens.exe

# Crie o diretório de saída se não existir
output:
	if not exist output mkdir output

all: output $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	del /f /q output\imagens.exe
	rmdir /s /q output

.PHONY: all clean output