#include <stdio.h>

// Define constants for maximum string lengths
#define MAX_STR_LEN 100
#define MAX_PAT_LEN 50
#define MAX_REP_LEN 50

// Function to calculate the length of a string
int string_length(char *str) {
    int length = 0; // Initialize length to 0
    // Iterate until the end of the string or a newline character
    while (str[length] != '\0' && str[length] != '\n') {
        length++; // Increment length for each character
    }
    return length; // Return the calculated length
}

// Function to perform pattern replacement in the main string
void pattern_replace(char *str, char *pat, char *rep, char *result) {
    int i = 0, j = 0, k = 0, found = 0; // Initialize indices and a found flag
    // Get the lengths of the main string, pattern, and replacement
    int str_len = string_length(str);
    int pat_len = string_length(pat);
    int rep_len = string_length(rep);

    // Loop through each character of the main string
    while (i < str_len) {
        // Initialize a temporary variable for matching
        int temp = i, match = 1; // Assume a match is found
        // Check if the pattern matches at the current position
        for (k = 0; k < pat_len; k++) {
            // If characters do not match, set match to 0 and break
            if (str[temp] != pat[k]) {
                match = 0; // Set match to false
                break; // Exit the loop
            }
            temp++; // Move to the next character in the main string
        }

        // If a match was found
        if (match == 1) {
            found = 1; // Set the found flag to true
            // Copy the replacement string into the result
            for (k = 0; k < rep_len; k++) {
                result[j++] = rep[k]; // Add each character from rep to result
            }
            i += pat_len; // Move past the matched pattern in the main string
        } else {
            // If no match, copy the current character from the main string to result
            result[j++] = str[i++]; // Add the current character and increment both indices
        }
    }
    result[j] = '\0'; // Null-terminate the result string

    // Check if the pattern was found and display the appropriate message
    if (!found) {
        printf("\nPattern string NOT found in the main string.\n");
    } else {
        printf("\nThe resultant string is:\n%s\n", result); // Print the resulting string
    }
}

int main() {
    // Declare arrays to hold the main string, pattern, replacement, and result
    char str[MAX_STR_LEN], pat[MAX_PAT_LEN], rep[MAX_REP_LEN], result[MAX_STR_LEN];

    // Read the main string from user input
    printf("Enter the main string (STR): ");
    fgets(str, sizeof(str), stdin); // Use fgets for safer input

    // Read the pattern string from user input
    printf("Enter the pattern string (PAT): ");
    fgets(pat, sizeof(pat), stdin); // Use fgets for safer input

    // Read the replacement string from user input
    printf("Enter the replacement string (REP): ");
    fgets(rep, sizeof(rep), stdin); // Use fgets for safer input

    // Call the pattern matching and replacement function
    pattern_replace(str, pat, rep, result);

    return 0; // Return success code
}
