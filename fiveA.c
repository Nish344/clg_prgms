#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

double compute(char symbol, double op1, double op2) {
    switch(symbol) {
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '*': return op1 * op2;
        case '/': return op1 / op2;
        case '$': // Fall-through intended?
        case '^': return pow(op1, op2);
        default: return 0;
    }
}

void main() {
    double s[20], res, op1, op2;
    int top, i;
    char postfix[20], symbol;

    printf("\nEnter the postfix expression:\n");
    gets(postfix);  // Note: 'gets' is unsafe, consider using 'fgets' instead.
    
    top = -1;
    for(i = 0; i < strlen(postfix); i++) {
        symbol = postfix[i];

        if (isdigit(symbol)) {
            s[++top] = symbol - '0';  // Convert character to integer
        } else {
            op2 = s[top--];
            op1 = s[top--];
            res = compute(symbol, op1, op2);
            s[++top] = res;
        }
    }

    res = s[top--];
    printf("\nThe result is: %f\n", res);
}
