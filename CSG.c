//
// Created by Muzains on 11/27/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HashTable.h"
#include "LinkedList.h"
#include "CSG.h"


struct HashTable{
    LinkedList** Table;
    int bucket_headers;
};

struct CSG{
    char course[6];
    char studentID[6];
    char grade[2];
};

CSG make_tuple_CSG(char* course, char* student_ID, char* grade){
    CSG tuple = /*(CSG)*/ malloc(sizeof(struct CSG));
    strcpy(tuple->course, course);
    strcpy(tuple->studentID, student_ID);
    strcpy(tuple->grade, grade);
    return tuple;
}

void insert_CSG(CSG tuple, HashTable h){
    int check = 1;
    for(int i = 0; i<h->bucket_headers; i++) {
        LinkedListIterator *f = LinkedList_iterator(h->Table[i]);
        while (LinkedListIterator_has_next(f)) {
            CSG t = LinkedListIterator_next(f);
            if (!strcmp(t->course, tuple->course) && !strcmp(t->studentID, tuple->studentID) && !strcmp(t->grade, tuple->grade)) {
                check = 0;
            }
        }
    }
    if (check == 1) {
        LinkedList_add_at_end(h->Table[string_to_num(tuple->studentID) % (h->bucket_headers)], tuple);
    }
    //printf("%s", "inserted\n");
}


void print_CSG(HashTable h){
    //CSG tuple = malloc(sizeof(struct CSG));
    printf("%s\n", "CSG table : ");
    for(int i = 0; i<h->bucket_headers; i++){
        LinkedListIterator* f = LinkedList_iterator(h->Table[i]);
        while(LinkedListIterator_has_next(f)){
            CSG t = LinkedListIterator_next(f);
            printf("%s%s%s%s%s%s\n", "Course: ", t->course, " Student ID: ", t->studentID," Grade: ", t->grade);
        }
    }
}

HashTable selection_csg(char* course, HashTable h){
    HashTable temp = h;
    for (int i = 0; i < temp->bucket_headers; i++) {
        LinkedListIterator *f = LinkedList_iterator(temp->Table[i]);
        while (LinkedListIterator_has_next(f)) {
            CSG t = LinkedListIterator_next(f);
            if ((strcmp(t->course, course))) {
                LinkedList_remove(temp->Table[i], t);
            }
        }
    }
    return temp;
}

void projection_csg_ID(HashTable h){
    printf("\nStudent ID:\n");
    for (int i = 0; i < h->bucket_headers; i++) {
        LinkedListIterator *f = LinkedList_iterator(h->Table[i]);
        while (LinkedListIterator_has_next(f)) {
            CSG t = LinkedListIterator_next(f);
            printf("%s\n", t->studentID);
        }
    }
}

void delete_CSG(char* course, char* studentID, char* grade, HashTable h) {
    if (!strcmp(studentID, "*")) {
        for (int i = 0; i < h->bucket_headers; i++) {
            LinkedListIterator *f = LinkedList_iterator(h->Table[i]);
            while (LinkedListIterator_has_next(f)) {
                CSG t = LinkedListIterator_next(f);
                if (!strcmp(t->course, course)) {
                    if(!strcmp(t->grade, grade)){
                        LinkedList_remove(h->Table[i], t);
                    }else if(!strcmp(grade, "*")) {
                        LinkedList_remove(h->Table[i], t);
                    }
                } else if (!strcmp(course, "*")) {
                    if(!strcmp(t->grade, grade)){

                        LinkedList_remove(h->Table[i], t);
                    }else if(!strcmp(grade, "*")) {
                        LinkedList_remove(h->Table[i], t);
                    }
                }
            }
        }
    } else {
        LinkedList *l = h->Table[(string_to_num(studentID) % h->bucket_headers)];
        LinkedListIterator *f = LinkedList_iterator(l);
        while (LinkedListIterator_has_next(f)) {
            CSG t = LinkedListIterator_next(f);
            if (!strcmp(t->studentID, studentID)) {
                if (!strcmp(t->course, course)) {
                    if(!strcmp(t->grade, grade)){
                        LinkedList_remove(l, t);
                    }else if(!strcmp(grade, "*")) {
                        LinkedList_remove(l, t);
                    }
                } else if (!strcmp(course, "*")) {
                    if(!strcmp(t->grade, grade)){
                        LinkedList_remove(l, t);
                    }else if(!strcmp(grade, "*")) {
                        LinkedList_remove(l, t);
                    }
                }
            }
        }
    }
}

void lookup_CSG(char* course, char* studentID, char* grade, HashTable h) {
    if (!strcmp(studentID, "*")) {
        for (int i = 0; i < h->bucket_headers; i++) {
            LinkedListIterator *f = LinkedList_iterator(h->Table[i]);
            while (LinkedListIterator_has_next(f)) {
                CSG t = LinkedListIterator_next(f);
                if (!strcmp(t->course, course)) {
                    if(!strcmp(t->grade, grade)){
                        printf("%s%s%s%s%s%s\n", "Course: ", t->course, " Student ID: ", t->studentID," Grade: ", t->grade);
                    }else if(!strcmp(grade, "*")) {
                        printf("%s%s%s%s%s%s\n", "Course: ", t->course, " Student ID: ", t->studentID," Grade: ", t->grade);
                    }
                } else if (!strcmp(course, "*")) {
                    if(!strcmp(t->grade, grade)){
                        printf("%s%s%s%s%s%s\n", "Course: ", t->course, " Student ID: ", t->studentID," Grade: ", t->grade);
                    }else if(!strcmp(grade, "*")) {
                        printf("%s%s%s%s%s%s\n", "Course: ", t->course, " Student ID: ", t->studentID," Grade: ", t->grade);
                    }
                }
            }
        }
    } else {
        LinkedList *l = h->Table[(string_to_num(studentID) % h->bucket_headers)];
        LinkedListIterator *f = LinkedList_iterator(l);
        while (LinkedListIterator_has_next(f)) {
            CSG t = LinkedListIterator_next(f);
            if (!strcmp(t->studentID, studentID)) {
                if (!strcmp(t->course, course)) {
                    if(!strcmp(t->grade, grade)){
                        printf("%s%s%s%s%s%s\n", "Course: ", t->course, " Student ID: ", t->studentID," Grade: ", t->grade);
                    }else if(!strcmp(grade, "*")) {
                        printf("%s%s%s%s%s%s\n", "Course: ", t->course, " Student ID: ", t->studentID," Grade: ", t->grade);
                    }
                } else if (!strcmp(course, "*")) {
                    if(!strcmp(t->grade, grade)){
                        printf("%s%s%s%s%s%s\n", "Course: ", t->course, " Student ID: ", t->studentID," Grade: ", t->grade);
                    }else if(!strcmp(grade, "*")) {
                        printf("%s%s%s%s%s%s\n", "Course: ", t->course, " Student ID: ", t->studentID," Grade: ", t->grade);
                    }
                }
            }
        }
    }
}