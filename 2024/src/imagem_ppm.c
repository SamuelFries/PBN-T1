#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura PPMImage
typedef struct {
    int width;              // Largura da imagem
    int height;             // Altura da imagem
    unsigned char *data;    // Dados da imagem (R, G, B para cada pixel)
} PPMImage;

// Função para ler imagem PPM
PPMImage *readPPM(const char *filename) {
    FILE *file;
    PPMImage *img;
    char buffer[16];
    int maxval;

    // Inicialize a estrutura PPMImage para evitar erros
    img = (PPMImage *)malloc(sizeof(PPMImage));
    if (!img) {
        fprintf(stderr, "Falha ao alocar memória para a imagem.\n");
        return NULL;
    }

    file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Não foi possível abrir o arquivo.\n");
        free(img);  // Libera a memória alocada antes de retornar
        return NULL;
    }

    // Lê o tipo de imagem
    if (!fgets(buffer, sizeof(buffer), file)) {
        fprintf(stderr, "Leitura do tipo de arquivo PPM falhou.\n");
        free(img);  // Libera a memória alocada antes de retornar
        fclose(file);
        return NULL;
    }

    // Verifica o tipo de imagem (P6 é binário)
    if (buffer[0] != 'P' || buffer[1] != '6') {
        fprintf(stderr, "Formato de arquivo PPM inválido.\n");
        free(img);  // Libera a memória alocada antes de retornar
        fclose(file);
        return NULL;
    }

    // Lê as dimensões da imagem e o valor máximo
    if (fscanf(file, "%d %d %d", &img->width, &img->height, &maxval) != 3) {
        fprintf(stderr, "Cabeçalho PPM inválido.\n");
        free(img);  // Libera a memória alocada antes de retornar
        fclose(file);
        return NULL;
    }

    img->data = (unsigned char *)malloc(img->width * img->height * 3);
    if (!img->data) {
        fprintf(stderr, "Falha ao alocar memória para os dados da imagem.\n");
        free(img);  // Libera a memória alocada antes de retornar
        fclose(file);
        return NULL;
    }

    // Lê os dados da imagem
    if (fread(img->data, 3, img->width * img->height, file) != (unsigned long)(img->width * img->height)) {
        fprintf(stderr, "Erro ao ler os dados da imagem.\n");
        free(img->data);
        free(img);
        fclose(file);
        return NULL;
    }

    fclose(file);
    return img;
}

// Função para salvar imagem PPM
void savePPM(const char *filename, const PPMImage *img) {
    FILE *file;
    file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Não foi possível abrir o arquivo para escrita.\n");
        return;
    }

    // Escreve o cabeçalho
    fprintf(file, "P6\n%d %d\n255\n", img->width, img->height);

    // Escreve os dados da imagem
    if (fwrite(img->data, 3, img->width * img->height, file) != (unsigned long)(img->width * img->height)) {
        fprintf(stderr, "Erro ao escrever no arquivo.\n");
    }

    fclose(file);
}