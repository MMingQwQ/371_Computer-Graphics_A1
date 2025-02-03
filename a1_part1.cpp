// Assignment 1: Part 1
// Team members: 1. Hui Zhang 40170679
//               2. Mingming Zhang 40258080
//               3. ...............

#include <iostream>

using namespace std;

// Function to create a dynamic array
int* createArray(int size) {
    return new int[size];  // Dynamically allocate memory for the array
}

// Function to initialize the array with values from 0 to size-1
void initializeArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }
}

// Function to print the array elements
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to delete the dynamically allocated array
void deleteArray(int* arr) {
    delete[] arr;  // Deallocate memory
}

int main() {
    int size;

    // Read the size of the array from the user
    cout << "Enter the size of the array: ";
    cin >> size;

    // Create the dynamic array
    int* arr = createArray(size);

    // Initialize the array with values
    initializeArray(arr, size);

    // Print the array
    cout << "The array elements are: ";
    printArray(arr, size);

    // Deallocate the array memory
    deleteArray(arr);

    return 0;
}
