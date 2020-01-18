// BabaGameLib.h

// Created on: 13 janv. 2020
// Author: Hugo Baba

#ifndef BABAGAMELIB_H_INCLUDED
#define BABAGAMELIB_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <unistd.h>

//////// TYPES DEFINITIONS ////////

// Booleen
typedef enum BOULEIN{
	FAUX,
	VRAI
} BOULEIN;


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


//////// PROTOTYPES ////////

//////// INITIALIZE CHAR ARRAY ////////
void initalise_char_array(int size_x, int size_y, char char_array[10][10]);

//////// VECTOR2 RELATED FUNCTIONS ////////
void reset_vector2_pos(vector2* p_position);
vector2 ceil_position(vector2 position, int x_min, int x_max, int y_min, int y_max);


//////// MENU NAVIGATION FUNCTIONS ////////
int navigate_menu(int index, int menu_size, INPUTS input);


//////// BINARY FILE RELATED FUNCTIONS ////////
void write_score(char name[20], int score);


//////// COLOR RELATED FUNCTIONS ////////
void change_text_color(colorVector2 cell_color);
colorVector2 define_text_color(int color1, int color2);

//////// PRINT ARRAYS ////////
void print_array(int array_size, char arr[][10]);
void print_array_color(int array_size, char arr[][10], colorVector2 color);


//////// INPUT RELATED FUNCTIONS ////////
INPUTS ask_for_input();

//////// TOGGLE FUNCTION ////////
void toggle_bool(BOULEIN booleen);

#endif // BABAGAMELIB_H_INCLUDED
