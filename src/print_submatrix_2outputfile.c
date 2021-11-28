#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_submatrix2outputfile(FILE *out_file, float *matrix, int rows, int columns){

    fprintf(out_file,"\n\n+-------------------Submatrices------------------+\n\n");
    //averageing matrix kernel
    int kernel[9][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,0},{0,1},{1,-1},{1,0},{1,1}};

    for (int i = 0; i < rows - 2 ; i++) {

        for(int j = 0; j < columns - 2; j++){

          float sum = 0;
          for(int k = 0; k < 9; k++){

            if(k%3 == 0){
              fprintf(out_file,"\n");
              for(int x = 0; x < 3; x++)fprintf(out_file,"\t+------+");
              fprintf(out_file,"\n");
            }
            sum += *(matrix + (i + kernel[k][0] + 1) * (columns) + (j + kernel[k][1] + 1));
            fprintf(out_file,"\t|%6.2f| ", *(matrix + (i + kernel[k][0] + 1) * (columns) + (j + kernel[k][1] + 1)));

          }
          fprintf(out_file,"\n");
          for(int x = 0; x < 3; x++)fprintf(out_file,"\t+------+");
          fprintf(out_file,"\n\n");
          fprintf(out_file,"\n\t%d.Submatrix: Sum: %.2f, Averaged: %.2f\n\n",i * (columns - 2) + j + 1,sum,sum/9.0);
        }
    }
}
