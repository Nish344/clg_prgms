#include <stdio.h>
#include <stdlib.h>

// Definition of a Binary Node
struct binaryNode {
    int data;
    struct binaryNode *left, *right; 
};

// Function to create a new node
struct binaryNode* createNode(int data) {
    struct binaryNode* newNode = (struct binaryNode*)malloc(sizeof(struct binaryNode));
    newNode->data = data;
    newNode->right = newNode->left = NULL;
    return newNode;
}

// Function to insert a node into the BST
struct binaryNode* insert(struct binaryNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Inorder Traversal
void inorder(struct binaryNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Preorder Traversal
void preorder(struct binaryNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder Traversal
void postorder(struct binaryNode* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Function to search for a key in the BST
int search(struct binaryNode* root, int key) {
    if (root == NULL) {
        return 0; // Key not found
    }
    if (key == root->data) {
        return 1; // Key found
    }
    if (key < root->data) {
        return search(root->left, key);
    }
    return search(root->right, key);
}

// Main Function
int main() {
    struct binaryNode* root = NULL;
    int choice, n, data, i, key, found;
    int elements[] = {6, 9, 5, 2, 8, 15, 24, 14, 7, 8, 5, 2};

    do {
        printf("\n--- Menu ---\n");
        printf("1. Create a BST of N Integers\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Search for an Element\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                root = NULL; // Reset the tree
                n = sizeof(elements) / sizeof(elements[0]);
                for (i = 0; i < n; i++) {
                    root = insert(root, elements[i]);
                }
                printf("BST created with given elements.\n");
                break;
            case 2:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                printf("Enter the element to search: ");
                scanf("%d", &key);
                found = search(root, key);
                if (found) {
                    printf("Element %d found in the BST.\n", key);
                } else {
                    printf("Element %d not found in the BST.\n", key);
                }
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 6);

    return 0;
}
