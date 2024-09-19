#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // Adicione esta linha para incluir strcmp
#include "imagem_ppm.h"

PPMImage *readPPM(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        return NULL;
    }

    char format[3];
    if (fscanf(file, "%2s", format) != 1 || strcmp(format, "P6") != 0) {
        fclose(file);
        return NULL;
    }

    int width, height, maxval;
    if (fscanf(file, "%d %d %d", &width, &height, &maxval) != 3 || maxval != 255) {
        fclose(file);
        return NULL;
    }

    fgetc(file);  // Consumir o caractere de nova linha após os cabeçalhos

    PPMImage *img = malloc(sizeof(PPMImage));
    img->width = width;
    img->height = height;
    img->data = malloc(width * height * 3);

    if (fread(img->data, 3, width * height, file) != width * height) {
        free(img->data);
        free(img);
        fclose(file);
        return NULL;
    }

    fclose(file);
    return img;
}

void savePPM(const char *filename, const PPMImage *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        return;
    }

    fprintf(file, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, 3, img->width * img->height, file);

    fclose(file);
}