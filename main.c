#include <stdio.h>
#include <stdlib.h>
#include "input.h"

// Définit les états possibles du jeu
enum state_map{MOVE, DIALOGUE, INVENTORY, CHAT};

// Définit le type Vector2
typedef struct Vector2 Vector2;
struct Vector2{
    int x;
    int y;
};

// Définit le type player
typedef struct type_player type_player;
struct type_player {
    char nom[15];
    Vector2 position;
};

// Définit le type map
typedef struct type_map type_map;
struct type_map {
    Vector2 size;
};

//////// Prototypes ////////

// Procedures
int currentStateProcedure(int state, type_player *player, type_map *map);

void moveProcedure(int player_input, type_player *player, type_map *map);
void dialogueProcedure(int player_input, type_player *player);
void inventoryProcedure(int player_input, type_player *player);
void chatProcedure(int player_input, type_player *player);

// Initialisations
void initialize_player(type_player *player);
void initialize_map(type_map *map);

// Logique
Vector2 bound_position_to_map(Vector2 player_pos, Vector2 map_size);



// Main procedure
int main()
{
    int game_status = 0;
    type_player player1;
    type_map map1;

    // Initialisation du player1
    initialize_player(&player1);

    // Initialisation de la map1
    initialize_map(&map1);

    // Declaration de l'etat du jeu actuel
    int state = MOVE;

    // Lance la procedure de l'état actuel en boucle
    do{
        game_status = currentStateProcedure(state, &player1, &map1);
    } while (game_status == 0);

    return 0;
}

// Redirige vers la procedure de l'etat actuel du jeu
int currentStateProcedure(int state, type_player *player, type_map *map){

    int player_input = VOID;
    player_input = ask_input();

    switch(state){
        case MOVE : moveProcedure(player_input, player, map); break;
        case DIALOGUE : dialogueProcedure(player_input, player); break;
        case INVENTORY : inventoryProcedure(player_input, player); break;
        case CHAT : chatProcedure(player_input, player); break;
    }

    return 0;
}

// Procedure de l'etat MOVE
void moveProcedure(int player_input, type_player *player, type_map *map){

    switch(player_input){
        case UP: player -> position.y += 1; break;
        case DOWN: player -> position.y -= 1; break;
        case RIGHT: player -> position.x += 1; break;
        case LEFT: player -> position.x -= 1; break;
        case ENTER: printf("ENTER\n"); break;
    }

    player -> position = bound_position_to_map(player -> position, map -> size);

    // Affiche la position du joueur a l'ecran en texte
    printf("Position du joueur: (%d, %d)\n", player -> position.x, player -> position.y);
}

// Procedure de l'etat DIALOGUE
void dialogueProcedure(int player_input, type_player *p_player){
    printf("Dialogue\n");
}

// Procedure de l'etat INVENTORY
void inventoryProcedure(int player_input, type_player *p_player){
    printf("Inventory\n");
}

// Procedure de l'etat CHAT
void chatProcedure(int player_input, type_player *p_player){
    printf("Chat\n");
}

// Initialisation d'un joueur
void initialize_player(type_player *player){
    player -> position.x = 1;
    player -> position.y = 1;
}

// Initialisation d'une map (Taille de base: 10*10 cases)
void initialize_map(type_map *map){
    map -> size.x = 10;
    map -> size.y = 10;
}

// Limite la position du joueur aux limites de la map
// Prend en argument la position du joueur, et la taille de la map
// Renvoi la position du joueur, corigée si necesaire
Vector2 bound_position_to_map(Vector2 player_pos, Vector2 map_size){

    // Limite la position du joueur sur l'axe des x aux limites de la map
    if (player_pos.x <= 0){
        player_pos.x = 1;
    } else if (player_pos.x > map_size.x){
        player_pos.x = map_size.x;
    }

    // Limite la position du joueur sur l'axe des y aux limites de la map
    if (player_pos.y <= 0){
        player_pos.y = 1;
    } else if (player_pos.y > map_size.y){
        player_pos.y = map_size.y;
    }

    return player_pos;
}

