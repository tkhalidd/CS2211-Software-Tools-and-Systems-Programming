#include <stdio.h>
#include <stdlib.h>
#include "movieTheaterDB_movie.h"
#include "movieTheaterDB_actor.h"

// Function to print the main program menu
void printHelp() {
    printf("\nCommands:\n");
    printf("h - Print help\n");
    printf("q - Quit program\n");
    printf("m - Control movies (submenu)\n");
    printf("a - Control actors (submenu)\n");
}

// Function for the movie submenu
void movieSubMenu() {
    char charInput;

    printf("\nMovie Submenu:\n");
    printf("e - Erase a movie\n");
    printf("i - Insert a new movie\n");
    printf("u - Update movie details\n");
    printf("s - Search for movie details\n");
    printf("p - Print all movies\n");

    printf("\nEnter operation code: ");
    scanf(" %c", &charInput);

    switch (charInput) {
        case 'e':
            // Erase a movie from the database
            erase_movie();
            break;
        case 'i':
            // Insert a new movie into the database
            insert_movie();
            break;
        case 'u':
            // Update details of an existing movie
            update_movie();
            break;
        case 's':
            // Search for details of a specific movie
            search_movie();
            break;
        case 'p':
            // Print details of all movies in the database
            print_movie();
            break;
        default:
            printf("Invalid operation code. Please try again.\n");
    }
}

// Function for the actor submenu
void actorSubMenu() {
    char charInput;

    printf("\nActor Submenu:\n");
    printf("e - Erase an actor\n");
    printf("i - Insert a new actor\n");
    printf("u - Update actor details\n");
    printf("s - Search actor details\n");
    printf("p - Print all actors\n");

    printf("\nEnter operation code: ");
    scanf(" %c", &charInput);

    switch (charInput) {
        case 'e':
            // Erase an actor from the database
            erase_actor();
            break;
        case 'i':
            // Insert a new actor into the database
            insert_actor();
            break;
        case 'u':
            // Update details of an existing actor
            update_actor();
            break;
        case 's':
            // Search for details of a specific actor
            search_actor();
            break;
        case 'p':
            // Print details of all actors in the database
            print_actor();
            break;
        default:
            printf("Invalid operation code. Please try again.\n");
    }
}

// Main program loop
int main() {
    char charInput;

    // Display initial program header
    printf("$ ./movieTheaterDB\n*********************\n* 2211 Movie Cinema *\n*********************");

    while (1) {
        // Prompt for the operation code
        printf("\n\nEnter operation code. Click 'h' for a description of the program: ");
        scanf(" %c", &charInput);

        switch (charInput) {
            case 'h':
                // Print the main program menu
                printHelp();
                break;
            case 'q':
                // Quit the program
                printf("Quitting program. All data is lost.\n");
                exit(0);
            case 'm':
                // Enter the movie submenu
                movieSubMenu();
                break;
            case 'a':
                // Enter the actor submenu
                actorSubMenu();
                break;
            default:
                printf("Invalid operation code. Please try again.\n");
        }
    }
}
