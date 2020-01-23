#include "txt_file.h"


// Read the txt file and
void read_map_in_txt_file(char* file_name, level* p_map){

    int red_char;
    int i = 0;
    int j = 0;

    // Open the file
    FILE* p_score_file = fopen("map.txt", "r");

    // Read the score file until it reach EOF
    if(p_score_file != NULL){
        while(red_char != EOF){
            // Read the current char
            red_char = fgetc(p_score_file);

            // Insert data of the file into the array of the map
            switch((char)red_char){
                case '|': p_map -> level_array[i][j].type = V_WALL_CELL; break;
                case '_': p_map -> level_array[i][j].type = H_WALL_CELL; break;
                case '#': p_map -> level_array[i][j].type = DOOR_CELL; break;
            }
            if(red_char != EOF){
                p_map -> level_array[i][j].content = red_char;
            } else{
                break; // If the EOF is reached, break out of the loop
            }

            // If the
            if((char)red_char == '\n' || j >= p_map -> dimension.x){
                j = 0;
                i++;
            } else {
                j++;
            }
        }
    } else {
        printf("Erreur lors de la lecture du fichier map.txt.\n");
    }
}
