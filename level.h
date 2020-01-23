#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED

#include "BabaGameLib.h"
#include "player.h"

// Define the cell type
typedef enum cell_type{
    EMPTY_CELL,
    DOOR_CELL,
    H_WALL_CELL,
    V_WALL_CELL
} cell_type;


// Define the cells of a level
typedef struct level_cell{
    cell_type type;
    char content;
} level_cell;


// Define the level type
typedef struct level{
    vector2 dimension;
    level_cell level_array[30][30];
} level;


//// PROTOTYPES ////
void initialize_level(level* p_current_level, int level_size_x, int level_size_y);
void print_current_level(player* p_player, level* p_map);
BOULEIN is_position_valid(vector2 pos, level* p_map);

#endif // LEVEL_H_INCLUDED
