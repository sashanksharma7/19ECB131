#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX][MAX];
int top = -1;

void push(char* str) {
    strcpy(stack[++top], str);
}

char* pop() {
    return stack[top--];
}

void postfixToInfix(char* postfix, char* infix) {
    char op1[MAX], op2[MAX], temp[MAX];
    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isalnum(postfix[i])) {
            char operand[2] = {postfix[i], '\0'};
            push(operand);
        } else {
            strcpy(op2, pop());
            strcpy(op1, pop());
            snprintf(temp, sizeof(temp), "(%s%c%s)", op1, postfix[i], op2);
            push(temp);
        }
    }
    strcpy(infix, pop());
}

int main() {
    char postfix[MAX] = "ABC*DEF^/G*-H*+";
    char infix[MAX];

    postfixToInfix(postfix, infix);

    printf("Postfix Expression: %s\n", postfix);
    printf("Infix Expression: %s\n", infix);

    return 0;
}

OUTPUT:

Postfix Expression: ABC*DEF^/G*-H*+
Infix Expression: (A+(((B*C)-((D/(E^F))*G))*H))
