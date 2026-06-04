#include "race_array.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void initRaceArray(RaceArray* array, int initial_capacity){
    if( array == NULL || initial_capacity <= 0 || array->data != NULL )
        exit(PARAM_ERROR);

    // array->data = malloc(sizeof(RaceResult) * initial_capacity);
    array->data = malloc(sizeof *array->data * initial_capacity);
    if( array->data == NULL ) 
        exit(MALLOC_ERROR);
    
    array->capacity = initial_capacity;
    array->count = 0;
}

bool check_result_param(RaceResult* r){
    if( r->bib < 0 ||
            r->bib > 1000 ||
            r->time < 0 ||
            r->time > 1e5 ||
            strlen(r->name) < 3 ){
                return false;;
        }
    return true;
}

int find_pos_insert(RaceArray* a, RaceResult* r){
    if( a == NULL || r == NULL ) exit(PARAM_ERROR);
    for(int i=0; i<a->count; i++){
        if( a->data[i].time > r->time )
            return i;
    }
    return a->count;
}

void addResult(RaceArray* array, RaceResult result){
    if( array == NULL || array->data == NULL ) exit(PARAM_ERROR);

    if( !check_result_param(&result) ) exit(PARAM_ERROR);
    
    if( array->count >= array->capacity ){
        const int new_cap = array->capacity *= 2;
        RaceResult* tmp = realloc( array->data, sizeof(RaceArray) * new_cap );
        if( tmp == NULL ) exit(MALLOC_ERROR);

        array->capacity = new_cap;
        array->data = tmp;
    }    

    // if( array->count == 0 ){
    //     array->data[0] = result;
    //     array->count++;
    //     return;
    // }

    const int pos = find_pos_insert(array, &result);
    for(int ind = array->count; ind > pos; ind--){
        array->data[ind] = array->data[ind-1];
    }
    array->data[pos] = result;
    array->count++;
}

const char* categoryToString(Category c){
    switch(c){
        case JUNIOR: return "Junior";
        case SENIOR: return "Senior";
        case VETERAN: return "Veteran";
    }
    return "Undifined";
}

void printRaceArray(const RaceArray* array){
    if(array == NULL || array->data == NULL) exit(PARAM_ERROR);

    for(int i=0; i<array->count; i++){
        printf("Name : %s  -  time : %.2lf  - Cat : %s\n", 
            array->data[i].name, 
            array->data[i].time, 
            categoryToString(array->data[i].category)
        );
    }
}