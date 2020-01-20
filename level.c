#include "level.h"

// Initialization of a level
void initialize_level(level* p_current_level, int level_size_x, int level_size_y){

    p_current_level -> dimension.x = level_size_x;
    p_current_level -> dimension.y = level_size_y;

    colorVector2 normal_color = define_text_color(WHITE, BLACK);

    for(int i = 0; i < level_size_y; i++){
        for(int j = 0; j < level_size_x; j++){
            p_current_level -> level_array[j][i].p_door = NULL;
            p_current_level -> level_array[j][i].empty_cell = VRAI;
        }
    }
}

// Initialize a door
void initalize_door(door* p_door, BOOL is_locked, int dest_level_index, int x_dest, int y_dest){
    p_door -> content = ' ';
    p_door -> locked = is_locked;
    p_door -> dest_level_index = dest_level_index;
    p_door -> dest_position.x = x_dest;
    p_door -> dest_position.y = y_dest;
    p_door -> color = define_text_color(WHITE, BLUE);
}


// Place the given door in the given level at the given position
void place_door(level* p_target_level, door* p_door, int x_pos, int y_pos){
    p_target_level -> level_array[x_pos][y_pos].empty_cell = FAUX;
    p_target_level -> level_array[x_pos][y_pos].p_door = p_door;
}
