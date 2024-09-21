#include <stdio.h>
#include <stdlib.h>
#include "cinza.h"
#include "negativo.h"
#include "raiox.h"
#include "envelhecida.h"
#include "rotacao.h"
#include "imagem_ppm.h"

int main() {
    char filename[100];
    int option;
    float factor;

    // Solicita o nome da imagem
    //printf("Digite o nome da imagem *.ppm (mínimo 400x400): ");
    //scanf("%99s", filename);

    // Carrega a imagem
    PPMImage *img = readPPM("imagem.ppm");

    if (img == NULL) {
        printf("Erro ao ler a imagem.\n");
        return 1;
    }

    // Exibe o menu de opções
    printf("Escolha uma opção:\n");
    printf("1. Gerar uma imagem em tons de cinza\n");
    printf("2. Gerar uma imagem negativa\n");
    printf("3. Gerar uma imagem raio-x\n");
    printf("4. Gerar uma imagem envelhecida/sépia\n");
    printf("5. Rotacionar a imagem 90 graus\n");
    scanf("%d", &option);

    switch (option) {
        case 1:
            grayscale(img);
            savePPM("output/output_grayscale.ppm", img);  // Inclui 'output/'
            break;
        case 2:
            negative(img);
            savePPM("output/output_negative.ppm", img);   // Inclui 'output/'
            break;
        case 3:
            printf("Digite o fator de intensidade para o efeito raio-X (entre 1.0 e 2.0): ");
            scanf("%f", &factor);
            xray(img, factor);
            savePPM("output/output_xray.ppm", img);       // Inclui 'output/'
            break;
        case 4:
            printf("Digite o fator de envelhecimento (exemplo 0.1): ");
            scanf("%f", &factor);
            sepia(img, factor);
            savePPM("output/output_sepia.ppm", img);      // Inclui 'output/'
            break;
        case 5:
            rotacionar_90(&img);
            savePPM("output/output_rotated.ppm", img);    // Inclui 'output/'
            break;
        default:
            printf("Opção inválida.\n");
            break;
    }

    // Libera a memória alocada para a imagem
    free(img->data);
    free(img);

    return 0;
}