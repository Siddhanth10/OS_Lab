//Disk Scheduling 
//SSTF
#include <stdio.h>
#include <stdlib.h>

int main() {
    int request[] = {98, 183, 41, 122, 14, 124, 65, 67};
    int n = 8;
    int visited[8] = {0};
	int i,j;
    int head = 53;
    int total = 0;

    printf("Initial Head Position: %d\n", head);
    printf("Request Sequence: ");
    for(i = 0; i < n; i++) {
        printf("%d ", request[i]);
    }

    printf("\n\nOrder of Execution (SSTF):\n");

    for(i = 0; i < n; i++) {
        int min = 1000, index = -1;

        // find nearest request
        for(j = 0; j < n; j++) {
            if(!visited[j]) {
                int distance = abs(head - request[j]);
                if(distance < min) {
                    min = distance;
                    index = j;
                }
            }
        }

        // print movement
        printf("%d -> %d (distance = %d)\n", head, request[index], min);

        total += min;
        head = request[index];
        visited[index] = 1;
    }

    printf("\nTotal Head Movement = %d\n", total);

    return 0;
}
