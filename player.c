#include "player.h"

// Initialization of a player
void initialize_player(player* p_player, level* p_level)
{
    p_player -> position.x = 0;
    p_player -> position.y = 0;
    p_player -> p_current_level = p_level;
}
