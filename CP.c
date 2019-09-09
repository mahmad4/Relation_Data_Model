//
// Created by Muzains on 11/27/2017.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HashTable.h"
#include "LinkedList.h"
#include "CP.h"


struct HashTable{
    LinkedList** Table;
    int bucket_headers;
};

struct CP{
    char course[6];
    char pre_req[6];
};

CP make_tuple_CP(char* course, char* pre_req){
    CP tuple = /*(CSG)*/ malloc(sizeof(struct CP));
    strcpy(tuple->course, course);
    strcpy(tuple->pre_req, pre_req);
    return tuple;
}

void insert_CP(CP tuple, HashTable h){
    int check = 1;
    for(int i = 0; i<h->bucket_headers; i++) {
        LinkedListIterator *f = LinkedList_iterator(h->Table[i]);
        while (LinkedListIterator_has_next(f)) {
            CP t = LinkedListIterator_next(f);
            if (!strcmp(t->course, tuple->course) && !strcmp(t->pre_req, tuple->pre_req)) {
                check = 0;
            }
        }
    }
    if (check == 1) {
        LinkedList_add_at_end(h->Table[string_to_num(tuple->course) % (h->bucket_headers)], tuple);
    }
}



void print_CP(HashTable h){
    //CSG tuple = malloc(sizeof(struct CSG));
    printf("%s\n", "CP table : ");
    for(int i = 0; i<h->bucket_headers; i++){
        LinkedListIterator* f = LinkedList_iterator(h->Table[i]);
        while(LinkedListIterator_has_next(f)){
            CP t = LinkedListIterator_next(f);
            printf("%s%s%s%s\n", "Course: ", t->course, " Prerequisite: ", t->pre_req);
        }
    }
}

void delete_CP(char* course, char* pre_req, HashTable h) {
    if (!strcmp(course, "*")) {
        for (int i = 0; i < h->bucket_headers; i++) {
            LinkedListIterator *f = LinkedList_iterator(h->Table[i]);
            while (LinkedListIterator_has_next(f)) {
                CP t = LinkedListIterator_next(f);
                if (!strcmp(t->pre_req, pre_req)) {
                    LinkedList_remove(h->Table[i], t);
                } else if (!strcmp(pre_req, "*")) {
                    LinkedList_remove(h->Table[i], t);
                }
            }
        }
    } else {
        LinkedList *l = h->Table[(string_to_num(course) % h->bucket_headers)];
        LinkedListIterator *f = LinkedList_iterator(l);
        while (LinkedListIterator_has_next(f)) {
            CP t = LinkedListIterator_next(f);
            if (!strcmp(t->course, course)) {
                if (!strcmp(t->pre_req, pre_req)) {
                    LinkedList_remove(l, t);
                } else if (!strcmp(pre_req, "*")) {
                    LinkedList_remove(l, t);
                }
            }
        }
    }
}


void lookup_CP(char* course, char* pre_req, HashTable h) {
    if (!strcmp(course, "*")) {
        for (int i = 0; i < h->bucket_headers; i++) {
            LinkedListIterator *f = LinkedList_iterator(h->Table[i]);
            while (LinkedListIterator_has_next(f)) {
                CP t = LinkedListIterator_next(f);
                if (!strcmp(t->pre_req, pre_req)) {
                    printf("%s%s%s%s\n", "Course: ", t->course, " Prerequisite: ", t->pre_req);
                } else if (!strcmp(pre_req, "*")) {
                    printf("%s%s%s%s\n", "Course: ", t->course, " Prerequisite: ", t->pre_req);
                }
            }
        }
    } else {
        LinkedList *l = h->Table[(string_to_num(course) % h->bucket_headers)];
        LinkedListIterator *f = LinkedList_iterator(l);
        while (LinkedListIterator_has_next(f)) {
            CP t = LinkedListIterator_next(f);
            if (!strcmp(t->course, course)) {
                if (!strcmp(t->pre_req, pre_req)) {
                    printf("%s%s%s%s\n", "Course: ", t->course, " Prerequisite: ", t->pre_req);
                } else if (!strcmp(pre_req, "*")) {
                    printf("%s%s%s%s\n", "Course: ", t->course, " Prerequisite: ", t->pre_req);
                }
            }
        }
    }
}