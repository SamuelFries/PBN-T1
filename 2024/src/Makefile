CC = gcc
CFLAGS = -g  # Add debugging symbols

SRC = main.c imagem_ppm.c cinza.c negativo.c raiox.c envelhecida.c rotacao.c
TARGET = output/imagens

# Crie o diretório de saída se não existir
$(shell mkdir -p output)

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f output/imagens

.PHONY: all clean