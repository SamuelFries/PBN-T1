#include "ppm.h"
#include <stdio.h>

void generate_image(const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    int width = 400;
    int height = 400;

    // Write PPM header
    fprintf(file, "P6\n%d %d\n255\n", width, height);

    // Write pixel data (example: solid red color)
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            fputc(255, file); // Red
            fputc(0, file);   // Green
            fputc(0, file);   // Blue
        }
    }

    fclose(file);
}