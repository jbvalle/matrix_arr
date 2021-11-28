#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "print_submatrix2outputfile.h"

void print2outputfile(float *matrix, float *matrix_avrg, int rows, int columns){

    FILE *out_file = fopen("output.txt", "w"); // write only

    // test for files not existing.
    if (out_file == NULL)
    {
      printf("Output File konnte nicht geöffnet werden\n");
      exit(-1); // must include stdlib.h
    }

    fprintf(out_file,"\nInput: \n");
    fprintf(out_file,"Dimensions %d x %d\n\n", rows, columns);
    for (int i = 0; i < rows; i++) {

        for(int k = 0; k < columns; k++)fprintf(out_file,"\t+------+");
        fprintf(out_file,"\n");
        for(int j = 0; j < columns; j++){
          fprintf(out_file,"\t|%6.2f| ", *(matrix + i * columns + j));
        }
        fprintf(out_file,"\n");
        for(int k = 0; k < columns; k++)fprintf(out_file,"\t+------+");
        fprintf(out_file,"\n");
    }

    fprintf(out_file,"\nOutput: \n");
    fprintf(out_file,"Dimensions %d x %d\n\n", rows-2, columns-2);
    for (int i = 0; i < rows-2; i++) {
        for(int k = 0; k < columns-2; k++)fprintf(out_file,"\t+------+");
        fprintf(out_file,"\n");
        for(int j = 0; j < columns-2; j++){
          fprintf(out_file,"\t|%6.2f| ", *(matrix_avrg + i * (columns - 2) + j));
        }
        fprintf(out_file,"\n");
        for(int k = 0; k < columns-2; k++)fprintf(out_file,"\t+------+");
        fprintf(out_file,"\n");
    }

    printf("\nOutput Matrix succesfully saved ./output.txt\n");

    print_submatrix2outputfile(out_file, matrix, rows, columns);

    fclose(out_file);
}
