#include<stdio.h>
#include<conio.h>
int main()
{

int count,j,n,TIME,remain,Fg=0,time_quantum;   //flag

int wait_time=0,turnaround_time=0,AT[10],BT[10],RT[10];

printf("Enter Total Process:\t");

scanf("%d",&n);

remain=n;

for(count=0;count<n;count++)

{

printf("Enter Arrival Time for Process Process Number %d :",count+1);

scanf("%d",&AT[count]);

printf("Enter Burst Time for Process Number %d:",count+1);

scanf("%d",&BT[count]);

RT[count]=BT[count];

}

printf("Enter Time Quantum:\t");

scanf("%d",&time_quantum);

printf("\n\nProcess\t| Burst Time    | Arrival Time  |Turnaround Time| Waiting Time\n\n");

for(TIME=0,count=0;remain!=0;)

{

if(RT[count]<=time_quantum && RT[count]>0)

{

TIME+=RT[count];

RT[count]=0;

Fg=1;

}

else if(RT[count]>0)

{

RT[count]-=time_quantum;

TIME+=time_quantum;

}

if(RT[count]==0 && Fg==1)

{

remain--;

printf("P[%d]\t|\t%d\t|\t%d\t|\t%d\t|\t%d\n",count+1,BT[count],AT[count],TIME-AT[count],TIME-AT[count]-BT[count]);

wait_time+=TIME-AT[count]-BT[count];

turnaround_time+=TIME-AT[count];

Fg=0;

}

if(count==n-1)

count=0;

else if(AT[count+1]<=TIME)

count++;

else

count=0;

}

printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n);

printf("Avg Turnaround Time = %f",turnaround_time*1.0/n);

return 0;

}
