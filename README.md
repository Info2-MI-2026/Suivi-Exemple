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
