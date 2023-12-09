#include <stdio.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

int main() {
    int processes, resources, i, j, k;
    int found;
    int available[MAX_RESOURCES];
    int maximum[MAX_PROCESSES][MAX_RESOURCES];
    int allocation[MAX_PROCESSES][MAX_RESOURCES];
    int need[MAX_PROCESSES][MAX_RESOURCES];
    int work[MAX_RESOURCES];
    int finish[MAX_PROCESSES];
    int count, safeSequence[MAX_PROCESSES];

    printf("Enter the number of processes: ");
    scanf("%d", &processes);

    printf("Enter the number of resources: ");
    scanf("%d", &resources);

    printf("Enter the available resources: ");
    for (i = 0; i < resources; ++i)
        scanf("%d", &available[i]);

    printf("Enter the allocation matrix:\n");
    for (i = 0; i < processes; ++i) {
        printf("Process %d allocation: ", i);
        for (j = 0; j < resources; ++j)
            scanf("%d", &allocation[i][j]);
    }

    printf("Enter the maximum matrix:\n");
    for (i = 0; i < processes; ++i) {
        printf("Process %d maximum: ", i);
        for (j = 0; j < resources; ++j) {
            scanf("%d", &maximum[i][j]);
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }

    // Banker's Algorithm
    for (i = 0; i < processes; ++i)
        finish[i] = 0;

    for (i = 0; i < resources; ++i)
        work[i] = available[i];

    count = 0;

    while (count < processes) {
        found = 0;
        for (i = 0; i < processes; ++i) {
            if (finish[i] == 0) {
                int j;
                for (j = 0; j < resources; ++j) {
                    if (need[i][j] > work[j])
                        break;
                }
                if (j == resources) {
                    for (k = 0; k < resources; ++k)
                        work[k] += allocation[i][k];

                    safeSequence[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if (found == 0) {
            printf("System is in an unsafe state! DEADLOCK DETECTED**\n");
            break;
        }
    }

    if (count == processes) {
        printf("System is in a safe state (NO DEADLOCK).\nSafe sequence is: ");
        for (i = 0; i < (processes - 1); ++i) {
            printf("P%d -> ", safeSequence[i]);
        }
        printf("P%d\n", safeSequence[processes - 1]);
    }
    return 0;
}
