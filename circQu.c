#include<stdio.h>               // Including standard input/output library for I/O functions
#define MAX 4                   // Defining a macro 'MAX' with value 4, which sets the size of the circular queue
int ch, front = 0, rear = -1, count = 0, q[MAX], item;  // Declaring variables: ch for choice, front and rear for queue pointers, count for tracking number of elements, q[] as the queue array, item for holding inserted item

// Function to insert an item into the circular queue
void insert(int item, int *rear, int *q, int *count)
{
    if(*count == MAX)           // Checking if the queue is full
        printf("Circular Queue is Full\n");  // If full, print a message
    else
    {
        *rear = (*rear + 1) % MAX;  // Increment rear in a circular manner using modulo
        q[*rear] = item;        // Add the item at the rear position in the queue
        (*count)++;             // Increment the count of items in the queue
    }
}

// Function to delete an item from the circular queue
void del(int *front, int *q, int *count)
{
    if(*count == 0)             // Checking if the queue is empty
        printf("Circular Queue is underflow\n");  // If empty, print underflow message
    else
    {
        item = q[*front];       // Get the item at the front of the queue
        printf("\nDeleted item is: %d", item);  // Print the deleted item
        *front = (*front + 1) % MAX;  // Increment front in a circular manner using modulo
        (*count)--;             // Decrease the count of items in the queue
    }
}

// Function to display the items in the circular queue
void display(int front, int q[], int count)
{
    int i;
    if(count == 0)              // Checking if the queue is empty
        printf("\nCircular Queue is Empty");  // If empty, print a message
    else
    {
        printf("\nContents of Circular Queue is:\n");  // Print message to show queue contents
        for(i = 1; i <= count; i++)  // Loop through the queue elements
        {
            printf("%d\t", q[front]);  // Print each item starting from front
            front = (front + 1) % MAX;  // Move front in a circular manner using modulo
        }
    }
}

// Main function where the user can interact with the circular queue
void main()
{
    do
    {
        // Display menu options for queue operations
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit");
        printf("\nEnter the choice: ");
        scanf("%d", &ch);        // Read user's choice

        switch(ch)               // Switch case for handling the choice
        {
            case 1:              // Case 1 for inserting an item into the queue
                printf("\nEnter the item to be inserted: ");
                scanf("%d", &item);  // Read the item to be inserted
                insert(item, &rear, q, &count);  // Call insert function
                break;

            case 2:              // Case 2 for deleting an item from the queue
                del(&front, q, &count);  // Call delete function
                break;

            case 3:              // Case 3 for displaying the queue contents
                display(front, q, count);  // Call display function
                break;

            case 4:              // Case 4 to exit the program
                exit(0);          // Exit the program
                break;
        }
    } while(ch != 4);            // Continue until the user chooses to exit
}
