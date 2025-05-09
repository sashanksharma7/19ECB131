#include <stdio.h>
#include <stdlib.h>

// Node structure for polynomial term
struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a term into the polynomial (sorted by exponent)
void insertTerm(struct Node** poly, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);
    if (*poly == NULL || (*poly)->exp < exp) {
        newNode->next = *poly;
        *poly = newNode;
    } else {
        struct Node* temp = *poly;
        while (temp->next != NULL && temp->next->exp > exp) {
            temp = temp->next;
        }
        if (temp->next != NULL && temp->next->exp == exp) {
            temp->next->coeff += coeff;
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

// Function to add two polynomials
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exp == poly2->exp) {
            insertTerm(&result, poly1->coeff + poly2->coeff, poly1->exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        } else if (poly1->exp > poly2->exp) {
            insertTerm(&result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        } else {
            insertTerm(&result, poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        }
    }

    // Add remaining terms
    while (poly1 != NULL) {
        insertTerm(&result, poly1->coeff, poly1->exp);
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        insertTerm(&result, poly2->coeff, poly2->exp);
        poly2 = poly2->next;
    }

    return result;
}

// Function to print the polynomial
void printPolynomial(struct Node* poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->exp);
        if (poly->next != NULL && poly->next->coeff >= 0)
            printf(" + ");
        poly = poly->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;

    // Sample Input: You can also scan from user
    insertTerm(&poly1, 5, 2);
    insertTerm(&poly1, 4, 1);
    insertTerm(&poly1, 2, 0);

    insertTerm(&poly2, 5, 1);
    insertTerm(&poly2, -2, 0);

    printf("Polynomial 1: ");
    printPolynomial(poly1);

    printf("Polynomial 2: ");
    printPolynomial(poly2);

    struct Node* sum = addPolynomials(poly1, poly2);

    printf("Sum: ");
    printPolynomial(sum);

    return 0;
}


OUTPUT:

Polynomial 1: 5x^2 + 4x^1 + 2x^0
Polynomial 2: 5x^1-2x^0
Sum: 5x^2 + 9x^1 + 0x^0
