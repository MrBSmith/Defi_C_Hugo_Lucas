#ifndef PROTOTYPES_H_INCLUDED
#define PROTOTYPES_H_INCLUDED

//////// Prototypes ////////

// Procedures
void currentStateProcedure(game_state state, player* p_player, level* p_current_level);

void moveProcedure(INPUTS player_input, player* p_player, level* p_current_level);
void dialogueProcedure(INPUTS player_input, player* p_player);
void inventoryProcedure(INPUTS player_input, player* p_player);
void chatProcedure(INPUTS player_input, player* p_player);

// Initializations
void initialize_player(player* p_player, level* p_level);
void initialize_map(level* p_current_level, int level_size_x, int level_size_y);

// Prints
void print_current_level(level* p_current_level, player* p_player);

#endif // PROTOTYPES_H_INCLUDED
