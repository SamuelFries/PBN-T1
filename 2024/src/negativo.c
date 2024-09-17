#include "negativo.h"

void negative(PPMImage *img) {
    for (int j = 0; j < img->height; j++) {
        for (int i = 0; i < img->width; i++) {
            int index = (j * img->width + i) * 3;  // Cada pixel tem 3 valores (R, G, B)
            
            unsigned char r = img->data[index];
            unsigned char g = img->data[index + 1];
            unsigned char b = img->data[index + 2];
            
            // Aplica a fórmula de imagem negativa
            img->data[index] = 255 - r;     // R_novo = 255 - R_original
            img->data[index + 1] = 255 - g; // G_novo = 255 - G_original
            img->data[index + 2] = 255 - b; // B_novo = 255 - B_original
        }
    }
}