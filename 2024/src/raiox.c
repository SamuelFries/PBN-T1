#include "raiox.h"

void xray(PPMImage *img, float factor) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].red = (unsigned char)(img->data[i].red * factor);
        img->data[i].green = (unsigned char)(img->data[i].green * factor);
        img->data[i].blue = (unsigned char)(img->data[i].blue * factor);
    }
}