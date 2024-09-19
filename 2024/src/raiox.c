#include "raiox.h"

void xray(PPMImage *img, float factor) {
    for (int i = 0; i < img->width * img->height * 3; i++) {
        int value = img->data[i] * factor;
        img->data[i] = value > 255 ? 255 : value;
    }
}