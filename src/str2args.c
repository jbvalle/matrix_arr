#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ptr2args(char **args, char *input_string, int max_args_num){

    //temporary buffer for single words in input string
    //length assumed to 100
    char temp[100];

    //Variable for incrementing through total arguments
    int args_num = 0;

    //Initializing temp with terminator for string function to work
    for(int i = 0; i < 100; i++)temp[i] = '\0';

    //Incrementing through input string
    //Checking for blank space and terminator sign at the end to determine
    //Number of arguments and individual sizes
    for(int i = 0, j = 0; i < 100;i++){

        //Checks for blankspaces and determines single words
        //Every single word ist added to args
        if((input_string[i] == ' ')||(input_string[i]=='\0')){
            //reset j = 0
            j = 0;
            args[args_num] = malloc(strlen(temp));
            strcpy(args[args_num++],temp);

            for(int i = 0; i < 100; i++)temp[i] = '\0';
            //Break the search onces the string is terminated
            if(args_num == max_args_num)break;
        }else temp[j++] = input_string[i];
    }
}
