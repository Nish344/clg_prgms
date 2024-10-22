#include <stdio.h>
#include <stdlib.h>  // Needed for exit()

#define MAX 5
int stack[MAX], item;
int ch, top = -1, status = 0;

void PUSH(int stack[], int item) {
    if (top == (MAX - 1)) {
        printf("Stack is overflow\n");
    } else {
        stack[++top] = item;
        status++;
    }
}

int pop(int stack[]) {
    int itemdel;
    if (top == -1) {
        printf("Stack is underflow\n");
        return -1; // Return -1 to indicate underflow
    } else {
        itemdel = stack[top--];
        status--;
        printf("Item %d is popped\n", itemdel);
        return itemdel;
    }
}

void palindrome(int stack[]) {
    int flag = 1, i;
    for (i = 0; i <= top / 2; i++) {
        if (stack[i] != stack[top - i]) {
            flag = 0;
            break;
        }
    }
    if (flag == 1) {
        printf("The stack is a palindrome\n");
    } else {
        printf("The stack is not a palindrome\n");
    }
}

void display(int stack[]) {
    int i;
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack contents are:\n");
        for (i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {  // Corrected the return type to int
    do {
        printf("\n1. Push (Insert)\n");
        printf("2. Pop\n");
        printf("3. Palindrome check\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);  // Use &ch to pass the address of ch
        switch (ch) {
            case 1:
                printf("Enter element to be pushed: ");
                scanf("%d", &item);  // Use &item to pass the address of item
                PUSH(stack, item);   // Corrected function call
                display(stack);      // Display stack after push
                break;
            case 2:
                item = pop(stack);  // Corrected function call
                break;
            case 3:
                palindrome(stack);  // Corrected function call
                break;
            case 4:
                display(stack);     // Corrected function call
                break;
            case 5:
                exit(0);  // Exit the program
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (ch != 5);
    return 0;  // Return 0 to indicate successful execution
}
