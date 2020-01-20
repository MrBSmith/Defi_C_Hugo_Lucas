#ifndef GAMESTATE_H_INCLUDED
#define GAMESTATE_H_INCLUDED

#include "player.h"
#include "level.h"

// Define the possible states of the game
typedef enum game_state{
    MOVE,
    DIALOGUE,
    INVENTORY,
    CHAT
} game_state;


//////// Prototypes ////////
void currentStateProcedure(game_state state, player* p_player, level* p_level_list[]);

void moveProcedure(INPUTS player_input, player* p_player, level* p_level_list[]);
void dialogueProcedure(INPUTS player_input, player* p_player);
void inventoryProcedure(INPUTS player_input, player* p_player);
void chatProcedure(INPUTS player_input, player* p_player);

void print_current_level(player* p_player);
void door_change_level(player* p_player, level* p_level_list[], door* p_door);

#endif // GAMESTATE_H_INCLUDED
