#ifndef IMAGEM_PPM_H
#define IMAGEM_PPM_H

typedef struct {
    unsigned char red, green, blue;
} PPMPixel;

typedef struct {
    int width, height;
    PPMPixel *data;
} PPMImage;

PPMImage *readPPM(const char *filename);
void savePPM(const char *filename, PPMImage *img);

#endif