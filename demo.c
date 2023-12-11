#include<stdio.h>

int main(){

int mempart[100],req[100],i,j,n,p,b,ab[100],index;

printf("\nEnter the number of memory partitions:\n ");
scanf("%d",&p);
printf("\n Enter %d memory partitions",p);
for(i=0;i<p;i++){
    scanf("%d",&mempart[i]);
}
printf("\nEnter no. of processes");
scanf("%d",&b);
printf("\nEnter memory required by %d processes:",b);
for(i = 0;i< b ;i++){
    scanf("%d",&req[i]);
}
for(i=0;i<p;i++){
    ab[i]=-1;
}      
                                                 
for(i = 0; i<b; i++){
    index = -1;
    for(j=0;j<p;j++){
        if(mempart[j] >= req[i]){
            if(index==-1 && ab[j]==-1){
                ab[j] = j;
                index = j;
                break;
            }// 500 400 
        }
    }
    if(index!=-1)
        printf("\nMemory block allocated at %d for %d",mempart[index],req[i]);
    else
        printf("\n Memory wasnt allocated for %d",req[i]);

    if(index!=-1) {
        mempart[index]-=req[i];
    }
}

    return 0;
}