#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

//////// INITIALIZATION ////////

// Initialization of a player
void initialize_player(player* p_player, level* p_level){
    p_player -> position.x = 0;
    p_player -> position.y = 0;
    p_player -> p_current_level = p_level;
}


//////// PRINT ////////

void print_current_level(level* p_current_level, player* p_player){

    int dim_x = p_current_level -> dimension.x;
    int dim_y = p_current_level -> dimension.y;

    for(int i = -1; i < dim_y + 1; i++){
        for(int j = -1; j < dim_x +1; j++){
            if (i == -1 || i == dim_y){         // Draw the top and bottom border
                printf("_ ");
            } else if(j == -1 || j == dim_x){   // Draw the left and right border
                printf("| ");
            } else if(p_player -> position.x == j && p_player -> position.y == i){  // Draw the player position
                printf("X ");
            } else {                            // Draw the rest of the map
                change_text_color(p_current_level -> level_array[j][i].color);
                printf("%c ", p_current_level -> level_array[j][i].content);
                change_text_color(NORMAL_TEXT);
            }
        }
        printf("\n");
    }
    printf("\n");
}

#endif // FUNCTIONS_H_INCLUDED
