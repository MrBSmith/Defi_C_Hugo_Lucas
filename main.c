#include <stdio.h>
#include <stdlib.h>

#include "BabaGameLib.h"
#include "types.h"
#include "prototypes.h"
#include "functions.h"
#include "procedures.h"

// Main procedure
int main()
{
    // Level declaration
    level level1, level2, level3;

    // Initialisation des maps
    level* p_level_list[3] = {&level1, &level2, &level3};
    for(int i = 0; i < 3; i++){
        initialize_map(p_level_list[i], 10, 10);
    }


    // Player declaration
    player local_player;
    player* p_player = &local_player;

    // Initialisation du player1
    initialize_player(p_player, p_level_list[0]);

    // Declaration de l'etat du jeu actuel
    game_state state = MOVE;

    // Lance la procedure de l'état actuel en boucle
    while(2){
        currentStateProcedure(state, p_player);
    }

    return 0;
}


