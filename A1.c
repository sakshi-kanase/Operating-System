#include <stdio.h>

int main() {
    int n, m, minResources;

    // Input number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input maximum resources each process may need
    printf("Enter the maximum resources a process may need: ");
    scanf("%d", &m);

    // Calculate minimum resources to avoid deadlock
    minResources = (n - 1) * (m - 1) + 1;

    printf("Minimum number of resources needed to avoid deadlock: %d\n", minResources);

    return 0;
}

