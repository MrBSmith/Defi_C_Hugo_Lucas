#ifndef TYPES_H_INCLUDED
#define TYPES_H_INCLUDED

// D�finit les �tats possibles du jeu
typedef enum game_state{
    MOVE,
    DIALOGUE,
    INVENTORY,
    CHAT
} game_state;


// D�finit le type level
typedef struct level{
    vector2 dimension;
} level;


// D�finit le type player
typedef struct player{
    char nom[15];
    vector2 position;
    level* p_current_level;
} player;

#endif // TYPES_H_INCLUDED
