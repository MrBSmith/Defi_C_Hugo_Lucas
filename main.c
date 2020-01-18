#include <stdio.h>
#include <stdlib.h>

#include "BabaGameLib.h"
#include "level.h"
#include "door.h"
#include "player.h"
#include "gameState.h"


// Main procedure
int main()
{
    // Level declaration
    level level1, level2, level3;

    // Initialisation des maps
    level* p_level_list[3] = {&level1, &level2, &level3};
    for(int i = 0; i < 3; i++){
        initialize_level(p_level_list[i], 10, 10);
    }

    // Define the current level
    level* p_current_level = p_level_list[0];

    // Define the door 1 of level 1
    door door_level1;
    door* p_door_level1 = door_constructor(&door_level1, FAUX, p_current_level, 5, 5);

    // Declare the position of the door in level1
    p_current_level -> level_array[5][8].p_object = malloc(sizeof(door*));

    if(p_current_level -> level_array[5][8].p_object == NULL){
        exit(0);
    }

    p_current_level -> level_array[5][8].p_object = p_door_level1;


    // Player declaration
    player local_player;
    player* p_player = &local_player;

    // Initialisation du player1
    initialize_player(p_player, p_level_list[0]);

    // Declaration de l'etat du jeu actuel
    game_state state = MOVE;

    // Lance la procedure de l'état actuel en boucle
    while(2){
        currentStateProcedure(state, p_player, p_current_level);
    }

    return 0;
}


