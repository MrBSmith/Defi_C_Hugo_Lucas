#include "door.h"

door* door_constructor(door* p_door, BOOL is_locked, level* p_level, int x_dest, int y_dest){

    p_door -> locked = is_locked;
    p_door -> p_destination_level = p_level;
    p_door -> dest_position.x = 0;
    p_door -> dest_position.y = 0;
    p_door -> color = define_text_color(WHITE, BLUE);

    return p_door;
}
