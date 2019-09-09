//
// Created by Muzains on 11/27/2017.
//
//
// Created by Muzains on 11/27/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HashTable.h"
#include "LinkedList.h"
#include "SNAP.h"


struct HashTable{
    LinkedList** Table;
    int bucket_headers;
};

struct SNAP{
    char studentID[6];
    char Name[20];
    char Address[100];
    char phone[10];
};

SNAP make_tuple_SNAP(char* student_ID, char* Name, char* Address, char* phone){
    SNAP tuple = /*(SNAP)*/ malloc(sizeof(struct SNAP));
    strcpy(tuple->studentID, student_ID);
    strcpy(tuple->Name, Name);
    strcpy(tuple->Address, Address);
    strcpy(tuple->phone, phone);
    return tuple;
}

void insert_SNAP(SNAP tuple, HashTable h){
    int check = 1;
    for(int i = 0; i<h->bucket_headers; i++) {
        LinkedListIterator *f = LinkedList_iterator(h->Table[i]);
        while (LinkedListIterator_has_next(f)) {
            SNAP t = LinkedListIterator_next(f);
            if (!strcmp(t->studentID, tuple->studentID)) {
                check = 0;
            }
        }
    }
    if(check == 1) {
        LinkedList_add_at_end(h->Table[string_to_num(tuple->studentID) % (h->bucket_headers)], tuple);
    }
    //printf("%s", "inserted\n");
}

void print_SNAP(HashTable h){
    printf("%s\n", "SNAP table : ");
    for(int i = 0; i<h->bucket_headers; i++){
        LinkedListIterator* f = LinkedList_iterator(h->Table[i]);
        while(LinkedListIterator_has_next(f)){
            SNAP t = LinkedListIterator_next(f);
            printf("%s%s%s%s%s%s%s%s\n", "Student ID: ", t->studentID, " Name: ", t->Name, " Address: ", t->Address, " Phone: ", t->phone);
        }
    }
}


void delete_SNAP(char* studentID, char* Name, char* Address, char* phone, HashTable h){
    if (!strcmp(studentID, "*")) {
        for (int i = 0; i < h->bucket_headers; i++) {
            LinkedListIterator *f = LinkedList_iterator(h->Table[i]);
            while (LinkedListIterator_has_next(f)) {
                SNAP t = LinkedListIterator_next(f);
                if (!strcmp(t->Name, Name)) {
                    if(!strcmp(t->Address, Address)){
                        if(!strcmp(t->phone, phone)){
                            LinkedList_remove(h->Table[i], t);
                        }else if(!(strcmp(phone, "*"))){
                            LinkedList_remove(h->Table[i], t);
                        }
                    }else if(!strcmp(Address, "*")) {
                        if(!strcmp(t->phone, phone)){
                            LinkedList_remove(h->Table[i], t);
                        }else if(!(strcmp(phone, "*"))){
                            LinkedList_remove(h->Table[i], t);
                        }
                    }
                } else if (!strcmp(Name, "*")) {
                    if(!strcmp(t->Address, Address)){
                        if(!strcmp(t->phone, phone)){
                            LinkedList_remove(h->Table[i], t);
                        }else if(!(strcmp(phone, "*"))){
                            LinkedList_remove(h->Table[i], t);
                        }
                    }else if(!strcmp(Address, "*")) {
                        if(!strcmp(t->phone, phone)){
                            LinkedList_remove(h->Table[i], t);
                        }else if(!(strcmp(phone, "*"))){
                            LinkedList_remove(h->Table[i], t);
                        }
                    }
                }
            }
        }
    } else {
        LinkedList *l = h->Table[(string_to_num(studentID) % h->bucket_headers)];
        LinkedListIterator *f = LinkedList_iterator(l);
        while (LinkedListIterator_has_next(f)) {
            SNAP t = LinkedListIterator_next(f);
            if (!strcmp(t->studentID, studentID)) {
                if (!strcmp(t->Name, Name)) {
                    if(!strcmp(t->Address, Address)){
                        if(!strcmp(t->phone, phone)){
                            LinkedList_remove(l, t);
                        }else if(!(strcmp(phone, "*"))){
                            LinkedList_remove(l, t);
                        }
                    }else if(!strcmp(Address, "*")) {
                        if(!strcmp(t->phone, phone)){
                            LinkedList_remove(l, t);
                        }else if(!(strcmp(phone, "*"))){
                            LinkedList_remove(l, t);
                        }
                    }
                } else if (!strcmp(Name, "*")) {
                    if(!strcmp(t->Address, Address)){
                        if(!strcmp(t->phone, phone)){
                            LinkedList_remove(l, t);
                        }else if(!(strcmp(phone, "*"))){
                            LinkedList_remove(l, t);
                        }
                    }else if(!strcmp(Address, "*")) {
                        if(!strcmp(t->phone, phone)){
                            LinkedList_remove(l, t);
                        }else if(!(strcmp(phone, "*"))){
                            LinkedList_remove(l, t);
                        }
                    }
                }
            }
        }
    }
}


void lookup_SNAP(char* studentID, char* Name, char* Address, char* phone, HashTable h){
    if (!strcmp(studentID, "*")) {
        for (int i = 0; i < h->bucket_headers; i++) {
            LinkedListIterator *f = LinkedList_iterator(h->Table[i]);
            while (LinkedListIterator_has_next(f)) {
                SNAP t = LinkedListIterator_next(f);
                if (!strcmp(t->Name, Name)) {
                    if(!strcmp(t->Address, Address)){
                        if(!strcmp(t->phone, phone)){
                            printf("%s%s%s%s%s%s%s%s\n", "Student ID: ", t->studentID, " Name: ", t->Name, " Address: ", t->Address, " Phone: ", t->phone);
                        }else if(!(strcmp(phone, "*"))){
                            printf("%s%s%s%s%s%s%s%s\n", "Student ID: ", t->studentID, " Name: ", t->Name, " Address: ", t->Address, " Phone: ", t->phone);
                        }
                    }else if(!strcmp(Address, "*")) {
                        if(!strcmp(t->phone, phone)){
                            printf("%s%s%s%s%s%s%s%s\n", "Student ID: ", t->studentID, " Name: ", t->Name, " Address: ", t->Address, " Phone: ", t->phone);
                        }else if(!(strcmp(phone, "*"))){
                            printf("%s%s%s%s%s%s%s%s\n", "Student ID: ", t->studentID, " Name: ", t->Name, " Address: ", t->Address, " Phone: ", t->phone);
                        }
                    }
                } else if (!strcmp(Name, "*")) {
                    if(!strcmp(t->Address, Address)){
                        if(!strcmp(t->phone, phone)){
                            printf("%s%s%s%s%s%s%s%s\n", "Student ID: ", t->studentID, " Name: ", t->Name, " Address: ", t->Address, " Phone: ", t->phone);
                        }else if(!(strcmp(phone, "*"))){
                            printf("%s%s%s%s%s%s%s%s\n", "Student ID: ", t->studentID, " Name: ", t->Name, " Address: ", t->Address, " Phone: ", t->phone);
                        }
                    }else if(!strcmp(Address, "*")) {
                        if(!strcmp(t->phone, phone)){
                            printf("%s%s%s%s%s%s%s%s\n", "Student ID: ", t->studentID, " Name: ", t->Name, " Address: ", t->Address, " Phone: ", t->phone);
                        }else if(!(strcmp(phone, "*"))){
                            printf("%s%s%s%s%s%s%s%s\n", "Student ID: ", t->studentID, " Name: ", t->Name, " Address: ", t->Address, " Phone: ", t->phone);
                        }
                    }
                }
            }
        }
    } else {
        LinkedList *l = h->Table[(string_to_num(studentID) % h->bucket_headers)];
        LinkedListIterator *f = LinkedList_iterator(l);
        while (LinkedListIterator_has_next(f)) {
            SNAP t = LinkedListIterator_next(f);
            if (!strcmp(t->studentID, studentID)) {
                if (!strcmp(t->Name, Name)) {
                    if(!strcmp(t->Address, Address)){
                        if(!strcmp(t->phone, phone)){
                            printf("%s%s%s%s%s%s%s%s\n", "Student ID: ", t->studentID, " Name: ", t->Name, " Address: ", t->Address, " Phone: ", t->phone);
                        }else if(!(strcmp(phone, "*"))){
                            printf("%s%s%s%s%s%s%s%s\n", "Student ID: ", t->studentID, " Name: ", t->Name, " Address: ", t->Address, " Phone: ", t->phone);
                        }
                    }else if(!strcmp(Address, "*")) {
                        if(!strcmp(t->phone, phone)){
                            printf("%s%s%s%s%s%s%s%s\n", "Student ID: ", t->studentID, " Name: ", t->Name, " Address: ", t->Address, " Phone: ", t->phone);
                        }else if(!(strcmp(phone, "*"))){
                            printf("%s%s%s%s%s%s%s%s\n", "Student ID: ", t->studentID, " Name: ", t->Name, " Address: ", t->Address, " Phone: ", t->phone);
                        }
                    }
                } else if (!strcmp(Name, "*")) {
                    if(!strcmp(t->Address, Address)){
                        if(!strcmp(t->phone, phone)){
                            printf("%s%s%s%s%s%s%s%s\n", "Student ID: ", t->studentID, " Name: ", t->Name, " Address: ", t->Address, " Phone: ", t->phone);
                        }else if(!(strcmp(phone, "*"))){
                            printf("%s%s%s%s%s%s%s%s\n", "Student ID: ", t->studentID, " Name: ", t->Name, " Address: ", t->Address, " Phone: ", t->phone);
                        }
                    }else if(!strcmp(Address, "*")) {
                        if(!strcmp(t->phone, phone)){
                            printf("%s%s%s%s%s%s%s%s\n", "Student ID: ", t->studentID, " Name: ", t->Name, " Address: ", t->Address, " Phone: ", t->phone);
                        }else if(!(strcmp(phone, "*"))){
                            printf("%s%s%s%s%s%s%s%s\n", "Student ID: ", t->studentID, " Name: ", t->Name, " Address: ", t->Address, " Phone: ", t->phone);
                        }
                    }
                }
            }
        }
    }
}
