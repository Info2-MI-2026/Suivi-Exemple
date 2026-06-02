#pragma once

#define NAME_LENGTH 20

#define PARAM_ERROR -1
#define MALLOC_ERROR -2

typedef enum {
    JUNIOR = 0,
    SENIOR = 1,
    VETERAN = 2
} Category;

typedef struct {
    int bib;
    double time;
    char name[NAME_LENGTH];
    Category category;
} RaceResult;

typedef struct {
    RaceResult* data;
    int count;
    int capacity;
} RaceArray;

void initRaceArray(RaceArray* array, int initial_capacity);
void addResult(RaceArray* array, RaceResult result);