#include <stdio.h>

#define MAX 10

int main() {
    int p, r, i, j;

    printf("Enter number of processes: ");
    scanf("%d", &p);

    printf("Enter number of resources: ");
    scanf("%d", &r);

    int allocation[MAX][MAX], request[MAX][MAX];

    // Step 1: Input Allocation Matrix
    printf("Enter Allocation Matrix:\n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    // Step 2: Input Request Matrix
    printf("\nEnter Request Matrix:\n");
    for ( i = 0; i < p; i++) {
        for ( j = 0; j < r; j++) {
            scanf("%d", &request[i][j]);
        }
    }

    printf("\n============================\n");
    printf("RESOURCE ALLOCATION GRAPH\n");
    printf("============================\n");

    // Step 3: Show Allocation Edges
    printf("\nChecking Allocation Edges (Resource -> Process)\n");
    for ( i = 0; i < p; i++) {
        for ( j = 0; j < r; j++) {
            printf("Checking allocation[%d][%d] = %d\n", i, j, allocation[i][j]);

            if (allocation[i][j] == 1) {
                printf("=> Resource R%d is allocated to Process P%d\n", j, i);
                printf("   Edge: R%d --> P%d\n", j, i);
            }
        }
    }

    // Step 4: Show Request Edges
    printf("\nChecking Request Edges (Process -> Resource)\n");
    for ( i = 0; i < p; i++) {
        for ( j = 0; j < r; j++) {
            printf("Checking request[%d][%d] = %d\n", i, j, request[i][j]);

            if (request[i][j] == 1) {
                printf("=> Process P%d is requesting Resource R%d\n", i, j);
                printf("   Edge: P%d --> R%d\n", i, j);
            }
        }
    }

    // Step 5: Summary
    printf("\nGraph Construction Completed!\n");
    printf("All allocation and request edges are shown above.\n");

    return 0;
}
