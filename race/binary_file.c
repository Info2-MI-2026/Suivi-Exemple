#include <stdio.h>
#include <stdlib.h>
#include "binary_file.h"
#include "race_array.h"

void extractFromBinary(const char* filename, RaceArray* array){
    if( array == NULL || filename == NULL ) exit(-1);

    FILE* f = fopen(filename, "rb");
    if(f == NULL ) exit(-1);

    int nbr_data = 0;
    int ret = fread(&nbr_data, sizeof(int), 1, f);
    if( ret != 1){
        fclose(f);
        exit(ERROR_READ_FILE);
    }

    #if 0
    RaceResult* tmp_array = malloc(sizeof(RaceResult) * nbr_data);
    ret = fread(tmp_array, sizeof(RaceResult), nbr_data, f);
    fclose(f);
    if(ret != nbr_data) exit(ERROR_READ_FILE);

    for(int i=0; i<nbr_data; i++){
        addResult(array, tmp_array[i]);
    }
    #else // plus simple mais moins perf.
    RaceResult result;
    for(int i=0; i<nbr_data; i++){
        ret = fread(&result, sizeof(RaceResult), 1, f);
        if(ret != 1) exit(ERROR_READ_FILE);
        addResult(array, result);
    }
    fclose(f);
    #endif
}


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