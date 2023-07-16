/*Program: Shortest Job First Scheduling Algorithm*/

#include<stdio.h>
struct process {
	int proc,arriv,burst,turn,compl,wait;
};
void main() {
 	struct process p[10];
 	int n,i,tburst[10];
 	printf("Enter the number of processes (Less Than 10) : ");
    	scanf("%d", &n);
 	for(i=0;i<n;i++) {
    		printf("Enter the procedure id, arrival time and burst time of process number %d: \n", i+1);
   		scanf("%d %d %d",&p[i].proc,&p[i].arriv,&p[i].burst); 
 	}
 
 	for(i=0;i<n;i++) {
 		for(int j=0;j<n-i-1;j++) { 
 			struct process temp;
     			if(p[j].burst>p[j+1].burst)	{
       				temp=p[j];
       				p[j]=p[j+1];
       				p[j+1]=temp;
     			}		
    		}
   	}
   	for(i=0;i<n;i++) {
   		tburst[i]=p[i].burst;
 	}
 	int time=0,c=0;
 	do {
  		for(i=0;i<n;i++) {
    			if((p[i].arriv<=time)&&(tburst[i]!=0)) {
     				p[i].compl=time+tburst[i];
     				time+=tburst[i];
     				tburst[i]=0;
     				c++;
     				break;
    			}
   		}
  	} while(c<n);
  	float avgtt=0,avgwt=0;
  	printf("Process\t\tArrival Time\t\tBurst Time \t\tCompletion Time\t\t Turn Around Time\t\t Waiting Time \n");
  	for(i=0;i<n;i++) {
  		p[i].turn=p[i].compl-p[i].arriv;
     		p[i].wait=p[i].turn-p[i].burst;
    		printf("%d\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t\t%d\n",p[i].proc,p[i].arriv,p[i].burst,p[i].compl,p[i].turn,p[i].wait);
    		avgtt+=p[i].turn;
    		avgwt+=p[i].wait;
  	}
  	avgtt/=n;
  	avgwt/=n;
   	printf("Average Turn Around Time\t= %.2f\n",avgtt);
    	printf("Average Waiting Time\t\t= %.2f\n",avgwt);
}
