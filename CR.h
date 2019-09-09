//
// Created by Muzains on 11/27/2017.
//

#ifndef PROJECT4_CR_H
#define PROJECT4_CR_H

#endif //PROJECT4_CR_H
#include "HashTable.h"

typedef struct CR *CR;
CR make_tuple_CR(char* course, char* room);
void insert_CR(CR tuple, HashTable h);
void print_CR(HashTable h);
void delete_CR(char* C, char* R, HashTable h);
void lookup_CR(char* C, char* R, HashTable h);
HashTable lookup_CR1(char* C, char* R, HashTable h);