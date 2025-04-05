#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100  

char stack[MAX];
int top = -1;

void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    return (top == -1) ? '\0' : stack[top--];
}

int precedence(char ch) {
    switch (ch) {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        case '^': return 3;
        default: return -1;
    }
}

void infixToPostfix(char* infix, char* postfix) {
    int i, j = 0;
    for (i = 0; infix[i] != '\0'; i++) {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];  // If operand, add to postfix
        }
        else if (infix[i] == '(') {
            push(infix[i]);  // Push '(' to stack
        }
        else if (infix[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();  // Pop till '('
            }
            pop();  // Remove '('
        }
        else {  // Operator encountered
            while (top != -1 && precedence(infix[i]) <= precedence(stack[top])) {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
    }

    while (top != -1) {  // Pop remaining operators
        postfix[j++] = pop();
    }
    
    postfix[j] = '\0';  // Null terminate string
}

int main() {
    char infix[MAX] = "A+(B*C-(D/E^F)*G)*H";
    char postfix[MAX];

    infixToPostfix(infix, postfix);
    
    printf("Infix Expression: %s\n", infix);
    printf("Postfix Expression: %s\n", postfix);

    return 0;
}

OUTPUT:

Infix Expression: A+(B*C-(D/E^F)*G)*H
Postfix Expression: ABC*DEF^/G*-H*+
