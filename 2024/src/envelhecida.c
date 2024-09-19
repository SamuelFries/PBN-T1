#include "envelhecida.h"

void sepia(PPMImage *img, float factor) {
    for (int i = 0; i < img->width * img->height; i++) {
        unsigned char old_red = img->data[i].red;
        unsigned char old_green = img->data[i].green;
        unsigned char old_blue = img->data[i].blue;

        img->data[i].red = (unsigned char) (old_red * 0.393 + old_green * 0.769 + old_blue * 0.189) * factor;
        img->data[i].green = (unsigned char) (old_red * 0.349 + old_green * 0.686 + old_blue * 0.168) * factor;
        img->data[i].blue = (unsigned char) (old_red * 0.272 + old_green * 0.534 + old_blue * 0.131) * factor;
    }
}