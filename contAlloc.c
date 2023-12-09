

#include<stdio.h>
#include<conio.h>

int allocateMemory(char arr[], int len, int addr, int value) {
    int i;
    for(i = addr ; i < (addr+len) ; i++) {
        arr[i] = (char)value;
    } 
    return 0;
}

int main() {
    int length, files, i, j, len, addr, a = 65;
    printf("\nEnter the length in an array : ");
    scanf("%d", &length);
    char arr[length];
    for(i = 0 ; i < length ; i++) {
        arr[i] = 'X';
    }
    printf("\nEnter the number of files you want to add in the array : ");
    scanf("%d", &files);
    for(i = 0 ; i < files ; i++) {
        printf("\nEnter the length of File %c : ", (char)a);
        scanf("%d", &len);
        printf("Enter the starting address of the File %c : ", (char)a);
        scanf("%d", &addr);
        allocateMemory(arr, len, addr, a);
        a++;
    }
    printf("\n\n\t\t*****MEMORY*****\n");
    for(i = 0 ; i < length ; i++) {
        if((i%6) == 0)
            printf("\n");
        if(arr[i] == 0) 
            printf("%d : X\t", i);
        else 
            printf("%d : %c\t", i, arr[i]);
    }
    return 0;
}