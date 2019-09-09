//
// Created by Muzains on 11/27/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HashTable.h"
#include "LinkedList.h"
#include "CDH.h"


struct HashTable{
    LinkedList** Table;
    int bucket_headers;
};

struct CDH{
    char course[6];
    char day[3];
    char hour[4];
};

CDH make_tuple_CDH(char* course, char* day, char* hour){
    CDH tuple = malloc(sizeof(struct CDH));
    strcpy(tuple->course, course);
    strcpy(tuple->day, day);
    strcpy(tuple->hour, hour);
    return tuple;
}

void insert_CDH(CDH tuple, HashTable h){
    int check = 1;
    for(int i = 0; i<h->bucket_headers; i++) {
        LinkedListIterator *f = LinkedList_iterator(h->Table[i]);
        while (LinkedListIterator_has_next(f)) {
            CDH t = LinkedListIterator_next(f);
            if (!strcmp(t->course, tuple->course) && !strcmp(t->day, tuple->day) && !strcmp(t->hour, tuple->hour)) {
                check = 0;
            }
        }
    }
    if (check == 1) {
        LinkedList_add_at_end(h->Table[string_to_num(tuple->course) % (h->bucket_headers)], tuple);
    }

}



void print_CDH(HashTable h){
    //CSG tuple = malloc(sizeof(struct CSG));
    printf("%s\n", "CDH table : ");
    for(int i = 0; i<h->bucket_headers; i++){
        LinkedListIterator* f = LinkedList_iterator(h->Table[i]);
        while(LinkedListIterator_has_next(f)){
            CDH t = LinkedListIterator_next(f);
            printf("%s%s%s%s%s%s\n", "Course: ", t->course, " Day: ", t->day," Hour: ", t->hour);
        }
    }
}

void delete_CDH(char* course, char* day, char* hour, HashTable h) {
    if (!strcmp(course, "*")) {
        for (int i = 0; i < h->bucket_headers; i++) {
            LinkedListIterator *f = LinkedList_iterator(h->Table[i]);
            while (LinkedListIterator_has_next(f)) {
                CDH t = LinkedListIterator_next(f);
                if (!strcmp(t->day, day)) {
                    if(!strcmp(t->hour, hour)){
                        printf("%s%s%s%s%s%s\n", "Course: ", t->course, " Day: ", t->day," Hour: ", t->hour);
                    }else if(!strcmp(hour, "*")) {
                        printf("%s%s%s%s%s%s\n", "Course: ", t->course, " Day: ", t->day," Hour: ", t->hour);
                    }
                } else if (!strcmp(day, "*")) {
                    if(!strcmp(t->hour, hour)){
                        printf("%s%s%s%s%s%s\n", "Course: ", t->course, " Day: ", t->day," Hour: ", t->hour);
                    }else if(!strcmp(hour, "*")) {
                        printf("%s%s%s%s%s%s\n", "Course: ", t->course, " Day: ", t->day," Hour: ", t->hour);
                    }
                }
            }
        }
    } else {
        LinkedList *l = h->Table[(string_to_num(course) % h->bucket_headers)];
        LinkedListIterator *f = LinkedList_iterator(l);
        while (LinkedListIterator_has_next(f)) {
            CDH t = LinkedListIterator_next(f);
            if (!strcmp(t->course, course)) {
                if (!strcmp(t->day, day)) {
                    if(!strcmp(t->hour, hour)){
                        printf("%s%s%s%s%s%s\n", "Course: ", t->course, " Day: ", t->day," Hour: ", t->hour);
                    }else if(!strcmp(hour, "*")) {
                        printf("%s%s%s%s%s%s\n", "Course: ", t->course, " Day: ", t->day," Hour: ", t->hour);
                    }
                } else if (!strcmp(day, "*")) {
                    if(!strcmp(t->hour, hour)){
                        printf("%s%s%s%s%s%s\n", "Course: ", t->course, " Day: ", t->day," Hour: ", t->hour);
                    }else if(!strcmp(hour, "*")) {
                        printf("%s%s%s%s%s%s\n", "Course: ", t->course, " Day: ", t->day," Hour: ", t->hour);
                    }
                }
            }
        }
    }
}


void lookup_CDH(char* course, char* day, char* hour, HashTable h) {
    if (!strcmp(course, "*")) {
        for (int i = 0; i < h->bucket_headers; i++) {
            LinkedListIterator *f = LinkedList_iterator(h->Table[i]);
            while (LinkedListIterator_has_next(f)) {
                CDH t = LinkedListIterator_next(f);
                if (!strcmp(t->day, day)) {
                    if(!strcmp(t->hour, hour)){
                        LinkedList_remove(h->Table[i], t);
                    }else if(!strcmp(hour, "*")) {
                        LinkedList_remove(h->Table[i], t);
                    }
                } else if (!strcmp(day, "*")) {
                    if(!strcmp(t->hour, hour)){
                        LinkedList_remove(h->Table[i], t);
                    }else if(!strcmp(hour, "*")) {
                        LinkedList_remove(h->Table[i], t);
                    }
                }
            }
        }
    } else {
        LinkedList *l = h->Table[(string_to_num(course) % h->bucket_headers)];
        LinkedListIterator *f = LinkedList_iterator(l);
        while (LinkedListIterator_has_next(f)) {
            CDH t = LinkedListIterator_next(f);
            if (!strcmp(t->course, course)) {
                if (!strcmp(t->day, day)) {
                    if(!strcmp(t->hour, hour)){
                        LinkedList_remove(l, t);
                    }else if(!strcmp(hour, "*")) {
                        LinkedList_remove(l, t);
                    }
                } else if (!strcmp(day, "*")) {
                    if(!strcmp(t->hour, hour)){
                        LinkedList_remove(l, t);
                    }else if(!strcmp(hour, "*")) {
                        LinkedList_remove(l, t);
                    }
                }
            }
        }
    }
}
