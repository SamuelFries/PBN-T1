#include <stdio.h>
#include <stdlib.h>
#include "cinza.h"
#include "negativo.h"
#include "raiox.h"
#include "envelhecida.h"
#include "rotacao.h"
#include "imagem_ppm.h"

int main() {
    int option;
    float factor;

    // Carrega a imagem
    PPMImage *img = readPPM("imagem.ppm");

    if (img == NULL) {
        printf("Erro ao ler a imagem.\n");
        return 1;
    }

    // Exibe o menu de opções até o usuário escolher uma válida
    do {
        printf("Escolha uma opção:\n");
        printf("1. Visulizar a imagem original\n");
        printf("2. Gerar uma imagem em tons de cinza\n");
        printf("3. Gerar uma imagem negativa\n");
        printf("4. Gerar uma imagem raio-x\n");
        printf("5. Gerar uma imagem envelhecida/sépia\n");
        printf("6. Rotacionar a imagem 90 graus\n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                savePPM("output/output_original.ppm", img);
                break;
            case 2:
                grayscale(img);
                savePPM("output/output_grayscale.ppm", img);
                break;
            case 3:
                negative(img);
                savePPM("output/output_negative.ppm", img);
                break;
            case 4:
                printf("Digite o fator de intensidade para o efeito raio-X (entre 1.0 e 2.0): ");
                scanf("%f", &factor);
                xray(img, factor);
                savePPM("output/output_xray.ppm", img);
                break;
            case 5:
                sepia(img, factor);
                savePPM("output/output_sepia.ppm", img);
                break;
            case 6:
                rotacionar_90(&img);
                savePPM("output/output_rotated.ppm", img);
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (option < 1 || option > 6);

    // Libera a memória alocada para a imagem
    free(img->data);
    free(img);

    return 0;
}