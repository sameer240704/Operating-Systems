#include<stdlib.h>
#include<conio.h>
#include<stdio.h>

int mutex = 1;
int full = 0;
int empty = 5;
int data = 0;

void wait(int *S) {
    while(*S<=0);
    (*S)--;
}

void signal(int *S) {
    (*S)++;
}

void producer() {
    wait(&empty);
    wait(&mutex);
    data++;
    signal(&mutex);
    signal(&full);
    printf("\nProduced item %d",data);
}

void consumer() {
    wait(&full);
    wait(&mutex);
    printf("\nConsumed Item %d",data);
    data--;
    signal(&mutex);
    signal(&empty);
}

int main() {
    int i, n;
    //clrscr();
    while(1) {
        printf("\n1.) Enter 1 for Producer\n2.) Enter 2 for Consumer\n3.) Enter 3 to Exit\n");
        scanf("%d", &n);
        switch(n) {
        case 1: if(mutex==1 && empty!=0)
                    producer();
                else
                    printf("Buffer is full");
                break;
            
        case 2: if(mutex==1 && full!=0)
                    consumer();
                else
                    printf("Buffer is empty");
                break;

        case 3: exit(0);
                break;
        }
    }
    getch();
}
