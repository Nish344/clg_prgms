#include <stdio.h>  // Include standard input/output library
#include <stdlib.h> // Include standard library for memory allocation

// Define a structure to represent a day with its details
struct DAY {
    char *dayname;    // Pointer to store the name of the day
    int date;         // Variable to store the date
    char *activity;   // Pointer to store the activity for the day
};

// Function to create a new day entry
void create(struct DAY *day) {
    // Allocate memory for the day name and activity
    day->dayname = (char *)malloc(sizeof(char) * 20); // Allocate memory for day name
    day->activity = (char *)malloc(sizeof(char) * 50); // Allocate memory for activity

    // Prompt user for day name and read it
    printf("Enter the name of the day: ");
    scanf("%s", day->dayname);

    // Prompt user for date and read it
    printf("Enter the date for the day: ");
    scanf("%d", &day->date);

    // Prompt user for activity and read it
    printf("Enter the activity for the day: ");
    scanf("%s", day->activity);
}

// Function to read multiple day entries into the calendar
void read(struct DAY *calendar, int size) {
    // Loop through the number of days specified
    for (int i = 0; i < size; i++) {
        printf("Enter details for day %d:\n", i + 1); // Prompt for details
        create(&calendar[i]); // Create a new day entry
    }
}

// Function to display the details of all days in the calendar
void display(struct DAY *calendar, int size) {
    // Print header for the activity details
    printf("Activity Details:\n");
    printf("_________________________________________\n");
    printf("Day\t\tName of the day\tDate\tActivity\n");
    printf("__________________________________________\n");

    // Loop through each day and print its details
    for (int i = 0; i < size; i++)
        printf("%d\t\t%s\t\t%d\t%s\n", i + 1, calendar[i].dayname, calendar[i].date, calendar[i].activity);
}

// Function to free allocated memory for day entries
void freememory(struct DAY *calendar, int size) {
    // Loop through each day and free allocated memory for day name and activity
    for (int i = 0; i < size; i++) {
        free(calendar[i].dayname);  // Free memory for day name
        free(calendar[i].activity);  // Free memory for activity
    }
}

// Main function
int main() {
    int size; // Variable to store the number of days in a week

    // Prompt user for the number of days and read it
    printf("Enter the number of days in a week: ");
    scanf("%d", &size);

    // Allocate memory for the calendar
    struct DAY *calendar = (struct DAY *)malloc(sizeof(struct DAY) * size);
    
    // Check if memory allocation was successful
    if (calendar == NULL) {
        printf("Memory allocation failed\n");
        return 1; // Exit if memory allocation fails
    }

    // Read details for each day in the calendar
    read(calendar, size);
    
    // Display the details of all days
    display(calendar, size);
    
    // Free allocated memory for each day's details
    freememory(calendar, size);
    
    // Free memory allocated for the calendar
    free(calendar);
    
    return 0; // Return success code
}
