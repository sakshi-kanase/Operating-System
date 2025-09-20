#include <stdio.h>

int main() {
    int n, r, i, j;

    // Input number of processes and resources
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &r);

    int Max[n][r], Allocation[n][r], Need[n][r];

    // Input Maximum Matrix
    printf("\nEnter the Maximum Matrix (%d x %d):\n", n, r);
    for(i = 0; i < n; i++) {
        printf("Process %d: ", i);
        for(j = 0; j < r; j++) {
            scanf("%d", &Max[i][j]);
        }
    }

    // Input Allocation Matrix
    printf("\nEnter the Allocation Matrix (%d x %d):\n", n, r);
    for(i = 0; i < n; i++) {
        printf("Process %d: ", i);
        for(j = 0; j < r; j++) {
            scanf("%d", &Allocation[i][j]);
        }
    }

    // Calculate Need Matrix
    for(i = 0; i < n; i++) {
        for(j = 0; j < r; j++) {
            Need[i][j] = Max[i][j] - Allocation[i][j];
        }
    }

    // Display Need Matrix
    printf("\nNeed Matrix (%d x %d):\n", n, r);
    for(i = 0; i < n; i++) {
        printf("Process %d: ", i);
        for(j = 0; j < r; j++) {
            printf("%d ", Need[i][j]);
        }
        printf("\n");
    }

    return 0;
}

