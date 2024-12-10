#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define structure for a node in the circular linked list
struct node {
    int cf, px, py, pz; // Coefficient and powers of x, y, z
    struct node *link;
};

typedef struct node *NODE;

// Function to allocate memory for a new node
NODE getnode() {
    NODE x = (NODE)malloc(sizeof(struct node));
    if (x == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    return x;
}

// Function to insert a node at the rear
NODE insert_rear(int cf, int px, int py, int pz, NODE head) {
    NODE temp = getnode(), cur = head->link;
    temp->cf = cf;
    temp->px = px;
    temp->py = py;
    temp->pz = pz;
    temp->link = head; // Circular linking
    while (cur->link != head)
        cur = cur->link;
    cur->link = temp;
    return head;
}

// Function to display the polynomial
void display(NODE head) {
    if (head->link == head) {
        printf("Polynomial is empty\n");
        return;
    }
    NODE temp = head->link;
    while (temp != head) {
        printf("%d*x^%d*y^%d*z^%d", temp->cf, temp->px, temp->py, temp->pz);
        if (temp->link != head)
            printf(" + ");
        temp = temp->link;
    }
    printf("\n");
}

// Function to read a polynomial
NODE read_poly(NODE head) {
    int cf, px, py, pz, cont;
    do {
        printf("Enter coefficient: ");
        scanf("%d", &cf);
        printf("Enter powers of x, y, z: ");
        scanf("%d%d%d", &px, &py, &pz);
        head = insert_rear(cf, px, py, pz, head);
        printf("Do you want to add more terms? (1 for Yes / 0 for No): ");
        scanf("%d", &cont);
    } while (cont == 1);
    return head;
}

// Function to evaluate a polynomial
void evaluate_poly(NODE head) {
    if (head->link == head) {
        printf("Polynomial is empty\n");
        return;
    }
    int x, y, z;
    double result = 0.0;
    printf("Enter values for x, y, z: ");
    scanf("%d%d%d", &x, &y, &z);
    NODE temp = head->link;
    while (temp != head) {
        result += temp->cf * pow(x, temp->px) * pow(y, temp->py) * pow(z, temp->pz);
        temp = temp->link;
    }
    printf("The evaluated result is: %.2lf\n", result);
}

// Function to add two polynomials
NODE add_poly(NODE h1, NODE h2, NODE h3) {
    NODE p1 = h1->link, p2;
    while (p1 != h1) {
        p2 = h2->link;
        int found = 0;
        while (p2 != h2) {
            if (p1->px == p2->px && p1->py == p2->py && p1->pz == p2->pz) {
                h3 = insert_rear(p1->cf + p2->cf, p1->px, p1->py, p1->pz, h3);
                found = 1;
                break;
            }
            p2 = p2->link;
        }
        if (!found)
            h3 = insert_rear(p1->cf, p1->px, p1->py, p1->pz, h3);
        p1 = p1->link;
    }
    p2 = h2->link;
    while (p2 != h2) {
        NODE temp = h3->link;
        int found = 0;
        while (temp != h3) {
            if (p2->px == temp->px && p2->py == temp->py && p2->pz == temp->pz) {
                found = 1;
                break;
            }
            temp = temp->link;
        }
        if (!found)
            h3 = insert_rear(p2->cf, p2->px, p2->py, p2->pz, h3);
        p2 = p2->link;
    }
    return h3;
}

// Main function
int main() {
    NODE h1 = getnode(), h2 = getnode(), h3 = getnode();
    h1->link = h1;
    h2->link = h2;
    h3->link = h3;

    int choice;
    while (1) {
        printf("\n1. Evaluate Polynomial\n2. Add Polynomials\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter the polynomial to evaluate:\n");
            h1 = read_poly(h1);
            display(h1);
            evaluate_poly(h1);
            break;
        case 2:
            printf("Enter the first polynomial:\n");
            h1 = read_poly(h1);
            printf("Enter the second polynomial:\n");
            h2 = read_poly(h2);
            h3 = add_poly(h1, h2, h3);
            printf("First Polynomial: ");
            display(h1);
            printf("Second Polynomial: ");
            display(h2);
            printf("Sum of Polynomials: ");
            display(h3);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice, try again.\n");
        }
    }
    return 0;
}
