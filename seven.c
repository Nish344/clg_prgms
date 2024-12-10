#include <stdio.h>
#include <stdlib.h>

struct Student{
    char USN[10];
    char Name[20] ;
    char Branch[10];
    int Sem;
    char PhNo[10];
    
    struct Student *next;
};

typedef struct Student Student;
int i;

Student *head = NULL;

void createFront(int n){
    for(i=0;i<n;i++){
        Student *newNode=(Student *)malloc(sizeof(Student));
        printf("\nEnter the student details\n");
        printf("Enter student USN\n");scanf("%s",newNode->USN);
        printf("Enter student Name\n");scanf("%s",newNode->Name);
        printf("Enter student Branch\n");scanf("%s",newNode->Branch);
        printf("Enter student Sem\n");scanf("%d",&newNode->Sem);
        printf("Enter student PhNo\n");scanf("%s",newNode->PhNo);
        newNode->next = head;
        head = newNode;
    }
}

void displayAndCount(){
    Student *temp=head;
    int count =0;
    if(!head){
        printf("The SLL is empty\n");
    }else{
        while(temp != NULL){
            printf("USN:%s\nName:%s\nBranch:%s\nSem:%d\nPhNo:%s\n\n",temp->USN,temp->Name,temp->Branch,temp->Sem,temp->PhNo);
            temp=temp->next;
            count++;
        }
    }
    printf("Total number of nodes is %d",count);
}

void insertEnd(){
    Student *newNode=(Student *)malloc(sizeof(Student));
    printf("\nEnter the student details to be inserted at Last\n");
    printf("Enter student USN\n");scanf("%s",newNode->USN);
    printf("Enter student Name\n");scanf("%s",newNode->Name);
    printf("Enter student Branch\n");scanf("%s",newNode->Branch);
    printf("Enter student Sem\n");scanf("%d",&newNode->Sem);
    printf("Enter student PhNo\n");scanf("%s",newNode->PhNo);
    newNode->next = NULL;

    if(head == NULL){
        head = newNode;
    }else{
        Student *temp = head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
}

void deleteEnd(){
    if(head == NULL){
        printf("The List is Empty\n");
        return;
    }
    if(head->next==NULL){
        free(head);
        head=NULL;
    }else{
        Student *temp=head;
        while(temp->next->next != NULL){
            temp=temp->next;
        }
        free(temp->next);
        temp->next=NULL;
    }
    printf("Node deleted from the END successfully");
}

void insertFront(){
    Student *newNode=(Student *)malloc(sizeof(Student));
    printf("\nEnter the student details to be inserted at Last\n");
    printf("Enter student USN\n");scanf("%s",newNode->USN);
    printf("Enter student Name\n");scanf("%s",newNode->Name);
    printf("Enter student Branch\n");scanf("%s",newNode->Branch);
    printf("Enter student Sem\n");scanf("%d",&newNode->Sem);
    printf("Enter student PhNo\n");scanf("%s",newNode->PhNo);
    newNode->next = head;
    head = newNode;
}

void deleteFront(){
    if(head == NULL){
        printf("The List is empty");
        return;
    }
    Student *temp = head;
    head = head->next;
    free(temp);
    printf("Node deleted from front");
}

int main() {
    int choice, n;
    do {
        printf("\n--- Menu ---\n");
        printf("1. Create SLL by Front Insertion\n");
        printf("2. Display SLL and Count Nodes\n");
        printf("3. Insert at End\n");
        printf("4. Delete from End\n");
        printf("5. Insert at Front\n");
        printf("6. Delete from Front\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of students: ");
                scanf("%d", &n);
                createFront(n);
                break;
            case 2:
                displayAndCount();
                break;
            case 3:
                insertEnd();
                break;
            case 4:
                deleteEnd();
                break;
            case 5:
                insertFront();
                break;
            case 6:
                deleteFront();
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 7);

    return 0;
}
