// This program is written by Tazrin Khalid, student # 251294394. This program takes arrays as input and preforms a variety of functions on them, like rearranging elements or adding them.
#include <stdio.h>

// Function to print the elements of an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("[%d] = %d, ", i, arr[i]);
    }
    printf("\n");
}

// Part 1: Print the original array
void part1(int arr[], int size) {
    printf("Part 1:\nYour array is: ");
    printArray(arr, size);
}

// Part 2: Print the array in reverse order
void part2(int arr[], int size) {
    printf("Part 2:\nYour array in reverse is: ");
    for (int i = size - 1; i >= 0; i--) {
        printf("[%d] = %d, ", size - 1 - i, arr[i]);
    }
    printf("\n");
}

// Part 3: Print the even elements of the array
void part3(int arr[], int size) {
    printf("Part 3:\nThe even elements in the array is: ");
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            printf("[%d] = %d, ", i, arr[i]);
        }
    }
    printf("\n");
}

// Part 4: Print the sum of all elements in the array
void part4(int arr[], int size) {
    printf("Part 4:\nThe sum of all values in your array is: ");
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    printf("%d\n", sum);
}

// Part 5: Print the array in sorted order
void part5(int arr[], int size) {
    printf("Part 5:\nYour array in sorted order is: ");
    int sortedArr[size];
    for (int i = 0; i < size; i++) {
        sortedArr[i] = arr[i];
    }

    // Bubble sort algorithm (could add a comment explaining bubble sort here)
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (sortedArr[i] > sortedArr[j]) {
                int temp = sortedArr[i];
                sortedArr[i] = sortedArr[j];
                sortedArr[j] = temp;
            }
        }
    }

    printArray(sortedArr, size);
}

// Part 6: Print the array with the first and last elements swapped
void part6(int arr[], int size) {
    printf("Part 6:\nYour array with first and last element switched is: ");
    int modifiedArr[size];
    for (int i = 0; i < size; i++) {
        modifiedArr[i] = arr[i];
    }

    // Swap the first and last elements (could add a comment explaining the swap here)
    int temp = modifiedArr[0];
    modifiedArr[0] = modifiedArr[size - 1];
    modifiedArr[size - 1] = temp;

    printArray(modifiedArr, size);
}

int main() {
    int numIntegers;

    printf("Please enter the number of integers to process (between 5 and 12): ");
    scanf("%d", &numIntegers);

    if (numIntegers < 5 || numIntegers > 12) {
        printf("Invalid input. Please provide a number between 5 and 12.\n");
        return 1;
    }

    int arr[numIntegers];

    printf("There is enough room in your array for %d integers (%lu bytes)\n", numIntegers, sizeof(arr));

    printf("\nPlease enter your integers separated by spaces: ");
    for (int i = 0; i < numIntegers; i++) {
        scanf("%d", &arr[i]);
    }

    // Call each part of the program
    part1(arr, numIntegers);
    part2(arr, numIntegers);
    part3(arr, numIntegers);
    part4(arr, numIntegers);
    part5(arr, numIntegers);
    part6(arr, numIntegers);

    return 0;
}
