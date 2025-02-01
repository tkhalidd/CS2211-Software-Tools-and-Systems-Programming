#include <stdio.h>
#include <stdlib.h>
#include "movieTheaterDB.h"
#include "movieTheaterDB_actor.h"

// Initialize the head of the actor database to NULL
struct Node* head_actor = NULL;
// Initialize the count of actors in the database to 0
int numActors = 0;

void insert_actor() {
// Check if the database is full
    if (numActors >= 100) {
        printf("Database is full. Cannot add more movies.\n");
        return;
    }

    // Input actor code
    int actorCode;
    printf("Enter actor code: ");
    scanf("%d", &actorCode);

    // Check if the actor code is valid
    if (actorCode < 0) {
        printf("Please enter a number greater than zero.\n");
        return;
    }

    // Check for duplicate actor codes
    struct Node* current = head_actor;
    while (current != NULL) {
        if (current->actor.code == actorCode) {
            printf("Actor with the same code already exists. Enter a different code.\n");
            return;
        }
        current = current->next;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }

    // Input actor details
    newNode->actor.code = actorCode;

    printf("Enter actor name: ");
    scanf(" %49[^\n]", newNode->actor.name);

    printf("Enter actor's IMDB profile: ");
    scanf(" %49[^\n]", newNode->actor.profile);

    printf("Enter actor age: ");
    scanf("%d", &newNode->actor.age);

    // Validate movie rating
    if (newNode->actor.age < 0 || newNode->actor.age > 120) {
        printf("Enter a valid actor age between 0 and 120.\n");
        free(newNode); // Release memory for the new node
        return;
    }

    // Insert the new node at the end of the linked list
    newNode->next = NULL;  // The new node will be the last one
    if (head_actor == NULL) {
        // If the list is empty, the new node becomes the head
        head_actor = newNode;
    } else {
        // Traverse to the end and link the new node
        current = head_actor;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

    // Increment the number of actors in the database
    numActors++;
}

void search_actor() { // Input actor code for searching
    int code;
    printf("Enter actor code: ");
    scanf("%d", &code);

    // Search for the actor by code
    struct Node* current = head_actor;
    while (current != NULL) {
        if (current->actor.code == code) {
            // Display movie details if found
            printf("%-12s%-40s%-25s%-49s\n", "Actor Code", "Actor Name", "Actor Age", "Actor IMBD Profile");
            printf("%-12d%-40s%-25d%.49s\n", current->actor.code, current->actor.name, current->actor.age, current->actor.profile);
            return;
        }
        current = current->next;
    }

    // Display message if actor is not found
    printf("Actor not found in database.\n");
}


void update_actor() {
    int code;
    printf("Enter actor code: ");
    scanf("%d", &code);

    // Search for the actor by code
    struct Node* current = head_actor;
    while (current != NULL) {
        if (current->actor.code == code) {
            // Input new actor details
            int newCode;
            printf("Enter new actor code: ");
            scanf("%d", &newCode);

            // Check for duplicate movie codes
            struct Node* temp = head_actor;
            while (temp != NULL) {
                if (temp != current && temp->actor.code == newCode) {
                    printf("Actor with the same code already exists. Enter a different code.\n");
                    return;
                }
                temp = temp->next;
            }

            current->actor.code = newCode;

            printf("Enter new actor name: ");
            scanf(" %49[^\n]", current->actor.name);

            printf("Enter actor's new IMDB profile: ");
            scanf(" %49[^\n]", current->actor.profile);

            printf("Enter new actor age: ");
            scanf("%d", &current->actor.age);

            // Validate new movie rating
            if (current->actor.age < 0 || current->actor.age > 120) {
                printf("Enter a valid actor age between 0 and 120.\n");
                return;
            }

            // Display success message after updating
            printf("Actor details updated successfully.\n");
            return;  // Exit the function after updating
        }
        current = current->next;
    }

    // Display message if actor is not found
    printf("Actor not found in database.\n");
}

void print_actor() {
    // Display all actors in the database
    printf("%-12s%-40s%-25s%-49s\n", "Actor Code", "Actor Name", "Actor Age", "Actor IMBD Profile");

    // Traverse the linked list and print actor details
    struct Node* current = head_actor;
    while (current != NULL) {
        printf("%-12d%-40s%-25d%.49s\n", current->actor.code, current->actor.name, current->actor.age, current->actor.profile);
        current = current->next;
    }
}

void erase_actor() {
    // Input actor code for erasing
    int code;
    printf("Enter actor code: ");
    scanf("%d", &code);

    // Search for the actor by code
    struct Node* current = head_actor;
    struct Node* prev = NULL;

    while (current != NULL) {
        if (current->actor.code == code) {
            // Found the movie, update the linked list to remove it
            if (prev == NULL) {
                // If the actor to be erased is the head, update the head
                head_actor = current->next;
            } else {
                // If the actor to be erased is not the head, update the previous node's next pointer
                prev->next = current->next;
            }

            // Free the memory for the erased node
            free(current);

            // Display success message after erasing
            printf("Actor erased successfully.\n");
            return;
        }

        // Move to the next node
        prev = current;
        current = current->next;
    }

    // Display message if movie is not found
    printf("Actor not found in database. Erase operation failed.\n");
}

