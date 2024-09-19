#include "rotacao.h"
#include <stdlib.h>
#include <string.h>

void rotacionar_90(PPMImage **img) {
    PPMImage *oldImg = *img;
    PPMImage *newImg = malloc(sizeof(PPMImage));
    newImg->width = oldImg->height;
    newImg->height = oldImg->width;
    newImg->data = malloc(newImg->width * newImg->height * 3);

    for (int y = 0; y < oldImg->height; y++) {
        for (int x = 0; x < oldImg->width; x++) {
            int oldIndex = (y * oldImg->width + x) * 3;
            int newIndex = ((oldImg->width - x - 1) * newImg->width + y) * 3;
            memcpy(&newImg->data[newIndex], &oldImg->data[oldIndex], 3);
        }
    }

    free(oldImg->data);
    free(oldImg);
    *img = newImg;
}