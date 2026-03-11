#include <stdio.h>
#include <stdint.h>

typedef struct Data{
    int id;
    double value;
    char name[25];
} Data;

int main(){

    FILE* f = fopen("fichier_bin.dat", "w");
    if( f == NULL )
        return 1;

    int16_t v1 = 0x61; // ASCII -> a
    fwrite(&v1, sizeof(int16_t), 1, f);
    // sizeof -> la taille du bloc à écrire
    // 1 : le nombre de bloc à écrire
    fclose(f);

    int tab[] = {1000, 2000, 3000, 126, -23};
    f = fopen("test_int.bin", "w");
    const size_t nb = sizeof(tab) / sizeof(tab[0]);
    fwrite(tab, sizeof(int), nb, f);
    fclose(f);

    // ftell - fseek
    f = fopen("test_int.bin", "r");
    int pos = ftell(f);
    printf("Pos start : %d\n", pos); // -> 0
    fseek(f, 0, SEEK_END); // déplace à la fin du fichier
    pos = ftell(f);
    printf("Pos end : %d\n", pos); // -> fin du fichier

    fseek(f, -2*sizeof(int), SEEK_END);
    pos = ftell(f);
    printf("Pos int -2 : %d\n", pos); // -> fin du fichier
    

    Data d = {.id = 12, .value = 3.14};
    d.name[0] = 'a';
    d.name[5] = '0';
    char* filename = "test_struct.bin";
    f = fopen(filename, "w");
    fwrite(&d, sizeof(Data), 1, f);
    d.id = 4;
    d.value = -10.6;
    fwrite(&d, sizeof(Data), 1, f);
    d.id = -2;
    d.value = 12e5;
    fwrite(&d, sizeof(Data), 1, f);
    fclose(f);



    int tab_r[10] = {0};
    f = fopen("test_int.bin", "r");
    fread(&tab_r, sizeof(int), 5, f);
    for( int i=0; i<5; i++)
        printf("I:%d = %d\n", i, tab_r[i]);
    fclose(f);

    Data d2 = {0};
    f = fopen(filename, "r");
    fseek(f, 2*sizeof(Data)+1, SEEK_SET);
    fread(&d2, sizeof(Data), 1, f);
    fclose(f);
    printf("id = %d\n value = %lf\n name = %s", d2.id, d2.value, d2.name);
}