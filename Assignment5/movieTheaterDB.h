#ifndef MOVIETHEATERDB_H
#define MOVIETHEATERDB_H

// Structure for storing movie details
struct Movie {
    int code;
    char name[100];
    char genre[25];
    float rating;
};

// Structure for storing actor details
struct Actor {
    int code;
    char name[50];
    int age;
    char profile[50];
};

// Node structure for creating a linked list that can store either movie or actor details
struct Node {
    union {
        struct Movie movie;
        struct Actor actor;
    };
    struct Node* next;
};

// External declarations for head pointers of movie and actor linked lists
extern struct Node* head_movie;
extern struct Node* head_actor;

// Function prototypes for movie-related operations
void insert_movie();
void search_movie();
void update_movie();
void print_movie();
void erase_movie();

// Function prototypes for actor-related operations
void insert_actor();
void search_actor();
void update_actor();
void print_actor();
void erase_actor();

#endif // MOVIETHEATERDB_H
