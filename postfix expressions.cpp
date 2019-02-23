#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

#define max 20
void stack_init(struct stack *ps);
int empty (struct stack *ps);
int pop(struct stack *ps);
void push(struct stack *ps,int x);
int underflow(struct stack *ps);
int overflow(struct stack *ps);
void  top(struct stack *ps);

struct stack
{
       int top;
       int item[max];
};

// stack initialization

void stack_init(struct stack *ps)
{
     ps->top=-1;
}

// empty stack

int empty (struct stack *ps)
{
    if(ps->top==-1)
		  return 1;

    else
	 return 0;
}

// pop operation
int pop(struct stack *ps)
{
    if(empty(ps))
    {
		 printf("\nEmpty stack\n");
	       //	 exit(1);
		 return 0;
    }

    else
	return(ps->item[(ps->top)--]);
}

//push
void push(struct stack *ps,int x)
{
     if(ps->top==max-1)
     {
		       printf("\nStack overflow\n");
		      // exit(1);
     }
     else
      {	// ps->item[++(ps->top)]=x;
      	++ps->top;
       	ps->item[ps->top]=x;
      }
}
// overflow
int underflow(struct stack *ps)
{
    if(empty(ps))
		return 1;
    else
	return 0;
}

int overflow(struct stack *ps)
{
    if(ps->top==max-1)
		      return 1;
    else
	 return 0;

}

void top(struct stack *ps)
{
    if(!empty(ps))
    {
		  printf("\nTop of stack is\n");
		  printf("%d",ps->top);


    }

    else
    {
	printf("\nError, stack is empty\n");

    }
}

int main()
{
	struct stack S;
	int operand1,operand2,value;
	stack_init(&S);
	printf("\nEnter infix expressions\n");
	char c[10];
	scanf("%s",c);
	for(int i=0;c[i]!='\0';i++)
	{
        if(c[i]>='0' && c[i]<='9')
		     push(&S,c[i]);
        else
        {
            operand2=pop(&S);
	    operand1=pop(&S);
	    if(c[i]=='+')
		 value= operand1 + operand2;
	    else if(c[i]=='-')
		 value= operand1 - operand2;
	    else if(c[i]=='*')
		 value= operand1 * operand2;
	    else if(c[i]=='/')
		 value= operand1 / operand2;
	    else if(c[i]=='$')
		 value= pow(operand1,operand2);


            push(&S,value);
            
        }
                                        
    }
    int x=pop(&S);
    printf("\nThe result is %d\t",x);
    getch();
    return 0;
	
	


}
