#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

//////// INITIALISATION ////////

// Initialisation d'une map (Taille de base: 10*10 cases)
void initialize_map(level* current_level, int level_size_x, int level_size_y){
    current_level -> dimension.x = level_size_x;
    current_level -> dimension.y = level_size_y;
}


// Initialisation d'un player
void initialize_player(player* p_player, level* p_level){
    p_player -> position.x = 0;
    p_player -> position.y = 0;
    p_player -> p_current_level = p_level;
}

#endif // FUNCTIONS_H_INCLUDED
