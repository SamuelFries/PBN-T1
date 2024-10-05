#include "envelhecida.h"

void sepia(PPMImage *img, float factor) {
    for (int i = 0; i < img->width * img->height; i++) {
        int r = img->data[i * 3];
        int g = img->data[i * 3 + 1];
        int b = img->data[i * 3 + 2];

        int tr = (int) (0.393 * r + 0.769 * g + 0.189 * b);
        int tg = (int) (0.349 * r + 0.686 * g + 0.168 * b);
        int tb = (int) (0.272 * r + 0.534 * g + 0.131 * b);

        img->data[i * 3] = tr > 255 ? 255 : tr;
        img->data[i * 3 + 1] = tg > 255 ? 255 : tg;
        img->data[i * 3 + 2] = tb > 255 ? 255 : tb;
    }
}