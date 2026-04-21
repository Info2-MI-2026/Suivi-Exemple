#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int size;
    int count;
    int* tab;
} Array;

bool add_value(Array* a, int value){
    if(a == NULL || a->tab == NULL) // exist ?
        return false;

    if( a->count >= a->size-1 ) // plein
        return false;

    a->tab[a->count] = value;
    a->count++;
}

bool init_array(Array* a, int size){
    a->tab = malloc(sizeof(int) * size);
    if( a->tab == NULL ) return false;

    a->size = size;
    a->count = 0;
}

int main(){
    const int nbr = 10;
    int pos = 0;
    int* tab = malloc(sizeof(int) * nbr);

    Array a1 = {0};
    init_array(&a1, 30);
    add_value(&a1, 30);
    add_value(&a1, 40);
}