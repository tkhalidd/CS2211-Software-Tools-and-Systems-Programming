/*
Name: Converter
Purpose: This program allows the user to convert various units including weight, area, volume, and distance.
Author: Tazrin Khalid
Student Number: 251294394
*/

#include <stdio.h>
#include <ctype.h>

// Function to perform unit conversion based on user input
void output(char letter, char a, char b, void (*conversionFunction1)(float), void (*conversionFunction2)(float)){
    float value; //Declaring the input value as a float

    // Check if the user's input matches option 'a'
    if (tolower(letter)==a) {
        printf("Please enter a value to be converted.\n");
        scanf("%f",&value);
        conversionFunction1(value); //Calls the conversion functions
    }
    // Check if the user's input matches option 'b'
    else if (tolower(letter)==b) {
        printf("Please enter a value to be converted.\n");
        scanf("%f",&value);
        conversionFunction2(value);
    }
    // If the input does not match either option
    else {
        printf("Please enter a valid input/value.\n");
    }
}

// Function to remove whitespace characters from user input
char removeWhitespace(){
    char letter;
    do {
        scanf("%c", &letter);
    } while (isspace(letter)); //Looping until a character is recognized, regardless of whitespace
    return letter;
}

// Functions for unit conversions and their respective outputs

void kgToLbs(float kg) { //Input kilograms, convert to pounds
    printf("Your conversion is: %.2f pounds.\n", kg * 2.20462);
}

void lbsToKg(float lbs) { //Input pounds, convert to kilograms
    printf("Your conversion is: %.2f kilograms.\n", lbs * 0.453592);
}

void haToAc(float ha) { //Input hectares, convert to acres
    printf("Your conversion is: %.2f acres.\n", ha * 2.47105);
}

void acToHa(float ac) { //Input acres, convert to hectares
    printf("Your conversion is: %.2f hectares.\n", ac * 0.404686);
}

void lToGal(float l) { //Input litres, convert to gallons
    printf("Your conversion is: %.2f gallons.\n", l * 0.264172);
}

void galToL(float gal) { //Input gallons, convert to litres
    printf("Your conversion is: %.2f litres.\n", gal * 3.78541);
}

void kmToMi(float km) { //Input kilometres, convert to miles
    printf("Your conversion is: %.2f miles.\n", km * 0.621371);
}

void miToKm(float mi) { //Input miles, convert to kilometres
    printf("Your conversion is: %.2f kilometres.\n", mi * 1.60934);
}

int main() {
    int menuOption; // Declaring the numerical options on the menu as an integer
    char letter; // Declaring conversion letter as a character

    // Main menu loop
    while (menuOption!=5){
        printf("Welcome to the Main Menu! Please enter: \n\n\"1\" to convert between Kilograms and Pounds\n\"2\" to convert between Hectares and Acres\n\"3\" to convert between Litres and Gallons\n\"4\" to convert between Kilometres and Miles\n\"5\" to quit\n");
        scanf("%d", &menuOption);
        getchar();

        if (menuOption < 1 || menuOption > 5) { // If statement to handle invalid inputs
            printf("Invalid input! You will be prompted to retry.\n");
        }

        // Switch statement to handle user's menu choice
        switch (menuOption) {
            case 1:
                printf("Enter K to convert from KG to LBS or P to convert from LBS to KG.\n");
                letter=removeWhitespace();
                output(letter, 'k', 'p', kgToLbs, lbsToKg); //Calling output function with user input to reduce redundant coding
                break;
            case 2:
                printf("Enter H to convert from HA to AC or A to convert from AC to HA.\n");
                letter=removeWhitespace();
                output(letter, 'h', 'a', haToAc, acToHa);
                break;
            case 3:
                printf("Enter L to convert from L to GAL or G to convert from GAL to L.\n");
                letter=removeWhitespace();
                output(letter, 'l', 'g', lToGal, galToL);
                break;
            case 4:
                printf("Enter K to convert from KM to MI or M to convert from MI to KM.\n");
                letter=removeWhitespace();
                output(letter, 'k', 'm', kmToMi, miToKm);
                break;
            case 5:
                printf("Thank you for using converter!");
                break;
        }
    }
}
