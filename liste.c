#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int value; // payload
    struct Node* next; // pointeur suivant
} Node;

typedef struct {
    Node* head;
} List;

void init_list(List* l){
    if(l == NULL) exit(1);

    l->head = NULL;
}

Node* create_node(int value){
    Node* new = malloc(sizeof(Node));
    if(new == NULL) exit(1);
    new->next = NULL;
    new->value = value;
    return new;
}

bool add_head(List* l, int data){
    Node* node = create_node(data);
    
    if(l->head == NULL) // liste est vide
        l->head = node;
    else{ // la liste contient un ou plusieurs noeuds
        node->next = l->head;
        l->head = node;
    }
    return true;
}

void print_list(List* p){

    Node* current = p->head;

    while(current != NULL){
        printf("Valeur : %d\n", current->value);
        current = current->next;
    }
}

bool list_pop_front(List* l, int* data){
    if(l->head == NULL) return false; // la liste est vide

    Node* to_delete = l->head;
    *data = to_delete->value;
    l->head = to_delete->next;
    free(to_delete);
    return true;
}

void free_list(List* l){
    if(l == NULL) return;

    int tmp;
    while(list_pop_front(l, &tmp)){}
}

int main(){
    List l = {0};
    init_list(&l);
    add_head(&l,4);
    add_head(&l,8);
    add_head(&l,12);
    print_list(&l);

    int cpt = 0;

    int* pi;
    *pi = 12;

    int* pi1 = malloc(sizeof(int));
    *pi1 = 12;
}