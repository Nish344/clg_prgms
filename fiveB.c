#include <stdio.h>

int count = 0;  // Global variable to count the moves

void tower(int n, char src, char temp, char dest) {
    if (n == 0)
        return;
    
    // Move n-1 discs from source to temporary rod
    tower(n-1, src, dest, temp);
    
    // Move nth disc from source to destination rod
    printf("\nMove disc %d from %c to %c", n, src, dest);
    count++;  // Increment move count
    
    // Move n-1 discs from temporary to destination rod
    tower(n-1, temp, src, dest);
}

int main() {
    int n;
    
    // Input the number of discs
    printf("\nEnter the number of discs: \n");
    scanf("%d", &n);
    
    // Call the Tower of Hanoi function
    tower(n, 'A', 'B', 'C');
    
    // Output the total number of moves
    printf("\nTotal number of moves = %d\n", count);
    
    return 0;
}
