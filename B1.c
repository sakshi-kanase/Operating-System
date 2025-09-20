#include <stdio.h>

#define MAX 10

int Allocation[MAX][MAX], Max[MAX][MAX], Need[MAX][MAX];
int Available[MAX];
int n, r; // n = number of processes, r = number of resources

// Function to accept Allocation and Max matrices
void acceptMatrices() {
    printf("\nEnter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &r);

    printf("\nEnter Allocation Matrix (%d x %d):\n", n, r);
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i);
        for (int j = 0; j < r; j++) {
            scanf("%d", &Allocation[i][j]);
        }
    }

    printf("\nEnter Max Matrix (%d x %d):\n", n, r);
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i);
        for (int j = 0; j < r; j++) {
            scanf("%d", &Max[i][j]);
        }
    }
}

// Function to accept Available vector
void acceptAvailable() {
    printf("\nEnter Available Resources (%d values):\n", r);
    for (int i = 0; i < r; i++) {
        scanf("%d", &Available[i]);
    }
}

// Function to display Allocation and Max matrices
void displayAllocationMax() {
    printf("\nAllocation Matrix:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d: ", i);
        for (int j = 0; j < r; j++) {
            printf("%d ", Allocation[i][j]);
        }
        printf("\n");
    }

    printf("\nMax Matrix:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d: ", i);
        for (int j = 0; j < r; j++) {
            printf("%d ", Max[i][j]);
        }
        printf("\n");
    }
}

// Function to compute and display Need matrix
void computeAndDisplayNeed() {
    printf("\nNeed Matrix:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d: ", i);
        for (int j = 0; j < r; j++) {
            Need[i][j] = Max[i][j] - Allocation[i][j];
            printf("%d ", Need[i][j]);
        }
        printf("\n");
    }
}

// Function to display Available vector
void displayAvailable() {
    printf("\nAvailable Resources: ");
    for (int i = 0; i < r; i++) {
        printf("%d ", Available[i]);
    }
    printf("\n");
}

// Main function with menu
int main() {
    int choice;

    do {
        printf("\n===== Banker's Algorithm Menu =====\n");
        printf("1. Accept Allocation and Max\n");
        printf("2. Accept Available Resources\n");
        printf("3. Display Allocation and Max\n");
        printf("4. Compute and Display Need\n");
        printf("5. Display Available\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                acceptMatrices();
                break;
            case 2:
                acceptAvailable();
                break;
            case 3:
                displayAllocationMax();
                break;
            case 4:
                computeAndDisplayNeed();
                break;
            case 5:
                displayAvailable();
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 0);

    return 0;
}

