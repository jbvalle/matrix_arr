#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ptr2args(char **args, char *input_string, int *args_num){

    char temp[100], letter;

    for(int i = 0; i < 100; i++){

        temp[i] = '\0';
        input_string[i] = '\0';
    }
    for(int i = 0; (letter = getchar())!='\n'; i++){
        input_string[i] = letter;
    }

    *args_num = 0;
    for(int i = 0, j = 0; i < 100;i++){

        if((input_string[i] == ' ')||(input_string[i]=='\0')){
            //reset j = 0
            j = 0;
            args[*args_num] = malloc(strlen(temp+1));
            strcpy(args[*args_num],temp);
            *args_num += 1;
            for(int i = 0; i < 100; i++)temp[i] = '\0';
            if(input_string[i]=='\0')break;
        }else temp[j++] = input_string[i];

    }

    for(int i = 0; i < *args_num; i++){
        printf("%s ",args[i]);
    }
}
