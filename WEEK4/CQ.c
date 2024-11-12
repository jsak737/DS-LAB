#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 4

void CQ_Insert();
int CQ_Delete();
void CQ_Display();

int cq[20];
int front=-1, rear=-1, item, ch, i;

void main()
{
    while(1)
    {
        printf(" \n 1. INSERT \n 2. DELETE \n 3. DISPLAY \n 4. EXIT \n");
        printf("enter your choice: \n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: CQ_Insert(); break;
            case 2: item=CQ_Delete();
                    if (item!=-1)
                    {
                        printf("the dequeued element is:%d\n",item);
                    }
                    break;
            case 3: CQ_Display(); break;
            case 4: exit(0);

        }
    }
}

void CQ_Insert()
{
    if (front == (rear+1)%MAX)
        {
            printf(" circular queue is FULL!! \n");
            return;
        }
    if (rear==-1 && front==-1)
    {
        rear=0;
        front=0;
    }
    else
        rear=(rear+1)%MAX;
    printf("enter the element to be inserted: \n");
    scanf("%d",&item);
    cq[rear]=item;
    return;
}

int CQ_Delete()
{
    if(front==-1 && rear==-1)
    {
        printf("circular queue is empty!! \n");
        return (-1);
    }
    item=cq[front];
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
        front=(front+1)%MAX;
    return item;
}

void CQ_Display()
{
    if(front==-1 && rear==-1)
    {
        printf("circular queue is empty!!!! \n");
        return;
    }

    printf("circular queue contents: \n");
    if (front<=rear)
    {
        for (int i=front;i<=rear;i++)
        {
            printf("%d\n",cq[i]);
        }
    }

   else
   {
        for(int i=front;i<=MAX-1;i++)
        {
            printf("%d\n",cq[i]);
        }
        for (int i=0;i<=rear;i++)
        {
            printf("%d\n",cq[i]);
        }
   }
   return;
}
