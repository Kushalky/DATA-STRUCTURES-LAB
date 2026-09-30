#include <stdio.h>
#define MAX 20

int stack[MAX];
int top = -1;

void push(int item)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        stack[top] = item;
        printf("%d pushed into stack\n", item);
    }
}

int pop()
{
    int item;

    if (top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        item = stack[top];
        top--;
        return item;
    }
}

void display()
{
    int i;

    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack elements are:\n");

        for (i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

int main()
{
    int choice, item;

    while (1)
    {
        printf("\n--- STACK MENU ---\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:   printf("Enter the element: ");
                      scanf("%d", &item);
                      push(item);
                      break;

            case 2:item =   pop();
                            if (item != -1)
                            printf("%d popped from stack\n", item);
                            break;

            case 3:   display();
                      break;

            case 4:  return 0;

            default:  printf("Invalid choice\n");
        }
    }

    return 0;
