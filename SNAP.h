//
// Created by Muzains on 11/27/2017.
//

#ifndef PROJECT4_SNAP_H
#define PROJECT4_SNAP_H

#endif //PROJECT4_SNAP_H

#include "HashTable.h"

typedef struct SNAP *SNAP;
SNAP make_tuple_SNAP(char* student_ID, char* Name, char* Address, char* phone);
void insert_SNAP(SNAP tuple, HashTable h);
void print_SNAP(HashTable h);
void delete_SNAP(char* studentID, char* Name, char* Address, char* phone, HashTable h);
void lookup_SNAP(char* studentID, char* Name, char* Address, char* phone, HashTable h);

