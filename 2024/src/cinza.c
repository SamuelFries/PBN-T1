#include "cinza.h"

void grayscale(PPMImage *img) {
    for (int j = 0; j < img->height; j++) {
        for (int i = 0; i < img->width; i++) {
            int pos = (j * img->width + i) * 3;

            unsigned char r = img->data[pos];
            unsigned char g = img->data[pos + 1];
            unsigned char b = img->data[pos + 2];

            unsigned char gray = (r * 0.299) + (g * 0.587) + (b * 0.114);

            img->data[pos] = gray;
            img->data[pos + 1] = gray;
            img->data[pos + 2] = gray;
        }
    }
}