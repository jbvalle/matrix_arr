#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "str2args.h"

int main(void){
    char **args = (char**)malloc(100*sizeof(char));
    char *input_string = (char*)malloc(100*sizeof(char));
    int  args_num;

    ptr2args(args, input_string, &args_num);

    printf("%f",atof(args[0]));
}
