#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#define max 20
struct STACK
{

    char item[5];
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
void main()
{
    struct STACK s;
    char str[50];
    int opr1, opr2, res;
    int i=0,  r;

    stack_init(&s);

    printf("\nEnter a string\t");
    scanf("%s",str);



for(i=0; str[i]!='\0'; i++)
{
       if(isdigit(str[i]))
        {
            push(&s, str[i]-'0');

        }

        if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'||str[i]=='$')
        {
            opr2=pop(&s);
            opr1=pop(&s);
        }

        if(str[i]=='+')
        {
            res=opr1+opr2;
            push(&s, res);
        }

        else if(str[i]=='-')
        {
            res=opr1-opr2;
            push(&s, res);        }
        else if(str[i]=='*')
        {
            res=opr1*opr2;
            push(&s, res);
        }
        else if(str[i]=='/')
        {
            res=opr1/opr2;
            push(&s, res);
        }
        else if(str[i]=='$')
        {
            res=pow(opr1,opr2);
            push(&s, res);
        }




}
r=pop(&s);
printf("\n%d",r);
}
