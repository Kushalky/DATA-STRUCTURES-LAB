#include<stdio.h>
#define MAX 4
int queue[MAX];
int front=-1;
int rear=-1;

void enqueue(int x)
{
    if((rear+1)%MAX==front)
        printf("Queue is full\n");
    else
    {
        if (front==-1)
            front=0;

        rear=(rear+1)%MAX;
        queue[rear]=x;
        printf("%d inserted successfully\n",x);
    }
}

void dequeue()
{
    if (front==-1)
        printf("Queue is empty\n");
    else
    {
        printf("%d deleted successfully\n",queue[front]);
        if (front==rear)
            front=rear=-1;
        else
            front=(front+1)%MAX;
    }
}

void display()
{
    int i=front;
    while(1)
    {
        printf("%d ",queue[i]);
        if(i==rear){
            printf("");
            break;
        }
        else
            i=(i+1)%MAX;
    }
}

int main()
{
    int choice;
    printf("CIRCULAR QUEUE OPERATIONS\n");
    printf("1.ENQUEUE\n");
    printf("2.DEQUEUE\n");
    printf("3.DISPLAY\n");
    printf("4.EXIT\n");
    while(1)
    {
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        if (choice==4)
        {
            printf("Exiting the program");
            break;
        }
        switch(choice)
        {
            case 1: int ele;
                    printf("Enter the element:");
                    scanf("%d",&ele);
                    enqueue(ele);
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            default: printf("Enter a valid number");
                     break;
        }
    }
    return 0;
}
