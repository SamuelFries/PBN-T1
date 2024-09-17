#include "raiox.h"
#include <math.h>  // Para usar a função de potência pow()

void xray(PPMImage *img, float factor) {
    // Primeiro, converte a imagem para tons de cinza
    for (int j = 0; j < img->height; j++) {
        for (int i = 0; i < img->width; i++) {
            int index = (j * img->width + i) * 3;  // Cada pixel tem 3 valores (R, G, B)
            
            unsigned char r = img->data[index];
            unsigned char g = img->data[index + 1];
            unsigned char b = img->data[index + 2];
            
            // Conversão para tons de cinza usando a fórmula ponderada
            unsigned char gray = (unsigned char)((r * 0.299) + (g * 0.587) + (b * 0.114));
            
            // Aplica a transformação de intensidade para simular raio-X
            unsigned char xray_value = (unsigned char)(pow(gray / 255.0, factor) * 255);
            
            // Substitui os valores de R, G e B pelo valor da imagem de raio-X
            img->data[index] = xray_value;
            img->data[index + 1] = xray_value;
            img->data[index + 2] = xray_value;
        }
    }
}