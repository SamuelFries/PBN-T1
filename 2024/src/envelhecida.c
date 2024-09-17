#include "envelhecida.h"

void sepia(PPMImage *img, float factor) {
    for (int j = 0; j < img->height; j++) {
        for (int i = 0; i < img->width; i++) {
            int index = (j * img->width + i) * 3;
            
            unsigned char r = img->data[index];
            unsigned char g = img->data[index + 1];
            unsigned char b = img->data[index + 2];
            
            // Reduz o azul
            b = b * (1 - factor);  // B = B * (1 - fator)
            
            // Aumenta o vermelho e o verde
            r = r * (1 + factor);  // R = R * (1 + fator)
            g = g * (1 + factor);  // G = G * (1 + fator)
            
            // Aplica uma tintura
            r = (r + 10 > 255) ? 255 : r + 10;
            g = (g + 10 > 255) ? 255 : g + 10;
            b = (b - 10 < 0) ? 0 : b - 10;
            
            // Atualiza os valores de RGB na imagem
            img->data[index] = r;
            img->data[index + 1] = g;
            img->data[index + 2] = b;
        }
    }
}