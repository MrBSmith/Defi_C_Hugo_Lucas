#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

enum INPUT {UP, LEFT, DOWN, RIGHT, INV, ENTER, ESC, ERROR, VOID};

// Prototype ask_input
int ask_input();

// Demande au joueur de rentrer un caractère, retourne une action déclarée dans l'enum INPUT, déclarée plus haut
int ask_input(){
    char player_input = VOID;
    int returned_val;

    player_input = getch();

    switch(player_input){
        case ('z'):
            returned_val = UP; break;
        case ('q'):
            returned_val = LEFT; break;
        case ('s'):
            returned_val = DOWN; break;
        case ('d'):
            returned_val = RIGHT; break;
        case ('i'):
            returned_val = INV; break;
        case 13 :
            returned_val = ENTER; break;
        case 27 :
            returned_val = ESC; break;
        default :
            returned_val = ERROR; break;
    }

    return returned_val;
}
