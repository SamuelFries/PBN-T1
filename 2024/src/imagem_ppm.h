#ifndef IMAGEM_PPM_H
#define IMAGEM_PPM_H

// Definição da estrutura da imagem PPM
typedef struct {
    int width;
    int height;
    unsigned char *data;  // Ponteiro para os dados da imagem
} PPMImage;

// Declarações das funções
PPMImage *readPPM(const char *filename);
void savePPM(const char *filename, PPMImage *image); // 'PPMImage *image' indica um ponteiro para uma estrutura PPMImage

#endif