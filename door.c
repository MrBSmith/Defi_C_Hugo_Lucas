#include <stdio.h>
#include <stdlib.h>

#include "door.h"

door* door_constructor(door* p_door, bool is_locked, level* p_level, int x_dest, int y_dest){

    p_door -> locked = is_locked;
    p_door -> p_destination_level = p_level;
    p_door -> dest_position.x = 0;
    p_door -> dest_position.y = 0;

    return *p_door
}
