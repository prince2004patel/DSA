//stack
#include <stdio.h>
#include <stdlib.h>
#include<process.h>
#define MAX 5

int top = -1, stack[MAX];
void push();
void pop();
void peep();
void change();
void display();


int main()
{
    int choice;

    while (1)
    {
        printf("\nstack operations");
        printf("\n 1.push \n 2.pop \n 3.peep \n 4.change \n 5.display \n 6.exit");
        printf("\nenter your choice");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            peep();
            break;    
        
        case 4:
            change();
            break;

        case 5:
            display();
            break;

         case 6:
           exit(0);

        default:
            printf("\n no valid");
        }
    }
}

void push()
{

    int val;

    if (top == MAX - 1)
    {
        printf("\nstack is full");
    }
    else
    {
        printf("\nenter elemnet to push");
        scanf("%d", &val);
        top = top + 1;
        stack[top] = val;
    }
}

void pop()
{

    if (top == -1)
    {

        printf("underflow");
    }
    else
    {
        printf("popped element: %d", stack[top]);
        top = top - 1;
    }
}
void peep()
{
int p;

printf("\nEnter the position : ");
scanf("%d",&p);

    if(top-p<=-1)
   {
       printf("\nSTACK is overflow !!!");
    }
   else
   {
       printf("\nThe Elements is:%d",stack[top-p]);
   }
}

void change()
{
int v1,v2;

printf("\nEnter Position for change:");
scanf("%d",&v1);

printf("\nEneter the Number for change: ");
scanf("%d",&v2);

    if(top-v1<=-1)
    {
      printf("\nSTACK is overflow !!!");
    }
   else
    {
     stack[top-v1]=v2;
     printf("\nCHANGE successfull !!!");
    }
}

void display()
{
    int i;

    if (top == -1)
    {
        printf("\nstack is empty");
    }
    else
    {
        printf("stack is ...\n");

        for (i = top; i >= 0; --i)
        {
           printf("%d\n", stack[i]);
        }
    }
}