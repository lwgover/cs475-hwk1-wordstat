/*
 * stats.h
 *
 *  Created on: Jan 23, 2023
 *      Author: lgover
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "defs.h"
#include "stats.h"

// function definitions for dealing with histogram below

bool isVowel(int index){
    if(index == 0 || index == 4 || index == 8 || index == 14 || index == 20){
        return 1;
    }
    return 0;
}

int numVowels(int histogram[]){
    int sum = 0;
    for(int i = 0; i < ALPHABET_SIZE; i++){
        if(isVowel(i)){
            sum += histogram[i];
        }
    }
    return sum;
}


int total_chars(int array[]){
    int total = 0;
    for(int i = 0; i < ALPHABET_SIZE;i++){
        total += array[i];
    }
    return total;
}

void print_vc_freq(int histogram[]){
    int total = total_chars(histogram);
    int numVowel = numVowels(histogram);
    printf("\nVowels = %d (%.2f%%), ",numVowel,(100.0 * numVowel)/total);
    printf("Consonants = %d (%.2f%%), ",total-numVowel,(100.0 * (total-numVowel))/total);
    printf("Total= %d\n",total);
}

int max(int array[]){
    int max = 0;
    for(int i = 0; i < ALPHABET_SIZE; i++){
        if(array[i] > max){
            max = array[i];
        }
    }
    return max;
}

void print_histogram(int histogram[]){
    for(int i = max(histogram); i > 0; i--){
        for(int j = 0; j < ALPHABET_SIZE; j++){
            if(histogram[j] >= i){
                printf("* ");
            }else{
                printf("  ");
            }
        }
        printf("\n");
    }
    printf("a b c d e f g h i j k l m n o p q r s t u v w x y z\n");
}

void update_histogram_for_letter(int histogram[], char letter){
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    for(int i = 0; i < 26; i++){
        if(alphabet[i] == letter || alphabet[i] == tolower(letter)){
            histogram[i]++;
            break;
        }
    }
}

void update_histogram(int histogram[], char str[]){
    for(int i = 0; i < strlen(str); i++){
        update_histogram_for_letter(histogram,str[i]);
    }
}