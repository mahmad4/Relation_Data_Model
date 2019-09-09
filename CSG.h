//
// Created by Muzains on 11/27/2017.
//

#ifndef PROJECT4_CSG_H
#define PROJECT4_CSG_H

#endif //PROJECT4_CSG_H

#include "HashTable.h"

typedef struct CSG *CSG;
CSG make_tuple_CSG(char* course, char* student_ID, char* grade);
void insert_CSG(CSG tuple, HashTable h);
void print_CSG(HashTable h);
HashTable selection_csg(char* course, HashTable h);
void projection_csg_ID(HashTable h);
void delete_CSG(char* course, char* studentID, char* grade, HashTable h);
void lookup_CSG(char* course, char* studentID, char* grade, HashTable h);

