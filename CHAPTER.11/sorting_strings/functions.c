#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "header.h"

//ACTION FUNCTIONS
char menu(int *n){ //MAIN MENU FUNCTION
    puts(PLHOLDER);
    while(getchar() != '\n'); //PROGRAM CHECKPOINT
    char c;
    printf("\n\t\tMAIN MENU\n"); //DISPLAY THE MENU
    puts(ASTERISKS);
    printf("a) add new string\tb) sort strings\n");
    printf("c) display strings\td) delete string\n");
    printf("e) clear array\t\ti) information\n");
    printf("q) quit\n");
    puts(ASTERISKS);
    printf("\t\t  Strings occupied: %d/%d\n", *n, LIMIT);
    printf("Choose operation: ");
    c = input_validation(); //GET INPUT FROM THE USER
    return c;
}

char input_validation(void){ //INPUT VALIDATION FOR MENU FUNCTION
    int i;
    char ch, string[2];
    bool valid = false;
    while(valid != true){
        while((ch = getchar()) == ' ' || ch == '\n'); //GET CHAR FROM USER (FIRST NONSPACE CHAR)
        if(ch != 'a' && ch != 'b' && ch != 'c' 
        && ch != 'd' && ch != 'e' && ch != 'i'
        && ch != 'q'){ //CHECK IF CHAR IS CORRECT
            printf("\nError! Please try again!\n");
            printf("Option selection: ");
        }else{
            valid = true;
            while(getchar() != '\n'); //GET RID OF THE REMAINING CHARACTERS
        }
    }
    return ch;
}

void addstring(char (*array)[LENGHT], int *n){ //ADDING STRINGS TO THE ARRAY  
    bool add = false, corrects = false;
    int i, j;
    char new_string[LENGHT];
    for(i = 0; add != true && i < LIMIT; i++){ //SEARCHING FOR THE CLOSEST FREE ROW OF THE ARRAY
        if(strlen(array[i]) != 0){ //SKIP THIS CYCLE IF A ROW IS OCCUPIED
            continue;
        }else{ //PREPARE FOR ENTERING DATA
            printf("Please enter string: ");
            while(fgets(new_string, LENGHT, stdin) == NULL 
                                    && *new_string != '\n'); //ADD STRING
            strncpy(array[i], new_string, LENGHT ); //TRANSFER NEW STRING TO THE ARRAY
            j = 0;
            while(array[i][j] != '\n' && array[i][j] != '\0'){
                if(isspace(array[i][j]) == 0) //ALARM WHEN STRING WAS BUILT USING ONLY SPACE CHARACTERS
                    corrects = true;
                j++;
            }
            if(corrects == false){ //DELETE STRING WHEN ALARM IN TURNED ON
                for(j = 0; array[i][j] != '\0'; j++)
                    array[i][j] = '\0';
            }else if(array[i][j] == '\n') //GET RID OF A NEWLINE CHARACTER THAT WAS CREATED BY fgets 
                array[i][j] = '\0';
            else{
                while(getchar() != '\n'); //WHEN INPUT STRING IS TOO LONG IT DISCARDS REST OF THE CHARACTERS
                printf("\nWARNING! PART OF THE STRING WAS ERASED.\n\n");
            }
            corrects == true ? (*n)++,  //INFORM USER OF STATUS AND INCREMENT count IF ALL WENT WELL
                                printf("String added and placed in %d position\n", i + 1):
                                printf("String was not added.\n");  
            add = true; //TERMINATE LOOP
        }
    }
}
void display(char (*array)[LENGHT]){ //ARRAY DISPLAY FUNCTION
    for(int i = 0; i < LIMIT; i++){
        printf("%d.\t", i + 1);
        fputs(array[i], stdout);
        printf("\n");
    }
}

//INFO FUNCTIONS
void intro(void){
    printf("Welcome into the sorting program.\n");//start intro
    sleep(1);
    printf("Please follow instructions.\n");
    sleep(1);
    printf("For more information choose option i from the menu.\n");//end intro 
    sleep(1);
}
void information(void){
    printf("This program can store strings and sort them.\nThere is a limit of %d strings inserted.\n", LIMIT);
    printf("Each string can fit %d characters.\nYou can delete any string by choosing \"d\" from menu an selecting index of string.\n", LENGHT - 1);
    printf("You can also clear whole array by choosing option \"e\".\nTo quit choose option \"q\" from the main menu.\n");
}