#include <stdio.h>
#include <stdlib.h>
#include "movieTheaterDB.h"
#include "movieTheaterDB_movie.h"

// Initialize the head of the movie database to NULL
struct Node* head_movie = NULL;
// Initialize the count of movies in the database to 0
int numMovies = 0;

void insert_movie() {
    // Check if the database is full
    if (numMovies >= 100) {
        printf("Database is full. Cannot add more movies.\n");
        return;
    }

    // Input movie code
    int movieCode;
    printf("Enter movie code: ");
    scanf("%d", &movieCode);

    // Check if the movie code is valid
    if (movieCode < 0) {
        printf("Please enter a number greater than zero.\n");
        return;
    }

    // Check for duplicate movie codes
    struct Node* current = head_movie;
    while (current != NULL) {
        if (current->movie.code == movieCode) {
            printf("Movie with the same code already exists. Enter a different code.\n");
            return;
        }
        current = current->next;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }

    // Input movie details
    newNode->movie.code = movieCode;

    printf("Enter movie name: ");
    scanf(" %99[^\n]", newNode->movie.name);

    printf("Enter movie genre: ");
    scanf(" %24[^\n]", newNode->movie.genre);

    printf("Enter movie rating: ");
    scanf("%f", &newNode->movie.rating);

    // Validate movie rating
    if (newNode->movie.rating < 0.0 || newNode->movie.rating > 10.0) {
        printf("Enter a valid movie rating between 0.0 and 10.0.\n");
        free(newNode); // Release memory for the new node
        return;
    }

    // Insert the new node at the end of the linked list
    newNode->next = NULL;  // The new node will be the last one
    if (head_movie == NULL) {
        // If the list is empty, the new node becomes the head
        head_movie = newNode;
    } else {
        // Traverse to the end and link the new node
        current = head_movie;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

    // Increment the number of movies in the database
    numMovies++;
}


void search_movie() {
    // Input movie code for searching
    int code;
    printf("Enter movie code: ");
    scanf("%d", &code);

    // Search for the movie by code
    struct Node* current = head_movie;
    while (current != NULL) {
        if (current->movie.code == code) {
            // Display movie details if found
            printf("%-12s%-40s%-25s%-15s\n", "Movie Code", "Movie Name", "Movie Genre", "Movie Rating");
            printf("%-12d%-40s%-25s%.1f\n", current->movie.code, current->movie.name, current->movie.genre, current->movie.rating);
            return;
        }
        current = current->next;
    }

    // Display message if movie is not found
    printf("Movie not found in database.\n");
}

void update_movie() {
    int code;
    printf("Enter movie code: ");
    scanf("%d", &code);

    // Search for the movie by code
    struct Node* current = head_movie;
    while (current != NULL) {
        if (current->movie.code == code) {
            // Input new movie details
            int newCode;
            printf("Enter new movie code: ");
            scanf("%d", &newCode);

            // Check for duplicate movie codes
            struct Node* temp = head_movie;
            while (temp != NULL) {
                if (temp != current && temp->movie.code == newCode) {
                    printf("Movie with the same code already exists. Enter a different code.\n");
                    return;
                }
                temp = temp->next;
            }

            current->movie.code = newCode;

            printf("Enter new movie name: ");
            scanf(" %99[^\n]", current->movie.name);

            printf("Enter new movie genre: ");
            scanf(" %24[^\n]", current->movie.genre);

            printf("Enter new movie rating: ");
            scanf("%f", &current->movie.rating);

            // Validate new movie rating
            if (current->movie.rating < 0.0 || current->movie.rating > 10.0) {
                printf("Enter a valid movie rating between 0.0 and 10.0.\n");
                return;
            }

            // Display success message after updating
            printf("Movie details updated successfully.\n");
            return;  // Exit the function after updating
        }
        current = current->next;
    }

    // Display message if movie is not found
    printf("Movie not found in database.\n");
}


void print_movie() {
    // Display all movies in the database
    printf("%-12s%-40s%-25s%-15s\n", "Movie Code", "Movie Name", "Movie Genre", "Movie Rating");

    // Traverse the linked list and print movie details
    struct Node* current = head_movie;
    while (current != NULL) {
        printf("%-12d%-40s%-25s%.1f\n", current->movie.code, current->movie.name, current->movie.genre, current->movie.rating);
        current = current->next;
    }
}

void erase_movie() {
    // Input movie code for erasing
    int code;
    printf("Enter movie code: ");
    scanf("%d", &code);

    // Search for the movie by code
    struct Node* current = head_movie;
    struct Node* prev = NULL;

    while (current != NULL) {
        if (current->movie.code == code) {
            // Found the movie, update the linked list to remove it
            if (prev == NULL) {
                // If the movie to be erased is the head, update the head
                head_movie = current->next;
            } else {
                // If the movie to be erased is not the head, update the previous node's next pointer
                prev->next = current->next;
            }

            // Free the memory for the erased node
            free(current);

            // Display success message after erasing
            printf("Movie erased successfully.\n");
            return;
        }

        // Move to the next node
        prev = current;
        current = current->next;
    }

    // Display message if movie is not found
    printf("Movie not found in database. Erase operation failed.\n");
}


