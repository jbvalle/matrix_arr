#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "str2args.h"

int main(void){
    //ptr2ptr to acces matrices with array indices
    char **args = (char**)malloc(100*sizeof(char));
    //Input Stream -> Floating Point Values of matrices
    char *input_string = (char*)malloc(100*sizeof(char));

    int  args_num,rows,columns;

    //Initialize input_string with terminator
    for(int i = 0; i < 100; i++)input_string[i] = '\0';

    //Read in dimensions
    scanf("%dx%d",&rows,&columns);getchar();

    //Memory allocate the matrice
    float *matrix = (float*)malloc(rows*columns*sizeof(float));
    //Memory allocate averaged matrice
    //Rows and columns reduces by 2
    float *matrix_avrg = (float*)malloc((rows-2)*(columns-2)*sizeof(float));

    //Letterwise input from stdin
    char letter;
    for(int i = 0, j = 0; j < rows;j++){
      for(; (letter = getchar())!='\n';){
            input_string[i++] = letter;
      }input_string[i++] = ' ';
    }

    //Parse input string to ptr array
    ptr2args(args, input_string, &args_num);

    //Parse input string arguments to matrix_arr
    for(int i = 0; i < rows; i++){
      for(int j = 0; j < columns; j++){
        *(matrix + i * columns + j) = atof(args[i * columns + j]);
      }
    }

    //Parse input string arguments to matrix_arr
    for(int i = 0; i < rows; i++){
      for(int j = 0; j < columns; j++){
        printf("%f ",*(matrix + i * columns + j));
      }
      printf("\n");
    }
}