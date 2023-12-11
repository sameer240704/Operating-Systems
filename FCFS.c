#include<stdio.h>
#include<conio.h>

int main()
{
    int t,s, temp, process, i, j;
    float avg_tat = 0, avg_wt = 0;
    int pid[100],at[100],bt[100],tat[100],wt[100],ct[100];
    //clrscr();
    printf("Enter the list of processes : ");
    scanf("%d", &process);

    printf("\n Enter Arrival Time and Burst Time of processes : \n");
    for(i=0 ; i<process ; i++) {
	    pid[i] = i+1;
	    printf("Process %d -> ", pid[i]);
	    scanf("%d %d",&at[i], &bt[i]);
    }
    printf("\n Now the Table is : ");
    printf("\nPID\tAT\tBT");
    for(i=0;i<process;i++) {
	    printf("\nP%d\t%d\t%d",pid[i],at[i],bt[i]);
    }
    printf("\n");
    for(i=0 ; i<process ; i++) {
        for(t=0 ; t<i ; t++) {
            if(at[t] > at[t+1]) {
                temp=at[t];
                at[t]=at[t+1];
                at[t+1]=temp;
                temp=pid[t];
                pid[t]=pid[t+1];
                pid[t+1]=temp;
                temp=bt[t];
                bt[t]=bt[t+1];
                bt[t+1]=temp;
            }
        }
    }

    ct[0] = at[0] + bt[0]; //Calculating first completion time
    for(i=1 ; i<process ; i++) { //Further completion time
	    temp = 0;
	    if(ct[i-1] < at[i]) {
	        temp = at[i] - ct[i-1];
        }
	    ct[i] = ct[i-1] + bt[i] + temp;
    }

    for(i=0 ; i<process ; i++) {
	    tat[i]=ct[i]-at[i];
	    wt[i]=tat[i]-bt[i];
	    avg_tat += tat[i];
	    avg_wt += wt[i];
    }

    for(i=0 ; i<process ; i++) {
        for(t=0 ; t<i ; t++) {
            if(pid[t] > pid[t+1]) {
                temp=pid[t];
                pid[t]=pid[t+1];
                pid[t+1]=temp;
                temp=at[t];
                at[t]=at[t+1];
                at[t+1]=temp;
                temp=bt[t];
                bt[t]=bt[t+1];
                bt[t+1]=temp;
                temp=ct[t];
                ct[t]=ct[t+1];
                ct[t+1]=temp;
                temp=tat[t];
                tat[t]=tat[t+1];
                tat[t+1]=temp;
                temp=wt[t];
                wt[t]=wt[t+1];
                wt[t+1]=temp;
            }
        }
    }

    avg_tat = avg_tat/process;
    avg_wt = avg_wt/process;

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT");
    for(i=0 ; i<process ; i++) {
	    printf("\nP%d\t%d\t%d\t%d\t%d\t%d",pid[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }

    printf("\n\nAverage TurnAround Time : %.2f\nAverage Waiting Time : %.2f", avg_tat, avg_wt);
    getch();
    return 0;
}