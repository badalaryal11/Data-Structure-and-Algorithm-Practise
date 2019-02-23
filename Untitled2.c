#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
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
int higher_priority(char x)
{
    if(x=='$')
        return 5;
    else if( x=='/'||x=='*')
        return 4;

     else if(x=='+'||x=='-')
        return 2;

}

int main()
{

    struct STACK s;
    char str[50], pstr[50];
    char r;
    int i, j=0, k=0;

    stack_init(&s);

    printf("\nEnter a string\t");
    scanf("%s",str);


for(i=0; str[i]!='\0'; i++)
{
    if(isalpha(str[i]))
    {
            pstr[k]=str[i];
            k++;
    }
    if(str[i]=='(')
       {
           push(&s, str[i]);
       }
    if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'||str[i]=='$')
    {
        if(is_empty(&s)) // if(is_empty(s.top==-1)
        {
            push(&s, str[i]);
        }


        else if(tos(&s)=='(')
           {
               push(&s, str[i]);
           }
          else if(higher_priority(str[i])>higher_priority(tos(&s)))
          {
               push(&s, str[i]);
          }

          else if(higher_priority(tos (&s))>= higher_priority(str[i]))  //***

          {

             while(higher_priority(tos (&s))>= higher_priority(str[i]))
                   {
                       pstr[k]=pop(&s);
                       k++;
                   }

                push(&s, str[i]);
          }
    }

    if(str[i]==')')
    {
        while(tos(&s)!='(') //****
              {
                  pstr[k]=pop(&s);
                  k++;
              }


        pop(&s);
    }

}


    while(!is_empty(&s))
    {
        pstr[k]=pop(&s);
        k++;


    }
pstr[k]='\0';

printf("\n%s",pstr);
getch();
}
