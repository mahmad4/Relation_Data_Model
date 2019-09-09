//
// Created by Muzains on 11/28/2017.
//

#ifndef PROJECT4_CR_CDH_H
#define PROJECT4_CR_CDH_H

#endif //PROJECT4_CR_CDH_H
#include "HashTable.h"

typedef struct CR_CDH *CR_CDH;

CR_CDH make_tuple_CR_CDH(char* course, char* room, char* day, char* hour);
void insert_CR_CDH(CR_CDH tuple, HashTable h);
void print_CR_CDH(HashTable h);
void join_CR_CDH(HashTable h_CR, HashTable h_CDH, HashTable CR_CDH);
HashTable selection_cr_cdh(char* room, HashTable h);
void projection_cr_cdr(HashTable h);
