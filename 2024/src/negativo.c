#include "negativo.h"

void negative(PPMImage *img) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].red = 255 - img->data[i].red;
        img->data[i].green = 255 - img->data[i].green;
        img->data[i].blue = 255 - img->data[i].blue;
    }
}