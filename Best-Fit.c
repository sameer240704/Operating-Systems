#include<conio.h>
#include<stdio.h>
#include<limits.h>
#define MAX 100

int main() {
    int best_fit = 0, block_size[MAX], process_size[MAX], temp_size[MAX];
    int process, blocks, i, j, allocated = 0, ptr = 0;
    printf("\nEnter the number of blocks in the memory : ");
    scanf("%d", &blocks);
    printf("\nEnter the sizes of each block : \n");
    for(i=0 ; i<blocks ; i++) {
        printf("Block %d -> ", (i+1));
        scanf("%d", &block_size[i]);
        temp_size[i] = block_size[i];
    }
    printf("\nEnter the number of processes : ");
    scanf("%d", &process);
    printf("\nEnter the size of each process : \n");
    for(i=0 ; i<process ; i++) {
        printf("Process %d -> ", (i+1));
        scanf("%d", &process_size[i]);
    }

    printf("\n***MEMORY BLOCKS***\n");
    for(i=0 ; i<blocks ; i++) {
        printf("| %d |", block_size[i]);
    }
    printf("\n***PROCESS***\n");
    for(i=0 ; i<process ; i++) {
        printf("| %d |", process_size[i]);
    }
    printf("\n");

    //Best - Fit
    for(i=0 ; i<process ; i++) {
        best_fit = INT_MAX; 
        ptr = -1;
        for(j=0 ; j<blocks ; j++) {
            if(temp_size[j] == block_size[j]) {
                if((best_fit >= (temp_size[j] - process_size[i])) && (temp_size[j] - process_size[i]) >= 0) {
                    best_fit = temp_size[j] - process_size[i];
                    ptr = j;
                }
            }
        }   
        block_size[ptr] -= process_size[i];
        if(ptr != -1)
            printf("\nProcess %d allocated to Block %d", (i+1), (ptr+1));
        else    
            printf("\nProcess %d not allocated", (i+1));
    }
    printf("\n\n***MEMORY BLOCKS***\n");
    for (i=0; i<blocks ; i++) {
        printf("| %d |", block_size[i]);
    }
}