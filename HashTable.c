//
// Created by Muzains on 11/27/2017.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HashTable.h"
#include "LinkedList.h"

struct HashTable{
    LinkedList** Table;
    int bucket_headers;
};


int string_to_num(char* str){
    int str_num = 0;
    for (int i = 0; i< strlen(str); i++){
        str_num += str[i];
    }
    return str_num;
}



HashTable new_hashtable(int bucket_headers){
    HashTable h = malloc(sizeof(struct HashTable));
    h->bucket_headers = bucket_headers;
    h->Table = calloc(bucket_headers, sizeof(LinkedList*));
    for(int i = 0; i < h->bucket_headers; i++){
        h->Table[i] = LinkedList_new();
    }
    //num_to_string(123);
    return h;
}



