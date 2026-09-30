#include <stdio.h>
#include <ctype.h>

#define MAX 20

char stack[MAX];
int top = -1;

void push(char item)
{
    if (top == MAX - 1)
        printf("Stack is full\n");
    else
    {
        top++;
        stack[top] = item;
    }
}

char pop()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return '\0';
    }
    else
    {
        return stack[top--];
    }
}

int main()
{
    char str[20], ele, temp;
    int i = 0, index = 0;
    printf("Enter the string:\n");
    scanf("%s", str);
    printf("Enter the character:\n");
    scanf(" %c", &ele);
    while (str[i] != '\0')
    {
        if (str[i] == ele)
            break;
        else
        {
            index++;
            i++;
        }
    }
    if (str[i] == '\0')
    {
        printf("Character not found\n");
        return 0;
    }
    for (i = 0; i <= index; i++)
    {
        temp = str[i];
        push(temp);
    }
    for (i = 0; i <= index; i++)
    {
        str[i] = pop();
    }
    printf("The string is %s", str);

    return 0;
}
