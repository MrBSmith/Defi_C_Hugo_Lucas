#ifndef GAMESTATE_H_INCLUDED
#define GAMESTATE_H_INCLUDED

#include "player.h"
#include "level.h"
#include "door.h"

// Define the possible states of the game
typedef enum game_state{
    MOVE,
    DIALOGUE,
    INVENTORY,
    CHAT
} game_state;


//////// Prototypes ////////
void currentStateProcedure(game_state state, player* p_player, level* p_map);

void moveProcedure(INPUTS player_input, player* p_player, level* p_map);
void dialogueProcedure(INPUTS player_input, player* p_player);
void inventoryProcedure(INPUTS player_input, player* p_player);
void chatProcedure(INPUTS player_input, player* p_player);

void print_current_level(player* p_player, level* p_map);

#endif // GAMESTATE_H_INCLUDED
