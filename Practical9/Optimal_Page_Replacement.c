#include <stdio.h>

#define MAX 50

int isPresent(int frames[], int f, int page) {
    int i;
	for (i = 0; i < f; i++) {
        if (frames[i] == page)
            return 1;
    }
    return 0;
}

int findOptimal(int pages[], int frames[], int n, int f, int index) {
    int farthest = index, pos = -1;

    int i;
	for (i = 0; i < f; i++) {
        int j;
        for (j = index + 1; j < n; j++) {
            if (frames[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    pos = i;
                }
                break;
            }
        }

        if (j == n)
            return i;
    }

    return (pos == -1) ? 0 : pos;
}

int main() {
    int pages[MAX], frames[MAX];
    int n, f, i, j;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for (i = 0; i < f; i++)
        frames[i] = -1;

    int pageFaults = 0, hits = 0;

    printf("\nStep-by-step execution:");
    for (i = 0; i < n; i++) {
        printf("\nStep %d: Page %d -> ", i + 1, pages[i]);

        if (isPresent(frames, f, pages[i])) {
            printf("HIT\n");
            hits++;
        } else {
            printf("FAULT\n");
            pageFaults++;

            int empty = -1;
            for (j = 0; j < f; j++) {
                if (frames[j] == -1) {
                    empty = j;
                    break;
                }
            }

            if (empty != -1) {
                frames[empty] = pages[i];
            } else {
                int pos = findOptimal(pages, frames, n, f, i);
                frames[pos] = pages[i];
            }
        }

        printf("Frames: ");
        for (j = 0; j < f; j++) {
            if (frames[j] == -1)
                printf("- ");
            else
                printf("%d ", frames[j]);
        }
        printf("\n");
    }

    // Calculate rates
    float faultRate = (float)pageFaults / n;
    float hitRate = (float)hits / n;

    printf("\nTotal Page Faults = %d\n", pageFaults);
    printf("Total Hits = %d\n", hits);

    printf("Page Fault Rate = %.2f\n", faultRate);
    printf("Page Hit Rate = %.2f\n", hitRate);

    return 0;
}
