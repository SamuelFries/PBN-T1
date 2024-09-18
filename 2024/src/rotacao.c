#include "rotacao.h"
#include <stdlib.h>
#include "ppm.h"

void rotacionar_90(PPMImage **img) {
    int old_width = (*img)->width;
    int old_height = (*img)->height;

    // Criando uma nova imagem com dimensões trocadas (transposta)
    PPMImage *rotated_img = (PPMImage *)malloc(sizeof(PPMImage));
    rotated_img->width = old_height;
    rotated_img->height = old_width;
    rotated_img->data = (unsigned char *)malloc(3 * rotated_img->width * rotated_img->height * sizeof(unsigned char));

    // Transpõe a matriz de pixels e inverte as colunas
    for (int j = 0; j < old_height; j++) {
        for (int i = 0; i < old_width; i++) {
            int old_index = (j * old_width + i) * 3;  // Índice na imagem original
            int new_index = ((i * old_height) + (old_height - 1 - j)) * 3;  // Índice na imagem rotacionada
            
            // Troca os valores RGB
            rotated_img->data[new_index] = (*img)->data[old_index];        // R
            rotated_img->data[new_index + 1] = (*img)->data[old_index + 1]; // G
            rotated_img->data[new_index + 2] = (*img)->data[old_index + 2]; // B
        }
    }

    // Libera a imagem original e aponta para a nova imagem rotacionada
    free((*img)->data);
    free(*img);
    *img = rotated_img;
}