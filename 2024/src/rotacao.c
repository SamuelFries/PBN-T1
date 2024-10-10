#include "rotacao.h"
#include <stdlib.h>
#include <stdio.h>

void rotacionar_90(PPMImage **img) {
    PPMImage *image = *img;
    
    // matriz temp
    unsigned char *tempData = malloc(image->width * image->height * 3);

    // rotação 90 graus
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            int oldIndex = (y * image->width + x) * 3;
            int newIndex = ((image->width - x - 1) * image->height + y) * 3;
            
            // Copia os valores de RGB para a matriz temporária
            tempData[newIndex] = image->data[oldIndex];         // R
            tempData[newIndex + 1] = image->data[oldIndex + 1]; // G
            tempData[newIndex + 2] = image->data[oldIndex + 2]; // B
        }
    }

    // libera a memória da imagem original
    free(image->data); 
    image->data = tempData;

    // inverte a largura e altura
    int temp = image->width;
    image->width = image->height;
    image->height = temp;
}