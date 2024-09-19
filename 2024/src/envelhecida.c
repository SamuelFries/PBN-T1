#include "envelhecida.h"

void sepia(PPMImage *img, float factor) {
    for (int i = 0; i < img->width * img->height; i++) {
        unsigned char r = img->data[i * 3];
        unsigned char g = img->data[i * 3 + 1];
        unsigned char b = img->data[i * 3 + 2];

        img->data[i * 3] = (unsigned char)(r * (1 - factor) + g * 0.5 * factor + b * 0.2 * factor);
        img->data[i * 3 + 1] = (unsigned char)(r * 0.2 * factor + g * (1 - factor) + b * 0.5 * factor);
        img->data[i * 3 + 2] = (unsigned char)(r * 0.2 * factor + g * 0.2 * factor + b * (1 - factor));
    }
}