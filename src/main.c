#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "str2args.h"
#include "matavg.h"
#include "print2outputfile.h"
#include "print2stdout.h"

//adds all number values of inputstream to input matrix
void add_args_to_matrix(char **args,float *matrix, int rows, int columns){
    //Parse input string arguments to matrix_arr
    //Convert to floating Type
    for(int i = 0; i < rows; i++){
      for(int j = 0; j < columns; j++){
          *(matrix + i * columns + j) = atof(args[i * columns + j]);

      }
    }
}

int main(void){

    //ptr2ptr to acces matrices with array indices
    char **args = (char**)malloc(100*sizeof(char));
    //Input Stream -> Floating Point Values of matrices
    char *input_string = (char*)malloc(100*sizeof(char));

    int  rows, columns;
    //Initialize input_string with terminator
    for(int i = 0; i < 100; i++)input_string[i] = '\0';

    //Input - Dimensions & Matrix Values ----------------------------------
    //Read in dimensions
    scanf("%dx%d",&rows,&columns);getchar();
    //Read Metrix demensions
    char letter;
    for(int i = 0, j = 0; j < rows;j++){
      for(; (letter = getchar())!='\n';){
            input_string[i++] = letter;
      }input_string[i++] = ' ';
    }
    //End: Input - Dimensions & Matrix Values ----------------------------------

    //Allocate Memory for input and Output Matrix----------------------------
    //Memory allocate the matrice
    float *matrix = (float*)malloc(rows*columns*sizeof(float));
    //Memory allocate averaged matrice
    //Rows and columns reduces by 2
    float *matrix_avrg = (float*)malloc((rows-2)*(columns-2)*sizeof(float));
    //End: Allocate Memory for input and Output Matrix----------------------------



    //Parse input string to ptr array
    //Parameters: args - array | input stream | maximum number of arguments to be fetched
    ptr2args(args, input_string,rows*columns);

    //Returns arguments values of input to matrix
    add_args_to_matrix(args, matrix, rows, columns);

    //Creates averged matrix
    matavg(matrix, matrix_avrg, rows, columns);


    //Prints INPUT, OUTPUT & SUBMATRICES to ./output.txt
    print2outputfile(matrix, matrix_avrg, rows, columns);
    //Prints INPUT, OUTPUT & SUBMATRICES to STDOUT
    print2stdout(matrix, matrix_avrg, rows, columns);
}
