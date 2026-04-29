#include<stdio.h>
int main() {
    // --- 1. INITIALIZATION ---
    int data[] = {64, 34, 25, 12, 22, 11, 90};
    int n = 7; // We have 7 elements
    int searchTarget = 25;
    int foundIndex = -1; // -1 represents "not found"
    int i, j, temp; // Loop counters and swap variable

    printf("--- ALL-IN-ONE MAIN FUNCTION ---\n\n");

    // --- 2. TRAVERSAL (Printing Original) ---
    printf("Original Array: [ ");
    for (i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    printf("]\n");

    // --- 3. LINEAR SEARCH ---
    // We look through the array one by one
    for (i = 0; i < n; i++) {
        if (data[i] == searchTarget) {
            foundIndex = i; // Save the location
            break;          // Stop searching once found
        }
    }

    if (foundIndex != -1) {
        printf("\nSearch Result: Found value %d at index %d.\n", searchTarget, foundIndex);
    } else {
        printf("\nSearch Result: Value %d not found.\n", searchTarget);
    }
}
