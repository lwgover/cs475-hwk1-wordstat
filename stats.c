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

/**
* determines whether index in histogram represents a vowel with a clean and efficient if statement
*
* @param index place in the alphabet
* @return whether it is a vowel
*/
bool isVowel(int index){
    if(index == 0 || index == 4 || index == 8 || index == 14 || index == 20){
        return 1;
    }
    return 0;
}
/**
* returns the number of vowels in the histogram
*
* @param histogram the histogram
* @return the number of values
*/
int numVowels(int histogram[]){
    int sum = 0;
    for(int i = 0; i < ALPHABET_SIZE; i++){
        if(isVowel(i)){
            sum += histogram[i];
        }
    }
    return sum;
}

/**
* returns the total number of chars in the histogram
*
* @param array array
* @return the sum of all ints stored in the array
*/
int total_chars(int array[]){
    int total = 0;
    for(int i = 0; i < ALPHABET_SIZE;i++){
        total += array[i];
    }
    return total;
}

/**
* prints the vowel and consonant frequencies
*
* @param histogram the histogram
*/
void print_vc_freq(int histogram[]){
    int total = total_chars(histogram);
    int numVowel = numVowels(histogram);
    printf("\nVowels = %d (%.2f%%), ",numVowel,(100.0 * numVowel)/total);
    printf("Consonants = %d (%.2f%%), ",total-numVowel,(100.0 * (total-numVowel))/total);
    printf("Total= %d\n",total);
}

/**
*returns the max int in an array
* 
* @param array an int array you want the max of. needs to have 26 characters
*/
int max(int array[]){
    int max = 0;
    for(int i = 0; i < ALPHABET_SIZE; i++){
        if(array[i] > max){
            max = array[i];
        }
    }
    return max;
}

/**
* prints the histogram
* 
* @param histogram the histogram
*/
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

//helper... updates the histogram for one letter
void update_histogram_for_letter(int histogram[], char letter){
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    for(int i = 0; i < 26; i++){
        if(alphabet[i] == letter || alphabet[i] == tolower(letter)){
            histogram[i]++;
            break;
        }
    }
}

/**
* updates the histogram with a string's chars
*
* @param histogram the histogram
* @param str string you want to add to the histogram database
*/
void update_histogram(int histogram[], char str[]){
    for(int i = 0; i < strlen(str); i++){
        update_histogram_for_letter(histogram,str[i]);
    }
}