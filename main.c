#include <stdio.h>
#include <stdlib.h>

#include "BabaGameLib.h"
#include "level.h"
#include "player.h"
#include "gameState.h"

// Main procedure
int main()
{
    // Level declaration
    level level1, level2, level3;
    level* p_level_list[3] = {&level1, &level2, &level3};
    for(int i = 0; i < 3; i++){
        initialize_level(p_level_list[i], 10, 10);
    }

    // Define the current level
    level* p_current_level = p_level_list[0];

    // Define the door 1 of level 1
    door door_level1;
    door* p_door_level1 = &door_level1;
    initalize_door(p_door_level1, FAUX, 2, 0, 0);

    // Place the door in the level
    place_door(p_current_level, p_door_level1, 9, 5);

    // Player declaration
    player local_player;
    player* p_player = &local_player;

    // Initialisation du player1
    initialize_player(p_player, p_level_list[0]);

    // Declaration de l'etat du jeu actuel
    game_state state = MOVE;

    // Lance la procedure de l'état actuel en boucle
    while(2){
        currentStateProcedure(state, p_player, p_level_list);
    }

    return 0;
}


