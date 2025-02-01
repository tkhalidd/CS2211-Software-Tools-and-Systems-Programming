#ifndef MOVIETHEATERDB_ACTOR_H
#define MOVIETHEATERDB_ACTOR_H

// Include the main header file to access common structures and declarations
#include "movieTheaterDB.h"

// Function prototypes for actor-related operations
void insert_actor();     // Inserts a new actor into the database
void search_actor();     // Searches for an actor in the database based on actor code
void update_actor();     // Updates details of an existing actor in the database
void print_actor();      // Prints details of all actors in the database
void erase_actor();      // Erases an actor from the database based on actor code

#endif // MOVIETHEATERDB_ACTOR_H
