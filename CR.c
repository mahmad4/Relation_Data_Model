//
// Created by Muzains on 11/27/2017.
//



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HashTable.h"
#include "LinkedList.h"
#include "CR.h"


struct HashTable{
    LinkedList** Table;
    int bucket_headers;
};

struct CR{
    char course[6];
    char room[20];
};

CR make_tuple_CR(char* course, char* room){
    CR tuple = /*(CSG)*/ malloc(sizeof(struct CR));
    strcpy(tuple->course, course);
    strcpy(tuple->room, room);
    return tuple;
}

void insert_CR(CR tuple, HashTable h){
    int check = 1;
    for(int i = 0; i<h->bucket_headers; i++) {
        LinkedListIterator *f = LinkedList_iterator(h->Table[i]);
        while (LinkedListIterator_has_next(f)) {
            CR t = LinkedListIterator_next(f);
            if (!strcmp(t->course, tuple->course) && !strcmp(t->room, tuple->room)) {
                check = 0;
            }
        }
    }
    if (check == 1) {
        LinkedList_add_at_end(h->Table[string_to_num(tuple->course) % (h->bucket_headers)], tuple);
    }
    //printf("%s", "inserted\n");
}


void print_CR(HashTable h){
    //CSG tuple = malloc(sizeof(struct CSG));
    printf("%s\n", "CR table : ");
    for(int i = 0; i<h->bucket_headers; i++){
        LinkedListIterator* f = LinkedList_iterator(h->Table[i]);
        while(LinkedListIterator_has_next(f)){
            CR t = LinkedListIterator_next(f);
            printf("%s%s%s%s\n", "Course: ", t->course, " Room: ", t->room);
        }
    }
}

void delete_CR(char* C, char* R, HashTable h) {
    if (!strcmp(C, "*")) {
        for (int i = 0; i < h->bucket_headers; i++) {
            LinkedListIterator *f = LinkedList_iterator(h->Table[i]);
            while (LinkedListIterator_has_next(f)) {
                CR t = LinkedListIterator_next(f);
                if (!strcmp(t->room, R)) {
                    LinkedList_remove(h->Table[i], t);
                } else if (!strcmp(R, "*")) {
                    LinkedList_remove(h->Table[i], t);
                }
            }
        }
    } else {
        LinkedList *l = h->Table[(string_to_num(C) % h->bucket_headers)];
        LinkedListIterator *f = LinkedList_iterator(l);
        while (LinkedListIterator_has_next(f)) {
            CR t = LinkedListIterator_next(f);
            if (!strcmp(t->course, C)) {
                if (!strcmp(t->room, R)) {
                    LinkedList_remove(l, t);
                } else if (!strcmp(R, "*")) {
                    LinkedList_remove(l, t);
                }
            }
        }
    }
}

void lookup_CR(char* C, char* R, HashTable h) {
    if (!strcmp(C, "*")) {
        for (int i = 0; i < h->bucket_headers; i++) {
            LinkedListIterator *f = LinkedList_iterator(h->Table[i]);
            while (LinkedListIterator_has_next(f)) {
                CR t = LinkedListIterator_next(f);
                if (!strcmp(t->room, R)) {
                    printf("%s%s%s%s\n", "Course: ", t->course, " Room: ", t->room);
                } else if (!strcmp(R, "*")) {
                    printf("%s%s%s%s\n", "Course: ", t->course, " Room: ", t->room);
                }
            }
        }
    } else {
        LinkedList *l = h->Table[(string_to_num(C) % h->bucket_headers)];
        LinkedListIterator *f = LinkedList_iterator(l);
        while (LinkedListIterator_has_next(f)) {
            CR t = LinkedListIterator_next(f);
            if (!strcmp(t->course, C)) {
                if (!strcmp(t->room, R)) {
                    printf("%s%s%s%s\n", "Course: ", t->course, " Room: ", t->room);
                } else if (!strcmp(R, "*")) {
                    printf("%s%s%s%s\n", "Course: ", t->course, " Room: ", t->room);
                }
            }
        }
    }
}

HashTable lookup_CR1(char* C, char* R, HashTable h) {
    HashTable lookup_hash = new_hashtable(20);
    if (!strcmp(C, "*")) {
        for (int i = 0; i < h->bucket_headers; i++) {
            LinkedListIterator *f = LinkedList_iterator(h->Table[i]);
            while (LinkedListIterator_has_next(f)) {
                CR t = LinkedListIterator_next(f);
                if (!strcmp(t->room, R)) {
                    insert_CR(make_tuple_CR(t->course, t->room), lookup_hash);
                    //printf("%s%s%s%s\n", "Course: ", t->course, " Room: ", t->room);
                } else if (!strcmp(R, "*")) {
                    insert_CR(make_tuple_CR(t->course, t->room), lookup_hash);
                    //printf("%s%s%s%s\n", "Course: ", t->course, " Room: ", t->room);
                }
            }
        }
    } else {
        LinkedList *l = h->Table[(string_to_num(C) % h->bucket_headers)];
        LinkedListIterator *f = LinkedList_iterator(l);
        while (LinkedListIterator_has_next(f)) {
            CR t = LinkedListIterator_next(f);
            if (!strcmp(t->course, C)) {
                if (!strcmp(t->room, R)) {
                    printf("%s%s%s%s\n", "Course: ", t->course, " Room: ", t->room);
                } else if (!strcmp(R, "*")) {
                    printf("%s%s%s%s\n", "Course: ", t->course, " Room: ", t->room);
                }
            }
        }
    }
    return lookup_hash;
}