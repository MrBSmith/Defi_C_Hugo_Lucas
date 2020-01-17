#ifndef DOOR_H_INCLUDED
#define DOOR_H_INCLUDED

// Define door type
typedef struct door{
    bool locked;
    level* p_destination_level;
    vector2 dest_position;
    colorVector2 color;
} door;


//// PROTOTYPES ////
door* door_constructor(door* p_door, bool is_locked, level* p_level, int x_dest, int y_dest);


#endif // DOOR_H_INCLUDED
