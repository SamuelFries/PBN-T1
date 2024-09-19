#include <stdio.h>
#include <stdlib.h>
#include "imagem_ppm.h"

PPMImage *readPPM(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("Erro ao abrir o arquivo.\n");
        return NULL;
    }

    char format[3];
    fscanf(fp, "%s", format);

    if (format[0] != 'P' || format[1] != '6') {
        printf("Formato de arquivo inválido.\n");
        fclose(fp);
        return NULL;
    }

    PPMImage *img = (PPMImage *)malloc(sizeof(PPMImage));
    fscanf(fp, "%d %d", &img->width, &img->height);

    int max_val;
    fscanf(fp, "%d", &max_val);
    fgetc(fp);  // Pula o caractere de nova linha após max_val

    img->data = (PPMPixel *)malloc(img->width * img->height * sizeof(PPMPixel));
    fread(img->data, sizeof(PPMPixel), img->width * img->height, fp);

    fclose(fp);
    return img;
}

void savePPM(const char *filename, P