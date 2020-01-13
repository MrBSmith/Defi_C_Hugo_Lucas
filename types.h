#ifndef TYPES_H_INCLUDED
#define TYPES_H_INCLUDED

// Définit les états possibles du jeu
typedef enum game_state{
    MOVE,
    DIALOGUE,
    INVENTORY,
    CHAT
} game_state;


// Définit le type level
typedef struct level{
    vector2 dimension;
} level;


// Définit le type player
typedef struct player{
    char nom[15];
    vector2 position;
    level* p_current_level;
} player;

#endif // TYPES_H_INCLUDED
