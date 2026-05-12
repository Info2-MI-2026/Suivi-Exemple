#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    int x;
    int y;
    int z;
} Point;

typedef struct Node {
    Point point;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail;
} List;

Node* create_node(Point* p) {
    Node* node = malloc(sizeof(Node));
    if (node == NULL) 
        return NULL;
    

    node->point = *p;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

void init_list(List* list) {
    list->head = NULL;
    list->tail = NULL;
}

bool insert_point_first(List* l, Point* p){
    Node* new = create_node(p);
    if( new == NULL ) return false;

    if(l->head == NULL){ // liste vide
        l->head = new;
        l->tail = new;
    }
    else{
        new->next = l->head;
        l->head->prev = new; // previous
        l->head = new;
    }
    return true;
}

Point create_point(int x, int y, int z){
    Point p = {.x=x, .y=y, .z=z};
    return p;
}

bool insert_end(List* l, int x, int y, int z){
    Point p = create_point(x,y,z);
    Node* new = create_node(&p);
    if(new == NULL) return false;

    if(l->tail == NULL){ // liste vide
        l->head = new;
        l->tail = new;
    }
    else{
        new->prev = l->tail;
        l->tail->next = new;
        l->tail = new;
    }
    return true;
}

void print_reverse(List* l){
    if(l==NULL) return;

    Node* current = l->tail;
    while(current != NULL){
        printf("Point : x:%4d y:%4d z:%4d\n", current->point.x,
        current->point.y, current->point.z);
        current = current->prev;
    }
}

Node* find_node(List* l, Point* p){
    if(l==NULL) return NULL;

    Node* n = l->head;
    while(n != NULL){
        if(memcmp(&n->point, p, sizeof(Point)) == 0){
            return n;
        }
        n = n->next;
    }
    return NULL;
}

bool insert_point_after(List* l, Point* dest, Point* new_point){
   if( l == NULL || dest == NULL || new_point == NULL ) return false; 

    Node* node = find_node(l, dest);
    if( node == NULL) return false;

    Node* new = create_node(new_point);
    if( new == NULL ) return false;

    new->prev = node;
    new->next = node->next;

    // test si dernier
    if( node == l->tail ){
        l->tail = new;
    }
    else{
        node->next->prev = new;
    }
    node->next = new;
    return true;
}

int main(){
    List l = {0};
    init_list(&l);
    Point p = {.x=1, .y=2, .z=3};
    insert_point_first(&l, &p);
    p.x=10, p.y=20, p.z=30;
    insert_point_first(&l, &p);

    insert_end(&l, -10,-20,-30);
    print_reverse(&l);

    Point p1 = create_point(5,6,7);
    if( !insert_point_after(&l, &p, &p1) )
        exit(1);

    printf("After insert p\n");
    print_reverse(&l);
}