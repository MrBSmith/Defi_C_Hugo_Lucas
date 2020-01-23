#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "BabaGameLib.h"

// Define player type
typedef struct player{
    char nom[15];
    vector2 position;
} player;


//// PROTOTYPES ////
void initialize_player(player* p_player);

#endif // PLAYER_H_INCLUDED
