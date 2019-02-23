#include<stdio.h>
#include<conio.h>
#include<math.h>
#define max 20

struct queue
{
       int item[max];
       int f,r;
};

void queue_init(struct queue*q)
{
     q->f==0;
     q->r==1;
 }
 
 int empty(struct queue *q)
 {
     return (q->r < q->f)
}

// queue full
int full(struct queue *q)
{
    return (q->r==max-1);
}


// insertion
void enqueue(struct queue *q,int a)
{
     if(full(q))
                printf("\nCan't insert\n")
}

// delete an item
void dequeue(struct queue *q)
{
     if(empty(q))
                 printf("\nCannot delete\n");
     else
     {
         return (q->item[q->f++])
     }

}
