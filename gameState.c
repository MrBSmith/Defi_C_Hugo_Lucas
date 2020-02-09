#include "gameState.h"
#include "player.h"

#include "level.h"
#include "wall.h"
#include "door.h"
#include "BabaGameLib.h"

//////// PROCEDURE DES ETATS DU JEU ////////

// Redirige vers la procedure de l'etat actuel du jeu
void currentStateProcedure(game_state state, player* p_player, level* p_map){

    INPUTS input  = ask_for_input();

    switch(state){
        case MOVE : moveProcedure(input, p_player, p_map); break;
        case DIALOGUE : dialogueProcedure(input, p_player); break;
        case INVENTORY : inventoryProcedure(input, p_player); break;
        case CHAT : chatProcedure(input, p_player); break;
    }
}


// Procedure de l'etat MOVE
void moveProcedure(INPUTS player_input, player* p_player, level* p_map){

    vector2 potential_pos = p_player -> position;

    switch(player_input){
        case UP: potential_pos.x -= 1; break;
        case DOWN: potential_pos.x += 1; break;
        case RIGHT: potential_pos.y += 1; break;
        case LEFT: potential_pos.y -= 1; break;
        case ENTER: break;
        default: break;
    }

    if(is_position_valid(potential_pos, p_map) == VRAI){
        // Ceil the player's postion to the boundries of the map
        potential_pos = ceil_position(potential_pos, 0, (p_map -> dimension.x) - 1, 0, (p_map -> dimension.y) - 1);

        // Move the player if the potential position is valid and inside the map
        p_player -> position = potential_pos;
    }

    // Refresh screen
    system("cls");

    // Affiche la position du joueur a l'ecran en texte (DEBUG)
    //printf("Position du joueur: (%d, %d)\n", p_player -> position.x, p_player -> position.y);

    // Print current level
    print_current_level(p_player, p_map);
}


// Procedure de l'etat DIALOGUE
void dialogueProcedure(INPUTS player_input, player* p_player){
    printf("Dialogue\n"); // Yet to develop
}


// Procedure de l'etat INVENTORY
void inventoryProcedure(INPUTS player_input, player* p_player){
    printf("Inventory\n"); // Yet to develop
}


// Procedure de l'etat CHAT
void chatProcedure(INPUTS player_input, player* p_player){
    printf("Chat\n"); // Yet to develop
}

