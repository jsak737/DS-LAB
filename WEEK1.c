#include <conio.h>
#include <stdio.h>
#include <stdbool.h>
#define MAX 3
int s[10],top=-1, i, item, ch;
bool b;
void push(); int pop(); void display(); bool isEmpty(); bool isFull(); void checkTop();
void main()
{
    while(1)
    {
        printf("1. PUSH \n 2. POP \n 3. DISPLAY \n 4. EMPTY? \n 5. FULL \n 6.DISPLAY THE TOP ELEMENT \n 7. EXIT \n\n");
        printf("enter your choice!");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: push(); break;
            case 2: item=pop();
                    if (item!=-1)
                    {
                        printf("Popped element is: %d \n", item);
                    }
                    break;
            case 3: display(); break;
            case 4: b=isEmpty();
                    if (b==1)
                        {printf("Yes, the stack is empty!\n");}
                    else 
                        {printf("Stack is not empty!! \n");}
                    break;
            case 5: b=isFull();
                    if (b==0)
                        {printf("Yes, the stack is Full!\n");}
                    else 
                        {printf("Stack is not Full!! \n");}
                    break;
            case 6: checkTop(); break;
            case 7: printf(" exiting the program"); break;
        }
    }
    getch();
    
}
void push()
{
    if (top==MAX-1)
    {
        printf("STACK OVERFLOW!!!\n");
        return;
    }
printf("enter the item to be pushed:");
scanf("%d",&item);
top=top+1;
s[top]=item;
}

int pop()
{
    if (top==-1)
    {
        printf("STACK UNDERFLOW!!!");
        return -1;
    }
    item=s[top];
    top=top-1;
    return item;
}

void display()
{
    if (top==-1)
        {
            printf("stack is empty nothing to display!");
            return;
        }
    else
        {
            printf("displaying the stack:\n");
            for (i=top;i>=0;i--)
            {
             printf("%d\n",s[i]);            
            }
        }
}

bool isEmpty()
{
    return top==-1;
}
bool isFull()
{
    return top=MAX-1;
}
void checkTop()
{
    printf("top is:%d",s[top]);
}

 
        
        
    
