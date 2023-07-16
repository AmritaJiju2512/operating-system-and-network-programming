/*Program: Priority Scheduling Algorithm*/

#include<stdio.h>
void main() {
  	int proc[10],arriv[10],burst[10],prior[10],prior1[10],n,i=0;
  	printf("Enter the number of processes (Less Than 10) : ");
  	scanf("%d", &n);
  	for(i=0;i<n;i++) {
    		printf("Enter the procedure,arrival time, burst time and priority of process number %d: \n", i+1);
    		scanf("%d %d %d %d",&proc[i],&arriv[i],&burst[i],&prior[i]);
  	}
  	for(i=0;i<n;i++) {
    		for(int j=0;j<n-i-1;j++) { 
      			int temp=0;
      			if(prior[j]>prior[j+1]) {
        			temp=arriv[j];
        			arriv[j]=arriv[j+1];
        			arriv[j+1]=temp;
        			temp=proc[j];
        			proc[j]=proc[j+1];
        			proc[j+1]=temp;
        			temp=burst[j];
        			burst[j]=burst[j+1];
        			burst[j+1]=temp;
        			temp=prior[j];
        			prior[j]=prior[j+1];
        			prior[j+1]=temp;
      			}
    		}
  	}
  	int turn[n],compl[n],wait[n],time=0,c=0;
  	do {
    		for(i=0;i<n;i++) {
      			if((arriv[i]<=time)&&(prior[i]!=-1)) {
        			compl[i]=time+burst[i];
        			time+=burst[i];
        			prior1[i]=prior[i];
        			prior[i]=-1;
        			c++;
        			break;
      			}
    		}
  	} while(c<n);
    	float avgtt=0,avgwt=0;
    	printf("Priority\tProcess\t\tArrival Time\t\t Burst Time \t\tCompletion Time\t\t Turn Around Time\t\t Waiting Time \n");
    	for(i=0;i<n;i++) {
      		turn[i]=compl[i]-arriv[i];
      		wait[i]=turn[i]-burst[i];
      		printf("%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t\t%d\n",prior1[i],proc[i],arriv[i],burst[i],compl[i],turn[i],wait[i]);
      		avgtt+=turn[i];
      		avgwt+=wait[i];
    	}
  	avgtt/=n;
  	avgwt/=n;
  	printf("Average turn around time\t= %.2f\n",avgtt);
  	printf("Average waiting time\t\t= %.2f\n",avgwt);
}
