/*Program: Implementation of First-fit Algorithm*/
#include<stdio.h>
#define MAX 20
struct BLOCK {
    int size;
    int isallocated;
    int pallocated;
    int frag;
} block[MAX];
 
void main() {
    int np, nb, i, psize[MAX], j;
    printf("Enter the no: of blocks: ");
    scanf("%d",&nb);
    printf("Enter the size of the blocks\n");
    for(i = 0; i < nb; i++) {
        printf("Block %d: ",i+1);
        scanf("%d",&block[i].size);
        block[i].isallocated = 0;
        block[i].pallocated = -1;
        block[i].frag = block[i].size;
    }
    printf("\nEnter the no: of processes: ");
    scanf("%d",&np);
    printf("Enter the size of the processes\n");
    for(j = 0; j < np; j++){
        printf("Process %d: ",j+1);
        scanf("%d",&psize[j]);
    }
    //First Fit Memory Allocation
    for(j = 0; j < np; j++) {
        for(i = 0; i < nb; i++) {
            printf("\nComparing process %d with block %d",j+1 ,i+1);
            if(block[i].isallocated==0 && block[i].size >= psize[j]) {
                printf("\nProcess %d is allocated to block %d\n",j+1 ,i+1);
                block[i].frag = block[i].size - psize[j];
                block[i].isallocated = 1;
                block[i].pallocated = j+1;
                break;
            }
        }
    }
    printf("\n\nBlock\tIsallocated\tProcess_allocated\tBlockSize\tPSize\tFragment\n");
    for(i = 0; i < nb; i++) {
        printf("%d\t%d\t\t%d\t\t\t%d\t\t%d\t%d\n",i+1, block[i].isallocated, block[i].pallocated, block[i].size, psize[block[i].pallocated], block[i].frag);
    }
}
