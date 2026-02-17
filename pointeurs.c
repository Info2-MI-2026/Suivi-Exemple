
#include <stdio.h>

int main(){

    int tab[] = {4, 8, 12, 20};

    int val = 12;
    int* pi = NULL; // toujours init à NULL si adresse inconue
    pi = &val;
    
    int* pi1 = &val;

    // pointeur suite
    int* p2 = &tab[0];

    printf("Val %d\n", tab[0]);

    printf("Add val %p\n", &val);
    printf("Add val %p\n", pi);
    printf("Add pi %p\n", &pi); // Attention adresse du pointeur


    printf("Add tab[0] %p\n", &tab[0]);
    printf("Add tab[1] %p\n", &tab[1]);
    printf("Add tab[0] %p\n", p2);
    p2 += 1;
    printf("Add p2 + 1 %p\n", p2);
}
