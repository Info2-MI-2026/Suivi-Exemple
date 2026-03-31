#include <stdio.h>
#include <stdlib.h>

void ex4()
{
    printf("Ex 4 allocation\n");
    
    int size = 7;

    // Allocation initiale
    int* tab = (int*)malloc(size * sizeof(int));

    // Vérification allocation
    if (tab == NULL) {
        printf("Erreur d'allocation mémoire\n");
        return;
    }

    for (int i = 0; i < 20; i++) {

        // Si on dépasse la capacité → on double
        if (i >= size) {
            int newSize = size * 2;

            int* temp = (int*)realloc(tab, newSize * sizeof(int));

            // Vérification realloc
            if (temp == NULL) {
                printf("Erreur de réallocation mémoire\n");
                free(tab);
                return;
            }

            tab = temp;
            size = newSize;

            printf("Tableau redimensionné à %d\n", size);
        }

        // Ajout de la valeur
        tab[i] = i;
    }

    // Affichage (optionnel)
    for (int i = 0; i < 20; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");

    free(tab);
}
