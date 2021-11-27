#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Returns averged output matrix
void matavg(float *matrix, float *matrix_avrg, int rows, int columns){


    //averageing matrix kernel
    int kernel[9][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,0},{0,1},{1,-1},{1,0},{1,1}};

    for(int i = 0; i < rows - 2; i++){
      for(int j = 0; j < columns - 2; j++){
        //avrg_matrix_index (STRUKTUR)= (i + 1) * (columns) + (j + 1);
        //indicates the index of the input matrix the averaging kernel
        //is allowed to move
        float averged_value = 0;
        for(int k = 0; k < 9; k++){
          averged_value += *(matrix + (i + kernel[k][0] + 1) * (columns) + (j + kernel[k][1] + 1)) / 9.0;
        }
            //i * (columns-2) + j ... indicates the incrementing index of the the output matrix which is
            //beeing overwritten by averged Values
            *(matrix_avrg + i * (columns-2) + j) = averged_value;
      }
    }
}
