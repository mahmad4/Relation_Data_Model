//
// Created by Muzains on 11/28/2017.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HashTable.h"
#include "LinkedList.h"
#include "CR_CDH.h"
#include "CR.h"
#include "CDH.h"


struct HashTable{
    LinkedList** Table;
    int bucket_headers;
};


struct CR_CDH{
    char course[6];
    char room[20];
    char day[3];
    char hour[4];
};
struct CDH{
    char course[6];
    char day[3];
    char hour[4];
};
struct CR{
    char course[6];
    char room[20];
};

CR_CDH make_tuple_CR_CDH(char* course, char* room, char* day, char* hour){
    CR_CDH tuple =  malloc(sizeof(struct CR_CDH));
    strcpy(tuple->course, course);
    strcpy(tuple->room, room);
    strcpy(tuple->day, day);
    strcpy(tuple->hour, hour);
    return tuple;
}

void insert_CR_CDH(CR_CDH tuple, HashTable h) {
    LinkedList_add_at_end(h->Table[string_to_num(tuple->course) % (h->bucket_headers)], tuple);
    //printf("%s", "inserted\n");
}

void print_CR_CDH(HashTable h){
    //CSG tuple = malloc(sizeof(struct CSG));
    printf("%s\n", "CR and CDH table: ");
    for(int i = 0; i<h->bucket_headers; i++){
        LinkedListIterator* f = LinkedList_iterator(h->Table[i]);
        while(LinkedListIterator_has_next(f)){
            CR_CDH t = LinkedListIterator_next(f);
            printf("%s%s%s%s%s%s%s%s\n", "Course: ", t->course, " Room: ", t->room, " Day: ", t->day," Hour: ", t->hour);
        }
    }
}

void join_CR_CDH(HashTable h_CR, HashTable h_CDH, HashTable CR_CDH){
    for (int i = 0; i < h_CR->bucket_headers; i++) {
        LinkedListIterator *f = LinkedList_iterator(h_CR->Table[i]);
        while (LinkedListIterator_has_next(f)) {
            CR t_CR = LinkedListIterator_next(f);
            for (int j = 0; j < h_CDH->bucket_headers; j++) {
                LinkedListIterator *g = LinkedList_iterator(h_CDH->Table[j]);
                while (LinkedListIterator_has_next(g)) {
                    CDH t_CDH = LinkedListIterator_next(g);
                    if(!(strcmp(t_CR->course, t_CDH->course))){
                        insert_CR_CDH(make_tuple_CR_CDH(t_CR->course, t_CR->room, t_CDH->day, t_CDH->hour), CR_CDH);
                    }
                }
            }
        }
    }
}

HashTable selection_cr_cdh(char* room, HashTable h){
    HashTable temp = h;
    for (int i = 0; i < temp->bucket_headers; i++) {
        LinkedListIterator *f = LinkedList_iterator(temp->Table[i]);
        while (LinkedListIterator_has_next(f)) {
            CR_CDH t = LinkedListIterator_next(f);
            if ((strcmp(t->room, room))) {
                LinkedList_remove(temp->Table[i], t);
            }
        }
    }
    return temp;
}

void projection_cr_cdr(HashTable h){
    for (int i = 0; i < h->bucket_headers; i++) {
        LinkedListIterator *f = LinkedList_iterator(h->Table[i]);
        while (LinkedListIterator_has_next(f)) {
            CR_CDH t = LinkedListIterator_next(f);
            printf("%s%s%s%s\n", "Day: ", t->day, " Hour: ", t->hour );
        }
    }
}