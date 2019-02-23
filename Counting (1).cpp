#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int coupen();
int coupen()
{   int a;
    static int coup=0;
    printf("\nPress 1 to get your coupen ");
    scanf("%d",&a);
    if (a == 1){
        coup++;
        printf("\nYour coupen number is %d ",coup);
        return coup;
    }
    else{
        printf("\nWrong selection");
    }
}
void counter();
void counter(){
    int b;
    int count=0;
    do{
    printf("\nPress 1 to call costomer ");
    scanf("%d",&b);
    count++;
    printf("\nCoupen Number %d please proceed to Counter", count);
    }while(count!=coupen());
}
int main(){
    int c;
    printf("1.To get coupen\n2.To call costomer\n3.exit");
    scanf("\n%d",&c);
    switch(c){
        case 1:{
            char a;
            do{
                coupen();
                printf("\nDo you want next coupen? press y for yes and n for no");
                scanf("\n%c",&a);
                if(a=="y"||a=="Y"){
                    coupen();
                }
            }while(a!="n"||a!="N");
            break;
        }
        case 2:{
            counter();
            break;
        }
        case 3:{
            exit(0);
        }
    }
    getch();
    return 0;
}

