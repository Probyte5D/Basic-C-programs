#include <stdio.h>
#include <stdlib.h>

// Function to calculate the absolute value of an integer
int valoreAssoluto(int n) {
    // If the number is positive, return it as is
    if (n > 0) {
        return n;
    }
    // If the number is negative, return its positive value
    else if (n < 0) {
        return -n;
    }
    // If the number is zero, return zero
    else {
        return 0;
    }
}

int main() {
    // Declare variable for user input
    int n;

    // Prompt user to enter a number
    printf("Enter a number: ");
    scanf("%d", &n); // Read the number from the keyboard

    // Print the absolute value of the entered number
    printf("The absolute value is: %d\n", valoreAssoluto(n));
    
    return 0;
}

