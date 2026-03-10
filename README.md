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
