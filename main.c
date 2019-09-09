/*
 * Muhammad Ahmad
 * mahmad4
 * 29879816
 */

#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HashTable.h"
#include "CSG.h"
#include "CDH.h"
#include "CP.h"
#include "SNAP.h"
#include "CR.h"
#include "CR_CDH.h"

void part2_a(HashTable temp_SNAP, HashTable temp_CSG, char* course, char* name);
void part2_b(HashTable temp_SNAP, HashTable temp_CSG, HashTable temp_CDH, HashTable temp_CR, char* name, char* day, char* hour);

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

struct CSG{
    char course[6];
    char studentID[6];
    char grade[2];
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

int main() {
    // Filling in all the tables! //
    // Filling in CSG table
    HashTable h_CSG = new_hashtable(20);
    insert_CSG(make_tuple_CSG("CS101", "12345", "A"), h_CSG);
    insert_CSG(make_tuple_CSG("CS101", "67890", "B"), h_CSG);
    insert_CSG(make_tuple_CSG("EE200", "12345", "C"), h_CSG);
    insert_CSG(make_tuple_CSG("EE200", "22222", "B+"), h_CSG);
    insert_CSG(make_tuple_CSG("CS101", "33333", "A-"), h_CSG);
    insert_CSG(make_tuple_CSG("PH100", "67890", "C+"), h_CSG);
    print_CSG(h_CSG);
    printf("\n");

    // Filling in SNAP table
    HashTable h_SNAP = new_hashtable(20);
    insert_SNAP(make_tuple_SNAP("12345", "C. Brown", "12 Apple St.", "555-1234"), h_SNAP);
    insert_SNAP(make_tuple_SNAP("67890", "L. Van Pelt", "34 Pear Ave.", "555-5678"), h_SNAP);
    insert_SNAP(make_tuple_SNAP("22222", "P. Patty", "56 Grape Blvd.", "555-9999"), h_SNAP);
    print_SNAP(h_SNAP);
    printf("\n");

    // Filling in course-prerequisite table
    HashTable h_CP = new_hashtable(20);
    insert_CP(make_tuple_CP("CS101", "CS100"), h_CP);
    insert_CP(make_tuple_CP("EE200", "EE005"), h_CP);
    insert_CP(make_tuple_CP("EE200", "CS100"), h_CP);
    insert_CP(make_tuple_CP("CS120", "CS101"), h_CP);
    insert_CP(make_tuple_CP("CS121", "CS120"), h_CP);
    insert_CP(make_tuple_CP("CS205", "CS101"), h_CP);
    insert_CP(make_tuple_CP("CS206", "CS121"), h_CP);
    insert_CP(make_tuple_CP("CS206", "CS205"), h_CP);
    print_CP(h_CP);
    printf("\n");

    // Filling in Course Day Hour table
    HashTable h_CDH = new_hashtable(20);
    insert_CDH(make_tuple_CDH("CS101", "M", "9AM"), h_CDH);
    insert_CDH(make_tuple_CDH("CS101", "W", "9AM"), h_CDH);
    insert_CDH(make_tuple_CDH("CS101", "F", "9AM"), h_CDH);
    insert_CDH(make_tuple_CDH("EE200", "Th", "10AM"), h_CDH);
    insert_CDH(make_tuple_CDH("EE200", "W", "1PM"), h_CDH);
    insert_CDH(make_tuple_CDH("EE200", "Th", "10AM"), h_CDH);
    print_CDH(h_CDH);
    printf("\n");

    //Filling in Course Room table
    HashTable h_CR = new_hashtable(20);
    insert_CR(make_tuple_CR("CS101", "Turing Aud."), h_CR);
    insert_CR(make_tuple_CR("EE200", "25 Ohm Hall"), h_CR);
    insert_CR(make_tuple_CR("PH100", "Newton Lab"), h_CR);
    print_CR(h_CR);
    printf("\n");


    // ********************* //
    // PART 1 OF THE PROJECT //
    // ********************* //
    printf("******************************\n            PART 1\n******************************\n\n");

    // Example 8.2 a
    printf("*PART A* \nlookup((""CS101"", 12345, *), Course-StudentId-Grade) \n\n");
    lookup_CSG("CS101", "12345", "*", h_CSG);
    printf("\n");

    // Example 8.2 b
    printf("*PART B* \nlookup((CS205, CS101), Course-Prerequisite) \n\n");
    lookup_CP("CS205", "CS120", h_CP);
    printf("\n");

    // Example 8.2 c
    printf("*PART C* \ndelete((CS101, *), Course-Room) \n\n");
    printf("After deleting: \n");
    delete_CR("CS101", "*", h_CR);
    print_CR(h_CR);
    insert_CR(make_tuple_CR("CS101", "Turing Aud."), h_CR); // inserting tuple back for use in next parts
    printf("\n");

    // Example 8.2 d
    printf("*PART D* \ninsert((CS205, CS120), Course-Prerequisite) \n\n");
    printf("After inserting: \n");
    insert_CP(make_tuple_CP("CS205", "CS120"), h_CP);
    print_CP(h_CP);
    printf("\n");

    // Example 8.2 e
    printf("*PART E* \ninsert((CS205, CS101), Course-Prerequisite) \n\n");
    printf("After inserting: \n");
    insert_CP(make_tuple_CP("CS205", "CS101"), h_CP);
    print_CP(h_CP);
    printf("\n");


    // ********************* //
    // PART 2 OF THE PROJECT //
    // ********************* //
    printf("******************************\n            PART 2\n******************************\n\n");
    printf("QUERY 1 -- What grade did StudentName get in CourseName\n");
    printf("Example a: CS101 L.Van Pelt\n");
    part2_a(h_SNAP, h_CSG, "CS101", "L. Van Pelt");
    printf("\nExample b: EE200 P. Patty\n");
    part2_a(h_SNAP, h_CSG, "EE200", "P. Patty");

    printf("\nQUERY 2 -- Where is StudentName at Time on Day?\n");
    printf("Example a: C. Brown on Monday at 9AM\n");
    part2_b(h_SNAP, h_CSG, h_CDH, h_CR, "C. Brown", "M", "9AM");
    printf("\nExample b: P. Patty on Wednesday at 1PM\n");
    part2_b(h_SNAP, h_CSG, h_CDH, h_CR, "P. Patty", "W", "1PM");


    // ********************* //
    // PART 3 OF THE PROJECT //
    // ********************* //

    printf("******************************\n            PART 3\n******************************\n\n");

    // EXAMPLE 8.12(SELECTION)
    printf("EXAMPLE 8.12(SELECTION):\n");
    printf("\nSelection of courses = CS101 on CSG\n");
    HashTable EX8_12 = selection_csg("CS101", h_CSG);
    print_CSG(EX8_12);

    // EXAMPLE 8.13(PROJECTION)
    printf("\nEXAMPLE 8.13(PROJECTION):\n");
    projection_csg_ID(EX8_12);

    // EXAMPLE 8.14(JOIN)
    printf("\nEXAMPLE 8.14(JOIN):\n\n");
    HashTable h_CR_CDH = new_hashtable(20);
    join_CR_CDH(h_CR, h_CDH, h_CR_CDH);
    print_CR_CDH(h_CR_CDH);

    // EXAMPLE 8.15(ALL)
    printf("\nEXAMPLE 8.15(ALL):\n\nJoin of CR and CDH,\nSelection of Room = Turing Aud. \nThen projecting Day and Hour\n\n");
    HashTable EX8_15 = selection_cr_cdh("Turing Aud.", h_CR_CDH);
    projection_cr_cdr(EX8_15);


    return 0;
}

// method for part 2 a
void part2_a(HashTable temp_SNAP, HashTable temp_CSG, char* course, char* name) {
    for (int i = 0; i < temp_SNAP->bucket_headers; i++) {
        LinkedListIterator *snap = LinkedList_iterator(temp_SNAP->Table[i]);
        while (LinkedListIterator_has_next(snap)) {
            SNAP t = LinkedListIterator_next(snap);
            if(!strcmp(t->Name, name)){
                for(int j = 0; j<temp_CSG->bucket_headers; j++){
                    LinkedListIterator* f = LinkedList_iterator(temp_CSG->Table[j]);
                    while(LinkedListIterator_has_next(f)){
                        CSG x = LinkedListIterator_next(f);
                        if(!strcmp(x->course, course) && !(strcmp(x->studentID, t->studentID))){
                            printf("%s got a %s in %s\n", t->Name, x->grade, x->course);
                        }
                    }
                }
            }
        }
    }
}

// method for part 2 b
void part2_b(HashTable temp_SNAP, HashTable temp_CSG, HashTable temp_CDH, HashTable temp_CR, char* name, char* day, char* hour){
    for (int i = 0; i < temp_SNAP->bucket_headers; i++) {
        LinkedListIterator *snap = LinkedList_iterator(temp_SNAP->Table[i]);
        while (LinkedListIterator_has_next(snap)) {
            SNAP z = LinkedListIterator_next(snap);
            if (!strcmp(z->Name, name)) {
                for (int j = 0; j < temp_CSG->bucket_headers; j++) {
                    LinkedListIterator *csg = LinkedList_iterator(temp_CSG->Table[j]);
                    while (LinkedListIterator_has_next(csg)) {
                        CSG y = LinkedListIterator_next(csg);
                        if (!(strcmp(y->studentID, z->studentID))) {
                            for (int k = 0; k < temp_CDH->bucket_headers; k++) {
                                LinkedListIterator *cdh = LinkedList_iterator(temp_CDH->Table[k]);
                                while (LinkedListIterator_has_next(cdh)) {
                                    CDH x = LinkedListIterator_next(cdh);
                                    if (!strcmp(y->course, x->course) && !strcmp(x->day, day) && !strcmp(x->hour, hour)) {
                                        for (int l = 0; l < temp_CR->bucket_headers; l++) {
                                            LinkedListIterator *cr = LinkedList_iterator(temp_CR->Table[l]);
                                            while (LinkedListIterator_has_next(cr)) {
                                                CR w = LinkedListIterator_next(cr);
                                                if (!strcmp(y->course, w->course)) {
                                                    printf("The Student %s is in room %s at %s on %s\n", z->Name, w->room, x->hour, x->day);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

