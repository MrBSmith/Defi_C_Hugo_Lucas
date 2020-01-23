#ifndef WALL_H_INCLUDED
#define WALL_H_INCLUDED

#include "BabaGameLib.h"
#include "level.h"

typedef struct wall{
    BOULEIN horizontal;
    char content;
} wall;


//////// PROTOTYPES ////////
void initalize_wall(wall* p_wall, BOULEIN horiz);
void place_wall(level* p_target_level, wall* p_wall, int x_pos, int y_pos);
BOULEIN is_cell_a_wall(level_cell cell);

#endif // WALL_H_INCLUDED
