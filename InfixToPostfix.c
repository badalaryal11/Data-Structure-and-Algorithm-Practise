#include<stdio.h>
#include<conio.h>
#define max 10
struct stack
{
	char item[5];
	int top;
};
void stack_init(struct stack *);
void stack_init(struct stack *p)
{
	p->top=-1;
}
int is_empty(struct stack *);
int is_empty(struct stack *p)
{
	if(p->top==-1)
	{
		return 1;
	}
	return 0;
}
int is_full(struct stack *);
int is_full(struct stack *p)
{
	if(p->top==max)
	{
		return 1;
	}
	return 0;
}
char push(struct stack *,char );
char push(struct stack *p,char x)
{
	if(is_full(p))
	{
		printf("Stack overflow \n");
	}
	else
	{
		p->top++;
		p->item[p->top]=x;
	}
}
char pop(struct stack *);
char pop(struct stack *p)
{
	char x;
	if(is_empty(p))
	{
		printf("Stack overflow \n");
		return 0;
	}
	else
	{
		x=p->item[p->top];
		p->top--;
		return x;
	}
}
char tos(struct stack *);
char tos(struct stack *p)
{
	char x;
	if(is_empty(p))
	{
		printf("Stack underflow \n");
		return 0;
	}
	else
	{
		x=p->item[p->top];
		return x;
	}
}
int priority(char);
int priority(char x)
{
    if(x=='$'|| x=='^')
    {
        return 5;
    }
    else if(x=='/'|| x=='*')
    {
        return 3;
    }else if(x=='+'|| x=='-')
    {
        return 1;
    }
}
void main()
{
    struct stack s;
    char a[20],b[20];
    int i,j=0;
    stack_init(&s);
    printf("enter a string");
    scanf("%s",a);
    for(i=0;a[i]!='\0';i++)
    {
            if(isalpha(a[i]))
            {
                        b[j]=a[i];
                        j++;
            }
            if(a[i]=='(')
            {
                     push(&s,a[i]);
            }
            if(a[i]=='+' || a[i]=='-'|| a[i]=='*' || a[i]=='/'|| a[i]=='$' ||a[i]=='^')
            {
                    if(is_empty(&s))
                    {
                        push(&s,a[i]);
                    }
                    else if(tos(&s)=='(')
                    {
                            push(&s,a[i]);

                    }
                    else if(priority(a[i])>priority(tos(&s)))
                    {
                                push(&s,a[i]);

                    }
                    else if(priority(a[i])<=priority(tos(&s)))
                    {
                        while(priority(a[i])<=priority(tos(&s)))
                        {
                            b[j]=pop(&s);
                            j++;
                        }
                        push(&s,a[i]);
                    }
            }
            if(a[i]==')')
            {
                while(tos(&s)!='(')
                {
                    b[j]=pop(&s);
                    j++;
                }
                pop(&s);
            }
    }
    while(s.top!=-1)
    {
        b[j]=pop(&s);
        j++;
    }
    printf("%s",b);
    getch();

}
