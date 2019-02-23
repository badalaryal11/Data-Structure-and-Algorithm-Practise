#include<stdio.h>
#include<conio.h>

char rec[200];




fstream fp;
record st;

class record


void write_student()
{
	fp.open("student.dat",ios::out|ios::app);
	st.getdata();
	fp.write((char*)&st,sizeof(student));
	fp.close();
	cout<<"\n\nStudent record has been created";
	getch();

}


int main()
{
    printf("\n\t\t\tWELCOME TO THE PROJECT");
    printf("\nEnter a string\n");
    scanf("%[^\n]",rec);
    printf("\nThe given string is \n%s",rec);
    getch();
    return 0;
}
