#include "level.h"

// Initialization of a level
void initialize_level(level* p_map, int level_size_x, int level_size_y){

    p_map -> dimension.x = level_size_x;
    p_map -> dimension.y = level_size_y;

    for(int i = 0; i < level_size_y; i++){
        for(int j = 0; j < level_size_x; j++){
            p_map -> level_array[j][i].content = ' ';
            p_map -> level_array[j][i].type = EMPTY_CELL;
        }
    }
}

// Print current level
void print_current_level(player* p_player, level* p_map){

    int dim_x = p_map -> dimension.x;
    int dim_y = p_map -> dimension.y;

    level_cell current_cell;
    // colorVector2 normal_text = define_text_color(WHITE, BLACK);

    for(int i = 0; i < dim_y; i++){
        for(int j = 0; j < dim_x; j++){
            current_cell = p_map -> level_array[i][j];
            if(i == p_player -> position.x && j == p_player -> position.y){
                printf("%c ", 'X');
            } else if(current_cell.type == EMPTY_CELL){
                printf("%c ", ' ');
            } else{
                printf("%c ", current_cell.content);
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Check if a position is valid. Returns VRAI if it is, FAUX if it's not
BOULEIN is_position_valid(vector2 pos, level* p_map){
    if(p_map -> level_array[pos.x][pos.y].type == EMPTY_CELL){
        return VRAI;
    }
    return FAUX;
}
