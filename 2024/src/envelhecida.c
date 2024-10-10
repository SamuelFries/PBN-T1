#include "envelhecida.h"

void sepia(PPMImage *img, float factor) {
    for (int i = 0; i < img->width * img->height; i++) {
        int r = img->data[i * 3];
        int g = img->data[i * 3 + 1];
        int b = img->data[i * 3 + 2];

        int tr = (int) (0.390 * r + 0.770 * g + 0.190 * b);
        int tg = (int) (0.350 * r + 0.690 * g + 0.170 * b);
        int tb = (int) (0.270 * r + 0.530 * g + 0.130 * b);

        img->data[i * 3] = tr > 255 ? 255 : tr;
        img->data[i * 3 + 1] = tg > 255 ? 255 : tg;
        img->data[i * 3 + 2] = tb > 255 ? 255 : tb;
    }
}