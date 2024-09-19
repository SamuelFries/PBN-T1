#include "cinza.h"

void grayscale(PPMImage *img) {
    for (int i = 0; i < img->width * img->height; i++) {
        unsigned char gray = (img->data[i * 3] + img->data[i * 3 + 1] + img->data[i * 3 + 2]) / 3;
        img->data[i * 3] = gray;
        img->data[i * 3 + 1] = gray;
        img->data[i * 3 + 2] = gray;
    }
}