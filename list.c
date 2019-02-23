#include<stdio.h>
#include<conio.h>
#define max 7

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

int getnode()
{
    int p;
    if (avail==-1)
    {
        printf("\nOverflow\n");
        return 0;
    }
    p=avail;
    avail=node[avail].next;
    length++;
    return p;
}



void insert_after(int p, int x)
{   int q;
    if(p<max-1&& p>=0)
    {
        if(length==0)
        {
        q=avail;
        pre=q;
        avail=node[avail].next;
        node[q].next=-1;
        node[q].data=x;
        length++;
        }
        else
        {   //p=avail;
            q=getnode();
            node[q].data=x;
            node[q].next=node[pre].next;
            node[pre].next=q;
            pre=q;
        }
    }

    else
    {
        printf("\nIndex out of bound\n");
    }
}

void del_after(int p, int *px)
{

    int q;
    if(p==-1||node[p].next==-1||length==0)
    {
        printf("\nvoid deletion");
        return;
    }

    q=node[p].next;
    *px=node[q].data;
    node[p].next=node[q].next;
    freenode(q);
    return;
}

void freenode(int p)
{
    node[p].next=avail;
    avail=p;
}

void main()
{
    int a;
    struct list l;
    list_init();

    insert_after(0,22);
    insert_after(1,256);
    insert_after(2,173);
    insert_after(3,225);
    insert_after(4,229);
    del_after(1, &a);
    printf("\nDeleted element = %d\n\n\n", a);
    printf("The displayed value\n");
    i=0;
    while(node[i].next!=-1)
    {
        printf("\n%d\t%d\n", node[i].data, node[i].next);
        i=node[i].next;
    }
    printf("\n%d\t%d\n", node[i].data, node[i].next);
    getch();
}
