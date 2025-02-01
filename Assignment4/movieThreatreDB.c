// This program is written by Tazrin Khalid - 251294394. This program creates a database for movies which will be shown at a movie theatre.

#include <stdio.h>

struct Movie {
    int code;
    char name[100];
    char genre[25];
    float rating;
};

struct Movie movielist[100];
int numMovies = 0;

void insert(){
    // Check if the database is full
    if (numMovies >= 100) {
        printf("Database is full. Cannot add more movies.\n");
        return;
    }

    // Input movie code
    printf("Enter movie code: ");
    scanf("%d", &movielist[numMovies].code);

    // Check if the movie code is valid
    if (movielist[numMovies].code < 0) {
        printf("Please enter a number greater than zero.\n");
        return;
    }

    // Check for duplicate movie codes
    for (int i = 0; i < numMovies; i++) {
        if (movielist[i].code == movielist[numMovies].code) {
            printf("Movie with the same code already exists. Enter a different code.\n");
            return;
        }
    }

    // Input movie details
    printf("Enter movie name: ");
    scanf(" %99[^\n]", movielist[numMovies].name);

    printf("Enter movie genre: ");
    scanf(" %24[^\n]", movielist[numMovies].genre);

    printf("Enter movie rating: ");
    scanf("%f", &movielist[numMovies].rating);

    // Validate movie rating
    if (movielist[numMovies].rating < 0.0 || movielist[numMovies].rating > 10.0) {
        printf("Enter a valid movie rating between 0.0 and 10.0.\n");
        return;
    }

    // Increment the number of movies in the database
    numMovies++;
}

void search(){
    // Input movie code for searching
    int code;
    printf("Enter movie code: ");
    scanf("%d", &code);

    // Search for the movie by code
    for (int i = 0; i < numMovies; i++) {
        if (movielist[i].code == code) {
            // Display movie details if found
            printf("%-12s%-40s%-25s%-15s\n", "Movie Code", "Movie Name","Movie Genre","Movie Rating");
            printf("%-12d%-40s%-25s%.1f\n", movielist[i].code, movielist[i].name, movielist[i].genre, movielist[i].rating);
            return;
        }
    }

    // Display message if movie is not found
    printf("Movie not found in database.\n");
}

void update() {
    int code;
    printf("Enter movie code: ");
    scanf("%d", &code);

    // Search for the movie by code
    for (int i = 0; i < numMovies; i++) {
        if (movielist[i].code == code) {
            // Input new movie details
            printf("Enter new movie code: ");
            scanf("%d", &movielist[i].code);

            // Check for duplicate movie codes
            for (int j = 0; j < numMovies; j++) {
                if (j != i && movielist[j].code == movielist[i].code) {
                    printf("Movie with the same code already exists. Enter a different code.\n");
                    return;
                }
            }

            printf("Enter new movie name: ");
            scanf(" %99[^\n]", movielist[i].name);

            printf("Enter new movie genre: ");
            scanf(" %24[^\n]", movielist[i].genre);

            printf("Enter new movie rating: ");
            scanf("%f", &movielist[i].rating);

            // Validate new movie rating
            if (movielist[i].rating < 0.0 || movielist[i].rating > 10.0) {
                printf("Enter a valid movie rating between 0.0 and 10.0.\n");
                return;
            }

            // Display success message after updating
            printf("Movie details updated successfully.\n");
            return;  // Exit the function after updating
        }
    }

    // Display message if movie is not found
    printf("Movie not found in database.\n");
}

void print() {
    // Display all movies in the database
    printf("%-12s%-40s%-25s%-15s\n", "Movie Code", "Movie Name","Movie Genre","Movie Rating");
    for (int i = 0; i < numMovies; i++) {
        printf("%-12d%-40s%-25s%.1f\n", movielist[i].code, movielist[i].name, movielist[i].genre, movielist[i].rating);
    }
}

int main() {
    char charInput;

    // Display initial program header
    printf("$ ./movieTheaterDB\n*********************\n* 2211 Movie Cinema *\n*********************\n\nEnter operation code: ");

    // Input the first operation code
    scanf(" %c", &charInput);

    // Main program loop
    while(charInput != 'q') {
        // Switch based on the operation code
        switch (charInput) {
            case 'i':
                insert();
                break;
            case 's':
                search();
                break;
            case 'u':
                update();
                break;
            case 'p':
                print();
                break;
            default:
                printf("Invalid operation code. Please try again.\n");
                break;
        }
        // Clear input buffer to handle any extra characters
        while ((getchar()) != '\n');

        // Prompt for the next operation code
        printf("\nEnter operation code: ");
        scanf(" %c", &charInput);
    }

    // End of the main program loop, indicating that the user entered 'q'
    return 0;
}