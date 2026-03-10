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

    Data d = {.id = 12, .value = 3.14};
    d.name[0] = 'a';
    d.name[5] = '0';
    f = fopen("test_struct.bin", "w");
    fwrite(&d, sizeof(Data), 1, f);
    fclose(f);

    int tab_r[10] = {0};
    f = fopen("test_int.bin", "r");
    fread(&tab_r, sizeof(int), 5, f);
    for( int i=0; i<5; i++)
        printf("I:%d = %d\n", i, tab_r[i]);
    fclose(f);

    Data d2 = {0};
    f = fopen("test_struct.bin", "r");
    fread(&d2, sizeof(Data), 1, f);
    fclose(f);
    printf("id = %d\n value = %lf\n name = %s", d2.id, d2.value, d2.name);
}