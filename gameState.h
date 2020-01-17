#ifndef TYPES_H_INCLUDED
#define TYPES_H_INCLUDED

// Define the possible states of the game
typedef enum game_state{
    MOVE,
    DIALOGUE,
    INVENTORY,
    CHAT
} game_state;


//////// Prototypes ////////
void currentStateProcedure(game_state state, player* p_player, level* p_current_level);

void moveProcedure(INPUTS player_input, player* p_player, level* p_current_level);
void dialogueProcedure(INPUTS player_input, player* p_player);
void inventoryProcedure(INPUTS player_input, player* p_player);
void chatProcedure(INPUTS player_input, player* p_player);

#endif // TYPES_H_INCLUDED
