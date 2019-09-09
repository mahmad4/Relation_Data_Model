//
// Created by Muzains on 11/27/2017.
//

#ifndef PROJECT4_CDH_H
#define PROJECT4_CDH_H

#endif //PROJECT4_CDH_H
#include "HashTable.h"

typedef struct CDH *CDH;
CDH make_tuple_CDH(char* course, char* day, char* hour);
void insert_CDH(CDH tuple, HashTable h);
void print_CDH(HashTable h);
void delete_CDH(char* course, char* day, char* hour, HashTable h);
void lookup_CDH(char* course, char* day, char* hour, HashTable h);