#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED

#include "BabaGameLib.h"

// Define door type
typedef struct door{
    char content;
    BOOL locked;
    int dest_level_index;
    vector2 dest_position;
    colorVector2 color;
} door;


// Define the cells of a level
typedef struct level_cell{
    BOULEIN empty_cell;
    door* p_door;
} level_cell;


// Define the level type
typedef struct level{
    vector2 dimension;
    level_cell level_array[10][10];
} level;


//// PROTOTYPES ////
void initialize_level(level* p_current_level, int level_size_x, int level_size_y);
void initalize_door(door* p_door, BOOL is_locked, int dest_level_index, int x_dest, int y_dest);
void place_door(level* p_target_level, door* p_door, int x_pos, int y_pos);

#endif // LEVEL_H_INCLUDED
