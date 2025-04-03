#include <stdio.h>

// O(n) Example: Linear time complexity
void linearExample(int n) {
    for (int i = 0; i < n; i++) {
        printf("Iteration %d\n", i); // This runs n times
    }
}

// O(n^2) Example: Quadratic time complexity
void quadraticExample(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("i: %d, j: %d\n", i, j); // This runs n^2 times
        }
    }
}

// O(1) Example: Constant time complexity
void constantExample() {
    printf("This is O(1) - runs once no matter the input size.\n");
}

int main() {
    int n = 5; // You can adjust n to test different input sizes

    printf("O(n) Example:\n");
    linearExample(n);

    printf("\nO(n^2) Example:\n");
    quadraticExample(n);

    printf("\nO(1) Example:\n");
    constantExample();

    return 0;
}

OUTPUT:

O(n) Example:
Iteration 0
Iteration 1
Iteration 2
Iteration 3
Iteration 4

O(n^2) Example:
i: 0, j: 0
i: 0, j: 1
i: 0, j: 2
i: 0, j: 3
i: 0, j: 4
i: 1, j: 0
i: 1, j: 1
i: 1, j: 2
i: 1, j: 3
i: 1, j: 4
i: 2, j: 0
i: 2, j: 1
i: 2, j: 2
i: 2, j: 3
i: 2, j: 4
i: 3, j: 0
i: 3, j: 1
i: 3, j: 2
i: 3, j: 3
i: 3, j: 4
i: 4, j: 0
i: 4, j: 1
i: 4, j: 2
i: 4, j: 3
i: 4, j: 4

O(1) Example:
This is O(1) - runs once no matter the input size.
