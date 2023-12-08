#include<conio.h>
#include<stdio.h>

int main() {
    int ptr = 0, frame, page[10], seq[100], page_hit = 0, page_fault = 0, i, j, count = 0, n;
    printf("Enter the number of page frames : ");
    scanf("%d", &frame);
    printf("\nEnter the total numbers in the sequence : ");
    scanf("%d", &n);
    printf("\nEnter the sequence of numbers : ");
    for(i=0 ; i<n ; i++) {
        scanf("%d", &seq[i]);
    }

    for(i=0 ; i<frame ; i++) {
        page[i] = -1;
    }

    for(i=0 ; i<n ; i++) {
        count = 0;
        if(ptr > (frame-1)) 
            ptr = 0;
        for(j=0 ; j<frame ; j++) {
            if(seq[i] == page[j]) {
                page_hit++;
                count++;
            }
        }
        if(count == 0) {
            page[ptr] = seq[i];
            page_fault++;
            ptr++;
        }
        printf("\n");
        for(j=0 ; j<frame ; j++) {
            if(page[j] != -1)
                printf("%d ", page[j]);
            else 
                printf(" ");
        }
    }
    printf("\nPage Fault : %d\nPage Hit : %d", page_fault, page_hit);
    return 0;
}