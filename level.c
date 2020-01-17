#include <stdio.h>
#include <stdlib.h>

#include "level.h"

// Initialization of a level
void initialize_map(level* p_current_level, int level_size_x, int level_size_y){
    p_current_level -> dimension.x = level_size_x;
    p_current_level -> dimension.y = level_size_y;
    for(int i = 0; i < level_size_y; i++){
        for(int j = 0; j < level_size_x; j++){
            p_current_level -> level_array[j][i].content = ' ';
            p_current_level -> level_array[j][i].p_object = NULL;
        }
    }
}
