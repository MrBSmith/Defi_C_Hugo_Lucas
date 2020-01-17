#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

// Define player type
typedef struct player{
    char nom[15];
    vector2 position;
    level* p_current_level;
} player;


//// PROTOTYPES ////
void initialize_player(player* p_player, level* p_level);

#endif // PLAYER_H_INCLUDED
