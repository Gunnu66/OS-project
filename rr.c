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
