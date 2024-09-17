#include <stdio.h>
#include <stdlib.h>
#include "cinza.h"
#include "ppm.h"  // Inclui o cabeçalho que define a estrutura PPM

int main() {
    char filename[100];
    int option;
    
    // Solicita o nome da imagem
    printf("Digite o nome da imagem *.ppm (mínimo 400x400): ");
    if (scanf("%99s", filename) != 1) {
        printf("Erro ao ler o nome do arquivo.\n");
        return 1;
    }

    // Carrega a imagem
    PPMImage *img = readPPM(filename);  // Supondo que você tenha uma função para ler a imagem
    
    if (img == NULL) {
        printf("Erro ao ler a imagem.\n");
        return 1;
    }

    // Exibe o menu de opções
    printf("Escolha uma opção:\n");
    printf("1. Gerar uma imagem em tons de cinza\n");
    if (scanf("%d", &option) != 1) {
        printf("Erro ao ler a opção.\n");
        return 1;
    }

    // Verifica se a opção é válida
    if (option != 1) {
        printf("Opção inválida.\n");
        return 1;
    }

    // Continue with the rest of the program logic...

    // Libera a memória alocada para a imagem
    free(img->data);
    free(img);

    return 0;
}