#pragma once
#include "race_array.h"

#define ERROR_READ_FILE -100

void extractFromBinary(const char* filename, RaceArray* array);
void createBinaryFile(const char* filename);