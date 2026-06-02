#include "binary_file.h"
#include "race_array.h"

int main(){
    createBinaryFile("result.bin");
    RaceArray race_array = {0};
    initRaceArray(&race_array, 3);
}