#ifndef DOOR_H_INCLUDED
#define DOOR_H_INCLUDED

#include "BabaGameLib.h"
#include "level.h"

// Define door type
typedef struct door{

    BOOL locked;
    level* p_destination_level;
    vector2 dest_position;
    colorVector2 color;

} door;

//// PROTOTYPES ////
door* door_constructor(door* p_door, BOOL is_locked, level* p_level, int x_dest, int y_dest);

#endif // DOOR_H_INCLUDED
