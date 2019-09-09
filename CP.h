//
// Created by Muzains on 11/27/2017.
//

#ifndef PROJECT4_CP_H
#define PROJECT4_CP_H

#endif //PROJECT4_CP_H
#include "HashTable.h"

typedef struct CP *CP;
CP make_tuple_CP(char* course, char* pre_req);
void insert_CP(CP tuple, HashTable h);
void print_CP(HashTable h);
void delete_CP(char* course, char* pre_req, HashTable h);
void lookup_CP(char* course, char* pre_req, HashTable h);