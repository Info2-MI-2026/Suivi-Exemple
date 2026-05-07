# Cours 08.05 - Préprocesseur et enum
## Enumérations:
Les énumérations sont un moyen de définir des types de données personnalisés en C. Elles permettent de donner des noms significatifs à des valeurs entières, ce qui rend le code plus lisible et maintenable.

Exemple d'énumération :
```c
typedef enum {
    RED,
    GREEN,
    BLUE
} Color;

Color c = RED;
```

Dans cet exemple, `Color` est un type énuméré qui peut prendre les valeurs `RED`, `GREEN` ou `BLUE`. Les valeurs sont automatiquement assignées à des entiers, en commençant par 0 pour `RED`, 1 pour `GREEN` et 2 pour `BLUE`.
Il est possible de spécifier des valeurs spécifiques pour les énumérations :
```c
typedef enum {
    RED = 1,
    GREEN = 2,
    BLUE = 4
} Color;
Color c = GREEN;
```

## Préprocesseur:
Le préprocesseur est un outil qui permet de manipuler le code source avant la compilation. Il est utilisé pour inclure des fichiers, définir des macros et conditionner le code.

Les instructions de base sont :
- `#include` : inclut un fichier source ou une bibliothèque

- `#define` : définit une macro
- `#ifdef` : conditionne le code en fonction de la définition d'une macro

- `#if` : conditionne le code en fonction d'une expression
- `#else` : alternative à une condition

- `#endif` : termine une condition

Par exemple pour ne pas inclure une partie de code si une macro est définie :
```c
#ifdef DEBUG
    printf("Debug mode\n");
#endif
```

Cyberlearn : 
- [enum](https://cyberlearn.hes-so.ch/pluginfile.php/3491031/mod_resource/content/0/INFO2.06%20-%20Compl%C3%A9ments%20sur%20les%20types%20de%20donn%C3%A9es%20%28enum-union-bits%29.pdf)
- [preproc](https://cyberlearn.hes-so.ch/pluginfile.php/3491034/mod_resource/content/0/INFO2.04%20-%20Le%20pr%C3%A9processeur.pdf)

Handout : 
- [enum](https://heig-tin-info.github.io/handout/content/datatype.html?highlight=enum#enumerations)
- [prépro](https://heig-tin-info.github.io/handout/content/preprocessor.html?highlight=pr%C3%A9proc)


Exercices : 1 à 4
https://github.com/tony-maulaz/info2-exercices/blob/main/preproc.md


## 28.04.2026 - Les listes chaînées
[Ex helpdesk](https://github.com/tony-maulaz/info2-exercices/blob/main/liste_helpdesk.md)
  
## 14.04.2026 - Les listes chaînées

L'example d'implémentation d'une liste chaînée est dans le fichier `list.c`

Lien vers le [handout](https://heig-tin-info.github.io/handout/content/data-structures.html#listes-chainees)

Lien vers le [slides](https://cyberlearn.hes-so.ch/pluginfile.php/3432214/mod_resource/content/0/liste-chain%C3%A9e.pdf)

Lien vers [developpez.com](https://chgi.developpez.com/liste/)

Important : 
- Une liste chaînée est une structure de données qui permet de stocker des éléments de manière dynamique.
- Chaque élément de la liste est appelé un nœud.
- Chaque nœud est créé dynamiquement avec `malloc`.
- Chaque nœud contient une valeur et un pointeur vers le nœud suivant.
- Le dernier nœud de la liste pointe vers NULL.
- La liste chaînée est dynamique, ce qui signifie que la taille de la liste peut changer à tout moment.
- La liste chaînée est plus flexible qu'un tableau, car elle permet d'ajouter et de supprimer des éléments facilement.
- Pour insérer ou supprimer un élément dans une liste chaînée, il faut modifier les pointeurs des nœuds.
- Pour parcourir une liste chaînée, il faut utiliser une boucle et un pointeur temporaire `Node* current`.

Exercice :
- [Intro sur liste chaînée](https://github.com/tony-maulaz/info2-exercices/blob/main/liste_chainee.md)
- [Liste personne](https://github.com/tony-maulaz/info2-exercices/blob/main/liste_personne.md)
- [Liste de points 3D](https://github.com/tony-maulaz/info2-exercices/blob/main/liste-points.md)


## 25.03.26 - Tableaux dynamiques
Lien vers le [handout](https://heig-tin-info.github.io/handout/content/data-structures.html#tableau-dynamique)

Cyberlearn : [Allocation dynamique](https://cyberlearn.hes-so.ch/pluginfile.php/3400672/mod_resource/content/0/allocation-dynamique.pdf)


Exercice : 
- [tableaux dynamique](https://github.com/tony-maulaz/info2-exercices/blob/main/td_allocation.md)
- [tableaux dynamique binaire](https://github.com/tony-maulaz/info2-exercices/blob/main/allocation_binaire.md)

## 17.03.26 - Allocation dynamique de mémoire

Lien vers le [handout](https://heig-tin-info.github.io/handout/content/memory-management.html?highlight=malloc#allocation-dynamique)

Cyberlearn : [Allocation dynamique](https://cyberlearn.hes-so.ch/pluginfile.php/3400672/mod_resource/content/0/allocation-dynamique.pdf)


L'allocation dynamique permet de réserver de la mémoire à l'exécution. Cela permet de ne pas avoir à définir la taille d'un tableau à la compilation. La taille peut être définie à l'exécution et est exprimée en octets.

>Pour rappel, il est possible de connaître la taille d'un type avec l'opérateur `sizeof`.

- `malloc` alloue de la mémoire
- `free` libère de la mémoire
- `realloc` réalloue de la mémoire ou **alloue de la mémoire si le pointeur est `NULL`**
- `calloc` alloue de la mémoire et initialise à 0

`malloc` prend en argument la taille en octets et retourne un pointeur sur la mémoire allouée. Si la mémoire n'est pas allouée, la fonction retourne `NULL`.

`free` prend en argument un pointeur sur la mémoire à libérer.

Exemple pour un tableau de 10 entiers :
```c
int *tab = malloc(10 * sizeof(int));
tab[0] = 42;
free(tab);

// avec realloc
int *tab = realloc(NULL, 10 * sizeof(int)); // équivalent à malloc avec le pointeur NULL
```

## Important
- Il n'est pas possible de récupérer la taille d'une zone mémoire allouée dynamiquement.
- Il n'est pas possible d'utiliser sizeof sur une zone mémoire allouée dynamiquement (comme avec malloc).
- Si l'adresse d'une zone allouée est perdue (c’est-à-dire si le pointeur est écrasé ou oublié), il est impossible de la retrouver.

### Réallocation de mémoire
`realloc` permet de réallouer de la mémoire. 

- Elle prend en argument un pointeur sur la mémoire à réallouer et la nouvelle taille en octets. 
- Si la mémoire n'est pas allouée, la fonction retourne `NULL`.
- Si la réallocation échoue, la mémoire originale est conservée.
- Si la réallocation réussit, la mémoire originale est libérée et la fonction retourne un pointeur sur la nouvelle mémoire allouée.

Exemple pour un tableau de 10 entiers :
```c
int *tab = malloc(10 * sizeof(int));
tab = realloc(tab, 20 * sizeof(int));
```

### Exercices
- [Exercices allocation dynamique 1](https://github.com/tony-maulaz/info2-exercices/blob/main/allocation.md)
- [Exercices allocation dynamique 2](https://github.com/tony-maulaz/info2-exercices/blob/main/allocation_dynamique.md)

## 10.03.26 - Fichier binaire
- `fwrite` écrit dans un fichier binaire
- `fread` lit dans un fichier binaire
- `fseek` permet de se déplacer dans un fichier
- `ftell` permet de connaître la position actuelle dans un fichier
- `rewind` permet de revenir au début d'un fichier

`fwrite` et `fread` prennent 4 arguments :
- un pointeur sur le buffer
- la taille d'un élément
- le nombre d'éléments
- le fichier
- `fwrite(&i, sizeof(int), 1, f);`

`fseek` prend 3 arguments :
- le décalage
- le point de départ
  - SEEK_SET : début du fichier
  - SEEK_CUR : position actuelle
  - SEEK_END : fin du fichier
- le fichier
- `fseek(f, 0, SEEK_SET);`

A faire :
- fichier :
Ecrire dans un fichier avec fwrite "Bonjour" pour que l'on puisse le lire avec un éditeur de texte

- exercice 9 à 11 : https://github.com/tony-maulaz/info2-exercices/blob/main/fichier.md#ex-9
- exercice meas : https://github.com/tony-maulaz/info2-exercices/blob/main/measure.md
- exercice revision : https://github.com/tony-maulaz/info2-exercices/blob/main/fichier_revision.md

## 03.03.26 - Ecriture dans fichier texte
Pour écire dans un fichier texte, on peut utiliser les fonctions `fprintf` et `fputs` :
- `fprintf` est similaire à `printf` mais écrit dans un fichier
- `fputs` écrit une chaîne de caractères dans un fichier

> La console est un fichier spécial, on peut donc utiliser `fprintf` pour écrire dans la console en utilisant `stdout` comme fichier :
```c
fprintf(stdout, "Hello, World!\n");
```

```c
FILE* f = stdout; // stdout est un pointeur vers le flux de sortie standard
fprintf(f, "Hello, World!\n");
```

Exemples :
```c
FILE *f = fopen("file.txt", "w");
if (f == NULL) {
    return 1;
}
int value = 42;
fprintf(f, "The value is %d\n", value);
fputs("This is a file.\n", f);
fclose(f);
``` 

### Exercices :
- https://github.com/tony-maulaz/info2-exercices/blob/main/ecriture-fichier-texte.md

- https://github.com/tony-maulaz/info2-exercices/blob/main/fichier_texte.md

## 25.02.26 - Les fichiers textes
[handout fichier](https://heig-tin-info.github.io/handout/content/files.html#)

La manipulation de fichier se fera en utilisant un pointeur de type `FILE*` et les fonctions suivantes :

- `fopen` ouvre un fichier
  - `a` pour ajouter à la fin
  - `r` pour lire
  - `w` pour écrire
- `fclose` ferme un fichier
- `fgetc` lit un caractère
- `fgets` lit une ligne et retourne un pointeur sur le buffer (ou NULL si fin de fichier)

la fonction `fgets` lit une ligne, mais si la ligne est plus longue que le buffer, elle ne lit que le buffer et laisse le reste dans le fichier. La fonction ajoutera un `\0` à la fin du buffer.

Exercices :
- [Github exercices](https://github.com/tony-maulaz/info2-exercices/blob/main/fichier_texte.md)

- [Github structure](https://github.com/tony-maulaz/info2-exercices/blob/main/structure_fichier_texte.md)

## 24.02.26 - Structure
- [handout](https://heig-tin-info.github.io/handout/content/composite-datatypes.html#structures)
- Une structure est un ensemble de variables regroupées sous un même nom
- `struct` est le mot clé pour définir une structure
- `.` est l'opérateur pour accéder à un champ d'une structure
- `->` est l'opérateur pour accéder à un champ d'une structure pointée
- Pour comparer deux structures, il faut comparer chaque champ ou utiliser `memcmp`

```c
typedef struct {
    int x;
    int y;
} Point;

Point p = {.x = 1, .y = 2};
p.x = 3;
```

Exercices :
[Github](https://github.com/tony-maulaz/info2-exercices/blob/main/structure.md)


## 17.02.26 - Pointeur
Cours : 
- [handout](https://heig-tin-info.github.io/handout/content/pointers.html?highlight=pointeur)
- [Cyberlearn](https://cyberlearn.hes-so.ch/course/view.php?id=30885)

- Un pointeur est une variable qui contient l'adresse d'une autre variable
- le & est l'opérateur d'adresse de
- le * est l'opérateur de déréférencement (la valeur à l'adresse de)
- Si on incérmante un pointeur, on incrémente de la taille du type pointé

Pour afficher l’adresse d’une variable, il est possible d’utiliser l’opérateur d’adressage & et le spécificateur de format %p avec printf :
```c
int main(void) {
    int x = 42;

    printf("Adresse de x : %p\n", (void*)&x);

    return 0;
}
```

### Exercices :
- https://github.com/tony-maulaz/info2-exercices/blob/main/pointeurs_simple.md
- https://github.com/tony-maulaz/info2-exercices/blob/main/pointeur.md
