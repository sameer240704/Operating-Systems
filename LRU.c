#include <stdio.h>

void LRU(int string[20], int n, int size) {
    int i, j, k, page_miss = 0, page_hits = 0;
    int frames[n];

    for(i=0 ; i<n ; i++)
        frames[i] = -1;

    for(i=0 ; i<size ; i++) {
        int symbol = string[i];
        int flag = 0;

        for(j=0 ; j<n ; j++) {
            if(symbol == frames[j]) {
                flag = 1;
                break;
            }
        }

        if (flag == 1) {
            printf("\nSymbol : %d\tFrame : ", symbol);
            for (j=0 ; j<n ; j++) {
                if(frames[j] == -1)
                    printf("- ");
                else
                    printf("%d ", frames[j]);
            }
            page_hits += 1;
        } 
        else {
            int found = 0;
            for (j=0 ; j<n ; j++) {
                if(frames[j] == -1) {
                    frames[j] = symbol;
                    found = 1;
                    break;
                }
            }

            if(found == 0) {
                int pos[20];
                //Will find the places with the occurrences from the array
                for(j=0 ; j<n ; j++) {
                    pos[j] = -1;
                    for(k=(i-1) ; k>=0 ; k--) {
                        if(frames[j] == string[k]) {
                            pos[j] = k;
                            break;
                        }
                    }
                }
                /*
                {6,1,1,2,0} Frame -> 6 1 2
                Symbol : 0

                pos[20] = {-1, 2, 3}
                */

                //Will check for the minimum position in the pos array
                int min_pos = pos[0];
                j = 0;
                for(k=1 ; k<n ; k++) {
                    if(pos[k] == -1 || (min_pos != -1 && min_pos > pos[k])) {
                        min_pos = pos[k];
                        j = k;
                    }
                }
                frames[j] = symbol;
            }

            printf("\nSymbol : %d\tFrame : ", symbol);
            for (j = 0; j < n; j++) {
                if(frames[j] == -1)
                    printf("- ");
                else
                    printf("%d ", frames[j]);
            }
            page_miss += 1;
        }
    }
    printf("\nPage Hits : %d", page_hits);
    printf("\nPage Faults : %d", page_miss);
}

int main() {
    int string[] = {6,1,1,2,0,3,4,6,0,2,1,2,1,2,0,3,2,1,2,0};
    int no_frames = 3;
    int size = sizeof(string) / sizeof(int);
    LRU(string, no_frames, size);
    return 0;
}