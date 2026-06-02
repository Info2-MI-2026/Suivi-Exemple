#include <stdio.h>
#include <stdlib.h>
#include "binary_file.h"

void createBinaryFile(const char* filename) {
    RaceResult results[] = {
        {12, 3245.78, "Dupont",   SENIOR},
        {47, 2987.12, "Martin",   VETERAN},
        {3,  3502.45, "Bernard",  JUNIOR},
        {28, 2845.90, "Lefebvre", SENIOR},
        {56, 3678.33, "Moreau",   JUNIOR},
        {91, 3120.05, "Garcia",   VETERAN},
        {7,  2756.88, "Rousseau", SENIOR}
    };
    int n = sizeof(results) / sizeof(results[0]);

    FILE* file = fopen(filename, "wb");
    if (!file) {
        perror("Erreur création fichier binaire");
        exit(-1);
    }
    fwrite(&n, sizeof(int), 1, file);
    fwrite(results, sizeof(RaceResult), n, file);
    fclose(file);
}