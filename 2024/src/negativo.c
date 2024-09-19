#include "negativo.h"

void negative(PPMImage *img) {
    for (int i = 0; i < img->width * img->height * 3; i++) {
        img->data[i] = 255 - img->data[i];
    }
}