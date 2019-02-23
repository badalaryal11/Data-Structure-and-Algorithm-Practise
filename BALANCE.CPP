#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define max 20
void stack_init(struct stack *ps);
int empty (struct stack *ps);
char pop(struct stack *ps);
void push(struct stack *ps,char x);
int underflow(struct stack *ps);
int overflow(struct stack *ps);
void  top(struct stack *ps);
void balance(char n[20],struct stack *ps);

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
char pop(struct stack *ps)
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
void push(struct stack *ps,char x)
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

void main()
{
	clrscr();
	char c[20];

     struct stack S;
     stack_init(&S);
     /*
    // pop(&S);
     push(&S,2);

    printf("\nThe poped value is %d",x);
   // top(&S);

   */

   printf("\nEnter any string\n");
   scanf("%s",c);
 /*  if(c[0]=='\n')
	{
		printf("\n0oik");
		getch();
		exit(1);
	}
 */
   balance(c,&S);
     getch();

}

void balance(char n[20],struct stack *ps)
{
     for(int i=0;n[i]!='\0';i++)
     {
	     if(n[i]=='(' || n[i]=='{' ||  n[i]=='[')
	     {
			  push(ps,n[i]);

	     }
	     else  //(n[i]==')' || n[i]=='}' || n[i]==']' )
	     {
		if(ps->item[ps->top]=='(' && n[i]==')'||  ps->item[ps->top]=='{' && n[i]=='}' || ps->item[ps->top]=='[' && n[i]==']'  )
		     pop(ps);
		else
		    {
				 printf("\nInvalid ");
				 getch();
				 exit(1);
		    }

	     }

     }



     if(ps->top==-1 )
		    printf("\nValid operation\n") ;
     else
	printf("\nInavalid operation\n");
}
