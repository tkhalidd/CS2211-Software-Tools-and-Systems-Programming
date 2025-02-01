/*
Name: Int To English
Purpose: This program converts numeric input (1-999) into their English word representations.
Author: Tazrin Khalid
Student Number: 251294394
*/

#include <stdio.h>

// Arrays to hold word representations of numbers
const char *ones[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
const char *teens[] = {"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
const char *tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

// Function to convert a number to its English word representation
void converter(int num){ // Parameter num declared as the integer for input

    if (num >= 1 && num <= 9) {
        printf("%s\n", ones[num]);  // Print the word representation for single-digit numbers
    } else if (num >= 11 && num <= 19) {
        printf("%s\n", teens[num - 11]);  // Print the word representation for numbers in the teens
    } else if (num >= 10 && num <= 99) {
        if (num % 10 == 0) {
            printf("%s\n", tens[num / 10]);  // Print the word representation for tens
        } else {
            printf("%s-%s\n", tens[num / 10], ones[num % 10]);  // Print the word representation for two-digit numbers
        }
    } else if (num >= 100 && num <= 999) {
        if (num % 100 == 0) {
            printf("%s hundred\n", ones[num / 100]);  // Print the word representation for hundreds
        } else {
            printf("%s hundred and ", ones[num / 100]);  // Print the word representation for hundreds
            converter(num % 100);  // Recursively calling converter for the remaining part of the number
        }
    } else {
        printf("Invalid input.\n");  // Printing error message for invalid input
    }
}

int main(){ //Main function to prompt the user
    int num;

    // Main loop to continuously get user input
    while (1) {
        printf("Please enter a value (1-999, 0 to quit): ");
        scanf("%d",&num);
        getchar();

        if (num == 0) {
            break;  // Exit the loop and quit program if user enters 0
        }
        else if (num < 1 || num > 999) {
            printf("Invalid input. Please enter a value between 1 and 999.\n");  // Prompt user for valid input
            continue;  // Skip the rest of the loop and start from the beginning
        }
        else {
            printf("You entered the number ");
            converter(num);  // Call the converter function to convert and print the word representation
        }
    }

    return 0; // Indicates that the program ended successfully
}
