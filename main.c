#include <stdio.h>
#include <stdlib.h>

#include "BabaGameLib.h"
#include "player.h"
#include "level.h"
#include "door.h"
#include "wall.h"
#include "gameState.h"
#include "txt_file.h"

// Main procedure
int main()
{
    // Level declaration & initialization
    level map;
    level* p_map = &map;
    initialize_level(p_map, 30, 30);

    // Read the txt file and store the date in an array
    read_map_in_txt_file("Map.txt", p_map);

    // Player declaration
    player local_player;
    player* p_player = &local_player;
    initialize_player(p_player);

    // print the current level before the player make any input
    print_current_level(p_player, p_map);

    // Declaration de l'etat du jeu actuel
    game_state state = MOVE;

    // Lance la procedure de l'état actuel en boucle
    while(2){
        currentStateProcedure(state, p_player, p_map);
    }

    return 0;
}


