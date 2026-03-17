#include <stdio.h>
#include <stdlib.h>

// ./app 1 2 3 4 5
// ./app 1 2 3
int main(int argc, char* argv[]){

    if(argc < 2 ) exit(1);

    int nbr;
    sscanf(argv[1], "%d", &nbr);
    
    int* tab = malloc(sizeof(int) * nbr);
    //int* tab = realloc(NULL, sizeof(int) * nbr);
    if( tab == NULL ) // on test pour control de la mémoire
        exit(2);

    printf("La zone : %p\n", tab);

    tab[0] = 4;
    tab[1] = -6;
    // tab[10] = 1; // attention au débordement

    for(int i=0; i<nbr; i++){
        tab[i] = i*i;
    }

    for(int k=0; k<nbr; k++){
        printf("Val %d : %d\n", k, tab[k]);
    }

    // augmenter la taille
    int* new_tab = realloc(tab, sizeof(int) * nbr * 2);
    // copier les valeurs tab -> new_tab
    // free tab
    if( new_tab == NULL ){
        // tab existe toujours
        printf("print tab : %d\n", tab[0]);
        exit(3);
    }

    printf("La nouvelle zone : %p\n", new_tab);

    free(new_tab); // on libère la mémoire
}