#include <stdio.h>

typedef struct{
    int id;
    double val;
    char txt[10];
} Meas;

int count(char* filename){
    FILE* f = fopen(filename, "r");
    fseek(f, 0, SEEK_END);
    long pos = ftell(f);
    return pos / sizeof(Meas);
}

int main(){

    Meas d = {.id = 12, .val = 3.14};
    char* filename = "Test_ex11.bin";
    FILE* f = fopen(filename, "w");
    fwrite(&d, sizeof(Meas), 1, f);
    fwrite(&d, sizeof(Meas), 1, f);
    fwrite(&d, sizeof(Meas), 1, f);
    fwrite(&d, sizeof(Meas), 1, f);
    fclose(f);

    printf("Number of struct : %d\n", count(filename));
}