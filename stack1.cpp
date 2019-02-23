#include<stdio.h>
#include<conio.h>
#define max 5
struct STACK
{

    char item[100];
    char top;

};
void stack_init(struct STACK *);
void stack_init(struct STACK *p)
{
    p->top=-1;


}
int is_empty(struct STACK *);
int is_empty(struct STACK *p)
{
    if(p->top==-1)
    {
        return 1;

    }
    return 0;
}
int is_full(struct STACK *);
int is_full(struct STACK *p)
{
    if(p->top==max)
       {
           return 1;
       }
       return 0;
}
void push(struct STACK *,char);
void push(struct STACK *p,char x)
{
    if(is_full(p))
    {
        printf("stack overflow\n");

    }
    else
    {
        p->top++;
        p->item[p->top]=x;
    }


}
char pop(struct STACK *);
char pop(struct STACK *p)
{
    char x;
    if(is_empty(p))
    {
        printf("stack underflow\n");

    }
    else
    {
       x=p->item[p->top];
       p->top--;
       return x;
    }
}

char tos(struct STACK *);
char tos(struct STACK *p)
{

    char x;
    if(is_empty(p))
    {
        printf("stack overflow\n");

    }
    else
    {
        x=p->item[p->top];
        return x;

    }
}

int main()
{

    struct STACK s;
    char r,a[10];
     int flag=0;

    printf("enter a string");
    scanf("%s\n",a);
    for(int i=0;a[i]!='\0';i++)
    {
        if(a[i]=='('||a[i]=='{'||a[i]=='[')
           {
               push(&s,a[i]);

           }
           else if(a[i]==')'||a[i]=='}'||a[i]==']')

           {
               if(tos(&s)=='('&&a[i]==')'||tos(&s)=='{'&&a[i]=='}'||tos(&s)=='['&&a[i]==']')
               {
                   pop(&s);
               }


           }
           else
           {
             flag=1;
           }
    }
        if(flag==0)
        {
            printf("balanced");
        }
    else
    {

        printf("imbalanced\n");
    }
    getch();
    return 0;
}

