#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct process
{
char name;
int at,bt,wt,tt,rt;
int completed;
}p[100];

int n;
int q[100];        // global waiting queue
int front=-1,rear=-1;    //queue paraametrs

int i,j,time=0,sum_bt=0,tq;
char c;
float avgwt=0,avgtt=0;


void enqueue(int i)                            
{
if(rear==100)
{
printf("overflow");
exit(0);
}                                    //inserting in queue
rear++;   
q[rear]=i; 
if(front==-1)
{
front=0;
}
}
int dequeue()   
{
if(front==-1)
{
printf("underflow");
exit(0);
}                                              //removing from queue
int temp=q[front];
if(front==rear)
front=rear=-1;
else
{
front++;
}
return temp;
}

int isInQueue(int i)
{int k;
for(k=front;k<=rear;k++)
{
if(q[k]==i)
return 1;
}
return 0;

}

int  dispatcher(i)
{
  enqueue(i);
}

void sortByArrival()
{
struct process temp;
int i,j;
for(i=0;i<n-1;i++)
for(j=i+1;j<n;j++)
{
if(p[i].at>p[j].at)
{
temp=p[i];
p[i]=p[j];
p[j]=temp;
}
}
}

void input()
{
	 printf("\n\nEnter no of processes:");
 scanf("%d",&n);
 for(i=0,c='A';i<n;i++,c++)
 {
 p[i].name=c;
 printf("\n\t------------   PROCESS %c   --------------: ",p[i].name);
 printf("\n\nEnter Arrival Time:");
 scanf("%d",&p[i].at);
 printf("\nEnter Burst Time:");
 scanf("%d",&p[i].bt);
 p[i].rt=p[i].bt;
 p[i].completed=0;
 sum_bt+=p[i].bt;
 
}

printf("\nEnter TIME QUANTUM:");
scanf("%d",&tq);
}


void display()
{
	
printf("\n\nPROCESS\t    ARRIVAL TIME\tBURST TIME\tWAITING TIME\tTURNAROUND TIME");
for(i=0;i<n;i++)
{
p[i].tt=p[i].bt+p[i].wt;


avgwt+=p[i].wt;
 avgtt+=p[i].tt;
printf("\n%c\t\t%d\t\t%d\t\t%d\t\t%d",p[i].name,p[i].at,p[i].bt,p[i].wt,p[i].tt);
}
printf("\nAverage waiting time:%f",avgwt/n);
printf("\nAverage Turnaround time:%f",avgtt/n);
}


