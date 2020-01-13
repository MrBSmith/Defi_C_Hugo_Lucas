#ifndef PROTOTYPES_H_INCLUDED
#define PROTOTYPES_H_INCLUDED

//////// Prototypes ////////

// Procedures
void currentStateProcedure(game_state state, player* p_player);

void moveProcedure(INPUTS player_input, player* p_player);
void dialogueProcedure(INPUTS player_input, player* p_player);
void inventoryProcedure(INPUTS player_input, player* p_player);
void chatProcedure(INPUTS player_input, player* p_player);

// Initialisations
void initialize_player(player* p_player, level* p_level);
void initialize_map(level* p_level, int level_size_x, int level_size_y);

#endif // PROTOTYPES_H_INCLUDED
