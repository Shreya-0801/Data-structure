#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
char stack[SIZE];
int top=-1;

void push(char add)
{      
        if(top==SIZE-1)
		printf("\n***STACK OVERFLOW***\n");
	else
	{
		top++;
		stack[top]=add;
	}
}


void display()
{	printf("\nThe reversed string is: ");
	int i;
       	if(top!=-1)
	{for(i=top;i>=0;i--)
		printf("%c",stack[i]);
	}
	else
		printf("Stack is empty!!");
	printf("\n");
}


void main()
{ int ch;char add;
	do
	{
	printf("\n||MENU||\n Enter your choice:\n1.Push\n2.Display\n3.Exit\n");
	scanf("%d",&ch);
	if(ch==1)
	{ printf("Enter a character:");
        scanf(" %c",&add);

		push(add);
	}
	else if(ch==2)
		display();
       else if(ch==3)
		exit;
	else
		printf("Invalid input!");
	}
	while(ch!=3);
}


