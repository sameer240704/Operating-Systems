#include<stdio.h>
#include<conio.h>
#define MAX 100

int main() {
    int block_size[MAX], process_size[MAX], temp_size[MAX];
    int blocks, process, i, j;
    //clrscr();
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
    for(i=0 ; i<process ; i++) {
        int allocated = 0;
        for(j=0 ; j<blocks ; j++) {
            if((block_size[j] == temp_size[j]) && (process_size[i] <= block_size[j]) && (allocated == 0)) {
                block_size[j] -= process_size[i];
                allocated = 1;
            }
        }
        if(!allocated) {
            printf("\nProcess %d cannot be allocated", (i+1));
        }
    }
    printf("\n\nBLOCK\tWASTAGE\n");
    for(i=0 ; i<blocks ; i++) {
        if(block_size[i] == temp_size[i]) 
            printf("\nB%d\t%d (Not Alloted)", (i+1), block_size[i]);
        else    
            printf("\nB%d\t%d", (i+1), block_size[i]);
    }
    getch();
    return 0;
}