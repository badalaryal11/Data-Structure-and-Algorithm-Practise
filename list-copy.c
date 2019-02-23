#include<stdio.h>
#include<conio.h>
#define max 5

int avail=0;    // current avail node
int length=0; //shows the count of data
int pre=-1;
int i;

struct list
{
    int data, next;
};

struct list node[max];

void list_init()
{
    for(i=0; i<max-1; i++)
    {
        node[i].next=i+1;
    }

    node[max-1].next=-1;
}
