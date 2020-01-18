#include "BabaGameLib.h"

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


// Define a color
colorVector2 define_text_color(int color1, int color2){
    colorVector2 color = {color1, color2};
    return color;
}

//////// INIITIALIZE CHAR ARRAY ////////

void initalise_char_array(int size_x, int size_y, char char_array[10][10]){
    for(int i = 0; i < size_x; i++){
        for(int j = 0; j < size_y; j++){
            char_array[i][j] = ' ';
        }
    }
}

//////// PRINT ARRAYS ////////

// Print every cells of the given array
void print_array(int array_size, char arr[10][10]){
    for(int i = 0; i < array_size; i++){
        for(int j = 0; j < array_size; j++){
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


// Print every cells of the given array, in the given color
void print_array_color(int array_size, char arr[10][10], colorVector2 color){

    colorVector2 normal_text = define_text_color(WHITE, BLACK);

    for(int i = 0; i < array_size; i++){
        for(int j = 0; j < array_size; j++){
        	change_text_color(color);
            printf("%c", arr[i][j]);
        }
        change_text_color(normal_text);
        printf("\n");
    }
    change_text_color(normal_text);
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
void toggle_bool(BOULEIN booleen){
    if(booleen != VRAI){
    	booleen = VRAI;
    } else {
    	booleen = FAUX;
    }
}
