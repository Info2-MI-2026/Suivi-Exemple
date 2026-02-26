/* gcc tri_fichier.c -Wall -oapp
./app tutu.txt

a
et
est
Hello
Bonjour
Vacances
Ordinateur
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 100

bool get_smaller_word(char* filename, int min_size, char* word){
    FILE* fp = fopen(filename, "r");
    if (fp == NULL){
        exit(12);
    }
    char line[SIZE];
    bool find = false;
    int actual_size = SIZE;
    //printf("Size : %d\n", min_size);
    do{
        if( fgets(line, SIZE, fp) == NULL ){
            break;
        }
        line[strcspn(line, "\n")] = '\0'; // remplace le \n par le \0

        const int len = strlen(line);
        if( len > min_size && len < actual_size ){
            strcpy(word, line);
            //printf("Update : %s\n", line);
            actual_size = strlen(line);
            find = true;
        }
    }while(true);
    fclose(fp);
    return find;

}

int main(int argc, char* argv[]){
    if(argc < 2){
        return 8;
    }
    int size = 0;
    char word[SIZE];

    while( get_smaller_word(argv[1], size, word) ){
        printf("%s\n", word);
        size = strlen(word);
    }
    return 0;
}