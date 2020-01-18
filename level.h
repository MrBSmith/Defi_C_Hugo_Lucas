#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED

#include "BabaGameLib.h"

// Define the cells of a level
typedef struct level_cell{
    char content;
    colorVector2 color;
    void* p_object;
} level_cell;


// Define the level type
typedef struct level{
    vector2 dimension;
    level_cell level_array[10][10];
} level;


//// PROTOTYPES ////
void initialize_level(level* p_current_level, int level_size_x, int level_size_y);

#endif // LEVEL_H_INCLUDED
