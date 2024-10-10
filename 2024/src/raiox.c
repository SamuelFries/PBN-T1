#include <math.h>
#include "raiox.h"
#include "cinza.h"

void xray(PPMImage *img, float factor) {
    //converte para cinza
    grayscale(img);

    //aplica o efeito de raio-X
    for (int i = 0; i < img->width * img->height * 3; i++) {
        int value = pow(img->data[i], factor); // Eleva o valor ao fator desejado
        img->data[i] = value > 255 ? 255 : value; // Limita o valor máximo a 255
    }
}