#include "wall.h"

// Initialize a wall
void initalize_wall(wall* p_wall, BOULEIN horiz){
    if(horiz == VRAI){
        p_wall -> content = '_';
    } else {
        p_wall -> content = '|';
    }
    p_wall -> horizontal = horiz;
}

// Place a wall in a level
void place_wall(level* p_target_level, wall* p_wall, int x_pos, int y_pos){
    if(p_wall -> horizontal == VRAI){
        p_target_level -> level_array[x_pos][y_pos].type = H_WALL_CELL;
    } else {
        p_target_level -> level_array[x_pos][y_pos].type = V_WALL_CELL;
    }
}


// Check if a given cell contains a wall or not
BOULEIN is_cell_a_wall(level_cell cell){
    if(cell.type == H_WALL_CELL || cell.type == V_WALL_CELL){
        return VRAI;
    }
    return FAUX;
}
