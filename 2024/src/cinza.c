#include "cinza.h"

void grayscale(PPMImage *img) {
    for (int i = 0; i < img->width * img->height; i++) {
        unsigned char gray = (img->data[i].red + img->data[i].green + img->data[i].blue) / 3;
        img->data[i].red = gray;
        img->data[i].green = gray;
        img->data[i].blue = gray;
    }
}