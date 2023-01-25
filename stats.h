/*
 * stats.h
 *
 *  Created on: Jan 23, 2023
 *      Author: lgover
 */

#ifndef STATS_H_
#define STATS_H_

// constants
#define ALPHABET_SIZE 26

// TODO: functions declarations go below

void update_histogram(int histogram[], char str[]);
void print_histogram(int histogram[]);
void print_vc_freq(int histogram[]);

#endif /* STATS_H_ */
