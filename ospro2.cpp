#include<iostream>

using namespace std;
 
int main()
{
    int n,BT[20],WT[20],TAT[20],AVWT=0,AVTAT=0,i,j;
    cout<<"Enter total number of processes(maximum 20):";
    cin>>n;
 
    cout<<"\nEnter Process Burst Time\n";
    for(i=0;i<n;i++)
    {
        cout<<"P["<<i+1<<"]:";
        cin>>BT[i];
    }
 
    WT[0]=0;    //waiting time for first process is 0
 
    //calculating waiting time
    for(i=1;i<n;i++)
    {
        WT[i]=0;
        for(j=0;j<i;j++)
            WT[i]+=BT[j];
    }
 
    cout<<"\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time";
 
    //calculating turnaround time
    for(i=0;i<n;i++)
    {
        TAT[i]=BT[i]+WT[i];
        AVWT+=WT[i];
        AVTAT+=TAT[i];
        cout<<"\nP["<<i+1<<"]"<<"\t\t"<<BT[i]<<"\t\t"<<WT[i]<<"\t\t"<<TAT[i];
    }
 
    AVWT/=i;
    AVTAT/=i;
    cout<<"\n\nAverage Waiting Time:"<<AVWT;
    cout<<"\nAverage Turnaround Time:"<<AVTAT;
 
    return 0;
}
