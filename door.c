#include "door.h"

// Initialize a door
void initalize_door(door* p_door, BOOL is_locked){
    p_door -> locked = is_locked;
    p_door -> color = define_text_color(WHITE, BLUE);
}


// Place the given door in the given level at the given position
void place_door(level* p_target_level, door* p_door, int x_pos, int y_pos){
    p_target_level -> level_array[x_pos][y_pos].type = DOOR_CELL;
    //p_target_level -> level_array[x_pos][y_pos].p_object = p_door;
}


// Check if a given cell contains a door or not
BOULEIN is_cell_a_door(level_cell cell){
    if(cell.type == DOOR_CELL){
        return VRAI;
    }
    return FAUX;
}
