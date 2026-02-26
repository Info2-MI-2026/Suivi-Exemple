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
