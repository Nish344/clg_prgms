#include<stdio.h>
#include<string.h>

// Function to define precedence when operators are in the stack
int stk_precedence(char symbol) {
    switch(symbol) {
        case '+':
        case '-': return 2;
        case '*':
        case '/':
        case '%': return 4;
        case '^': return 5;
        case '(': return 0;
        case '#': return -1;
        default: return 8; // For operands
    }
}

// Function to define precedence when operators are in the infix expression
int in_precedence(char symbol) {
    switch(symbol) {
        case '+':
        case '-': return 1;
        case '*':
        case '/':
        case '%': return 3;
        case '^': return 6;
        case '(': return 9;
        case ')': return 0;
        default: return 7; // For operands
    }
}

// Function to convert infix to postfix
void infix_to_postfix(char infix[], char postfix[]) {
    char stack[30]; // Stack for operators
    int top = -1, i, j = 0;
    char symbol;
    stack[++top] = '#'; // Initialize stack with a special marker

    for(i = 0; i < strlen(infix); i++) {
        symbol = infix[i];

        // If symbol is an operand, add it to postfix
        if((symbol >= 'a' && symbol <= 'z') || (symbol >= 'A' && symbol <= 'Z') || (symbol >= '0' && symbol <= '9')) {
            postfix[j++] = symbol;
        }
        else {
            // Pop operators from stack if their precedence is higher
            while(stk_precedence(stack[top]) > in_precedence(symbol)) {
                postfix[j++] = stack[top--];
            }
            // If symbol is ')', pop until '(' is found
            if(symbol == ')') {
                while(stack[top] != '(') {
                    postfix[j++] = stack[top--];
                }
                top--; // Remove the '(' from stack
            } else {
                stack[++top] = symbol; // Push the operator or '(' onto the stack
            }
        }
    }

    // Pop remaining operators in the stack
    while(stack[top] != '#') {
        postfix[j++] = stack[top--];
    }

    postfix[j] = '\0'; // Null-terminate the postfix expression
}

int main() {
    char infix[30], postfix[30];

    printf("Enter a valid infix expression: ");
    scanf("%s", infix); // Use scanf for safer input

    infix_to_postfix(infix, postfix);

    printf("The postfix expression is: %s\n", postfix);

    return 0;
}
