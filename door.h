#ifndef DOOR_H_INCLUDED
#define DOOR_H_INCLUDED

#include "BabaGameLib.h"
#include "level.h"

// Define door type
typedef struct door{
    BOOL locked;
    colorVector2 color;
} door;

//////// PROTOTYPES ////////
void initalize_door(door* p_door, BOOL is_locked);
void place_door(level* p_target_level, door* p_door, int x_pos, int y_pos);
BOULEIN is_cell_a_door(level_cell cell);

#endif // DOOR_H_INCLUDED
