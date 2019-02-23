#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
#define max 2
 void stackinit(struct stack *ps);
  int empty (struct stack *ps);
    int pop (struct stack *ps);
     void push (struct stack *ps, char x );
      int underflow(struct stack *ps);
     int overflow(struct stack *ps ); 
     void top (struct stack *ps);
struct stack
 {
       int top ;
       int item[max];
       
};
 
void stackinit(struct stack *ps)
{
     ps->top=-1;
 }
  int empty (struct stack *ps)
    {
            if (ps->top==-1)
            return 1;
            else 
            return 0;
            }
    int pop (struct stack *ps)
    {
        if (empty(ps))
         {
             printf("stack is empty");
             //exit (1);
             return 0;
             }
             else
             {
                 return (ps->item[ps->top--]);
             }
         }
       void push (struct stack *ps, char x )
       { 
            if (ps->top==max-1)
            {
                printf("\n stack over flow" );
                //exit(1);
                
                }
              else
              {
                  ps-> item[++(ps->top)]=x;
                  }
                  }
           int underflow(struct stack *ps)
           {
               if (empty(ps))
               {  return 1;
               }
               else 
               return 0;
               }
               
            int overflow(struct stack *ps )
            {
                if(ps->top==max-1)
                return 1;
                else 
                return 0;
                }
                  
              void top (struct stack *ps)
              {
                   if(!empty(ps))
                   {
                         printf("\n top of the stack");
                         printf("%d",ps->top);
                         }
                         
                        else 
                        {
                        printf("\n stack is empty\n");                
                        }
                        }  
    void balance (char n[20],struct stack *ps)
    {
         for (int i=0;n[i]!='\0';i++)
         {
             if(n[i]=='('||n[i]=='{'||n[i]=='[')
             {
                 push(ps,n[i]);
                                                
             
             }
             
             else
             {
                 if (ps->item[ps->top]=='('&&n[i]==')'||ps->item[ps->top]=='{'&&n[i]=='}'||ps->item[ps->top]=='['&&n[i]==']')
                   pop(ps);
                   else 
                   {
                      printf("\n invalid");
                      getch();
                      exit(1);
                        
                   }
                 
              }
         }          
            if (ps->top==-1)
            printf("valid expression");
            else
            printf("invalid expression") ;
    }      
             
    int  main()
    {
         struct stack s;
         char a[20];
         stackinit(&s);
         printf("enter the string");
         scanf("%s",a);
         balance(a,&s);
         getch();
         return 0;

                                               
           }    
