#ifndef TYPES_H_INCLUDED
#define TYPES_H_INCLUDED

// Define the posible states of the game
typedef enum game_state{
    MOVE,
    DIALOGUE,
    INVENTORY,
    CHAT
} game_state;


// Define the cells of a level
typedef struct level_cell{
    char content;
    colorVector2 color;
} level_cell;


// Define the level type
typedef struct level{
    vector2 dimension;
    level_cell level_array[10][10];
} level;


// Define player type
typedef struct player{
    char nom[15];
    vector2 position;
    level* p_current_level;
} player;

#endif // TYPES_H_INCLUDED
