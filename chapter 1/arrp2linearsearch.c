/*#include<stdio.h>
int main()
{
    int i,key,f=0;
    int arr[5]={5,10,20,30,40};
    printf("enter a number you want to search");
    scanf("%d",key);
    for(i=0;i<5;i++)
    {
        if(key==arr[i])
        
        {
            printf("successful");
        }
        else
        {
         printf("not successful");
        }
    }    
    return i;
}*/
#include <stdio.h>

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

    // --- 4. BUBBLE SORT ---
    // We nest two loops to compare and swap
    for (i = 0; i < n - 1; i++) {            // Outer loop for passes
        for (j = 0; j < n - i - 1; j++) {    // Inner loop for comparison
            if (data[j] > data[j + 1]) {
                // SWAP LOGIC
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }

    // --- 5. TRAVERSAL (Printing Sorted) ---
    printf("\nSorted Array:   [ ");
    for (i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    printf("]\n");

    return 0;
}