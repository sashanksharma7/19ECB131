#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum number of elements in array

// Array to store data
int arr[MAX];
int size = 0;

// Function to insert an element at the end of the array
void insert(int value) {
    if (size >= MAX) {
        printf("Array is full. Cannot insert new element.\n");
    } else {
        arr[size++] = value;
        printf("%d inserted successfully.\n", value);
    }
}

// Function to delete an element from the end of the array
void delete() {
    if (size <= 0) {
        printf("Array is empty. Cannot delete element.\n");
    } else {
        printf("%d deleted successfully.\n", arr[size - 1]);
        size--;
    }
}

// Function to display the elements in the array
void display() {
    if (size <= 0) {
        printf("Array is empty.\n");
    } else {
        printf("Array elements: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    
    display();
    
    delete();
    delete();
    
    display();
    
    return 0;
}
OUTPUT:

10 inserted successfully.
20 inserted successfully.
30 inserted successfully.
40 inserted successfully.
50 inserted successfully.
Array elements: 10 20 30 40 50 
50 deleted successfully.
40 deleted successfully.
Array elements: 10 20 30 
