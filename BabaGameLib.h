// BabaGameLib.h

// Created on: 13 janv. 2020
// Author: Hugo Baba

#ifndef BABAGAMELIB_H_
#define BABAGAMELIB_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <unistd.h>

//////// TYPES DEFINITIONS ////////

// Booleen
typedef enum bool{
	false,
	true
} bool;


// Color list definition
typedef enum COLOR{
    BLACK = 0,
	DARK_BLUE = 1,
    GREEN = 2,
	BLUE_GREY = 3,
	BROWN = 4,
	CRIMSON = 5,
    KAKI = 6,
	LIGHT_GREY = 7,
	GREY = 8,
    BLUE = 9,
	LIGHT_GREEN = 10,
	TURQUOISE = 11,
    RED = 12,
	PINK = 13,
	YELLOW = 14,
    WHITE = 15
} COLOR;


// Input list definition
typedef enum INPUTS{
    EMPTY_INPUT,
    UP,
    DOWN,
    LEFT,
    RIGHT,
    ENTER,
    SPACE,
	ESCAPE,
    ERR
} INPUTS;


// Vector2 definition
typedef struct vector2{
    int x;
    int y;
} vector2;


// color Vector2 definition
typedef struct colorVector2{
	COLOR text_col;
	COLOR back_col;
} colorVector2;


//////// CONSTANTES ////////


// Text color definition
colorVector2 NORMAL_TEXT = {WHITE, BLACK};
colorVector2 NEGATIVE_TEXT = {BLACK, WHITE};
colorVector2 RED_TEXT = {RED, BLACK};
colorVector2 GREEN_TEXT = {GREEN, BLACK};
colorVector2 BLUE_TEXT = {BLUE, BLACK};
colorVector2 RED_BACK_TEXT = {WHITE, RED};
colorVector2 GREEN_BACK_TEXT = {WHITE, GREEN};
colorVector2 BLUE_BACK_TEXT = {WHITE, BLUE};


//////// PROTOTYPES ////////


//////// INITIALIZE CHAR ARRAY ////////
void initalise_char_array(int size_x, int size_y, char char_array[size_y][size_x]);

//////// VECTOR2 RELATED FUNCTIONS ////////
void reset_vector2_pos(vector2* p_position);
vector2 ceil_position(vector2 position, int x_min, int x_max, int y_min, int y_max);


//////// MENU NAVIGATION FUNCTIONS ////////
int navigate_menu(int index, int menu_size, INPUTS input);


//////// BINARY FILE RELATED FUNCTIONS ////////
void write_score(char name[20], int score);


//////// COLOR RELATED FUNCTIONS ////////
void change_text_color(colorVector2 cell_color);


//////// PRINT ARRAYS ////////
void print_array(int array_size, char arr[array_size][array_size]);
void print_array_color(int array_size, char arr[array_size][array_size], colorVector2 color);


//////// INPUT RELATED FUNCTIONS ////////
INPUTS ask_for_input();


//////// TOGGLE FUNCTION ////////
void toggle_bool(bool booleen);


//////// FUNCTIONS DECLARATIONS ////////


//////// VECTOR2 RELATED FUNCTIONS ////////

// Reset cursor position
void reset_vector2_pos(vector2* p_position){
	p_position -> x = 0;
	p_position -> y = 0;
}


// Ceil the given position to given min and max
vector2 ceil_position(vector2 position, int x_min, int x_max, int y_min, int y_max){
    if(position.x < x_min){
    	position.x = x_min;
    } else if(position.x > x_max){
    	position.x = x_max;
    }
    if(position.y < y_min){
    	position.y = y_min;
    } else if(position.y > y_max){
    	position.y = y_max;
    }

    return position;
}


//////// MENU NAVIGATION FUNCTIONS ////////

// Menu navigation
int navigate_menu(int index, int menu_size, INPUTS input){
    if(input == UP){
        index--;
        if(index < 0){
            index = menu_size - 1;
        }
    } else if(input == DOWN){
        index++;
        if(index > menu_size - 1){
            index = 0;
        }
    }
    return index;
}


//////// BINARY FILE RELATED FUNCTIONS ////////

// Write the score and the player's name into the file (player's name limited to 19 char)
void write_score(char name[20], int score){

    FILE* p_score_file = fopen("score.bin", "ab");
    int str_size_oct = sizeof(name[0]) * 20;

    if(p_score_file == NULL){
        printf("L'ouverture du fichier n'a pas fonctionnee\n");
    } else {
        fwrite(name, str_size_oct, 1, p_score_file);
        fwrite(&score, 4, 1, p_score_file);
        fclose(p_score_file);
    }
}


//////// COLOR RELATED FUNCTIONS ////////

// Change the colors of the text with a vector2, the x is the text color, the y the background color
void change_text_color(colorVector2 cell_color){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, cell_color.back_col * 16 + cell_color.text_col);
}

//////// INIITIALIZE CHAR ARRAY ////////

void initalise_char_array(int size_x, int size_y, char char_array[size_y][size_x]){
    for(int i = 0; i < size_x; i++){
        for(int j = 0; j < size_y; j++){
            char_array[i][j] = ' ';
        }
    }
}

//////// PRINT ARRAYS ////////

// Print every cells of the given array
void print_array(int array_size, char arr[array_size][array_size]){
    for(int i = 0; i < array_size; i++){
        for(int j = 0; j < array_size; j++){
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


// Print every cells of the given array, in the given color
void print_array_color(int array_size, char arr[array_size][array_size], colorVector2 color){
    for(int i = 0; i < array_size; i++){
        for(int j = 0; j < array_size; j++){
        	change_text_color(color);
            printf("%c", arr[i][j]);
        }
        change_text_color(NORMAL_TEXT);
        printf("\n");
    }
    change_text_color(NORMAL_TEXT);
    printf("\n");
}


//////// INPUT RELATED FUNCTIONS ////////

// Get inputs from a player, and return the corresponding input type
INPUTS ask_for_input(){
    int input;
    INPUTS returned_input;
    input = getch();

    switch(input){
        case 8:										// BACKSPACE
        case 32: returned_input = SPACE; break; 	// SPACE BAR
        case 13: returned_input = ENTER; break; 	// ENTER
        case 90:									// Z
        case 122: returned_input = UP; break;		// z
        case 83:									// S
        case 115: returned_input = DOWN; break;		// s
        case 81:									// Q
        case 113: returned_input = LEFT; break;		// q
        case 68:									// D
        case 100: returned_input = RIGHT; break;	// d
        default: returned_input = ERR; break;		// Any other input
    }
    return returned_input;
}


//////// TOGGLE FUNCTION ////////

// Toggle the given booleen
void toggle_bool(bool booleen){
    if(booleen != true){
    	booleen = true;
    } else {
    	booleen = false;
    }
}
#endif /* BABAGAMELIB_H_ */
