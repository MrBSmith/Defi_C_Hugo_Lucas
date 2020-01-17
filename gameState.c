#include <stdio.h>
#include <stdlib.h>

#include "BabaGameLib.h"

//////// PROCEDURE DES ETATS DU JEU ////////

// Redirige vers la procedure de l'etat actuel du jeu
void currentStateProcedure(game_state state, player* p_player, level* p_current_level){

    INPUTS input  = ask_for_input();

    switch(state){
        case MOVE : moveProcedure(input, p_player, p_current_level); break;
        case DIALOGUE : dialogueProcedure(input, p_player); break;
        case INVENTORY : inventoryProcedure(input, p_player); break;
        case CHAT : chatProcedure(input, p_player); break;
    }
}


// Procedure de l'etat MOVE
void moveProcedure(INPUTS player_input, player* p_player, level* p_current_level){

    switch(player_input){
        case UP: p_player -> position.y -= 1; break;
        case DOWN: p_player -> position.y += 1; break;
        case RIGHT: p_player -> position.x += 1; break;
        case LEFT: p_player -> position.x -= 1; break;
        case ENTER: printf("ENTER\n"); break;
        default: break;
    }


    p_player -> position = ceil_position(p_player -> position, 0, p_player -> p_current_level -> dimension.x - 1, 0, p_player -> p_current_level -> dimension.y - 1);

    // Refresh screen
    system("cls");

    // Affiche la position du joueur a l'ecran en texte
    printf("Position du joueur: (%d, %d)\n", p_player -> position.x, p_player -> position.y);

    // Print current level
    print_current_level(p_current_level, p_player);
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
