
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int value) {
    struct Node *newnode;

    newnode = (struct Node *)malloc(sizeof(struct Node));

    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    newnode->data = value;
    newnode->next = top;
    top = newnode;

    printf("%d inserted\n", value);
}

void pop() {
    struct Node *temp;

    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    temp = top;
    top = top->next;

    printf("%d popped\n", temp->data);
    free(temp);
}

void display() {
    struct Node *temp;

    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    temp = top;

    printf("Stack elements are:\n");

    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    int choice, ele;

    printf("STACK OPERATIONS USING LINKED LIST\n");

    while (1) {
        printf("\n1. PUSH\n");
        printf("2. POP\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element: ");
                scanf("%d", &ele);
                push(ele);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting the program\n");
                return 0;

            default:
                printf("Enter a valid choice\n");
        }
    }

    return 0;
}
