#include <stdio.h>

// #define DEBUG 
#define SIZE 10

#ifndef M_PI
    #define M_PI 3.14
#endif

#define REPEAT_A(x)  for(int i=0; i<x; i++){printf("a");};

#define ADD(a,b) (a+b)

// int
typedef enum {
    RED = 2, // 0
    GREEN, // 1
    BLUE, // 2
    VIOLET = 0,
    BLACK
} Color;

typedef enum {
    // RED, attention existe déjà
    ORANGE
} Light;

void print_color(Color c){
    if( c == RED ) printf("Red");
    else if( c == GREEN ) printf("GREEN");
}

void test(void){
    printf("Test\n");
}

int main(void){

    test();
    test(1,2,34);

    REPEAT_A(3)

    int res = ADD(3,4) * 2;

    int tab[SIZE + 4]; // remplace SIZE par 10

    Color c = BLACK;

    #if SIZE == 10
    //
    #endif

    #ifdef DEBUG
    print_color(c);
    #endif

    if( c == RED ){
        printf("La couleur est rouge\n");
    }

    printf("c : %d\n", c);

}