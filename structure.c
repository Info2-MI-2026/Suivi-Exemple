#include <stdio.h>

struct PointComplet{
    int x;
    int y;
    int z;
};

// on s'implifie avec typedef
typedef struct Point{
    int x;
    int y;
    int z;
} Point;

// fonction avec structure en copie
void print_point(Point p){
    printf("Le point : \n");
    printf("  x : %d\n", p.x);
    printf("  y : %d\n", p.y);
    printf("  z : %d\n", p.z);
}

void init_point(int x, int y, int z, Point* p){
    (*p).x = x; // pas bon
    p->y = y;
    p->z = z; // accès à une structure avec un pointeur
}

// ATTENTION
Point* new_point(void){
    Point p = {.x=1, .y=2, .z=3};
    return &p; // ne jamais retourner l'adresse d'une variable
}

int main(void){
// déclaration d'une structure
struct PointComplet p1 = {.x=1, .y=2, .z=3};
struct PointComplet p2 = {.x=1, .y=2, .z=3};

// plus besoin du struct comme mot clef
Point p10 = {.x=10, .y=20, .z=30}; // initialisation
Point p20;

p20.x = 0; // accès aux champs
p20.y = 12;

// comparaison d'une zone mémoire
// faux si chaîne de caractère
memcmp(&p20, &p10, sizeof(Point));

}