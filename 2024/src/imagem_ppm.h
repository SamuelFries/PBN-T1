// imagem_ppm.h
#ifndef IMAGEM_PPM_H
#define IMAGEM_PPM_H

typedef struct {
    int width;
    int height;
    unsigned char *data;
} PPMImage;

PPMImage *readPPM(const char *filename);
void savePPM(const char *filename, const PPMImage *image); // Atualize para const

#endif