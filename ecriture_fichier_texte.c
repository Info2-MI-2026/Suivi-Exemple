#include <stdio.h>
#include <stdlib.h>

#define ERROR_FILE 3

int main(void){

    char* filename = "test.txt";
    FILE* file = fopen(filename, "a");

    // FILE* file = stdout;
    
    if( file == NULL )
        exit(ERROR_FILE);

    int a = 34;
    fprintf(file, "La valeur est : %d\n", a);

    fprintf(file, "a=%d [N]  -  b=%.2lf [g]\n", a, 3.14);

    fputs("Fin du fichier", file);

    fclose(file);
}