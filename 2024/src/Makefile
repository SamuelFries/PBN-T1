CC = gcc
CFLAGS = -Wall -Wextra -g3

SRC = main.c imagem_ppm.c cinza.c negativo.c raiox.c envelhecida.c rotacao.c
OBJ = $(SRC:.c=.o)
OBJ_OUTPUT = $(patsubst %.o,output/%.o,$(OBJ))  # Mapeia para a pasta output

TARGET = output/main

# Crie o diretório de saída se não existir
$(shell mkdir -p output)

all: $(TARGET)

$(TARGET): $(OBJ_OUTPUT)
	$(CC) $(CFLAGS) -o $@ $^

output/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f output/*.o $(TARGET)

.PHONY: all clean