#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print2stdout(float *matrix, float *matrix_avrg, int rows, int columns){

    printf("\nInput: \n");
    printf("Dimensions %d x %d\n\n", rows, columns);
    for (int i = 0; i < rows; i++) {

      for(int k = 0; k < columns; k++)printf("\t+------+");
      printf("\n");
      for(int j = 0; j < columns; j++){
        printf("\t|%6.2f| ", *(matrix + i * columns + j));
      }
      printf("\n");
      for(int k = 0; k < columns; k++)printf("\t+------+");
      printf("\n");
    }

    printf("\nOutput: \n");
    printf("Dimensions %d x %d\n\n", rows-2, columns-2);
    for (int i = 0; i < rows-2; i++) {
      for(int k = 0; k < columns-2; k++)printf("\t+------+");
      printf("\n");
      for(int j = 0; j < columns-2; j++){
        printf("\t|%6.2f| ", *(matrix_avrg + i * (columns - 2) + j));
      }
      printf("\n");
      for(int k = 0; k < columns-2; k++)printf("\t+------+");
      printf("\n");
    }
    printf("\n\n+-------------------Submatrices------------------+\n\n");
    //averageing matrix kernel
    int kernel[9][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,0},{0,1},{1,-1},{1,0},{1,1}};

    for (int i = 0; i < rows - 2 ; i++) {

        for(int j = 0; j < columns - 2; j++){

          float sum = 0;
          for(int k = 0; k < 9; k++){

            if(k%3 == 0){
              printf("\n");
              for(int x = 0; x < 3; x++)printf("\t+------+");
              printf("\n");
            }
            sum += *(matrix + (i + kernel[k][0] + 1) * (columns) + (j + kernel[k][1] + 1));
            printf("\t|%6.2f| ", *(matrix + (i + kernel[k][0] + 1) * (columns) + (j + kernel[k][1] + 1)));

          }
          printf("\n");
          for(int x = 0; x < 3; x++)printf("\t+------+");
          printf("\n\n");
          printf("\n\t%d.Submatrix: Sum: %.2f, Averaged: %.2f\n\n",i * (columns - 2) + j + 1,sum,sum/9.0);
        }
    }
}
