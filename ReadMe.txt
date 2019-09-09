Muhammad Ahmad 
To run the project type make in the command window once at the file location in the directory Then run auto (the executable – using ./auto)
My project prints everything in one go: At the top it prints all the tables Then prints each part in order I have tried to include detailed print statements.

I have a separate .c file for each Relation. My main.c makes the all the Relations and inserts the tuples. It also has calls method for rest of the project. Most of my code is commented and easy to follow

For each Relation: make tuple method which makes the tuple. Insert method, it inserts the tuple into the HashTable - if not already present Print method Delete tuple method Lookup tuple method some have selection and projection methods as well

My Hash function: CSG: uses StudentID SNAP: uses StudentID CP: uses course CDH: uses course CR: uses course
I have used a HashTable to store the tuples. Each bucket has its own linkedlist. 
For insert - my code goes through the entire HashTable to check if there is already a similar tuple present with the same key 
For delete - if key is not provided, my code goes through the entire HashTable to find and delete the tuple 
Same for the lookup function Each relation has its own selection and projection

For selection -- Big O(n): My function goes through the entire HashTable and makes a new HashTable to store the selected tuples 
For projection -- Big O(n): My function goes through the entire HashTable and projects the schema the
question asks 
For Join: CR Join CDH -- Big O(nm) I make a new struct CR_CDH that joins the two relations on course and CR_CDH has its own selection and projection method. For each tuple in CR, I go through all the tuples in CDH and update the new HashTable - CR_CDH