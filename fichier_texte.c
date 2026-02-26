#include <stdio.h>
#include <stdbool.h>

#define SIZE_BUFF 4

int main(void)
{

    FILE* fp = NULL; // toujours un pointeur

    fp = fopen("test.txt", "r"); // mode r, w, a  (a=append)
    if (fp == NULL)
    { // toujours tester si le fichier est ouvert
        return 12;
    }

    do
    {
        char c = fgetc(fp);
        if (c == EOF)
            break;
        printf("%c ", c);
    } while (true);

    fclose(fp); // fermer un fichier à la fin

    // lecture d'une ligne
    printf("\nLecture avec fgets\n");
    fp = fopen("test.txt", "r");
    if (fp == NULL)
    {
        return 12;
    }

    char line[SIZE_BUFF];
    do
    {
        char *l = fgets(line, SIZE_BUFF, fp); // lit une ligne et ajout \0
        if (l == NULL)                        // test la fin du fichier
            break;
        printf("%s\n", line);
    } while (true);
    fclose(fp);
}