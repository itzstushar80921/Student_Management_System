#include<stdio.h>
int main()
{ /*int data[]={5, 50, 20, 10, 40};
    int n=5;
    int i,j,temp;
    printf("original array: [ ");
    for(i=0;i< n;i++)
    {
        printf("%d " , data[i]);
    }
    printf(" ] \n");*/
    int n ,i,j,temp;
    scanf("%d",&n);
    int data[n];
    printf("enter %d numbers :\n",n);
    for(i=0;i<n;i++)
    {
     scanf("%d ",&data[i]); // array mein input lene ka tarika 
    }
    printf("original array: [ ");
    for(i=0;i<n;i++)
    {
     printf("%d ", data[i]);//original array ko print karne ke screen pr
    }
    printf(" ] \n");
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
    printf("\nSorted Array:   [ ");
    for (i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    printf("]\n");

    return 0;
}