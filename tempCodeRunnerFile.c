if (flag==1) {
            printf("\nSymbol: %d  Frame: ",symbol);
            for (int j=0;j<n;j++)
                printf("%d ",frames[j]);
            page_hits+=1;
        }
        else {
            if (full==0) {
                index=(index+1)%n;
                frames[index]=symbol;
                page_miss+=1;
                printf("\nSymbol: %d  Frame: ",symbol);
                for (int j=0;j<n;j++)
                    printf("%d ",frames[j]);
            }
            else {
                int pos=999;
                int index=-1;
                for(int j=0;j<n;j++) {
                    for (int k=0;k<size;k++) {
                        if (frames[j]==string[k]) {
                            if (pos>k) {
                                pos=k;
                                index=j;
                                break;
                            }
                        } 
                    }
                }
                frames[index]=symbol;

            }
        }