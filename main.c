/*
 * main.c
 *
 *  Created on: Jan 23, 2022
 *      Author: lgover
 */
#include <stdio.h>
#include <string.h>
#include "defs.h"
#include "stats.h"
#include "menu.h"

void getInputString(char input[]){
    //scan user input into the char array
    fgets(input,MAX_INPUT_LEN,stdin);
}

void histogram_input(int histogram[]){
	char input[MAX_INPUT_LEN];
	// TODO: start by getting strings from users until # is input
	printf("Enter strings (# to stop): \n");
	while(1){
		getInputString(input);
		if(strlen(input) <= 2 && input[0] == '#'){
			break;
		}else{
			update_histogram(histogram,input);
		}
	}
}

/**
 * @brief Main function
 *
 * @param argc Ignore
 * @param argv Ignore
 * @return int
 */
int main(int argc, char *argv[]) {
	// declare and initialize the histogram
	int histogram[ALPHABET_SIZE];
	for(int i = 0; i < ALPHABET_SIZE; i++){
		histogram[i] = 0;
	}

	histogram_input(histogram);

	// TODO: after # is input, print menu options
	while(1){
	int choice = getMenuOption();
	switch(choice){
		case 1:
			print_vc_freq(histogram);
			break;
		case 2:
			print_histogram(histogram);
			break;
		case 3:
			histogram_input(histogram);
			break;
		case 4:
			printf("Exiting...\n");
			return 0; // signifies a normal exit
		default: // if choice wasn't a recognized number
			printf("%d is not a valid option, please try again\n", choice);
		}
	}
}