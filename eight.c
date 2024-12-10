#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Employee structure for DLL nodes
struct Employee {
    char SSN[15], Name[50], Dept[20], Designation[30], PhNo[15];
    float Sal;
    struct Employee *prev, *next;
};

// Function to create a new employee node
struct Employee* createNode() {
    struct Employee* newNode = (struct Employee*)malloc(sizeof(struct Employee));
    printf("Enter SSN: ");
    scanf("%s", newNode->SSN);
    printf("Enter Name: ");
    scanf("%s", newNode->Name);
    printf("Enter Department: ");
    scanf("%s", newNode->Dept);
    printf("Enter Designation: ");
    scanf("%s", newNode->Designation);
    printf("Enter Salary: ");
    scanf("%f", &newNode->Sal);
    printf("Enter Phone Number: ");
    scanf("%s", newNode->PhNo);
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Function to insert at the end of DLL
struct Employee* insertAtEnd(struct Employee* head) {
    struct Employee* newNode = createNode();
    if (head == NULL) {
        return newNode;
    }
    struct Employee* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

// Function to display the DLL and count nodes
void displayDLL(struct Employee* head) {
    if (head == NULL) {
        printf("DLL is empty.\n");
        return;
    }
    struct Employee* temp = head;
    int count = 0;
    printf("Employee Data in DLL:\n");
    while (temp != NULL) {
        printf("SSN: %s, Name: %s, Dept: %s, Designation: %s, Salary: %.2f, Phone: %s\n",
               temp->SSN, temp->Name, temp->Dept, temp->Designation, temp->Sal, temp->PhNo);
        count++;
        temp = temp->next;
    }
    printf("Total number of nodes: %d\n", count);
}

// Function to delete from the end of DLL
struct Employee* deleteAtEnd(struct Employee* head) {
    if (head == NULL) {
        printf("DLL is empty. Cannot delete.\n");
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    struct Employee* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
    return head;
}

// Function to insert at the front of DLL
struct Employee* insertAtFront(struct Employee* head) {
    struct Employee* newNode = createNode();
    if (head == NULL) {
        return newNode;
    }
    newNode->next = head;
    head->prev = newNode;
    return newNode;
}

// Function to delete from the front of DLL
struct Employee* deleteAtFront(struct Employee* head) {
    if (head == NULL) {
        printf("DLL is empty. Cannot delete.\n");
        return NULL;
    }
    struct Employee* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
    return head;
}

// Main function to demonstrate operations
int main() {
    struct Employee* head = NULL;
    int choice;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Create DLL of Employees Data\n");
        printf("2. Display DLL and Count Nodes\n");
        printf("3. Insert at End\n");
        printf("4. Delete from End\n");
        printf("5. Insert at Front\n");
        printf("6. Delete from Front\n");
        printf("7. Use DLL as Double-Ended Queue\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of employees: ");
                int n;
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    head = insertAtEnd(head);
                }
                printf("DLL created with %d employees.\n", n);
                break;
            case 2:
                displayDLL(head);
                break;
            case 3:
                head = insertAtEnd(head);
                printf("Node inserted at the end.\n");
                break;
            case 4:
                head = deleteAtEnd(head);
                printf("Node deleted from the end.\n");
                break;
            case 5:
                head = insertAtFront(head);
                printf("Node inserted at the front.\n");
                break;
            case 6:
                head = deleteAtFront(head);
                printf("Node deleted from the front.\n");
                break;
            case 7:
                printf("Using DLL as Double-Ended Queue:\n");
                printf("1. Insert at Front, 2. Insert at End, 3. Delete from Front, 4. Delete from End\n");
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 8);

    return 0;
}
