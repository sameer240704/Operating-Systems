#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 100

struct Node {
    int data;
    struct Node* next;
} *node = NULL, *list = NULL, *last = NULL, *temp = NULL;

struct Node* createNode(int );
void AddAtBack(int );
void displayList();

struct Node* createNode(int value) {
    node = (struct Node*)malloc(sizeof(struct Node));
    node -> data = value;
    node -> next = NULL;
    return node;
}

void AddAtBack(int value) {
    node = createNode(value);
    if(list == NULL) 
        list = last = node;
    else {
        last -> next = node;
        last = node;
    }
}

void displayList() {
    if(list == NULL)
        printf("\nNo File was allocated any memory");
    else {
        temp = list;
        while(temp != NULL) {
            printf("%d -> ", temp -> data);
            temp = temp -> next;
        }
        printf("NULL");
    }
}

int main() {
    int ll_alloc[MAX], i, value, size, length;
    printf("Enter the size of the array : ");
    scanf("%d", &size);
    for(i=0 ; i<size ; i++) {
        ll_alloc[i] = -1;
    }
    printf("\nEnter the length of the file : ");
    scanf("%d", &length);
    printf("\nEnter the array index : ");
    for(i=0 ; i<length ; i++) {
        if(i == 0) {
            printf("\nStart -> ");
            scanf("%d", &value);
            AddAtBack(value);
            ll_alloc[value] = 0;
        }
        else if(i == (length-1)) {
            printf("End -> ");
            scanf("%d", &value);
            AddAtBack(value);
            ll_alloc[value] = 0;
        }
        else {
            printf("Index %d -> ", (i+1));
            scanf("%d", &value);
            AddAtBack(value);
            ll_alloc[value] = 0;
        }
    }
    printf("\n\t\t***MEMORY BLOCK***\n");
    for(i=0 ; i<size ; i++) {
        if(i%5 == 0)
            printf("\n");
        if(ll_alloc[i] == -1)
            printf("%d: X\t", i);
        else 
            printf("%d: A\t", i);
    }
    printf("\nThe Linked List Allocation is : \n");
    displayList();
}