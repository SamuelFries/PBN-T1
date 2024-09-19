#include "rotacao.h"
#include <stdlib.h>

void rotacionar_90(PPMImage **img) {
    PPMImage *rotated = (PPMImage *) malloc(sizeof(PPMImage));
    rotated->width = (*img)->height;
    rotated->height = (*img)->width;
    rotated->data = (PPMPixel *) malloc(rotated->width * rotated->height * sizeof(PPMPixel));

    for (int y = 0; y < (*img)->height; y++) {
        for (int x = 0; x < (*img)->width; x++) {
            rotated->data[x * rotated->height + (rotated->height - y - 1)] = (*img)->data[y * (*img)->width + x];
        }
    }

    free((*img)->data);
    free(*img);
    *img = rotated;
}