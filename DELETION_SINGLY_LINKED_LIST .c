#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void create(struct Node **head)
{
    struct Node *newnode, *temp;
    int n, i;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        newnode = (struct Node*)malloc(sizeof(struct Node));

        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if(*head == NULL)
        {
            *head = newnode;
        }
        else
        {
            temp = *head;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }
}

void deleteFromFirst(struct Node **head)
{
    if(*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = *head;
    *head = temp->next;
    free(temp);
    printf("First node deleted\n");
}

void deleteFromEnd(struct Node **head)
{
    if(*head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = *head;
    if(temp->next == NULL)
    {
        free(temp);
        *head = NULL;
        return;
    }
    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    printf("Last node deleted\n");
}

void deleteAtPosition(struct Node **head, int position)
{
    if(*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = *head;
    if(position == 0)
    {
        deleteFromFirst(head);
        return;
    }
    for(int i = 1; temp != NULL && i <=position - 1; i++)
    {
        temp = temp->next;
    }
    if(temp == NULL || temp->next == NULL)
    {
        printf("Position out of range\n");
        return;
    }
    struct Node *next = temp->next->next;
    free(temp->next);
    temp->next = next;
    printf("Node deleted at position %d\n", position);
}


void display(struct Node *head)
{
    struct Node *temp = head;
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("Linked List: ");
    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main()
{
    struct Node *head = NULL;
    int choice, position;
    while(1)
    {
        printf("\n--- SINGLY LINKED LIST ---\n");
        printf("1. Create Linked List\n");
        printf("2. Delete First Node\n");
        printf("3. Delete Last Node\n");
        printf("4. Delete At Specified Position\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                create(&head);
                break;

            case 2:
                deleteFromFirst(&head);
                break;

            case 3:
                deleteFromEnd(&head);
                break;

            case 4:
                printf("Enter position: ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                break;

            case 5:
                display(head);
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
