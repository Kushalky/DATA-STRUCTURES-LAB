#include<stdio.h>
#define MAX 4

int queue[MAX];
int rear=-1;
int front=-1;

void enqueue(int item)
{
    if (rear==MAX-1){
        printf("Queue is full");
        return;
    }
    else{
        if (front=-1){
            front=0;
        }
        rear++;
        queue[rear]=item;
        printf("%d inserted successfully\n",item);
    }
}

void dequeue()
{
    if (front==-1||front>rear){
        printf("Queue is empty");
        return;
    }
    else{
        printf("%d deleted succesfully from queue\n",queue[front]);
        front++;
    }
}

void display()
{
    if (front==-1||front>rear){
        printf("Queue is empty");
    }
    else{
        for(int i=front;i<=rear;i++)
            printf("%d  ",queue[i]);
    }
}

int main()
{
    int choice,ele;
    printf("---QUEUE OPERATIONS---\n");
    printf("1.ENQUEUE\n");
    printf("2.DEQUEUE\n");
    printf("3.DISPLAY\n");
    printf("4.EXIT\n");
    while(1)
    {
      printf("\nEnter your choice:");
      scanf("%d",&choice);
      if (choice==4){
        printf("Exiting the program\n");
        break;
    }
    switch(choice)
    {
        case 1:printf("Enter the element:");
               scanf("%d",&ele);
               enqueue(ele);
               break;
        case 2:dequeue();
               break;
        case 3:display();
               break;
    }
    }
    return 0;
}
