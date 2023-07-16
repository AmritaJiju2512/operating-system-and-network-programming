/* Program : First Come First Serve Scheduling Algorithm */

#include<stdio.h>

int main() {
int n,proc[10],arriv[10],burst[10];
printf("Enter the number of processes (Less Than 10) : ");
scanf("%d", &n);
  	for(int i=0;i<n;i++) {
  		printf("Enter the procedure id, arrival time and burst time of process number %d: \n", i+1);
    		scanf("%d %d %d",&proc[i],&arriv[i],&burst[i]);
  	}
  	for(int i=0;i<n;i++) {
  		for(int j=0;j<n-i-1;j++) { 
  			int temp=0;
    			if(arriv[j]>arriv[j+1])	{
      				temp=arriv[j];
      				arriv[j]=arriv[j+1];
      				arriv[j+1]=temp;
      				temp=proc[j];
      				proc[j]=proc[j+1];
      				proc[j+1]=temp;
      				temp=burst[j];
      				burst[j]=burst[j+1];
      				burst[j+1]=temp;
    			}
  		}
  	}
int turn[n],compl[n],wait[n],time=0;
compl[0]=burst[0];
turn[0]=compl[0]-arriv[0];
wait[0]=turn[0]-burst[0];
  	for(int i=1;i<n;i++) {
    		compl[i]=compl[i-1]+burst[i];
    		turn[i]=compl[i]-arriv[i];
    		wait[i]=turn[i]-burst[i];
  	}
  	float avgtt=0,avgwt=0;
  	printf("Process\t\tArrival Time\t\t Burst Time \t\tCompletion Time\t\t Turn Around Time\t\t Waiting Time \n");
  	for(int i=0;i<n;i++) {
    		printf(" %d\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t\t%d\n",proc[i],arriv[i],burst[i],compl[i],turn[i],wait[i]);
    		avgtt+=turn[i];
    		avgwt+=wait[i];
  	}
  	avgtt/=n;
  	avgwt/=n;
  	printf("Average Turn Around Time\t= %.2f\n",avgtt);
  	printf("Average Waiting Time\t\t= %.2f\n",avgwt);
}

